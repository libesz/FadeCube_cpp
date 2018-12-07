/*
 * CubeDisplay.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <CubeDisplay.h>
#include <stdexcept>
#ifdef __MINGW32__
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#endif // __MINGW32__
#include <stdlib.h>
#include <cstring>
#include <sstream>

namespace FadeCube {

CubeDisplay::CubeDisplay(std::string addr, unsigned short port) {
  cubeSocket = createUdpSocket();
  cubeAddress = create_sockaddr(addr, port);
}

CubeDisplay::~CubeDisplay() {
  // TODO Auto-generated destructor stub
}

int CubeDisplay::createUdpSocket() {
  int udp_socket;
  if( ( udp_socket = socket( AF_INET, SOCK_DGRAM, 0 ) ) < 0) {
    throw std::bad_alloc();
  }
  return udp_socket;
}

struct sockaddr_in CubeDisplay::create_sockaddr( std::string ip, unsigned short port ) {
  struct sockaddr_in address;
  memset(&(address.sin_zero), 0, sizeof(address.sin_zero));

  address.sin_family = AF_INET; // sets the server address to type AF_INET, similar to the socket we will use.
  address.sin_addr.s_addr = inet_addr( ip.c_str() ); // this sets the server address.
  address.sin_port = htons( port );
  return address;
}

void CubeDisplay::sendFrameToCube( unsigned char *packet_payload ) const {
  if( sendto( cubeSocket, (const char *)packet_payload, cubeDataSize, 0, ( struct sockaddr * ) &cubeAddress, sizeof( cubeAddress ) ) < 0 ) {
    throw std::runtime_error("can't send data to cube");
  }
}

void CubeDisplay::setLed( unsigned char *frame, Point p ) const {
   unsigned short int index;
   unsigned char inner_index, reversed_z = 9 - p.getZ();
   index = ( reversed_z * 100 ) + ( p.getY() * 10 ) + p.getX(); //index in the 0-1023 range
   inner_index = 2 * ( 3 - ( index % 4 ) ); //the inner-byte index (0-3)
   index /= 4; //convert index to 0-250 range

   if(index > cubeDataSize-1) {
	 std::stringstream ss("bad point coordinate: ");
	 ss << p;
     throw std::runtime_error(ss.str());
   }

   frame[ index ] &= ~( 0b00000011 << inner_index ); //set the state of the coordinate to 0
   frame[ index ] |= ( ( p.getBr() / 64 ) << inner_index ); //set the new value
}

void CubeDisplay::draw(const std::vector<Point> points) const {
  unsigned char packet_payload[cubeDataSize]; //create buffer
  memset( packet_payload, 0, sizeof( packet_payload ) );

  packet_payload[0] = 1; //first byte is 1 -> means frame data for the cube

  for(auto p: points) {
    setLed(&packet_payload[1], p);
  }
  sendFrameToCube(packet_payload);
}

} /* namespace FadeCube */

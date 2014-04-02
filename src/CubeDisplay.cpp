/*
 * CubeDisplay.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <CubeDisplay.h>
#include <stdexcept>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <cstring>

namespace FadeCube {

CubeDisplay::CubeDisplay() {
  cubeSocket = createUdpSocket();
  cubeAddress = create_sockaddr("192.168.1.99", 1125);
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

struct sockaddr_in CubeDisplay::create_sockaddr( char *ip, unsigned short port ) {
  struct sockaddr_in address;
  memset(&(address.sin_zero), 0, sizeof(address.sin_zero));

  address.sin_family = AF_INET; // sets the server address to type AF_INET, similar to the socket we will use.
  address.sin_addr.s_addr = inet_addr( ip ); // this sets the server address.
  address.sin_port = htons( port );
  return address;
}

int CubeDisplay::sendFrameToCube( int client_socket, struct sockaddr_in cube_address, cube_frame_t *cube_frame ) const {
  unsigned char packet_payload[251]; //create buffer
  memset( packet_payload, 0, sizeof( packet_payload ) );

  packet_payload[0] = 1; //first byte is 1 -> means frame data for the cube

  memcpy( &packet_payload[1], cube_frame->leds, 250 ); //copy the frame data to the buffer

  if( sendto( client_socket, packet_payload, sizeof( packet_payload ), 0, ( struct sockaddr * ) &cube_address, sizeof( cube_address ) ) < 0 ) {
    return -1;
  }
  return 1;
}

void CubeDisplay::setLed( cube_frame_t *frame, coord_t coordinate, unsigned char brightness ) const {
   unsigned short int index;
   unsigned char inner_index, reversed_z = 9 - coordinate.z;
   index = ( reversed_z * 100 ) + ( coordinate.y * 10 ) + coordinate.x; //index in the 0-1023 range
   inner_index = 2 * ( 3 - ( index % 4 ) ); //the inner-byte index (0-3)
   index /= 4; //convert index to 0-250 range

   frame->leds[ index ] &= ~( 0b00000011 << inner_index ); //set the state of the coordinate to 0
   frame->leds[ index ] |= ( ( brightness & 3 ) << inner_index ); //set the new value
}

void CubeDisplay::draw(const std::vector<Point> points) const {
  cube_frame_t frame;
  memset( &frame, 0, sizeof( frame ) );

  for(auto p: points) {
    coord_t c;
    c.x = p.getX();
    c.y = p.getY();
    c.z = p.getZ();
    setLed(&frame, c, p.getBr());
  }
  sendFrameToCube(cubeSocket, cubeAddress, &frame);
}

} /* namespace FadeCube */

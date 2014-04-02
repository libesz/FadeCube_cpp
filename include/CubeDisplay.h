/*
 * CubeDisplay.h
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#ifndef CUBEDISPLAY_H_
#define CUBEDISPLAY_H_

#include <Display.h>
#include <netinet/in.h>

namespace FadeCube {

class CubeDisplay: public FadeCube::Display {
  typedef struct cube_frame {
      unsigned char leds[250];
  } cube_frame_t;

  typedef struct coord {
      char x;
      char y;
      char z;
  } coord_t;

  int cubeSocket;
  struct sockaddr_in cubeAddress;

  int createUdpSocket();
  int sendFrameToCube( int client_socket, struct sockaddr_in cube_address, cube_frame_t *cube_frame ) const;
  struct sockaddr_in create_sockaddr( char *ip, unsigned short port );
  void setLed( cube_frame_t *frame, coord_t coordinate, unsigned char brightness ) const;
public:
  CubeDisplay();
  virtual ~CubeDisplay();
  void draw(const std::vector<Point>) const;
};

} /* namespace FadeCube */

#endif /* CUBEDISPLAY_H_ */

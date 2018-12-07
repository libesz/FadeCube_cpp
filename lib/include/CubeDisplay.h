/*
 * CubeDisplay.h
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#ifndef CUBEDISPLAY_H_
#define CUBEDISPLAY_H_

#include <Display.h>
#ifdef __MINGW32__
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif
#include <string>

namespace FadeCube {

class CubeDisplay: public FadeCube::Display {
  const int cubeDataSize = 251;
  int cubeSocket;
  struct sockaddr_in cubeAddress;

  static int createUdpSocket();
  static struct sockaddr_in create_sockaddr( std::string ip, unsigned short port );
  void setLed( unsigned char *frame, Point p ) const;
  void sendFrameToCube( unsigned char *packet_payload ) const;
public:
  CubeDisplay(std::string addr, unsigned short port);
  virtual ~CubeDisplay();
  void draw(const std::vector<Point>) const;
};

} /* namespace FadeCube */

#endif /* CUBEDISPLAY_H_ */

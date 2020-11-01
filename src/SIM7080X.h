#ifndef SIM7080X_h
#define SIM7080X_h

#include <stdlib.h>
#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <wiring.h>
#endif

//#define unsigned int uint8_t

/* SIM7080X Class */
class SIM7080X {

public:
  // Pin definition
  const static int powerkey = 2;	// POWERKEY의 기본값
  int userkey;

  SIM7080X();
  ~SIM7080X();

  void init(Stream* espSerial);
  // SIM query
  void PowerOn(int PowerKey = powerkey);

  bool connectCellular(unsigned int timeout=10000);
  bool connectServer(const char* host, uint16_t port, const char* token, unsigned int timeout=10000, unsigned int keeptime=60, bool ignore=false);
  bool isServer(unsigned int timeout = 10000);
  // GPS positoning
  bool GPSPositioning();

  // Other functions.
  uint8_t sendATcommand(const char* ATcommand, const char* expected_answer, unsigned int timeout);
  bool sendDataJson(const char* value, unsigned int timeout = 10000);
  
  void cleanBuf();
  
  Stream *SIM_Serial;
};

//extern SIM7080X sim7600;

#endif


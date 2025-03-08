/**
 * WiegandMultiReader
 * 
 * By Steven de Salas
 * 
 * Upstream source code written by JP Liew
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 */

#ifndef _WIEGAND_MULTI_H_
#define _WIEGAND_MULTI_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class WIEGAND {

public:
	WIEGAND();
	bool available();
  void ReadD0();
	void ReadD1();
	unsigned long getCode();
	int getWiegandType();
	
private:
	bool DoWiegandConversion ();
	unsigned long GetCardId (volatile unsigned long *codehigh, volatile unsigned long *codelow, char bitlength);
	
	volatile unsigned long 	_cardTempHigh;
	volatile unsigned long 	_cardTemp;
	volatile unsigned long 	_lastWiegand;
	volatile int				_bitCount;	
	int				_wiegandType;
	unsigned long	_code;
};

#endif

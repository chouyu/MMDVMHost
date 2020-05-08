/*
 *   Copyright (C) 2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(FMControl_H)
#define	FMControl_H

#include "FMNetwork.h"
#include "Defines.h"

typedef struct 
{
	union
	{
		int pack;
		char packBytes[4];
	};
	
} SamplePack;


class CFMControl {
public:
	CFMControl(CFMNetwork* network);
	~CFMControl();

	bool writeModem(const unsigned char* data, unsigned int length);

	unsigned int readModem(unsigned char* data, unsigned int space);

	void clock(unsigned int ms);

	void enable(bool enabled);

private:
	CFMNetwork* m_network;
    bool        m_enabled;
};

#endif

//====== Copyright � 1996-2003, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#ifndef MAPINFO_H
#define MAPINFO_H
#ifdef _WIN32
#pragma once
#endif


#include "baseentity.h"


class CMapInfo : public CPointEntity
{
public :
	
	CMapInfo();
	virtual ~CMapInfo();

	bool KeyValue( const char *szKeyName, const char *szValue );
	void Spawn();


public:
	int m_iBuyingStatus;
	float m_flBombRadius;
};


// The info_map_parameters entity in this map (only one is allowed for).
extern CMapInfo *g_pMapInfo;


#endif // MAPINFO_H
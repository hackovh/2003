//========= Copyright � 1996-2001, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef ISCENETOKENPROCESSOR_H
#define ISCENETOKENPROCESSOR_H
#ifdef _WIN32
#pragma once
#endif

class ISceneTokenProcessor
{
public:
	virtual const char	*CurrentToken( void ) = 0;
	virtual bool		GetToken( bool crossline ) = 0;
	virtual bool		TokenAvailable( void ) = 0;
	virtual void		Error( const char *fmt, ... ) = 0;
};

#endif // ISCENETOKENPROCESSOR_H

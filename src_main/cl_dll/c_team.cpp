//========= Copyright � 1996-2001, Valve LLC, All rights reserved. ============
//
// Purpose: Client side CTeam class
//
// $NoKeywords: $
//=============================================================================
#include "cbase.h"
#include "c_team.h"

//-----------------------------------------------------------------------------
// Purpose: RecvProxy that converts the Team's player UtlVector to entindexes
//-----------------------------------------------------------------------------
void RecvProxy_PlayerList(  const CRecvProxyData *pData, void *pStruct, void *pOut )
{
	C_Team *pTeam = (C_Team*)pOut;
	pTeam->m_aPlayers[pData->m_iElement] = pData->m_Value.m_Int;
}


void RecvProxyArrayLength_PlayerArray( void *pStruct, int objectID, int currentArrayLength )
{
	C_Team *pTeam = (C_Team*)pStruct;
	
	if ( pTeam->m_aPlayers.Size() != currentArrayLength )
		pTeam->m_aPlayers.SetSize( currentArrayLength );
}


IMPLEMENT_CLIENTCLASS_DT_NOBASE(C_Team, DT_Team, CTeam)
	RecvPropInt( RECVINFO(m_iTeamNum)),
	RecvPropInt( RECVINFO(m_iScore)),
	RecvPropString( RECVINFO(m_szTeamname)),
	
	RecvPropArray2( 
		RecvProxyArrayLength_PlayerArray,
		RecvPropInt( "player_array_element", 0, SIZEOF_IGNORE, 0, RecvProxy_PlayerList ), 
		MAX_PLAYERS, 
		0, 
		"player_array"
		)
END_RECV_TABLE()

// Global list of client side team entities
CUtlVector< C_Team * > g_Teams;

//=================================================================================================
// C_Team functionality

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
C_Team::C_Team()
{
	m_iScore = 0;
	memset( m_szTeamname, 0, sizeof(m_szTeamname) );

	m_iDeaths = 0;
	m_iPing = 0;
	m_iPacketloss = 0;

	// Add myself to the global list of team entities
	g_Teams.AddToTail( this );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
C_Team::~C_Team()
{
	g_Teams.FindAndRemove( this );
}


void C_Team::RemoveAllPlayers()
{
	m_aPlayers.RemoveAll();
}

void C_Team::PreDataUpdate( DataUpdateType_t updateType )
{
	BaseClass::PreDataUpdate( updateType );
}


//-----------------------------------------------------------------------------
// Gets the ith player on the team (may return NULL) 
//-----------------------------------------------------------------------------
C_BasePlayer* C_Team::GetPlayer( int idx )
{
	return (C_BasePlayer*)cl_entitylist->GetEnt(m_aPlayers[idx]);
}


int C_Team::GetTeamNumber()
{
	return m_iTeamNum;
}


//=================================================================================================
// TEAM HANDLING
//=================================================================================================
// Purpose: 
//-----------------------------------------------------------------------------
char *C_Team::Get_Name( void )
{
	return m_szTeamname;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int C_Team::Get_Score( void )
{
	return m_iScore;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int C_Team::Get_Deaths( void )
{
	return m_iDeaths;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int C_Team::Get_Ping( void )
{
	return m_iPing;
}

//-----------------------------------------------------------------------------
// Purpose: Return the number of players in this team
//-----------------------------------------------------------------------------
int C_Team::Get_Number_Players( void )
{
	return m_aPlayers.Size();
}

//-----------------------------------------------------------------------------
// Purpose: Returns true if the specified player is on this team
//-----------------------------------------------------------------------------
bool C_Team::ContainsPlayer( int iPlayerIndex )
{
	for (int i = 0; i < m_aPlayers.Size(); i++ )
	{
		if ( m_aPlayers[i] == iPlayerIndex )
			return true;
	}

	return false;
}


void C_Team::ClientThink()
{
}


//=================================================================================================
// GLOBAL CLIENT TEAM HANDLING
//=================================================================================================
// Purpose: Get the C_Team for the local player
//-----------------------------------------------------------------------------
C_Team *GetLocalTeam( void )
{
	if ( !engine )
		return NULL;
	return GetPlayersTeam( engine->GetPlayer() );
}

//-----------------------------------------------------------------------------
// Purpose: Get the C_Team for the specified team number
//-----------------------------------------------------------------------------
C_Team *GetGlobalTeam( int iTeamNumber )
{
	for (int i = 0; i < g_Teams.Size(); i++ )
	{
		if ( g_Teams[i]->GetTeamNumber() == iTeamNumber )
			return g_Teams[i];
	}

	return NULL;
}

//-----------------------------------------------------------------------------
// Purpose: Get the team of the specified player
//-----------------------------------------------------------------------------
C_Team *GetPlayersTeam( int iPlayerIndex )
{
	for (int i = 0; i < g_Teams.Size(); i++ )
	{
		if ( g_Teams[i]->ContainsPlayer( iPlayerIndex ) )
			return g_Teams[i];
	}

	return NULL;
}

//-----------------------------------------------------------------------------
// Purpose: Get the team of the specified player
//-----------------------------------------------------------------------------
C_Team *GetPlayersTeam( C_BasePlayer *pPlayer )
{
	return GetPlayersTeam( pPlayer->entindex() );
}

//-----------------------------------------------------------------------------
// Purpose: Returns true if the two specified players are on the same team
//-----------------------------------------------------------------------------
bool ArePlayersOnSameTeam( int iPlayerIndex1, int iPlayerIndex2 )
{
	for (int i = 0; i < g_Teams.Size(); i++ )
	{
		if ( g_Teams[i]->ContainsPlayer( iPlayerIndex1 ) && g_Teams[i]->ContainsPlayer( iPlayerIndex2 ) )
			return true;
	}

	return false;
}

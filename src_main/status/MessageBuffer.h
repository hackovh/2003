// MessageBuffer.h: interface for the CMessageBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESSAGEBUFFER_H__808F72A0_B24F_11D1_8748_006097A548BE__INCLUDED_)
#define AFX_MESSAGEBUFFER_H__808F72A0_B24F_11D1_8748_006097A548BE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define	NET_NAMELEN			64

#define NET_MAXMESSAGE		8192
#define NET_HEADERSIZE		(2 * sizeof(unsigned int))
#define NET_DATAGRAMSIZE	(MAX_DATAGRAM + NET_HEADERSIZE)

class CMessageBuffer  
{
public:
	int GetReadCount();
	int GetCurSize();
	void SetCurSize(int nSize);
	void * GetData();
	int GetMaxSize();
	CMessageBuffer();
	CMessageBuffer(int sz); // sets max size at allocation.
	virtual ~CMessageBuffer();

	void SZ_Alloc (int startsize);
	void SZ_Free ();
	void SZ_Clear ();
	void *SZ_GetSpace (int length);
	void SZ_Write (void *data, int length);
	void SZ_Print (char *data);	// strcats onto the sizebuf

	void  MSG_WriteChar (int c);
	void  MSG_WriteByte (int c);
	void  MSG_WriteShort (int c);
	void  MSG_WriteWord (int c);
	void  MSG_WriteLong (int c);
	void  MSG_WriteFloat (float f);
	void  MSG_WriteString (char *s);
	void  MSG_WriteBuf (int iSize, void *buf);
	void  MSG_WriteCoord (float f);
	void  MSG_WriteAngle (float f);
	void  MSG_WriteHiresAngle (float f);

	void  MSG_BeginReading (void);
	int	  MSG_ReadChar (void);
	int   MSG_ReadByte (void);
	int   MSG_ReadShort (void);
	int   MSG_ReadWord (void);
	int   MSG_ReadLong (void);
	float MSG_ReadFloat (void);
	char *MSG_ReadString (void);
	int   MSG_ReadBuf(int iSize, void *pbuf);
	float MSG_ReadCoord (void);
	float MSG_ReadAngle (void);
	float MSG_ReadHiresAngle (void);

	BOOL	m_bMsgBadRead;

protected:
	int		m_nMsgReadCount;
	unsigned char *m_pData;
	int		m_nMaxSize;
	int		m_nCurSize;
	BOOL	m_bAllowOverflow;	// if false, do a Sys_Error
	BOOL	m_bOverFlowed;		// set to true if the buffer size failed
};

#endif // !defined(AFX_MESSAGEBUFFER_H__808F72A0_B24F_11D1_8748_006097A548BE__INCLUDED_)


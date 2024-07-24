#include  "WonsikWorldDummyProxy.h"
#include "WonsikWorldPKT_TYPE.h"
void WonsikWorldDummyProxy::EnterGame_CS(SessionInfo sessionInfo, WString& nickName, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_EnterGame_CS << nickName;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::EnterGame_CS(List<SessionInfo>& sessionInfoList, WString& nickName, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_EnterGame_CS << nickName;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::EnterGame_SC(SessionInfo sessionInfo, short enterGameResult, LONG64 playerID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_EnterGame_SC << enterGameResult << playerID;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::EnterGame_SC(List<SessionInfo>& sessionInfoList, short enterGameResult, LONG64 playerID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_EnterGame_SC << enterGameResult << playerID;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateMyCharacter_SC(SessionInfo sessionInfo, short mapID, float dirX, float dirY, float locationX, float locationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateMyCharacter_SC << mapID << dirX << dirY << locationX << locationY;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateMyCharacter_SC(List<SessionInfo>& sessionInfoList, short mapID, float dirX, float dirY, float locationX, float locationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateMyCharacter_SC << mapID << dirX << dirY << locationX << locationY;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& nickName, float dirX, float dirY, float locationX, float locationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateOtherCharacter_SC << mapID << playerID << nickName << dirX << dirY << locationX << locationY;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateOtherCharacter_SC(List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, WString& nickName, float dirX, float dirY, float locationX, float locationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateOtherCharacter_SC << mapID << playerID << nickName << dirX << dirY << locationX << locationY;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::DeleteCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_DeleteCharacter_SC << mapID << playerID;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::DeleteCharacter_SC(List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_DeleteCharacter_SC << mapID << playerID;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_CS(SessionInfo sessionInfo, short beforeMapID, short afterMapID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_ChangeMap_CS << beforeMapID << afterMapID;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_CS(List<SessionInfo>& sessionInfoList, short beforeMapID, short afterMapID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_ChangeMap_CS << beforeMapID << afterMapID;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_SC(SessionInfo sessionInfo, short beforeMapID, short afterMapID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_ChangeMap_SC << beforeMapID << afterMapID;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_SC(List<SessionInfo>& sessionInfoList, short beforeMapID, short afterMapID, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_ChangeMap_SC << beforeMapID << afterMapID;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_CS(SessionInfo sessionInfo, short mapID, WString& chatMessage, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_SendChatMessage_CS << mapID << chatMessage;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_CS(List<SessionInfo>& sessionInfoList, short mapID, WString& chatMessage, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_SendChatMessage_CS << mapID << chatMessage;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& chatMessage, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_SendChatMessage_SC << mapID << playerID << chatMessage;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_SC(List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, WString& chatMessage, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_SendChatMessage_SC << mapID << playerID << chatMessage;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_CS(SessionInfo sessionInfo, short mapID, float destinationX, float destinationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_CS << mapID << destinationX << destinationY;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_CS(List<SessionInfo>& sessionInfoList, short mapID, float destinationX, float destinationY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_CS << mapID << destinationX << destinationY;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_SC(SessionInfo sessionInfo, short mapID, Vector<float>& destinationsX, Vector<float>& destinationsY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_SC << mapID << destinationsX << destinationsY;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_SC(List<SessionInfo>& sessionInfoList, short mapID, Vector<float>& destinationsX, Vector<float>& destinationsY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_SC << mapID << destinationsX << destinationsY;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, Vector<float>& destinationsX, Vector<float>& destinationsY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveOtherCharacter_SC << mapID << playerID << destinationsX << destinationsY;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveOtherCharacter_SC(List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, Vector<float>& destinationsX, Vector<float>& destinationsY, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveOtherCharacter_SC << mapID << playerID << destinationsX << destinationsY;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::HeartBeat_CS(SessionInfo sessionInfo, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_HeartBeat_CS;
	}
	catch(int useSize)
	{
	}
	_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::HeartBeat_CS(List<SessionInfo>& sessionInfoList, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_HeartBeat_CS;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummy->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}

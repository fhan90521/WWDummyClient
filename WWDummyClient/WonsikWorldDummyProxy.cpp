#include "WonsikWorldDummyProxy.h"
#include "WonsikWorldPKT_TYPE.h"
#include "Network/IOCPDummyClient.h"
#include "WWVector2D.h"
void WonsikWorldDummyProxy::EnterGame_CS(SessionInfo sessionInfo, const WString& nickName, bool bDisconnect)
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::EnterGame_CS(const List<SessionInfo>& sessionInfoList, const WString& nickName, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::EnterGame_SC(const List<SessionInfo>& sessionInfoList, short enterGameResult, LONG64 playerID, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateMyCharacter_SC(SessionInfo sessionInfo, short mapID, const WWVector2D& dirVec, const WWVector2D& location, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateMyCharacter_SC << mapID << dirVec << location;
	}
	catch(int useSize)
	{
	}
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateMyCharacter_SC(const List<SessionInfo>& sessionInfoList, short mapID, const WWVector2D& dirVec, const WWVector2D& location, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateMyCharacter_SC << mapID << dirVec << location;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, const WString& nickName, const WWVector2D& dirVec, const WWVector2D& location, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateOtherCharacter_SC << mapID << playerID << nickName << dirVec << location;
	}
	catch(int useSize)
	{
	}
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::CreateOtherCharacter_SC(const List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, const WString& nickName, const WWVector2D& dirVec, const WWVector2D& location, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_CreateOtherCharacter_SC << mapID << playerID << nickName << dirVec << location;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::DeleteCharacter_SC(const List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_CS(const List<SessionInfo>& sessionInfoList, short beforeMapID, short afterMapID, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::ChangeMap_SC(const List<SessionInfo>& sessionInfoList, short beforeMapID, short afterMapID, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_CS(SessionInfo sessionInfo, short mapID, const WString& chatMessage, bool bDisconnect)
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_CS(const List<SessionInfo>& sessionInfoList, short mapID, const WString& chatMessage, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, const WString& chatMessage, bool bDisconnect)
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::SendChatMessage_SC(const List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, const WString& chatMessage, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_CS(SessionInfo sessionInfo, short mapID, const WWVector2D& destination, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_CS << mapID << destination;
	}
	catch(int useSize)
	{
	}
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_CS(const List<SessionInfo>& sessionInfoList, short mapID, const WWVector2D& destination, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_CS << mapID << destination;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_SC(SessionInfo sessionInfo, short mapID, const Vector<WWVector2D>& destinations, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_SC << mapID << destinations;
	}
	catch(int useSize)
	{
	}
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveMyCharacter_SC(const List<SessionInfo>& sessionInfoList, short mapID, const Vector<WWVector2D>& destinations, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveMyCharacter_SC << mapID << destinations;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, const Vector<WWVector2D>& destinations, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveOtherCharacter_SC << mapID << playerID << destinations;
	}
	catch(int useSize)
	{
	}
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::MoveOtherCharacter_SC(const List<SessionInfo>& sessionInfoList, short mapID, LONG64 playerID, const Vector<WWVector2D>& destinations, bool bDisconnect)
{
	CSendBuffer* pBuf = CSendBuffer::Alloc();
	pBuf->IncrementRefCnt();
	try
	{
		*pBuf << PKT_TYPE_MoveOtherCharacter_SC << mapID << playerID << destinations;
	}
	catch(int useSize)
	{
	}
	for(SessionInfo sessionInfo: sessionInfoList)
	{
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
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
	_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	pBuf->DecrementRefCnt();
}
void WonsikWorldDummyProxy::HeartBeat_CS(const List<SessionInfo>& sessionInfoList, bool bDisconnect)
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
		_pDummyClient->Unicast(sessionInfo, pBuf, bDisconnect);
	}
	pBuf->DecrementRefCnt();
}

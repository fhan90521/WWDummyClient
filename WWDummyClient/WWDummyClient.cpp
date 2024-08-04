#include "WWDummyClient.h"
#include "MakeShared.h"
#include "Log.h"
#include "WWDummyRoom.h"

void WWDummyClient::OnConnect(SessionInfo sessionInfo)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::Enter, sessionInfo);
}

void WWDummyClient::OnDisconnect(SessionInfo sessionInfo)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::Leave, sessionInfo);
}

void WWDummyClient::OnRecv(SessionInfo sessionInfo, CRecvBuffer& buf)
{
	if (PacketProc(sessionInfo, buf) == false)
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "OnRecv Error\n");
		Disconnect(sessionInfo);
	}
}

WWDummyClient::WWDummyClient(): IOCPDummyClient("WWDummySet.json"),WonsikWorldDummyProxy(this)
{
	_wwDummyRoom = new WWDummyRoom(this);
}

WWDummyClient::~WWDummyClient()
{
	delete _wwDummyRoom;
	CloseDummy();
}

void WWDummyClient::Run()
{
	IOCPRun();
}

void WWDummyClient::PrintDummyStatus()
{
	_wwDummyRoom->PrintRoomStatus();
}
void WWDummyClient::ProcEnterGame_SC(SessionInfo sessionInfo, short enterGameResult, LONG64 playerID)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::EnterGameSC, sessionInfo, enterGameResult, playerID);
}

void WWDummyClient::ProcCreateMyCharacter_SC(SessionInfo sessionInfo, short mapID, float dirX, float dirY, float locationX, float locationY)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::CreateMyCharacterSC, sessionInfo, mapID);
}

void WWDummyClient::ProcCreateOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& nickName, float dirX, float dirY, float locationX, float locationY)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::CreateOtherCharacterSC, sessionInfo, mapID, playerID);
}

void WWDummyClient::ProcDeleteCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::DeleteCharacterSC, sessionInfo, mapID, playerID);
}

void WWDummyClient::ProcChangeMap_SC(SessionInfo sessionInfo, short beforeMapID, short afterMapID)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::ChangeMapSC, sessionInfo, beforeMapID, afterMapID);
}

void WWDummyClient::ProcSendChatMessage_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& chatMessage)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::SendChatMessageSC, sessionInfo, mapID, playerID);
}

void WWDummyClient::ProcMoveMyCharacter_SC(SessionInfo sessionInfo, short mapID, Vector<float>& destinationsX, Vector<float>& destinationsY)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::MoveMyCharacterSC, sessionInfo, mapID);
}

void WWDummyClient::ProcMoveOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, Vector<float>& destinationsX, Vector<float>& destinationsY)
{
	_wwDummyRoom->PushJob(&WWDummyRoom::MoveOtherCharacterSC, sessionInfo, mapID, playerID);
}

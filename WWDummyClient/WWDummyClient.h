#pragma once
#include "IOCPDummyClient.h"
#include "WonsikWorldDummyProxy.h"
#include "WonsikWorldServerStub.h"
#include <thread>
#include "MyStlContainer.h"
class WWDummyClient: public IOCPDummyClient,public WonsikWorldDummyProxy, public WonsikWorldServerStub
{
private:
	virtual void OnConnect(SessionInfo sessionInfo) override;
	virtual void OnDisconnect(SessionInfo sessionInfo) override;
	virtual void OnRecv(SessionInfo sessionInfo, CRecvBuffer& buf) override;
public:
	WWDummyClient();
	virtual ~WWDummyClient();
	virtual void Run() override;
	void PrintDummyStatus();
private:
	class WWDummyRoom* _wwDummyRoom;
//Recv
	virtual void ProcEnterGame_SC(SessionInfo sessionInfo, short enterGameResult, LONG64 playerID) override;
	virtual void ProcCreateMyCharacter_SC(SessionInfo sessionInfo, short mapID, float dirX, float dirY, float locationX, float locationY) override;
	virtual void ProcCreateOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& nickName, float dirX, float dirY, float locationX, float locationY) override;
	virtual void ProcDeleteCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID) override;
	virtual void ProcChangeMap_SC(SessionInfo sessionInfo, short beforeMapID, short afterMapID) override;
	
	
	virtual void ProcSendChatMessage_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& chatMessage) override;
	virtual void ProcMoveMyCharacter_SC(SessionInfo sessionInfo, short mapID, Vector<float>& destinationsX, Vector<float>& destinationsY) override;
	virtual void ProcMoveOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, Vector<float>& destinationsX, Vector<float>& destinationsY) override;

	virtual void ProcHeartBeat_CS(SessionInfo sessionInfo) {}
};
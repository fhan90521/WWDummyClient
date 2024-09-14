#pragma once
#include "Network/IOCPDummyClient.h"
#include "Container/MyStlContainer.h"
#include "WonsikWorldDummyProxy.h"
#include "WonsikWorldDummyStub.h"
#include <thread>
class WWDummyClient: public IOCPDummyClient,public WonsikWorldDummyProxy, private WonsikWorldDummyStub
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
	virtual void ProcCreateMyCharacter_SC(SessionInfo sessionInfo, short mapID, WWVector2D& dirVec, WWVector2D& location) override;
	virtual void ProcCreateOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& nickName, WWVector2D& dir, WWVector2D& location) override;
	virtual void ProcDeleteCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID) override;
	virtual void ProcChangeMap_SC(SessionInfo sessionInfo, short beforeMapID, short afterMapID) override;
	
	
	virtual void ProcSendChatMessage_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, WString& chatMessage) override;
	virtual void ProcMoveMyCharacter_SC(SessionInfo sessionInfo, short mapID, Vector<WWVector2D>& destinations) override;
	virtual void ProcMoveOtherCharacter_SC(SessionInfo sessionInfo, short mapID, LONG64 playerID, Vector<WWVector2D>& destinations) override;

	virtual void ProcHeartBeat_CS(SessionInfo sessionInfo) {}
};
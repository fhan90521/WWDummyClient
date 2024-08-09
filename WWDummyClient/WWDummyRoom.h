#pragma once
#include "JobQueue.h"
class WWDummyRoom : public JobQueue
{
private:
	//더미옵션
	int _dummyCnt = 1000;
	int _updatePeriod = 20;
	int _doingContentProbability = 5;
	int _changeMapProbaility = 5;
	ULONG64 _newDummyID = 0;
	ULONG64 _startDummyID = 0;
	int _randomSeed = 0;
	int _disconnectProbability = 1;
	
private:
	//error
	int _connectFailCnt = 0;
	int _enterFailCnt = 0;
	int _disconnectCnt = 0;

	int _mapIdErrorInCreatMyCharacter = 0;
	int _mapIdErrorInCreatOhterCharacter = 0;
	int _mapIdErrorInDeleteCharacter = 0;
	int _mapIdErrorInChangeMap = 0;
	int _mapIdErrorInSendChatMessage = 0;
	int _mapIdErrorInMoveMyCharacter = 0;
	int _mapIdErrorInMoveOtherCharacter = 0;

	int _creatAleadyExistOhterCharacter = 0;
	int _noneExistDeleteCharacter = 0;
	int _noneExistSendChatMessage = 0;
	int _noneExistMoveOtherCharacter = 0;

private:
	Vector<WString> _dummyChats;
	HANDLE _hShutDownEvent;
	std::thread* _updateThread;
	Map<SessionInfo::ID, class WWDummySession*> _dummySessionMap;
	
	
	void Update();
	void UpdateThreadFunc();
	class WWDummyClient* _wwDummyClient = nullptr;
	void GetDummyOption();
public:
	int GetPlayerCnt();
	void ConnectWork();
	WWDummyRoom(class WWDummyClient* wwDummyClient);
	virtual ~WWDummyRoom();
public:
	//Recv
	void Enter(SessionInfo sessionInfo);
	void Leave(SessionInfo sessionInfo);
	void EnterGameSC(SessionInfo sessionInfo, short enterGameResult, LONG64 playerID);
	void CreateMyCharacterSC(SessionInfo sessionInfo, short mapID);
	void CreateOtherCharacterSC(SessionInfo sessionInfo, short mapID, LONG64 playerID);
	void DeleteCharacterSC(SessionInfo sessionInfo, short mapID, LONG64 playerID);
	void ChangeMapSC(SessionInfo sessionInfo, short beforeMapID, short afterMapID);

	void SendChatMessageSC(SessionInfo sessionInfo, short mapID, LONG64 playerID);
	void MoveMyCharacterSC(SessionInfo sessionInfo, short mapID); 
	void MoveOtherCharacterSC(SessionInfo sessionInfo, short mapID, LONG64 playerID);

	void PrintRoomStatus();




};
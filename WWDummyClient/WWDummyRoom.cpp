#include "WWDummyRoom.h"
#include "WWDummySession.h"
#include "WWEnum.h"
#include "WWDummyClient.h"
#include <format>
#include <iostream>
#include <fstream>
void WWDummyRoom::Update()
{
	for (auto& dummyPair : _dummySessionMap)
	{
		SessionInfo dummySessionInfo = dummyPair.first;
		WWDummySession* dummySession = dummyPair.second;
		int probability = rand() % 10000;
		if (probability < _disconnectProbability)
		{
			dummySession->bSelfDisconnect = true;
			_wwDummyClient->Disconnect(dummySessionInfo);
		}
		else
		{
			if (dummySession->bChangingMap == true)
			{
				continue;
			}

			if (dummySession->sessionType == SessionType::GUEST)
			{


				WString dummyNickName = L"DUMMY";
				dummyNickName.append(std::to_wstring(_startDummyID));
				dummyNickName.append(std::to_wstring(_newDummyID++));

				dummySession->bChangingMap = true;
				_wwDummyClient->EnterGame_CS(dummySessionInfo, dummyNickName);
			}

			else if (dummySession->sessionType == SessionType::PLAYER)
			{
				probability = rand() % 10000;
				if (probability < _doingContentProbability)
				{
					probability = rand() % 100;
					if (probability < 50)
					{
						int chatIndex = rand() % _dummyChats.size();
						_wwDummyClient->SendChatMessage_CS(dummySessionInfo, dummySession->mapID, _dummyChats[chatIndex]);
					}
					else
					{
						int destinationX = rand() % (MAP_WIDTH+ MAP_WIDTH/50) - MAP_WIDTH /25;
						int destinationY = rand() % (MAP_HEIGHT+ MAP_WIDTH /50) - MAP_WIDTH / 25;
						_wwDummyClient->MoveMyCharacter_CS(dummySessionInfo, dummySession->mapID, destinationX, destinationY);
					}
				}

				probability = rand() % 10000;
				if (probability < _changeMapProbaility)
				{
					dummySession->bChangingMap = true;
					int beforeMapID = dummySession->mapID;
					if (beforeMapID == MAP_ID_FIELD1)
					{
						_wwDummyClient->ChangeMap_CS(dummySessionInfo, MAP_ID_FIELD1, MAP_ID_FIELD2);
					}
					else 
					{
						_wwDummyClient->ChangeMap_CS(dummySessionInfo, MAP_ID_FIELD2, MAP_ID_FIELD1);
					}
				}

			}
		}
	}
}

void WWDummyRoom::UpdateThreadFunc()
{
	srand(_randonSeed);
	while (1)
	{
		DWORD retWait = WaitForSingleObject(_hShutDownEvent, _updatePeriod);
		if (retWait == WAIT_OBJECT_0)
		{
			break;
		}

		ConnectWork();
		//棱贸府
		int queueLen = GetJobQueueLen();
		for (int i = 0; i < queueLen; i++)
		{
			Job* pJob = nullptr;
			PopJob(&pJob);
			pJob->Execute();
			Delete<Job>(pJob);
		}
		Update();
	}

}

void WWDummyRoom::GetDummyOption()
{
	std::wifstream fin; 
	fin.imbue(std::locale("kor"));
	fin.open("ChatList.txt");
	if (fin.is_open())
	{
		WString wLine;
		while (std::getline(fin, wLine))
		{
			_dummyChats.push_back(wLine);
		}

	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL,"None ChatList.txt");
		DebugBreak();
	}
	//dummy  可记 汲沥
	std::cout << "dummyCnt :";
	std::cin >> _dummyCnt;

	std::cout << "updatePeriod :";
	std::cin >> _updatePeriod;

	std::cout << "doingContentProbability :";
	std::cin >> _doingContentProbability;

	std::cout << "changeMapProbaility :";
	std::cin >> _changeMapProbaility;

	std::cout << "startDummyID: ";
	std::cin >> _startDummyID;

	std::cout << "randonSeed : ";
	std::cin >> _randonSeed;

	
	std::cout << "disconnectProbability : ";
	std::cin >> _disconnectProbability;
}

int WWDummyRoom::GetPlayerCnt()
{
    return _dummySessionMap.size();
}

void WWDummyRoom::ConnectWork()
{
	int connectCnt = 0;
	connectCnt = _dummyCnt - _dummySessionMap.size();
	for (int i = 0; i < connectCnt; i++)
	{
		if (_wwDummyClient->Connect() == false)
		{
			_connectFailCnt++;
		} 
		Sleep(0);
	}
}

WWDummyRoom::WWDummyRoom(WWDummyClient* wwDummyClient)
{
	GetDummyOption();
	_wwDummyClient = wwDummyClient;
	_hShutDownEvent = CreateEvent(NULL, TRUE, false, NULL);
	_updateThread = new std::jthread(&WWDummyRoom::UpdateThreadFunc, this);
}

WWDummyRoom::~WWDummyRoom()
{
	SetEvent(_hShutDownEvent);
	_updateThread->join();
	delete _updateThread;

	CloseHandle(_hShutDownEvent);
}

void WWDummyRoom::Enter(SessionInfo sessionInfo)
{
	_dummySessionMap[sessionInfo.id] = new WWDummySession;
}

void WWDummyRoom::Leave(SessionInfo sessionInfo)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->bSelfDisconnect == false)
		{
			_disconnectCnt++;
		}
		delete iterDummy->second;
		_dummySessionMap.erase(iterDummy);
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "Leave Room dummy not exist error\n");
	}
}

void WWDummyRoom::EnterGameSC(SessionInfo sessionInfo, short enterGameResult, LONG64 playerID)
{
	if (enterGameResult == ENTER_GAME_SUCCESS)
	{

		auto iterDummy = _dummySessionMap.find(sessionInfo.id);
		if (iterDummy != _dummySessionMap.end())
		{
			iterDummy->second->sessionType = SessionType::PLAYER;
			iterDummy->second->playerID = playerID;
		}
		else
		{
			Log::LogOnFile(Log::SYSTEM_LEVEL, "EnterGameSC not exist error\n");
			_wwDummyClient->Disconnect(sessionInfo);
		}
	}
	else if (enterGameResult == NAME_DUPLICATION)
	{
		_wwDummyClient->Disconnect(sessionInfo);
	}
	else 
	{
		_enterFailCnt++;
	}
}

void WWDummyRoom::CreateMyCharacterSC(SessionInfo sessionInfo, short mapID)
{

	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInCreatMyCharacter++;
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "CreateMyCharacterSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::CreateOtherCharacterSC(SessionInfo sessionInfo, short mapID, LONG64 playerID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInCreatOhterCharacter++;
		}
		else
		{
			auto returnInsert= iterDummy->second->otherPlayerIDs.insert(playerID);
			if (returnInsert.second == false)
			{
				_creatAleadyExistOhterCharacter++;
			}
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "CreateOtherCharacterSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::DeleteCharacterSC(SessionInfo sessionInfo, short mapID, LONG64 playerID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInDeleteCharacter++;
		}
		else
		{
			int returnErase = iterDummy->second->otherPlayerIDs.erase(playerID);
			if (returnErase != 1)
			{
				_deleteNoneExistCharacter++;
			}
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "DeleteCharacter_SC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::ChangeMapSC(SessionInfo sessionInfo, short beforeMapID, short afterMapID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != beforeMapID)
		{
			_mapIdErrorInChangeMap++;
		}
		else
		{
			iterDummy->second->bChangingMap = false;
			iterDummy->second->otherPlayerIDs.clear();
			iterDummy->second->mapID = afterMapID;
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "ChangeMapSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::SendChatMessageSC(SessionInfo sessionInfo, short mapID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInSendChatMessage++;
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "SendChatMessageSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::MoveMyCharacterSC(SessionInfo sessionInfo, short mapID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInMoveMyCharacter++;
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "MoveMyCharacterSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::MoveOtherCharacterSC(SessionInfo sessionInfo, short mapID)
{
	auto iterDummy = _dummySessionMap.find(sessionInfo.id);
	if (iterDummy != _dummySessionMap.end())
	{
		if (iterDummy->second->mapID != mapID)
		{
			_mapIdErrorInMoveOtherCharacter++;
		}
	}
	else
	{
		Log::LogOnFile(Log::SYSTEM_LEVEL, "MoveOtherCharacterSC not exist error\n");
		_wwDummyClient->Disconnect(sessionInfo);
	}
}

void WWDummyRoom::PrintRoomStatus()
{

	std::cout << std::format(R"(
-------------------------------------
	SessionCnt : {}
	connectFailCnt : {}
	disconnectCnt : {}
	enterFailCnt : {}
	mapIdErrorInCreatMyCharacter : {}
	mapIdErrorInCreatOhterCharacter : {}
	creatAleadyExistOhterCharacter : {}
	mapIdErrorInDeleteCharacter : {}
	deleteNoneExistCharacter : {}
	mapIdErrorInChangeMap :{} 
	mapIdErrorInSendChatMessage :{}
	mapIdErrorInMoveMyCharacter : {}
	mapIdErrorInMoveOtherCharacter :{}
)",
_dummySessionMap.size(),
_connectFailCnt,
_disconnectCnt,
_enterFailCnt,
_mapIdErrorInCreatMyCharacter,
_mapIdErrorInCreatOhterCharacter,
_creatAleadyExistOhterCharacter,
_mapIdErrorInDeleteCharacter,
_deleteNoneExistCharacter,
_mapIdErrorInChangeMap,
_mapIdErrorInSendChatMessage,
_mapIdErrorInMoveMyCharacter,
_mapIdErrorInMoveOtherCharacter);
}

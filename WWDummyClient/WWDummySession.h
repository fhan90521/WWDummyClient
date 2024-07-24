#pragma once
#include "WWEnum.h"
#include "MyStlContainer.h"
#include "MyWindow.h"
enum class SessionType
{
	GUEST,
	PLAYER
};
struct WWDummySession
{
	SessionType sessionType= SessionType::GUEST;
	LONG64 playerID;
	short mapID=MAP_ID_LOBBY;
	bool bChangingMap = false;
	bool bSelfDisconnect = false;
	Set<LONG64> otherPlayerIDs;
};
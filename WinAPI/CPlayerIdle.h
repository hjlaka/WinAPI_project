#pragma once
#include "CStatePlayer.h"
class CPlayerIdle : public CStatePlayer
{

public:
	CPlayerIdle();
	virtual ~CPlayerIdle();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player) {};
};


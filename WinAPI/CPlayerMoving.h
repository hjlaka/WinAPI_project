#pragma once
#include "CStatePlayer.h"
class CPlayerMoving : public CStatePlayer
{
public:
	CPlayerMoving();
	virtual ~CPlayerMoving();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


#pragma once
#include "CStatePlayer.h"
class CPlayerDashing : public CStatePlayer
{
public:
	CPlayerDashing();
	virtual ~CPlayerDashing();

public:
	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player) {};
	virtual void Enter(CPlayer* player) {};
	virtual void Exit(CPlayer* player) {};
};


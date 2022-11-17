#pragma once
#include "CStatePlayer.h"
class CPlayerFalling : public CStatePlayer
{
public:
	CPlayerFalling();
	virtual ~CPlayerFalling();

public:
	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


#pragma once
#include "CStatePlayer.h"
class CPlayerAttackB : public CStatePlayer
{
public:
	CPlayerAttackB();
	virtual ~CPlayerAttackB();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


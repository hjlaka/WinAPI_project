#pragma once
#include "CStatePlayer.h"
class CPlayerAttacking : public CStatePlayer
{
public:
	CPlayerAttacking();
	virtual ~CPlayerAttacking();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


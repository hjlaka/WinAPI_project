#pragma once
#include "CStatePlayer.h"
class CPlayerAttackA : public CStatePlayer
{
public:
	CPlayerAttackA();
	virtual ~CPlayerAttackA();

public:

	virtual CStatePlayer* HandleInput(CPlayer* pPlayer);
	virtual void Update(CPlayer* pPlayer);
	virtual void Enter(CPlayer* pPlayer);
	virtual void Exit(CPlayer* pPlayer);
};


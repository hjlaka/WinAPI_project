#pragma once
#include "CStatePlayer.h"

class CPlayerJumpAttack : public CStatePlayer
{
public:
	CPlayerJumpAttack();
	virtual ~CPlayerJumpAttack();

public:
	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


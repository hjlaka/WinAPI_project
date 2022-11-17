#pragma once
#include "CStatePlayer.h"
class CPlayerJumping : public CStatePlayer
{
public:
	CPlayerJumping();
	virtual ~CPlayerJumping();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


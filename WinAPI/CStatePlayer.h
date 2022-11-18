#pragma once
#include "CPlayer.h"
#include "CRigidBody.h"


class CPlayer;


class CStatePlayer
{
	friend CPlayer;

public:
	CStatePlayer();
	virtual ~CStatePlayer();

protected:
	CStatePlayer* ActionFromIdle(CPlayer* pPlayer);

public:
	virtual CStatePlayer* HandleInput(CPlayer* pPlayer) { return nullptr; };
	virtual void Update(CPlayer* pPlayer) {};
	virtual void Enter(CPlayer* pPlayer) {};
	virtual void Exit(CPlayer* pPlayer) {};
};


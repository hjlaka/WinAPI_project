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


public:
	virtual CStatePlayer* HandleInput(CPlayer* player) { return nullptr; };
	virtual void Update(CPlayer* player) {};
	virtual void Enter(CPlayer* player) {};
	virtual void Exit(CPlayer* player) {};
};


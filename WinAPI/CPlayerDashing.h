#pragma once
#include "CStatePlayer.h"
class CPlayerDashing : public CStatePlayer
{
public:
	CPlayerDashing();
	virtual ~CPlayerDashing();

public:
	//static CStatePlayer* Instance();

	virtual CStatePlayer* HandleInput(CPlayer* pPlayer);
	virtual void Update(CPlayer* pPlayer);
	virtual void Enter(CPlayer* pPlayer);
	virtual void Exit(CPlayer* pPlayer);
};


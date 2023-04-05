#pragma once
#include "CStatePlayer.h"
class CPlayerDie : public CStatePlayer
{
public:
	CPlayerDie();
	virtual ~CPlayerDie();

private:
	float m_fPlayTime;

public:
	virtual CStatePlayer* HandleInput(CPlayer* pPlayer);
	virtual void Update(CPlayer* pPlayer);
	virtual void Enter(CPlayer* pPlayer);
	virtual void Exit(CPlayer* pPlayer);
};


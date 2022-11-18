#pragma once
#include "CStatePlayer.h"
class CPlayerSkillS : public CStatePlayer
{
public:
	CPlayerSkillS();
	virtual ~CPlayerSkillS();

private:
	float m_fSkillSClock;

public:

	virtual CStatePlayer* HandleInput(CPlayer* pPlayer);
	virtual void Update(CPlayer* pPlayer);
	virtual void Enter(CPlayer* pPlayer);
	virtual void Exit(CPlayer* pPlayer);
};


#pragma once
#include "CStatePlayer.h"

class CPlayerSkillA : public CStatePlayer
{
public:
	CPlayerSkillA();
	virtual ~CPlayerSkillA();

public:
	virtual CStatePlayer* HandleInput(CPlayer* player);
	virtual void Update(CPlayer* player);
	virtual void Enter(CPlayer* player);
	virtual void Exit(CPlayer* player);
};


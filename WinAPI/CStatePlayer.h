#pragma once
#include "CComponent.h"
class CPlayer;
class CPlayerMoving;
class CPlayerJumping;
class CPlayerDashing;
class CPlayerAttacking;

class CStatePlayer : public CComponent
{
public:
	CStatePlayer();
	virtual ~CStatePlayer();

protected:
	static CPlayerMoving* moving;
	static CPlayerJumping* jumping;
	static CPlayerDashing* dashing;
	static CPlayerAttacking* attacking;





public:
	virtual CStatePlayer* HandleInput(CPlayer* player) { return this; };
	virtual void Update(CPlayer* player) {};
	virtual void Enter(CPlayer* player) {};
	virtual void Exit(CPlayer* player) {};
};


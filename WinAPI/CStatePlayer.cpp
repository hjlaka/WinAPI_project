#include "framework.h"
#include "CStatePlayer.h"

#include "CPlayerIdle.h"
#include "CPlayerAttackA.h"
#include "CPlayerDashing.h"
#include "CPlayerJumping.h"
#include "CPlayerMoving.h"
#include "CPlayerSkillA.h"
#include "CPlayerJumpAttack.h"
#include "CPlayerFalling.h"


CStatePlayer::CStatePlayer()
{

}

CStatePlayer::~CStatePlayer()
{
}

CStatePlayer* CStatePlayer::ActionFromIdle(CPlayer* pPlayer)
{
	CPlayerIdle* idle = new CPlayerIdle;
	CStatePlayer* next = idle->HandleInput(pPlayer);
	if (next == nullptr)
		return idle;
	else
	{
		delete idle;
		return next;
	}
}



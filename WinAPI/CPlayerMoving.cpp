#include "framework.h"
#include "CPlayerMoving.h"
#include "CPlayerIdle.h"
#include "CPlayerJumping.h"
#include "CPlayerDashing.h"
#include "CPlayerAttackA.h"
#include "CPlayerSkillA.h"
#include "CPlayerSkillS.h"

CPlayerMoving::CPlayerMoving()
{
}

CPlayerMoving::~CPlayerMoving()
{
}



CStatePlayer* CPlayerMoving::HandleInput(CPlayer* pPlayer)
{
	// 키 업일때 해제

	if (pPlayer->m_vecMoveDir.x < 0 && BUTTONUP(VK_LEFT))
	{
		return new CPlayerIdle;
	}
	else if (pPlayer->m_vecMoveDir.x > 0 && BUTTONUP(VK_RIGHT))
	{
		return new CPlayerIdle;
	}

	// 공격
	if (BUTTONDOWN('X'))
	{
		return new CPlayerAttackA;
	}

	// 점프
	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
	{
		return new CPlayerJumping;
	}

	// 대쉬
	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)
	{
		return new CPlayerDashing;
	}

	// 스킬
	if (BUTTONDOWN('A') && pPlayer->m_skillA->state == SKILL_STATE::READY)
	{
		return new CPlayerSkillA;
	}
	if (BUTTONDOWN('S') && pPlayer->m_skillS->state == SKILL_STATE::READY)
	{
		return new CPlayerSkillS;
	}

	return nullptr;
}

void CPlayerMoving::Update(CPlayer* pPlayer)
{
	//pPlayer->m_pRigid->SetVelocityX(pPlayer->m_vecMoveDir.x * pPlayer->m_fSpeed);
}

void CPlayerMoving::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::MOVE;
	pPlayer->m_bIsCanMove = true;
}

void CPlayerMoving::Exit(CPlayer* pPlayer)
{
	pPlayer->m_pRigid->SetVelocityX(0);
}


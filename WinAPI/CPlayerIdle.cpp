#include "framework.h"
#include "CPlayerIdle.h"
#include "CPlayerMoving.h"
#include "CPlayerJumping.h"
#include "CPlayerDashing.h"
#include "CPlayerAttackA.h"
#include "CPlayerFalling.h"
#include "CPlayerSkillA.h"
#include "CPlayerSkillS.h"






CPlayerIdle::CPlayerIdle()
{
}

CPlayerIdle::~CPlayerIdle()
{
}


CStatePlayer* CPlayerIdle::HandleInput(CPlayer* pPlayer)
{
	// 방향 전환

	if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecMoveDir.x = -1;

	}
	else if (BUTTONSTAY(VK_RIGHT))
	{

		pPlayer->m_vecMoveDir.x = +1;
	}
	else
	{
		pPlayer->m_vecMoveDir.x = 0;
	}


	// 떨어짐

	if (pPlayer->m_pRigid->GetGroundCount() == 0 && pPlayer->m_pRigid->GetGravitySpeed() >= 0)
	{
		return new CPlayerFalling;
	}


	Logger::Debug(L"아이들 핸들인풋 진입");
    // 이동
	if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecMoveDir.x = -1;
		return new CPlayerMoving;
	}
	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecMoveDir.x = 1;
		return new CPlayerMoving;
	}
	else
	{
		pPlayer->m_vecMoveDir.x = 0;
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

	// 공격
	if (BUTTONDOWN('X'))
	{
		return new CPlayerAttackA;
	}

	// 스킬
	if (BUTTONDOWN('A') && pPlayer->m_skillA != nullptr && pPlayer->m_skillA->state == SKILL_STATE::READY)
	{
		return new CPlayerSkillA;
	}
	if (BUTTONDOWN('S') && pPlayer->m_skillS != nullptr && pPlayer->m_skillS->state == SKILL_STATE::READY)
	{
		return new CPlayerSkillS;
	}




    return nullptr;
}

void CPlayerIdle::Update(CPlayer* pPlayer)
{
}

void CPlayerIdle::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::IDLE;
	pPlayer->m_bIsCanMove = true;
}

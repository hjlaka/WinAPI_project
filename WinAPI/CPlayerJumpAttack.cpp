#include "framework.h"
#include "CPlayerJumpAttack.h"
#include "CPlayerIdle.h"
#include "CPlayerDashing.h"
#include "CPlayerJumping.h"

CPlayerJumpAttack::CPlayerJumpAttack()
{
}

CPlayerJumpAttack::~CPlayerJumpAttack()
{
}

CStatePlayer* CPlayerJumpAttack::HandleInput(CPlayer* pPlayer)
{
	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)		// 대쉬를 입력 받으면 행동을 캔슬한다.
	{
		return new CPlayerDashing;
	}

	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)		// 점프를 입력 받으면 행동을 캔슬한다.
		return new CPlayerJumping;

	if (pPlayer->m_fAttackJTime <= 0)
	{
		return ActionFromIdle(pPlayer);

	}
    return nullptr;
}

void CPlayerJumpAttack::Update(CPlayer* pPlayer)
{
	pPlayer->m_fAttackJTime -= DT;
}

void CPlayerJumpAttack::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::JUMPATTACK;
	pPlayer->JumpAttack();
	pPlayer->m_fAttackJTime = 0.5f;
}

void CPlayerJumpAttack::Exit(CPlayer* player)
{
}

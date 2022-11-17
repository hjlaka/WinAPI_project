#include "framework.h"
#include "CPlayerJumpAttack.h"

CPlayerJumpAttack::CPlayerJumpAttack()
{
}

CPlayerJumpAttack::~CPlayerJumpAttack()
{
}

CStatePlayer* CPlayerJumpAttack::HandleInput(CPlayer* player)
{
    return nullptr;
}

void CPlayerJumpAttack::Update(CPlayer* player)
{
	pPlayer->m_fAttackJTime -= DT;
}

void CPlayerJumpAttack::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::JUMPATTACK;
	pPlayer->m_bIsAttack = true;
	pPlayer->Attack();
	pPlayer->m_fAttackJTime = 0.5f;
}

void CPlayerJumpAttack::Exit(CPlayer* player)
{
}

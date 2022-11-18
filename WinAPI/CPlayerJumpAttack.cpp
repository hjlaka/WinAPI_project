#include "framework.h"
#include "CPlayerJumpAttack.h"
#include "CPlayerIdle.h"

CPlayerJumpAttack::CPlayerJumpAttack()
{
}

CPlayerJumpAttack::~CPlayerJumpAttack()
{
}

CStatePlayer* CPlayerJumpAttack::HandleInput(CPlayer* pPlayer)
{
	if (pPlayer->m_fAttackJTime <= 0)
	{
		return ActionFromIdle(pPlayer);
		/*CPlayerIdle* idle = new CPlayerIdle;
		CStatePlayer* next = idle->HandleInput(pPlayer);
		if (next == nullptr)
			return idle;
		else
		{
			delete idle;
			return next;
		}*/
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
	//pPlayer->m_bIsAttack = true;
	pPlayer->Attack();
	pPlayer->m_fAttackJTime = 0.5f;
}

void CPlayerJumpAttack::Exit(CPlayer* player)
{
}

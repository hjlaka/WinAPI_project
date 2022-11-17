#include "framework.h"
#include "CPlayerAttacking.h"
#include "CPlayerIdle.h"


CPlayerAttacking::CPlayerAttacking()
{
}

CPlayerAttacking::~CPlayerAttacking()
{
}


CStatePlayer* CPlayerAttacking::HandleInput(CPlayer* pPlayer)
{
	// 시간 지나면 돌아감
	if (pPlayer->m_iAttackCount == 0 && pPlayer->m_fAttackATime <= 0)
	{
		if (pPlayer->m_bAttackContinue &&
			pPlayer->m_pRigid->GetGravitySpeed() <= 0)
			return new CPlayerAttacking;
		else
			return new CPlayerIdle;
	}
	else if(pPlayer->m_iAttackCount == 1 && pPlayer->m_fAttackBTime <= 0)
	{
		if (pPlayer->m_bAttackContinue && 
			pPlayer->m_pRigid->GetGravitySpeed() <= 0)
			return new CPlayerAttacking;
		else
			return new CPlayerIdle;
	}

	// 공격 시간이 끝났고 후속 공격 조작이 또 있으면 다음 공격으로 넘어감
	// 연계 공격 타이밍 내에 후속 공격 입력이 있다면?

	// 연계 공격이 되는데 떨어지고 있는 중이라면


	return nullptr;
}

void CPlayerAttacking::Update(CPlayer* pPlayer)
{
	
	if (pPlayer->m_iAttackCount == 0)
	{
		pPlayer->m_fAttackATime -= DT;
	}
	else if (pPlayer->m_iAttackCount == 1)
	{
		pPlayer->m_fAttackBTime -= DT;
	}

	if (BUTTONDOWN('X') && !pPlayer->m_bAttackContinue)
	{
		pPlayer->m_bAttackContinue = true;
	}

}

void CPlayerAttacking::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::ATTACK;
	pPlayer->m_bIsCanMove = false;
	pPlayer->m_bAttackContinue = false;

	// 이미 올려치기가 진행되었다면 공격 모션 카운트 초기화
	pPlayer->m_iAttackCount++;

	if (pPlayer->m_iAttackCount >= 2)
		pPlayer->m_iAttackCount = 0;



	if (pPlayer->m_iAttackCount == 0)
	{
		// 첫번째 내려치기 공격
		// 공격 충돌체 만들기
		pPlayer->Attack();
		pPlayer->m_fAttackATime = 0.5f;
		
	}
	else if (pPlayer->m_iAttackCount == 1)
	{
		// 두번째 올려치기 공격
		pPlayer->Attack();
		pPlayer->m_fAttackBTime = 0.4f;
	}
	else
	{
		assert(0 && L"AttackCount is More than 2");
	}

	// 공격 진입 시점에 방향키가 눌리고 있다면 해당 방향으로 이동하며 공격한다. (한번만 누른 경우는 안 포함?)
	//if (BUTTONSTAY(VK_RIGHT))
	//{
	//	pPlayer->m_pRigid->PowerToX(450.f);
	//	pPlayer->m_vecMoveDir.x = +1;
	//}
	//else if (BUTTONSTAY(VK_LEFT))
	//{
	//	pPlayer->m_pRigid->PowerToX(-450.f);
	//	pPlayer->m_vecMoveDir.x = -1;
	//}
}

void CPlayerAttacking::Exit(CPlayer* pPlayer)
{
	if (pPlayer->m_iAttackCount == 0)
	{
		pPlayer->m_fAttackATime = 0;
	}
	else if (pPlayer->m_iAttackCount == 1)
	{
		pPlayer->m_fAttackBTime = 0;
	}
}

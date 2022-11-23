#include "framework.h"
#include "CPlayerAttackB.h"
#include "CPlayerIdle.h"
#include "CPlayerAttackA.h"
#include "CPlayerDashing.h"


CPlayerAttackB::CPlayerAttackB()
{
}

CPlayerAttackB::~CPlayerAttackB()
{
}


CStatePlayer* CPlayerAttackB::HandleInput(CPlayer* pPlayer)
{
	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)		// 대쉬를 입력 받으면 행동을 캔슬한다.
	{
		return new CPlayerDashing;
	}

	if (BUTTONDOWN('X'))								// 공격진입으로 연결되는 버튼 눌리기 이후에 버튼이 또 눌리는지 확인해야 한다.
	{
		pPlayer->m_bAttackContinue = true;
	}

	// 시간 지나면 돌아감
	if(pPlayer->m_fAttackBTime <= 0)
	{
		Logger::Debug(L"공격2");
		if (pPlayer->m_bAttackContinue && 
			pPlayer->m_pRigid->GetGravitySpeed() <= 0)
			return new CPlayerAttackA;
		else
			return ActionFromIdle(pPlayer);
	}

	// 공격 시간이 끝났고 후속 공격 조작이 또 있으면 다음 공격으로 넘어감
	// 연계 공격 타이밍 내에 후속 공격 입력이 있다면?

	// 연계 공격이 되는데 떨어지고 있는 중이라면


	return nullptr;
}

void CPlayerAttackB::Update(CPlayer* pPlayer)
{
	if (pPlayer->m_fAttackBTime < 0.4f)		// 첫 프레임 외에 적용
	{
		pPlayer->m_pRigid->SetVelocityX(0);
	}
	
	pPlayer->m_fAttackBTime -= DT;


	

}

void CPlayerAttackB::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::ATTACKB;
	pPlayer->m_bIsCanMove = false;
	pPlayer->m_bAttackContinue = false;

	pPlayer->Attack(Vector(pPlayer->m_vecLookDir.x * 25, 10));
	pPlayer->m_fAttackBTime = 0.4f;


	 //공격 진입 시점에 방향키가 눌리고 있다면 해당 방향으로 이동하며 공격한다. (한번만 누른 경우는 안 포함?)
	if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_pRigid->Power(Vector(3000.f, 0));
		pPlayer->m_vecMoveDir.x = +1;
	}
	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_pRigid->Power(Vector(-3000.f, 0));
		pPlayer->m_vecMoveDir.x = -1;
	}


}

void CPlayerAttackB::Exit(CPlayer* pPlayer)
{
	pPlayer->m_pRigid->SetVelocityX(0.f);
	pPlayer->m_bAttackContinue = false;
	pPlayer->m_fAttackBTime = 0;
}

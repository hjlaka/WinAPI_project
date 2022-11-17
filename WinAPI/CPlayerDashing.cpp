#include "framework.h"
#include "CPlayerDashing.h"
#include "CPlayerIdle.h"



CPlayerDashing::CPlayerDashing()
{
}

CPlayerDashing::~CPlayerDashing()
{
}


CStatePlayer* CPlayerDashing::HandleInput(CPlayer* pPlayer)
{

	// 대쉬 중에는 다른 인풋을 받지 않는다.

	// 대쉬 시간이 끝나면 대쉬는 종료된다.

	if (pPlayer->m_fDashClock <= 0)
	{
		return new CPlayerIdle;
	}

	return nullptr;

}

void CPlayerDashing::Update(CPlayer* pPlayer)
{
	if (pPlayer->m_fDashClock > 0)
	{
		pPlayer->m_fDashClock -= DT;
		
		pPlayer->m_pRigid->SetGravitySpeed(0);
		
	}
}

void CPlayerDashing::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::DASH;
	pPlayer->m_bIsCanMove = false;

	//pPlayer->m_bIsDash = true;
	pPlayer->m_fDashClock = 0.3f;
	pPlayer->m_pRigid->PowerToX(pPlayer->m_vecLookDir.x * 500.f);
}

void CPlayerDashing::Exit(CPlayer* pPlayer)
{
	//pPlayer->m_bIsDash = false;
}

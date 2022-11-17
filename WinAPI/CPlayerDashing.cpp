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

	// �뽬 �߿��� �ٸ� ��ǲ�� ���� �ʴ´�.

	// �뽬 �ð��� ������ �뽬�� ����ȴ�.

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

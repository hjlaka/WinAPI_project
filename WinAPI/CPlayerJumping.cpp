#include "framework.h"
#include "CPlayerJumping.h"
#include "CPlayerIdle.h"
#include "CPlayerDashing.h"

#include "CSmoke.h"

CPlayerJumping::CPlayerJumping()
{
}

CPlayerJumping::~CPlayerJumping()
{
}

//CStatePlayer* CPlayerJumping::Instance()
//{
//	static CPlayerJumping instance;
//	return &instance;
//}

CStatePlayer* CPlayerJumping::HandleInput(CPlayer* pPlayer)
{

	// ���� ������ �� �� ���¿��� �ѹ� �� ����Ű�� ������ (�ٽ� ���� ���·� �̵�?)

	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
		return new CPlayerJumping;

	// ���� ���¿��� ����Ű�� ������ ��������



	// ���� ������...
	if (pPlayer->m_pRigid->GetGravitySpeed() == 0)
		return new CPlayerIdle;



	// �뽬
	if (BUTTONDOWN('Z'))
	{
		return new CPlayerDashing;
	}



	return nullptr;

}

void CPlayerJumping::Update(CPlayer* pPlayer)
{

	

	

	
	
}

void CPlayerJumping::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::JUMP;
	pPlayer->m_bIsCanMove = true;


	pPlayer->m_bOverPeak = false;
	pPlayer->m_pRigid->PowerToY(-550.f);
	pPlayer->m_iJumpCount++;

	Logger::Debug(L"Jump!");
	if (pPlayer->m_iJumpCount == 2)
	{
		CSmoke* pSmoke = new CSmoke();
		pSmoke->SetPos(pPlayer->m_vecPos.x, pPlayer->m_vecPos.y);
		ADDOBJECT(pSmoke);
	}
}

void CPlayerJumping::Exit(CPlayer* player)
{
}

#include "framework.h"
#include "CPlayerJumping.h"
#include "CPlayerIdle.h"
#include "CPlayerDashing.h"
#include "CPlayerFalling.h"
#include "CPlayerJumpAttack.h"
#include "CPlayerSkillA.h"
#include "CPlayerSkillS.h"

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
	// �������� �ӵ��� ��ȯ
	if (pPlayer->m_pRigid->GetGravitySpeed() > 0)
	{
		return new CPlayerFalling;
	}

	// ���� ������ �� �� ���¿��� �ѹ� �� ����Ű�� ������ (�ٽ� ���� ���·� �̵�?)

	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
		return new CPlayerJumping;

	// ���� ���¿��� ����Ű�� ������ ��������
	if (BUTTONDOWN('X'))
		return new CPlayerJumpAttack;


	// ���� ������...
	if (pPlayer->m_pRigid->GetGravitySpeed() == 0)
		return new CPlayerIdle;



	// �뽬
	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)
	{
		return new CPlayerDashing;
	}

	// ��ų
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

void CPlayerJumping::Update(CPlayer* pPlayer)
{

	

	

	
	
}

void CPlayerJumping::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::JUMP;
	pPlayer->m_bIsCanMove = true;


	pPlayer->m_bOverPeak = false;
	pPlayer->m_pRigid->PowerToY(pPlayer->m_fJumpPower);
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

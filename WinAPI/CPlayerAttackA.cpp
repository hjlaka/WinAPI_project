#include "framework.h"
#include "CPlayerAttackA.h"
#include "CPlayerIdle.h"
#include "CPlayerAttackB.h"
#include "CPlayerDashing.h"

CPlayerAttackA::CPlayerAttackA()
{
}

CPlayerAttackA::~CPlayerAttackA()
{
}

CStatePlayer* CPlayerAttackA::HandleInput(CPlayer* pPlayer)
{


	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)		// �뽬�� �Է� ������ �ൿ�� ĵ���Ѵ�.
	{
		return new CPlayerDashing;
	}

	if (BUTTONDOWN('X'))								// ������������ ����Ǵ� ��ư ������ ���Ŀ� ��ư�� �� �������� Ȯ���ؾ� �Ѵ�.
	{
		pPlayer->m_bAttackContinue = true;
	}

	if (pPlayer->m_fAttackATime <= 0)
	{
		Logger::Debug(L"����1");
		if (pPlayer->m_bAttackContinue &&
			pPlayer->m_pRigid->GetGravitySpeed() <= 0)
			return new CPlayerAttackB;
		else
			return ActionFromIdle(pPlayer);
	}

    return nullptr;
}

void CPlayerAttackA::Update(CPlayer* pPlayer)
{
	
	if (pPlayer->m_fAttackATime < 0.5f)		// ù ������ �ܿ� ����
	{
		pPlayer->m_pRigid->SetVelocityX(0);
	}

	pPlayer->m_fAttackATime -= DT;

	
}

void CPlayerAttackA::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::ATTACKA;
	pPlayer->m_bIsCanMove = false;
	pPlayer->m_bAttackContinue = false;

	pPlayer->Attack(Vector(pPlayer->m_vecLookDir.x * 30, -10));
	pPlayer->m_fAttackATime = 0.5f;

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

void CPlayerAttackA::Exit(CPlayer* pPlayer)
{
	pPlayer->m_pRigid->SetVelocityX(0.f);
	pPlayer->m_bAttackContinue = false;
	pPlayer->m_fAttackATime = 0;
}

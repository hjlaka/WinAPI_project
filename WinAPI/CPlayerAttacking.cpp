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
	// �ð� ������ ���ư�
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

	// ���� �ð��� ������ �ļ� ���� ������ �� ������ ���� �������� �Ѿ
	// ���� ���� Ÿ�̹� ���� �ļ� ���� �Է��� �ִٸ�?

	// ���� ������ �Ǵµ� �������� �ִ� ���̶��


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

	// �̹� �÷�ġ�Ⱑ ����Ǿ��ٸ� ���� ��� ī��Ʈ �ʱ�ȭ
	pPlayer->m_iAttackCount++;

	if (pPlayer->m_iAttackCount >= 2)
		pPlayer->m_iAttackCount = 0;



	if (pPlayer->m_iAttackCount == 0)
	{
		// ù��° ����ġ�� ����
		// ���� �浹ü �����
		pPlayer->Attack();
		pPlayer->m_fAttackATime = 0.5f;
		
	}
	else if (pPlayer->m_iAttackCount == 1)
	{
		// �ι�° �÷�ġ�� ����
		pPlayer->Attack();
		pPlayer->m_fAttackBTime = 0.4f;
	}
	else
	{
		assert(0 && L"AttackCount is More than 2");
	}

	// ���� ���� ������ ����Ű�� ������ �ִٸ� �ش� �������� �̵��ϸ� �����Ѵ�. (�ѹ��� ���� ���� �� ����?)
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

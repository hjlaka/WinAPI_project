#include "framework.h"
#include "CPlayerAttackB.h"
#include "CPlayerIdle.h"
#include "CPlayerAttackA.h"


CPlayerAttackB::CPlayerAttackB()
{
}

CPlayerAttackB::~CPlayerAttackB()
{
}


CStatePlayer* CPlayerAttackB::HandleInput(CPlayer* pPlayer)
{
	if (BUTTONDOWN('X'))								// ������������ ����Ǵ� ��ư ������ ���Ŀ� ��ư�� �� �������� Ȯ���ؾ� �Ѵ�.
	{
		pPlayer->m_bAttackContinue = true;
	}

	// �ð� ������ ���ư�
	if(pPlayer->m_fAttackBTime <= 0)
	{
		Logger::Debug(L"����2");
		if (pPlayer->m_bAttackContinue && 
			pPlayer->m_pRigid->GetGravitySpeed() <= 0)
			return new CPlayerAttackA;
		else
			return ActionFromIdle(pPlayer);
	}

	// ���� �ð��� ������ �ļ� ���� ������ �� ������ ���� �������� �Ѿ
	// ���� ���� Ÿ�̹� ���� �ļ� ���� �Է��� �ִٸ�?

	// ���� ������ �Ǵµ� �������� �ִ� ���̶��


	return nullptr;
}

void CPlayerAttackB::Update(CPlayer* pPlayer)
{
	
	
	pPlayer->m_fAttackBTime -= DT;


	

}

void CPlayerAttackB::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::ATTACKB;
	pPlayer->m_bIsCanMove = false;
	pPlayer->m_bAttackContinue = false;

	//pPlayer->Attack();
	pPlayer->m_fAttackBTime = 0.4f;


	 //���� ���� ������ ����Ű�� ������ �ִٸ� �ش� �������� �̵��ϸ� �����Ѵ�. (�ѹ��� ���� ���� �� ����?)
	if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_pRigid->PowerToX(50.f);
		pPlayer->m_vecMoveDir.x = +1;
	}
	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_pRigid->PowerToX(-50.f);
		pPlayer->m_vecMoveDir.x = -1;
	}


}

void CPlayerAttackB::Exit(CPlayer* pPlayer)
{
	pPlayer->m_pRigid->SetVelocityX(0.f);
	pPlayer->m_bAttackContinue = false;
	pPlayer->m_fAttackBTime = 0;
}
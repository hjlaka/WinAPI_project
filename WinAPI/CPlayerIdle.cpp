#include "framework.h"
#include "CPlayerIdle.h"
#include "CPlayerMoving.h"
#include "CPlayerJumping.h"
#include "CPlayerDashing.h"
#include "CPlayerAttacking.h"






CPlayerIdle::CPlayerIdle()
{
}

CPlayerIdle::~CPlayerIdle()
{
}

//CStatePlayer* CPlayerIdle::Instance()
//{
//	static CPlayerIdle instance;
//	return &instance;
//}

CStatePlayer* CPlayerIdle::HandleInput(CPlayer* pPlayer)
{
	Logger::Debug(L"���̵� �ڵ���ǲ ����");
    // �̵�
	if (BUTTONDOWN(VK_LEFT))
	{
		pPlayer->m_vecMoveDir.x = -1;
		return new CPlayerMoving;
	}
	else if (BUTTONDOWN(VK_RIGHT))
	{
		pPlayer->m_vecMoveDir.x = 1;
		return new CPlayerMoving;
	}
	else
	{
		pPlayer->m_vecMoveDir.x = 0;
	}

	// ����
	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
	{
		return new CPlayerJumping;
	}

	//// ������
	//if (pPlayer->m_pRigid->GetGravitySpeed() > 0)
	//{
	//	return pPlayer->fall;
	//}

	// �뽬
	if (BUTTONDOWN('Z'))
	{
		return new CPlayerDashing;
	}

	// ����
	if (BUTTONDOWN('X'))
	{
		return new CPlayerAttacking;
	}

	//// ��ų
	//if (BUTTONDOWN('A'))
	//{
	//	return pPlayer->skillA;
	//}




    return nullptr;
}

void CPlayerIdle::Update(CPlayer* pPlayer)
{
}

void CPlayerIdle::Enter(CPlayer* pPlayer)
{
	pPlayer->m_state = STATE::IDLE;
	pPlayer->m_bIsCanMove = true;
}

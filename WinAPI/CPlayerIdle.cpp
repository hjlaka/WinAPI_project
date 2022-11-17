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
	Logger::Debug(L"아이들 핸들인풋 진입");
    // 이동
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

	// 점프
	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
	{
		return new CPlayerJumping;
	}

	//// 떨어짐
	//if (pPlayer->m_pRigid->GetGravitySpeed() > 0)
	//{
	//	return pPlayer->fall;
	//}

	// 대쉬
	if (BUTTONDOWN('Z'))
	{
		return new CPlayerDashing;
	}

	// 공격
	if (BUTTONDOWN('X'))
	{
		return new CPlayerAttacking;
	}

	//// 스킬
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

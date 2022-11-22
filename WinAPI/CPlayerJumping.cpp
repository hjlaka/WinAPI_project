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
	// 떨어지는 속도로 전환
	if (pPlayer->m_pRigid->GetGravitySpeed() > 0)
	{
		return new CPlayerFalling;
	}

	// 더블 점프를 안 한 상태에서 한번 더 점프키를 누르면 (다시 점프 상태로 이동?)

	if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
		return new CPlayerJumping;

	// 점프 상태에서 공격키를 누르면 점프어택
	if (BUTTONDOWN('X'))
		return new CPlayerJumpAttack;


	// 땅에 닿으면...
	if (pPlayer->m_pRigid->GetGravitySpeed() == 0)
		return new CPlayerIdle;



	// 대쉬
	if (BUTTONDOWN('Z') && pPlayer->m_fDashCoolTime <= 0)
	{
		return new CPlayerDashing;
	}

	// 스킬
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

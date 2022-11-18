#include "framework.h"
#include "CPlayerFalling.h"
#include "CPlayerIdle.h"
#include "CPlayerJumping.h"
#include "CPlayerDashing.h"
#include "CPlayerJumpAttack.h"
#include "CPlayerSkillA.h"
#include "CPlayerSkillS.h"

CPlayerFalling::CPlayerFalling()
{
}

CPlayerFalling::~CPlayerFalling()
{
}

CStatePlayer* CPlayerFalling::HandleInput(CPlayer* pPlayer)
{
    


    // 바닥 착지
    if (pPlayer->m_pRigid->GetGroundCount() > 0)
    {
        return new CPlayerIdle;
    }
    // 점프
    if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
    {
        return new CPlayerJumping;
    }

    // 점프 공격
    if (BUTTONDOWN('X'))
        return new CPlayerJumpAttack;

    // 대쉬
    if (BUTTONDOWN('Z'))
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

void CPlayerFalling::Update(CPlayer* pPlayer)
{
    pPlayer->m_fFallTime += DT;
}

void CPlayerFalling::Enter(CPlayer* pPlayer)
{
    pPlayer->m_state = STATE::FALL;
    pPlayer->m_fFallTime = 0;
}

void CPlayerFalling::Exit(CPlayer* pPlayer)
{

}

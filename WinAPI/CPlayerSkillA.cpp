#include "framework.h"
#include "CPlayerSkillA.h"

CPlayerSkillA::CPlayerSkillA()
{
    m_fSkillAClock = 0;             // 내부에 변수를 두었다.
}

CPlayerSkillA::~CPlayerSkillA()
{
}

CStatePlayer* CPlayerSkillA::HandleInput(CPlayer* pPlayer)
{
    // 시간 지나면 상태 변화
    if (m_fSkillAClock <= 0)
        return ActionFromIdle(pPlayer);

    return nullptr;
}

void CPlayerSkillA::Update(CPlayer* pPlayer)
{
    m_fSkillAClock -= DT;
    pPlayer->m_pRigid->SetGravitySpeed(0);
    pPlayer->m_pRigid->SetVelocityX(0);
}

void CPlayerSkillA::Enter(CPlayer* pPlayer)
{
    pPlayer->m_state = STATE::SKILLA;
    m_fSkillAClock = pPlayer->m_skillA->fMotionTime;
    pPlayer->SkillA();
    pPlayer->m_bIsCanMove = false;
}

void CPlayerSkillA::Exit(CPlayer* pPlayer)
{
}

#include "framework.h"
#include "CPlayerSkillS.h"

CPlayerSkillS::CPlayerSkillS()
{
    m_fSkillSClock = 0;
}

CPlayerSkillS::~CPlayerSkillS()
{
}

CStatePlayer* CPlayerSkillS::HandleInput(CPlayer* pPlayer)
{
    // �ð� ������ ���� ��ȭ
    if (m_fSkillSClock <= 0)
        return ActionFromIdle(pPlayer);

    return nullptr;
}

void CPlayerSkillS::Update(CPlayer* pPlayer)
{
    m_fSkillSClock -= DT;
    pPlayer->m_pRigid->SetGravitySpeed(0);
    pPlayer->m_pRigid->SetVelocityX(0);
}

void CPlayerSkillS::Enter(CPlayer* pPlayer)
{
    pPlayer->m_state = STATE::SKILLS;
    m_fSkillSClock = pPlayer->m_skillS->fMotionTime;
    pPlayer->SkillS();
    pPlayer->m_bIsCanMove = false;
    pPlayer->SetName(L"���� ��");
}

void CPlayerSkillS::Exit(CPlayer* pPlayer)
{
    pPlayer->SetName(L"Player");
}

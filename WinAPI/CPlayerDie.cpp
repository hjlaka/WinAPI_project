#include "framework.h"
#include "CPlayerDie.h"

CPlayerDie::CPlayerDie()
{
}

CPlayerDie::~CPlayerDie()
{
}

CStatePlayer* CPlayerDie::HandleInput(CPlayer* pPlayer)
{
    return nullptr;
}

void CPlayerDie::Update(CPlayer* pPlayer)
{
    m_fPlayTime -= DT;
    if (m_fPlayTime <= 0)
        pPlayer->SetIsActive(false);
}

void CPlayerDie::Enter(CPlayer* pPlayer)
{
    m_fPlayTime = pPlayer->m_pAnimator->FindAnimation(L"Die")->GetFullTime();
    pPlayer->m_state = STATE::DIE;
    pPlayer->m_bIsCanMove = false;
}

void CPlayerDie::Exit(CPlayer* pPlayer)
{
}

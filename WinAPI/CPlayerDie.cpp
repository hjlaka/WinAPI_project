#include "framework.h"
#include "CPlayerDie.h"
#include "CPlayerIdle.h"

CPlayerDie::CPlayerDie()
{
}

CPlayerDie::~CPlayerDie()
{
}

CStatePlayer* CPlayerDie::HandleInput(CPlayer* pPlayer)
{
    if (m_fPlayTime <= -3.f)
    {
        pPlayer->SetCurHp(pPlayer->GetHp());
        return new CPlayerIdle;         // 임시 부활
    }
    return nullptr;
}

void CPlayerDie::Update(CPlayer* pPlayer)
{
    m_fPlayTime -= DT;
    
}

void CPlayerDie::Enter(CPlayer* pPlayer)
{
    m_fPlayTime = pPlayer->m_pAnimator->FindAnimation(L"Die")->GetFullTime();
    pPlayer->m_state = STATE::DIE;
    pPlayer->m_bIsCanMove = false;
    pPlayer->m_pRigid->SetVelocityX(0);
}

void CPlayerDie::Exit(CPlayer* pPlayer)
{
}

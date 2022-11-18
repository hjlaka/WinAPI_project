#include "framework.h"
#include "CPlayerFalling.h"
#include "CPlayerIdle.h"
#include "CPlayerJumping.h"
#include "CPlayerDashing.h"
#include "CPlayerJumpAttack.h"

CPlayerFalling::CPlayerFalling()
{
}

CPlayerFalling::~CPlayerFalling()
{
}

CStatePlayer* CPlayerFalling::HandleInput(CPlayer* pPlayer)
{
    // �ٴ� ����
    if (pPlayer->m_pRigid->GetGroundCount() > 0)
    {
        return new CPlayerIdle;
    }
    // ����
    if (BUTTONDOWN('C') && pPlayer->m_iJumpCount < 2)
    {
        return new CPlayerJumping;
    }

    // ���� ����
    if (BUTTONDOWN('X'))
        return new CPlayerJumpAttack;

    // �뽬
    if (BUTTONDOWN('Z'))
    {
        return new CPlayerDashing;
    }

    // ��ų

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

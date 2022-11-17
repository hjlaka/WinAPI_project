#include "framework.h"
#include "CPlayerSkillA.h"

CPlayerSkillA::CPlayerSkillA()
{
}

CPlayerSkillA::~CPlayerSkillA()
{
}

CStatePlayer* CPlayerSkillA::HandleInput(CPlayer* player)
{
    // 시간 지나면 상태 변화
    // 모션 타임을 어디서 가져오면 좋을까? 스킬 자료에 함께 저장?

    return nullptr;
}

void CPlayerSkillA::Update(CPlayer* player)
{
}

void CPlayerSkillA::Enter(CPlayer* pPlayer)
{
    pPlayer->SkillA();
}

void CPlayerSkillA::Exit(CPlayer* player)
{
}

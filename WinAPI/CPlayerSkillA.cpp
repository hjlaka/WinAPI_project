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
    // �ð� ������ ���� ��ȭ
    // ��� Ÿ���� ��� �������� ������? ��ų �ڷῡ �Բ� ����?

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

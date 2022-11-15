#include "framework.h"
#include "CSkulLittleBone.h"

#include "CShootedHead.h"

CSkulLittleBone::CSkulLittleBone()
{
}

CSkulLittleBone::~CSkulLittleBone()
{
}

bool CSkulLittleBone::GetHeadOn()
{
	return m_bHeadOn;
}

void CSkulLittleBone::SetHeadOn(bool headOn)
{
	m_bHeadOn = headOn;
}

void CSkulLittleBone::SkillSetUp()
{
	SkillInfo skillShootHead;
	skillShootHead.strName = L"�ΰ��� ��ô";
	skillShootHead.fCool = 6.f;
	skillShootHead.fCurCool = 0.f;
	skillShootHead.state = SKILL_STATE::READY;
	skillShootHead.strDescription = L"�ڽ��� �Ӹ��� ���� ������������ �����ϴ�. \n���� �Ӹ��� ȸ���ϸ� ��Ÿ���� �ʱ�ȭ�˴ϴ�.";

	SkillInfo skillHeadIsI;
	skillHeadIsI.strName = L"�Ӹ��� ��ü";
	skillHeadIsI.fCool = 3.f;
	skillHeadIsI.fCurCool = 0.f;
	skillHeadIsI.state = SKILL_STATE::READY;
	skillHeadIsI.strDescription = L"�Ӹ��� ���� ������ �� �Ӹ��� �̵��մϴ�.";

	m_skillA = skillShootHead;		// �� ����
	m_skillS = skillHeadIsI;
}

void CSkulLittleBone::SkillA()
{
	if (m_skillA.state == SKILL_STATE::READY)
	{
		CShootedHead* head = new CShootedHead;
		head->SetPos(GetPos());

		head->GetRigidBody()->PowerToX(m_vecLookDir.x * 400.f);
		head->SetOwner(this);
		ADDOBJECT(head);

		m_bHeadOn = false;
		m_skillA.UseSkill();
	}
	
	// ���� �Ŀ� ȸ��? SkillA�� ������ ������Ʈ�� ���¿� ���� ȸ��?		- ���߿� ��� ������ �Ǿ����� ã�Ⱑ ������?
	// �ƴϸ� ������ ���¸� ������Ʈ �� ��, ���ۿ� ���� ȸ��?
}

void CSkulLittleBone::SkillS()
{
}

//void CSkulLittleBone::SkillAction()
//{
//}

void CSkulLittleBone::Render()
{
	CPlayer::Render();
	RENDER->Text(L"�Ӹ� ����:" + to_wstring((int)m_bHeadOn), GetPos().x, GetPos().y + 100, GetPos().x + 100, GetPos().y + 200);
	RENDER->Text(L"��ųA��:" + to_wstring((int)m_skillA.fCurCool), GetPos().x, GetPos().y + 120, GetPos().x + 100, GetPos().y + 220);
}

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
	skillShootHead.strName = L"두개골 투척";
	skillShootHead.fCool = 6.f;
	skillShootHead.fCurCool = 0.f;
	skillShootHead.state = SKILL_STATE::READY;
	skillShootHead.strDescription = L"자신의 머리를 던져 마법데미지를 입힙니다. \n던진 머리를 회수하면 쿨타임이 초기화됩니다.";

	SkillInfo skillHeadIsI;
	skillHeadIsI.strName = L"머리가 본체";
	skillHeadIsI.fCool = 3.f;
	skillHeadIsI.fCurCool = 0.f;
	skillHeadIsI.state = SKILL_STATE::READY;
	skillHeadIsI.strDescription = L"머리가 없는 상태일 때 머리로 이동합니다.";

	m_skillA = skillShootHead;		// 값 복사
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
	
	// 몇초 후에 회복? SkillA로 생성된 오브젝트의 상태에 따라 회복?		- 나중에 어디서 변경이 되었는지 찾기가 어려울까?
	// 아니면 스컬의 상태를 업데이트 한 후, 조작에 따라 회복?
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
	RENDER->Text(L"머리 상태:" + to_wstring((int)m_bHeadOn), GetPos().x, GetPos().y + 100, GetPos().x + 100, GetPos().y + 200);
	RENDER->Text(L"스킬A쿨:" + to_wstring((int)m_skillA.fCurCool), GetPos().x, GetPos().y + 120, GetPos().x + 100, GetPos().y + 220);
}

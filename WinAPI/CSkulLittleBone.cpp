#include "framework.h"
#include "CSkulLittleBone.h"

#include "CShootedHead.h"

CSkulLittleBone::CSkulLittleBone()
{
	m_pHead = nullptr;
}

CSkulLittleBone::~CSkulLittleBone()
{
}

void CSkulLittleBone::Init()
{
	CPlayer::Init();
	m_pHead = new CShootedHead;
	m_pHead->SetOwner(this);
	m_pHead->SetPos(GetPos());
	ADDOBJECT(m_pHead);

	SkillSetUp();
}

void CSkulLittleBone::Update()
{
	CPlayer::Update();

	if (!m_bHeadOn)
	{
		m_vecHeadPos = m_pHead->GetPos();
	}
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

	m_skillA = skillShootHead;		// �� ���� (?)
	m_skillS = skillHeadIsI;
}

bool CSkulLittleBone::GetHeadOn()
{
	return m_bHeadOn;
}

void CSkulLittleBone::SetHeadOn(bool headOn)
{
	m_bHeadOn = headOn;
}

void CSkulLittleBone::ReturnHead()
{
	m_pHead->HeadInit();
	m_skillA.ReadySkill();
}



void CSkulLittleBone::SkillA()
{
	if (m_skillA.state == SKILL_STATE::READY)
	{
		Logger::Debug(L"��ų ���. �ٶ󺸴� ��: " + to_wstring(m_vecLookDir.x));
		m_pHead->SetPos(GetPos() + Vector(m_vecLookDir.x * 60, -10));
		//m_pHead->GetRigidBody()->PowerToX(m_vecLookDir.x * 400.f);
		m_pHead->GetRigidBody()->SetVelocityX(m_vecLookDir.x * 400.f);
		m_pHead->SetAttackDuration(6.f);
		//m_pHead->GetRigidBody()->

		m_bHeadOn = false;
		m_skillA.UseSkill();
	}
	
	// ���� �Ŀ� ȸ��? SkillA�� ������ ������Ʈ�� ���¿� ���� ȸ��?		- ���߿� ��� ������ �Ǿ����� ã�Ⱑ ������?
	// �ƴϸ� ������ ���¸� ������Ʈ �� ��, ���ۿ� ���� ȸ��?
}

void CSkulLittleBone::SkillS()
{
	if (m_skillA.state == SKILL_STATE::READY)
	{
		
	}
}

//void CSkulLittleBone::SkillAction()
//{
//}



void CSkulLittleBone::Render()
{
	CPlayer::Render();
	RENDER->Text(L"�÷��̾� ��ġ:" + to_wstring((int)GetPos().x) + L", " + to_wstring((int)GetPos().y), GetPos().x, GetPos().y + 90, GetPos().x + 200, GetPos().y + 190);
	RENDER->Text(L"�Ӹ� ����:" + to_wstring((int)m_bHeadOn), GetPos().x, GetPos().y + 100, GetPos().x + 100, GetPos().y + 200);
	RENDER->Text(L"�Ӹ� ��ġ:" + to_wstring((int)m_pHead->GetPos().x) + L", " + to_wstring((int)m_pHead->GetPos().y), GetPos().x, GetPos().y + 110, GetPos().x + 200, GetPos().y + 210);
	RENDER->Text(L"��ųA��:" + to_wstring((int)m_skillA.fCurCool), GetPos().x, GetPos().y + 120, GetPos().x + 100, GetPos().y + 220);
}

void CSkulLittleBone::OnCollisionEnter(CCollider* pOtherCollider)
{
	CPlayer::OnCollisionEnter(pOtherCollider);

	if (pOtherCollider->GetObjName() == L"�� �ΰ���")
	{
		Logger::Debug(L"�ΰ��� ����");
		ReturnHead();
	}
}

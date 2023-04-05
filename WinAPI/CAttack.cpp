#include "framework.h"
#include "CAttack.h"


#include "CUnit.h"
#include "CHit.h"

CAttack::CAttack()
{
	m_pOwner = nullptr;
	m_fDuration = 0;
	m_type = ATTACK_TYPE::MELEE;
	m_iAttack = 0;

	m_iCurFrame = 0;
	m_fAccTime = 0;

}

CAttack::~CAttack()
{
}


void CAttack::MakeEffect()
{
	CHit* pHit = new CHit();
	int xOffset = rand() % 20;
	int yOffset = rand() % 15;
	pHit->SetPos(m_vecPos + Vector(m_vecDir.x * xOffset, -10 + yOffset));
	pHit->SetDir(m_vecDir);
	ADDOBJECT(pHit);
}

ATTACK_TYPE CAttack::GetAttackType()
{
	return m_type;
}

CUnit* CAttack::GetOwner()
{
	return m_pOwner;
}

int CAttack::GetAttack()
{
	return m_iAttack;
}

Vector CAttack::GetDir()
{
	return m_vecDir;
}

float CAttack::GetAttackDuration()
{
	return m_fDuration;
}

void CAttack::SetOwner(CUnit* owner)
{
	m_pOwner = owner;
}

void CAttack::SetAttackDuration(float duration)
{
	m_fDuration = duration;
}

void CAttack::SetOffset(Vector offset)
{
	m_vecOffset = offset;
}

void CAttack::SetAttack(int attack)
{
	m_iAttack = attack;
}

void CAttack::SetDir(Vector dir)
{
	m_vecDir = dir;
}

void CAttack::SetAttackFrame(Vector pos, float duration)
{
	AttackFrame frame = { pos, duration };
	m_vAttackFlow.push_back(frame);
}

void CAttack::Init()
{
}

void CAttack::Update()
{
	if(ATTACK_TYPE::MELEE == m_type)
		m_vecPos = m_pOwner->GetPos() + m_vecOffset;

	if (m_fDuration > 0)
	{
		m_fDuration -= DT;
	}
	else
	{
		DELETEOBJECT(this);
	}
}

void CAttack::Render()
{
}

void CAttack::Release()
{
}

void CAttack::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CAttack::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CAttack::OnCollisionExit(CCollider* pOtherCollider)
{
}

#include "framework.h"
#include "CAttack.h"

#include "CUnit.h"

CAttack::CAttack()
{
	m_pOwner = nullptr;
	m_fDuration = 0;
	m_type = ATTACK_TYPE::MELEE;

}

CAttack::~CAttack()
{
}

ATTACK_TYPE CAttack::GetAttackType()
{
	return m_type;
}

CUnit* CAttack::GetOwner()
{
	return m_pOwner;
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

void CAttack::Init()
{
}

void CAttack::Update()
{
	m_vecPos = m_pOwner->GetPos() + m_vecOffset;

	if (m_fDuration > 0)
	{
		m_fDuration -= DT;
	}
	else
	{
		DELETEOBJECT(this);
		Logger::Debug(L"�����Ǿ���");
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

#include "framework.h"
#include "CUnit.h"


CUnit::CUnit()
{
	m_bGetHit = false;
	m_fInvincibleTime = 0;
}

CUnit::~CUnit()
{
}


void CUnit::Init()
{
}

void CUnit::Update()
{

	if (m_bGetHit)
	{
		m_fInvincibleTime += DT;

		if (m_fInvincibleTime > 0.2f)
			m_bGetHit = false;
	}
}

void CUnit::Render()
{
}

void CUnit::Release()
{
}

void CUnit::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CUnit::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CUnit::OnCollisionExit(CCollider* pOtherCollider)
{
}

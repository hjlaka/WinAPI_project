#include "framework.h"
#include "CUnit.h"


CUnit::CUnit()
{
	m_bGetHit = false;
	m_fInvincibleTime = 0;

	m_iHp = 0;
	m_iCurHp = 0;
	m_iAtt = 0;

	m_fSpeed = 0;
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

int CUnit::GetHp()
{
	return m_iHp;
}

int CUnit::GetCurHp()
{
	return m_iCurHp;
}

int CUnit::GetAttack()
{
	return m_iAtt;
}

float CUnit::GetSpeed()
{
	return m_fSpeed;
}

void CUnit::SetHp(int hp)
{
	m_iHp = hp;
}

void CUnit::SetCurHp(int curHp)
{
	m_iCurHp = curHp;
}

void CUnit::SetAttack(int att)
{
	m_iAtt = att;
}

void CUnit::SetSpeed(float spd)
{
	m_fSpeed = spd;
}

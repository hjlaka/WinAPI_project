#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"
#include "CRigidBody.h"
#include "CHpBar.h"

CMonster::CMonster()
{
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_status = STATUS::IDLE;
	m_vecTargetPos = Vector(0, 0);
	m_TargetObj = nullptr;
	m_hpBar = nullptr;
}

CMonster::~CMonster()
{
}

void CMonster::MoveToTargetPos()
{
	if (m_TargetObj != nullptr)
	{
		m_vecMoveDir.x = (m_TargetObj->GetPos().x - m_vecPos.x > 0) ? 1 : -1;
		m_pRigid->SetVelocityX(m_vecMoveDir.x * m_fSpeed);

	}

}

void CMonster::Init()
{
	m_hpBar = new CHpBar;
	AddComponent(m_hpBar);

}

void CMonster::Update()
{
}

void CMonster::Render()
{
}

void CMonster::Release()
{
}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌진입");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌진입");
	}
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌해제");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		Logger::Debug(L"몬스터가 미사일과 충돌해제");
	}
}

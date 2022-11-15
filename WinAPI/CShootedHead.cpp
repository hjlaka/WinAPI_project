#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	m_fAttack = 15.f;
	m_fDuration = 0.f;

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_pRigid->SetIsGravity(false);
	m_pRigid->SetIsFrictional(false);
}

CShootedHead::~CShootedHead()
{
}

CRigidBody* CShootedHead::GetRigidBody()
{
	return m_pRigid;
}

void CShootedHead::Update()
{
	
	if (m_fDuration > 0)
	{
		m_fDuration -= DT;
	}
	

	Logger::Debug(to_wstring(m_fDuration));

	/*if (m_fDuration < 0)
	{
		DELETEOBJECT(this);
	}*/
}

void CShootedHead::OnCollisionEnter(CCollider* pOtherCollider)
{
	


	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->SetIsGravity(true);
		m_pRigid->SetIsFrictional(true);
		m_pRigid->GroundCollisionEnter(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetObjName() == L"몬스터1")			// 몬스터와 충돌도 벽타일처럼 반응
	{
		Logger::Debug(L"벽충돌");
		m_pRigid->SetIsGravity(true);
		m_pRigid->SetIsFrictional(true);
		m_pRigid->PowerToX(-20.f);
		m_pRigid->WallCollisionEnter(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Player")
	{

	}
}

void CShootedHead::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->WallCollisionStay(GetCollider(), pOtherCollider);
	}
}

void CShootedHead::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->GroundCollisionExit(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetObjName() == L"몬스터1")
	{
		m_pRigid->WallCollisionExit(GetCollider(), pOtherCollider);

	}
}

//void CShootedHead::Init()
//{
//}
//
//void CShootedHead::Update()
//{
//}
//
//void CShootedHead::Render()
//{
//}
//
//void CShootedHead::Release()
//{
//}

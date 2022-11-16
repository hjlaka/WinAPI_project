#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	m_strName = L"내 두개골";
	m_fAttack = 15.f;
	m_fDuration = 0.f;

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	
	
}

CShootedHead::~CShootedHead()
{
}

CRigidBody* CShootedHead::GetRigidBody()
{
	return m_pRigid;
}

void CShootedHead::HeadInit()
{
	Logger::Debug(L"머리 초기화");
	//m_pRigid->InitRigidBody();
	m_pRigid->SetIsGravity(false);
	m_pRigid->SetIsFrictional(false);
	m_vecPos = Vector(-100, -100);
	
}

void CShootedHead::Init()
{
	CPlayerAttack::Init();

	HeadInit();
}

void CShootedHead::Update()
{
	
	if (m_fDuration > 0)			// 머리가 활성화된 시간
	{
		m_fDuration -= DT;

		if (m_fDuration <= 0)
		{
			Logger::Debug(L"머리 돌아감");
			HeadInit();
		}
	}

	
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
		Vector diff = GetCollider()->GetPos() - pOtherCollider->GetPos();
		m_pRigid->PowerToX(diff.Normalized().x * 20.f);
		m_pRigid->WallCollisionEnter(GetCollider(), pOtherCollider);

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

#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	m_strName = L"�� �ΰ���";
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
	Logger::Debug(L"�Ӹ� �ʱ�ȭ");
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
	
	if (m_fDuration > 0)
	{
		m_fDuration -= DT;
	}

	if (m_fDuration <= 0)
	{
		HeadInit();
		//DELETEOBJECT(this);
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
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetObjName() == L"����1")			// ���Ϳ� �浹�� ��Ÿ��ó�� ����
	{
		Logger::Debug(L"���浹");
		m_pRigid->SetIsGravity(true);
		m_pRigid->SetIsFrictional(true);
		m_pRigid->PowerToX(-20.f);
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
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetObjName() == L"����1")
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

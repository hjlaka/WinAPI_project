#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	//m_strName = L"�� �ΰ���";
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
	
	m_strName = L"PlayerAttack";
	
	m_vecPos = Vector(-100, -100);			// �̵��ϸ� �ڵ����� Exit �Ǵ� ��쵵 �ִ�.
	//m_pRigid->InitWallCollision();				// Exit�� �߸��Ǵ� ��쵵 �ִ�. �� ������� �ȵ���?? �� -2�� ����?
	m_pRigid->SetIsGravity(false);
	m_pRigid->SetIsFrictional(false);
	
}

void CShootedHead::Init()
{
	CPlayerAttack::Init();

	HeadInit();
}

void CShootedHead::Update()
{
	
	if (m_fDuration > 0)			// �Ӹ��� Ȱ��ȭ�� �ð�
	{
		m_fDuration -= DT;

		if (m_fDuration <= 0)
		{
			Logger::Debug(L"�Ӹ� ���ư�");
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
		m_strName = L"�� �ΰ���";
		m_pRigid->GroundCollisionEnter(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetObjName() == L"����1")			// ���Ϳ� �浹�� ��Ÿ��ó�� ����
	{
		Logger::Debug(L"���浹");
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

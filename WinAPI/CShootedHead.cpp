#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	//m_strName = L"내 두개골";
	m_fAttack = 15.f;
	m_fDuration = 0.f;

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);

	m_bHeadOn = true;
	
	
}

CShootedHead::~CShootedHead()
{
}

CRigidBody* CShootedHead::GetRigidBody()
{
	return m_pRigid;
}

void CShootedHead::SetHeadOn(bool value)
{
	m_bHeadOn = value;
}

bool CShootedHead::GetHeadOn()
{
	return m_bHeadOn;
}

void CShootedHead::HeadInit()
{
	Logger::Debug(L"머리 초기화");
	
	m_strName = L"PlayerAttack";
	
	m_vecPos = Vector(-100, -100);			// 이동하면 자동으로 Exit 되는 경우도 있다.
	//m_pRigid->InitWallCollision();				// Exit이 잘못되는 경우도 있다. 왜 생각대로 안되지?? 왜 -2가 되지?
	m_pRigid->SetIsGravity(false);
	m_pRigid->SetIsFrictional(false);
	m_bHeadOn = true;
	
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
		m_strName = L"내 두개골";
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

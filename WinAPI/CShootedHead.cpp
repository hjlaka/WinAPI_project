#include "framework.h"
#include "CShootedHead.h"
#include "CRigidBody.h"

CShootedHead::CShootedHead()
{
	m_fDuration = 0.f;
	m_vecDir = Vector(0, 0);

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);

	m_bHeadOn = true;
	m_type = ATTACK_TYPE::RANGED;

	m_pImg = nullptr;

	m_fSpeed = 400.f;
	
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

void CShootedHead::SetDir(Vector dir)
{
	m_vecDir = dir;
}

void CShootedHead::Shoot(Vector headPos, Vector lookDir)
{
	SetPos(headPos);
	SetDir(lookDir);
	m_pRigid->SetVelocityX(m_vecDir.x * m_fSpeed);
}

void CShootedHead::HeadInit()
{
	
	m_strName = L"PlayerAttack";
	
	m_vecPos = Vector(-100, -100);		
	m_pRigid->SetIsGravity(false);
	m_pRigid->SetGravitySpeed(0);
	m_pRigid->SetIsFrictional(false);
	m_pRigid->SetVelocityX(0);
	m_bHeadOn = true;
	
}

void CShootedHead::Init()
{
	CPlayerAttack::Init();

	HeadInit();

	m_pImg = RESOURCE->LoadImg(L"SkulHead", L"Image\\skul_head.png");
	m_pImg->SetImageRate(1.1f);

}

void CShootedHead::Update()
{
	
	if (m_fDuration > 0)			// 머리가 활성화된 시간
	{
		m_fDuration -= DT;

		if (m_fDuration <= 0)
		{
			HeadInit();
		}
	}
}

void CShootedHead::Render()
{
	if (nullptr == m_pImg)
		return;

	bool flip = (m_vecDir.x == -1);

	RENDER->FrameImage(
		m_pImg,
		m_vecPos.x - m_pImg->GetWidth() * 0.5f,
		m_vecPos.y - m_pImg->GetHeight() * 0.5f,
		m_vecPos.x + m_pImg->GetWidth() * 0.5f,
		m_vecPos.y + m_pImg->GetHeight() * 0.5f,
		0,
		0,
		m_pImg->GetWidth(),
		m_pImg->GetHeight(),
		flip
	);
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
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetOwner()->GetLayer() == Layer::Monster)			// 몬스터와 충돌도 벽타일처럼 반응
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
	else if (pOtherCollider->GetObjName() == L"Wall" || pOtherCollider->GetOwner()->GetLayer() == Layer::Monster)
	{
		m_pRigid->WallCollisionExit(GetCollider(), pOtherCollider);

	}
}

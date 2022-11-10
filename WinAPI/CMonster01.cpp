#include "framework.h"
#include "CMonster01.h"

#include "CRigidBody.h"

CMonster01::CMonster01()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"¸ó½ºÅÍ1";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);


	m_uiHp = 200;
	m_uiCurHp = 200;
	m_uiAtt = 15;
}

CMonster01::~CMonster01()
{
}

void CMonster01::Init()
{
	m_pIdleImage = RESOURCE->LoadImg(L"MonsterIdle", L"Image\\big_knight_idle.png");
	m_pMoveImage = RESOURCE->LoadImg(L"MonsterMove", L"Image\\big_knight_move.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Idle", m_pIdleImage, Vector(0.f, 0.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.5f, 4);
	
	m_pAnimator->Play(L"Idle", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_bIsRigidBody = true;
}

void CMonster01::Update()
{
	if (BUTTONSTAY(VK_LEFT))
	{
		m_pRigid->SetDirectionX(-1);
		//m_vecPos.x -= m_fSpeed * DT;
		m_vecMoveDir.x = -1;

	}
	else if (BUTTONSTAY(VK_RIGHT))
	{
		m_pRigid->SetDirectionX(+1);
		//m_vecPos.x += m_fSpeed * DT;
		m_vecMoveDir.x = +1;
	}
	else
	{
		m_vecMoveDir.x = 0;
		m_pRigid->SetDirectionX(0);
	}
}

void CMonster01::Render()
{
}

void CMonster01::Release()
{
}

void CMonster01::OnCollisionEnter(CCollider* pOtherCollider)
{

	if (pOtherCollider->GetObjName() == L"PlayerAttack")
	{
		m_vecPos += (GetCollider()->GetPos() - pOtherCollider->GetPos()).Normalized() * 10;
	}

	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->GroundCollisionEnter(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_pRigid->WallCollisionEnter(GetCollider(), pOtherCollider);


	}
}

void CMonster01::OnCollisionStay(CCollider* pOtherCollider)
{

}

void CMonster01::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->GroundCollisionExit(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_pRigid->WallCollisionExit(GetCollider(), pOtherCollider);

	}
}

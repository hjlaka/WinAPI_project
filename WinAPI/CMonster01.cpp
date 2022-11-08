#include "framework.h"
#include "CMonster01.h"

CMonster01::CMonster01()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"¸ó½ºÅÍ1";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;
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

	AddCollider(ColliderType::Rect, Vector(30, 30), Vector(0, 0));

}

void CMonster01::Update()
{
}

void CMonster01::Render()
{
}

void CMonster01::Release()
{
}

void CMonster01::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CMonster01::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster01::OnCollisionExit(CCollider* pOtherCollider)
{
}

#include "framework.h"
#include "CMonsterAttack.h"

CMonsterAttack::CMonsterAttack()
{
	m_layer = Layer::MonsterAttack;
	m_strName = L"MonsterAttack";
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
}

CMonsterAttack::~CMonsterAttack()
{
}

void CMonsterAttack::Init()
{
	AddCollider(ColliderType::Rect, m_vecScale, Vector(0,0));
}

void CMonsterAttack::Update()
{
	CAttack::Update();
}

void CMonsterAttack::Render()
{
}

void CMonsterAttack::Release()
{
}

void CMonsterAttack::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CMonsterAttack::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonsterAttack::OnCollisionExit(CCollider* pOtherCollider)
{
}

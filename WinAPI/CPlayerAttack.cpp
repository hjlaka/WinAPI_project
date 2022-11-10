#include "framework.h"
#include "CPlayerAttack.h"


CPlayerAttack::CPlayerAttack()
{
	m_layer = Layer::PlayerAttack;
	m_strName = L"PlayerAttack";
}

CPlayerAttack::~CPlayerAttack()
{
}

void CPlayerAttack::Init()
{
	AddCollider(ColliderType::Rect, Vector(10, 10), Vector(0, 0));
}

void CPlayerAttack::Update()
{
	CAttack::Update();
}

void CPlayerAttack::Render()
{
}

void CPlayerAttack::Release()
{
}


void CPlayerAttack::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPlayerAttack::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayerAttack::OnCollisionExit(CCollider* pOtherCollider)
{
}

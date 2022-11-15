#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	m_fAttack = 15.f;

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
}

CShootedHead::~CShootedHead()
{
}

void CShootedHead::Init()
{
}

void CShootedHead::Update()
{
}

void CShootedHead::Render()
{
}

void CShootedHead::Release()
{
}

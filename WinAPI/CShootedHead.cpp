#include "framework.h"
#include "CShootedHead.h"

CShootedHead::CShootedHead()
{
	m_fAttack = 15.f;

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_pRigid->SetIsGravity(false);
}

CShootedHead::~CShootedHead()
{
}

CRigidBody* CShootedHead::GetRigidBody()
{
	return m_pRigid;
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

#include "framework.h"
#include "CRigidBody.h"

CRigidBody::CRigidBody()
{
	m_bIsGravity = true;
}

CRigidBody::~CRigidBody()
{
}

bool CRigidBody::GetIsGravity()
{
	return m_bIsGravity;
}

void CRigidBody::SetIsGravity(bool isGravity)
{
	m_bIsGravity = isGravity;
}

void CRigidBody::Init()
{
}

void CRigidBody::Update()
{
	if (m_bIsGravity)
	{
		GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * 26 * DT);
	}
}

void CRigidBody::Render()
{
}

void CRigidBody::Release()
{
}

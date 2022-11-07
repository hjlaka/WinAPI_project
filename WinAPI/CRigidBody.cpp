#include "framework.h"
#include "CRigidBody.h"

CRigidBody::CRigidBody()
{
	m_fAcceleartion = 0;
	m_fGravity = 2.8f;
	m_bIsGravity = true;

	m_fGravitySpeed = 0;
	m_bOnGround = false;
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

void CRigidBody::SetGravitySpeed(float speed)
{
	m_fGravitySpeed = speed;
}

void CRigidBody::SetOnGround(bool onGround)
{
	m_bOnGround = onGround;
}

void CRigidBody::Init()
{
}

void CRigidBody::Update()
{

	if (m_bIsGravity)
	{		
		if(!m_bOnGround)
		{ 
			m_fGravitySpeed += m_fGravity;
			GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * m_fGravitySpeed * DT);
		}
	}
}

void CRigidBody::Render()
{
}

void CRigidBody::Release()
{
}

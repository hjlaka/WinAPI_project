#include "framework.h"
#include "CRigidBody.h"

CRigidBody::CRigidBody()
{
	m_fLaunchSpeed = 0;
	m_fGravity = 1280.f;
	m_bIsGravity = true;
	m_fSpeed = 200.f;

	m_fGravitySpeed = 0;
	m_iGroundCount = 0;
}

CRigidBody::~CRigidBody()
{
}

bool CRigidBody::GetIsGravity()
{
	return m_bIsGravity;
}

int CRigidBody::GetGroundCount()
{
	return m_iGroundCount;
}

void CRigidBody::SetIsGravity(bool isGravity)
{
	m_bIsGravity = isGravity;
}

void CRigidBody::SetGravitySpeed(float speed)
{
	m_fGravitySpeed = speed;
}

void CRigidBody::SetGroundCount(int value)
{
	m_iGroundCount += value;
}

void CRigidBody::Init()
{
}

void CRigidBody::Update()
{

	GetOwner()->SetPos(GetOwner()->GetPos() + m_vecDir.Normalized() * m_fSpeed * DT);

	if (m_bIsGravity)
	{		
		if (m_iGroundCount == 0)
		{
			if (m_fGravitySpeed < 1000.f)
			{
				m_fGravitySpeed += m_fGravity * DT;
			}
		}
		else if (m_iGroundCount < 0)
			assert(!m_iGroundCount < 0);

		GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * (m_fGravitySpeed) * DT);
		//Logger::Debug(L"중력: " + to_wstring(m_fGravitySpeed));
		//Logger::Debug(L"충돌 갯수: " + to_wstring(m_iGroundCount));
	}
}

void CRigidBody::PowerToY(float y)
{
	//m_fLaunchSpeed = -1.f * y;
	m_fGravitySpeed = -1.f * y;
}

void CRigidBody::Render()
{
}

void CRigidBody::Release()
{
}




void CRigidBody::SetDirectionX(int dirX)
{
	m_vecDir.x = dirX;
}

void CRigidBody::SetSpeed(float spd)
{
	m_fSpeed = spd;
}

void CRigidBody::SetDirectionY(int dirY)
{
	m_vecDir.y = dirY;
}
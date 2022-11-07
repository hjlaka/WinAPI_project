#include "framework.h"
#include "CRigidBody.h"

CRigidBody::CRigidBody()
{
	m_fLaunchSpeed = 0;
	m_fGravity = 1280.f;
	m_bIsGravity = true;

	m_fGravitySpeed = 0;
	m_uiGroundCount = 0;
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

void CRigidBody::SetGroundCount(UINT value)
{
	m_uiGroundCount += value;
}

void CRigidBody::Init()
{
}

void CRigidBody::Update()
{

	if (m_bIsGravity)
	{		
		if (m_uiGroundCount == 0)
		{
			if (m_fGravitySpeed < 1000.f)
			{
				m_fGravitySpeed += m_fGravity * DT;
			}
		}
		else if (m_uiGroundCount < 0)
			assert(m_uiGroundCount < 0);

		GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * (m_fGravitySpeed) * DT);
		Logger::Debug(L"ม฿ทย: " + to_wstring(m_fGravitySpeed));
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

#include "framework.h"
#include "CRigidBody.h"

CRigidBody::CRigidBody()
{
	m_fLaunchSpeed = 0;
	m_fGravity = 1080.f;
	m_bIsGravity = true;
	m_fSpeed = 200.f;

	m_fGravitySpeed = 0;
	m_iGroundCount = 0;
	m_bIsOnGround = false;
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

Vector CRigidBody::GetValidDir()
{
	Vector validDir = m_vecDir;
	if (validDir.x > 0)
	{
		validDir.x *= m_arrDirSpeed[(int)Dir::RIGHT];
	}
	else if (validDir.x < 0)
	{
		validDir.x *= m_arrDirSpeed[(int)Dir::LEFT];
	}

	if (validDir.y > 0)
	{
		validDir.y *= m_arrDirSpeed[(int)Dir::DOWN];
	}
	else if (validDir.y < 0)
	{
		validDir.y *= m_arrDirSpeed[(int)Dir::UP];
	}

	return validDir;
}

float CRigidBody::GetGravitySpeed()
{
	return m_fGravitySpeed;
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
	for (int i = 0; i < 4; i++)
	{
		m_arrDirSpeed[i] = 1;	// 왠만하면 초기화?
	}

	if (m_bIsGravity)
	{		
		
		if (!m_bIsOnGround)
		{
			if (m_fGravitySpeed < 1000.f)
			{
				m_fGravitySpeed += m_fGravity * DT;
			}
			
		}
		else if (m_iGroundCount < 0)
			assert(!m_iGroundCount < 0);
		else
		{
			//m_bIsOnGround 가 true인 경우
			m_bIsOnGround = false; // 초기화
		}


		GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * (m_fGravitySpeed) * DT);
		
		//Logger::Debug(L"중력: " + to_wstring(m_fGravitySpeed));
		//Logger::Debug(L"충돌 갯수: " + to_wstring(m_iGroundCount));
	}
}

void CRigidBody::PowerToY(float y)
{
	//m_fLaunchSpeed = 1.f * y;
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
	if (dirX > 0)
	{
		m_vecDir.x = dirX * m_arrDirSpeed[(int)Dir::RIGHT];

	}
	else if (dirX < 0)
	{
		m_vecDir.x = dirX * m_arrDirSpeed[(int)Dir::LEFT];
	}
	else
		m_vecDir.x = dirX;
}

void CRigidBody::SetSpeed(float spd)
{
	m_fSpeed = spd;
}

void CRigidBody::SetDirSpeed(Dir dir, float spd)
{
	m_arrDirSpeed[(int)dir] = spd;
}

void CRigidBody::SetDirectionY(int dirY)
{
	if (dirY > 0)
		m_vecDir.y = dirY * m_arrDirSpeed[(int)Dir::DOWN];
	else if (dirY < 0)
		m_vecDir.y = dirY * m_arrDirSpeed[(int)Dir::UP];
	else
		m_vecDir.y = dirY;
}
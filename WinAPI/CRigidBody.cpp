#include "framework.h"
#include "CRigidBody.h"

#include "CGameObject.h"
#include "CCollider.h"

CRigidBody::CRigidBody()
{
	m_fLaunchSpeed = 0;
	m_fGravity = 1080.f;
	m_bIsGravity = true;
	m_fSpeed = 200.f;
	m_fMultiSpeed = 1.f;

	m_fGravitySpeed = 0;
	m_iGroundCount = 0;
	m_bIsOnGround = false;

	m_uiNotBlockingCount = 0;
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

int CRigidBody::GetCollisionCont(Dir dir)
{
	return m_arrCollisionCount[(int)dir];
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
	


	GetOwner()->SetPos(GetOwner()->GetPos() + m_vecDir.Normalized() * m_fSpeed * m_fMultiSpeed *  DT);

	/*for (int i = 0; i < 4; i++)
	{
		if(m_arrCollisionCount[i] == 0)
			m_arrDirSpeed[i] = 1;
	}*/


	if (m_bIsGravity)			// �߷��� �޴� ��ü���?
	{		
		
		if (m_iGroundCount == 0/*!m_bIsOnGround*/)
		{
			if (m_fGravitySpeed < 1000.f)
			{
				m_fGravitySpeed += m_fGravity * DT;
			}
			
		}
		else if (m_iGroundCount < 0)
			assert(!m_iGroundCount < 0);
		



		GetOwner()->SetPos(GetOwner()->GetPos() + Vector(0.f, 1.f) * (m_fGravitySpeed) * DT);

		//Logger::Debug(L"�߷�: " + to_wstring(m_fGravitySpeed));
		//Logger::Debug(L"�浹 ����: " + to_wstring(m_iGroundCount));
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

void CRigidBody::SetMultiSpeed(float spd)
{
	m_fMultiSpeed = spd;
}

void CRigidBody::SetDirSpeed(Dir dir, float spd)
{
	m_arrDirSpeed[(int)dir] = spd;
}

void CRigidBody::SetCollisionConunt(Dir dir, int value)
{
	m_arrCollisionCount[(int)dir] += value;

	if (m_arrCollisionCount[(int)dir] > 0)
		m_arrDirSpeed[(int)dir] = 0;
	else
		m_arrDirSpeed[(int)dir] = 1;
}

bool CRigidBody::GroundCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider)
{
	Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
	Vector groundToMe = ground - myCollider->GetPos();

	if (myCollider->GetPos().y + myCollider->GetScale().y/2 < pOtherCollider->GetPos().y - pOtherCollider->GetScale().y/2 + 2.f && GetGravitySpeed() >= 0)
		//ĳ���Ͱ� ��ֹ� ���� �ְ�, �Ʒ��� �������� �ӵ��� 0 �̻��� ��
		//if (groundToMe.Normalized().y >= 0.690f)			// ���� �ٴ� �Ʒ� �� Ÿ�ϰ� �̸� �����浹 ���� �ʿ䰡 ������. �ٸ� ������Ʈ�� �ȵȴٴ� �� ������. 
	{
		Logger::Debug(L"�����浹");

		GetOwner()->SetPos(GetOwner()->GetPos().x, pOtherCollider->GetPos().y - pOtherCollider->GetScale().y/2 - myCollider->GetScale().y/2 + 0.1f) ;


		SetGravitySpeed(0);


		SetGroundCount(+1);

		return true;		// �����浹 ����

	}
	else
	{
		m_uiNotBlockingCount++;

		return false;
	}
}

void CRigidBody::WallCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider)
{
	Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
	Vector groundToMe = ground - myCollider->GetPos();
	//if (groundToMe.Normalized().y < 0.70f)	// �������� �浹 ������ ����
	{
		Logger::Debug(L"�¿��浹");

		if (/*m_vecMoveDir.x < 0 &&*/ groundToMe.x < 0)
		{
			//m_pRigid->SetDirSpeed(Dir::LEFT, 0);
			SetCollisionConunt(Dir::LEFT, +1);
			//SetPos(Vector(pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + GetCollider()->GetScale().x / 2 + 0.1f, GetCollider()->GetPos().y));
		}


		if (/*m_vecMoveDir.x > 0 &&*/ groundToMe.x > 0)
		{
			//m_pRigid->SetDirSpeed(Dir::RIGHT, 0);
			SetCollisionConunt(Dir::RIGHT, +1);
			//SetPos(Vector(pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - GetCollider()->GetScale().x / 2 - 0.1f, GetCollider()->GetPos().y));
		}
	}
}

void CRigidBody::GroundCollisionExit(CCollider* myCollider, CCollider* pOtherCollider)
{
	if (m_uiNotBlockingCount > 0)
	{
		m_uiNotBlockingCount--;
	}
	else
		SetGroundCount(-1);
}

void CRigidBody::WallCollisionExit(CCollider* myCollider, CCollider* pOtherCollider)
{
	//if (pOtherCollider->GetPos().x + pOtherCollider->GetScale().x/2 < myCollider->GetPos().x - myCollider->GetScale().x/2)
	if (pOtherCollider->GetPos().x< myCollider->GetPos().x)
		//m_pRigid->SetDirSpeed(Dir::LEFT, 1);
		SetCollisionConunt(Dir::LEFT, -1);
	//else if (pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 > myCollider->GetPos().x + myCollider->GetScale().x / 2)
	else if (pOtherCollider->GetPos().x > myCollider->GetPos().x)
		//m_pRigid->SetDirSpeed(Dir::RIGHT, 1);
		SetCollisionConunt(Dir::RIGHT, -1);
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
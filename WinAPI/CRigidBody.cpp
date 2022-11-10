#include "framework.h"
#include "CRigidBody.h"

#include "CGameObject.h"
#include "CCollider.h"

CRigidBody::CRigidBody()
{
	m_fGravity = 1080.f;
	m_bIsGravity = true;
	m_fSpeed = 200.f;
	m_fMultiSpeed = 1.f;		// �뽬 �ӵ� ��

	m_iGroundCount = 0;
	m_bIsOnGround = false;
	m_uiNotBlockingCount = 0;

	m_fForceX = 0;
	m_fFriction = 30.f;

	m_vecForce = Vector(0, 0);

	m_vecVelocity = Vector(0, 0);
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



float CRigidBody::GetGravitySpeed()
{
	return m_vecVelocity.y;
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
	m_vecVelocity.y = speed;
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
	//m_vecVelocity.Normalized();		// 2���� �����̾ �ʿ� ���� �� ����.
	UpdateVelocityX();
	//UpdateVelocityY

	// �ӵ� = �ӵ� + ���ӵ�
	// �Ÿ� = �ӵ� x �ð�

	GetOwner()->SetPos(GetOwner()->GetPos() + m_vecVelocity * DT);

	

	if (m_vecForce.Magnitude() > 1.f)
	{
		m_vecForce += m_vecForce.Normalized() * -1 * m_fFriction * 3.f * DT;
	}
	else
	{
		m_vecForce = Vector(0, 0);
	}


	if (m_vecVelocity.x > 0)
	{
		m_vecVelocity.x -= m_fFriction * DT;
	}
	else if (m_vecVelocity.x < 0)
	{
		m_vecVelocity.x += m_fFriction * DT;
	}


	if (m_bIsGravity)			// �߷��� �޴� ��ü���?
	{		
		
		if (m_iGroundCount == 0/*!m_bIsOnGround*/)
		{
			if (m_vecVelocity.y < 1000.f)
			{
				m_vecVelocity.y += m_fGravity * DT;
			}
			
		}
		else if (m_iGroundCount < 0)
			assert(!m_iGroundCount < 0);
		
	}
}



void CRigidBody::PowerToY(float y)
{
	m_vecVelocity.y = -1.f * y;
}
void CRigidBody::PowerToX(float x)
{
	m_fForceX = x;
}

void CRigidBody::Power(Vector force)
{
	m_vecForce = force;
}



void CRigidBody::Render()
{
}

void CRigidBody::Release()
{
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

void CRigidBody::SetVelocityX(float x)
{
	m_vecVelocity.x = x;
}

void CRigidBody::UpdateVelocityX()
{
	if (m_vecVelocity.x > 0)
	{
		m_vecVelocity.x *= m_fMultiSpeed* m_arrDirSpeed[(int)Dir::RIGHT];
	}
	else if (m_vecVelocity.x < 0)
	{
		m_vecVelocity.x *= m_fMultiSpeed * m_arrDirSpeed[(int)Dir::LEFT];
	}
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
void CRigidBody::SetDirectionX(int dirX)
{
	if (dirX > 0)
	{

		m_vecVelocity.x = dirX * m_arrDirSpeed[(int)Dir::RIGHT];

	}
	else if (dirX < 0)
	{

		m_vecVelocity.x = dirX * m_arrDirSpeed[(int)Dir::LEFT];

	}
	else
		m_vecVelocity.x = dirX;


}

void CRigidBody::SetDirectionY(int dirY)
{
	/*if (dirY > 0)
		m_vecVelocity.y = dirY * m_arrDirSpeed[(int)Dir::DOWN];
	else if (dirY < 0)
		m_vecVelocity.y = dirY * m_arrDirSpeed[(int)Dir::UP];
	else
		m_vecVelocity.y = dirY;*/
}
#include "framework.h"
#include "CRigidBody.h"

#include "CGameObject.h"
#include "CCollider.h"

CRigidBody::CRigidBody()
{
	m_fGravity = 1180.f;
	m_bIsGravity = true;
	m_fSpeed = 200.f;
	m_fMultiSpeed = 1.f;		// 대쉬 속도 등

	m_bIsOnGround = false;
	m_uiNotBlockingCount = 0;

	m_fForceX = 0;
	m_fFriction = 50.f;

	m_vecForce = Vector(0, 0);

	m_vecVelocity = Vector(0, 0);

	isUpDownCol = false;
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
	return m_arrCollisionCount[(int)Dir::DOWN];
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


void CRigidBody::Init()
{
}

void CRigidBody::Update()
{

	if (m_vecForce.Magnitude() > 1.f)
	{
		m_vecForce += m_vecForce.Normalized() * -1 * m_fFriction * DT;
	}
	else
	{
		m_vecForce = Vector(0, 0);
	}
	


	if (m_vecVelocity.x > 1.f)
	{
		m_vecVelocity.x -= m_fFriction * DT;			// 항시 작용한다?
	}
	else if (m_vecVelocity.x < 1.f)
	{
		m_vecVelocity.x += m_fFriction * DT;
	}
	else
	{
		m_vecVelocity.x = 0;
	}


	if (m_bIsGravity)			// 중력을 받는 물체라면?
	{		
		
		{
			if (m_vecVelocity.y < 900.f)
			{
				m_vecVelocity.y += m_fGravity * DT;
			}
			
		}
		
	}

	m_vecVelocity += m_vecForce * 500 * DT;
	//m_vecVelocity.Normalized();		// 2차원 조작이어서 필요 없는 것 같다.
	UpdateVelocityX();
	UpdateVelocityY();

	// 속도 = 속도 + 가속도
	// 거리 = 속도 x 시간


	GetOwner()->SetPos(GetOwner()->GetPos() + m_vecVelocity * DT);
}



void CRigidBody::PowerToY(float y)
{
	m_vecVelocity.y =  y;
}
void CRigidBody::PowerToX(float x)
{
	m_vecVelocity.x = x;
}

void CRigidBody::Power(Vector force)
{
	m_vecForce = force;
	//m_vecVelocity += force;
}



void CRigidBody::Render()
{
	if (isUpDownCol)
		RENDER->Text(L"상하충돌중", GetOwner()->GetPos().x, GetOwner()->GetPos().y, GetOwner()->GetPos().x + 100, GetOwner()->GetPos().y + 100);
	RENDER->Text(L"중력값:" + to_wstring(m_vecVelocity.y), GetOwner()->GetPos().x, GetOwner()->GetPos().y + 20, GetOwner()->GetPos().x + 100, GetOwner()->GetPos().y + 120);
	RENDER->Text(L"힘 값:" + to_wstring(m_vecForce.x) + L", " + to_wstring(m_vecForce.y), GetOwner()->GetPos().x, GetOwner()->GetPos().y + 40, GetOwner()->GetPos().x + 100, GetOwner()->GetPos().y + 140);
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

void CRigidBody::UpdateVelocityY()
{
	if (m_vecVelocity.y > 0)
	{
		m_vecVelocity.y *= m_arrDirSpeed[(int)Dir::DOWN];
	}
	else if (m_vecVelocity.y < 0)
	{
		m_vecVelocity.y *= m_arrDirSpeed[(int)Dir::UP];
	}
}

bool CRigidBody::GroundCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider)
{
	Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
	Vector groundToMe = ground - myCollider->GetPos();

	if (myCollider->GetPos().y + myCollider->GetScale().y/2 < pOtherCollider->GetPos().y - pOtherCollider->GetScale().y/2 + 2.f && GetGravitySpeed() >= 0)
		//캐릭터가 장애물 위에 있고, 아래로 떨어지는 속도가 0 이상일 때
		//if (groundToMe.Normalized().y >= 0.690f)			// 굳이 바닥 아래 옆 타일과 미리 상하충돌 중일 필요가 있을까. 다만 업데이트가 안된다는 게 문제다. 
	{
		//Logger::Debug(L"상하충돌");
		isUpDownCol = true;

		GetOwner()->SetPos(GetOwner()->GetPos().x, pOtherCollider->GetPos().y - pOtherCollider->GetScale().y/2 - myCollider->GetScale().y/2 + 0.1f) ;


		SetGravitySpeed(0);


		SetCollisionConunt(Dir::DOWN, +1);

		return true;		// 상하충돌 여부

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
	//if (groundToMe.Normalized().y < 0.70f)	// 방향으로 충돌 종류를 감지
	{
		//Logger::Debug(L"좌우충돌");

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
	{
		SetCollisionConunt(Dir::DOWN, -1);
		isUpDownCol = false;
	}
		
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
void CRigidBody::WallCollisionStay(CCollider* myCollider, CCollider* pOtherCollider)
{
	
	Vector wallPos = pOtherCollider->GetPos();
	Vector myPos = myCollider->GetPos();
	Vector wallScale = pOtherCollider->GetScale();
	Vector myScale = myCollider->GetScale();

	//타일과 부딪혔는데
	//타일의 꼭대기보다 유닛이 위에, 혹은 타일의 바닥보다 유닛이 아래에 있다면

	if (myPos.y + myScale.y * 0.5f > wallPos.y - wallScale.y * 0.5f + 5.f  &&
		myPos.y - myScale.y * 0.5f < wallPos.y + wallScale.y * 0.5f - 5.f)
	{
		Logger::Debug(L"벽충돌");
		// 유닛이 벽보다 오른쪽에 있다면
		if (myPos.x - myScale.x * 0.5f > wallPos.x + wallScale.x * 0.5f - 3.f)
		{
			myCollider->GetOwner()->SetPos(wallPos.x + (wallScale.x + myScale.x) * 0.5f, myPos.y);
		}
		else if (myPos.x + myScale.x * 0.5f < wallPos.x - wallScale.x * 0.5f + 3.f)
		{
			myCollider->GetOwner()->SetPos(wallPos.x - (wallScale.x + myScale.x) * 0.5f, myPos.y);
		}
	}


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
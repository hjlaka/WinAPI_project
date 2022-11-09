#include "framework.h"
#include "CMonster01.h"

#include "CRigidBody.h"

CMonster01::CMonster01()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"����1";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);

}

CMonster01::~CMonster01()
{
}

void CMonster01::Init()
{
	m_pIdleImage = RESOURCE->LoadImg(L"MonsterIdle", L"Image\\big_knight_idle.png");
	m_pMoveImage = RESOURCE->LoadImg(L"MonsterMove", L"Image\\big_knight_move.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Idle", m_pIdleImage, Vector(0.f, 0.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.5f, 4);
	
	m_pAnimator->Play(L"Idle", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_bIsRigidBody = true;
}

void CMonster01::Update()
{
}

void CMonster01::Render()
{
}

void CMonster01::Release()
{
}

void CMonster01::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
		Vector groundToMe = ground - GetCollider()->GetPos();

		if (GetCollider()->GetPos().y < pOtherCollider->GetPos().y && m_pRigid->GetGravitySpeed() >= 0)
			//if (groundToMe.Normalized().y >= 0.690f)			// ���� �ٴ� �Ʒ� �� Ÿ�ϰ� �̸� �����浹 ���� �ʿ䰡 ������. �ٸ� ������Ʈ�� �ȵȴٴ� �� ������. 
		{
			Logger::Debug(L"�����浹");

			//SetPos(Vector(GetCollider()->GetPos().x, pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2 - GetCollider()->GetScale().y / 2 - 0.01f));			// �ʿ��Ѱ�?
			//m_pRigid->SetIsGravity(false);


			m_pRigid->SetGravitySpeed(0);

			//m_pRigid->m_bIsOnGround = true;
			m_pRigid->SetGroundCount(+1);



		}
		/*else
		{
			m_uiNotBlockingCount++;
		}*/
	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
		Vector groundToMe = ground - GetCollider()->GetPos();
		//if (groundToMe.Normalized().y < 0.70f)	// �������� �浹 ������ ����
		{
			Logger::Debug(L"�¿��浹");

			if (m_vecMoveDir.x < 0 && groundToMe.x < 0)
			{
				//m_pRigid->SetDirSpeed(Dir::LEFT, 0);
				m_pRigid->SetCollisionConunt(Dir::LEFT, +1);
				//SetPos(Vector(pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + GetCollider()->GetScale().x / 2 + 0.1f, GetCollider()->GetPos().y));
			}


			if (m_vecMoveDir.x > 0 && groundToMe.x > 0)
			{
				//m_pRigid->SetDirSpeed(Dir::RIGHT, 0);
				m_pRigid->SetCollisionConunt(Dir::RIGHT, +1);
				//SetPos(Vector(pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - GetCollider()->GetScale().x / 2 - 0.1f, GetCollider()->GetPos().y));
			}
		}

	}
}

void CMonster01::OnCollisionStay(CCollider* pOtherCollider)
{
	////Ÿ�� �浹 ����(�÷��̾� �ڵ�� ����)
	//if (pOtherCollider->GetObjName() == L"Ground")
	//{
	//	Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
	//	Vector groundToMe = ground - GetCollider()->GetPos();


	//	if (groundToMe.Normalized().y < 0.70f)	// �������� �浹 ������ ����
	//	{
	//		Logger::Debug(L"�¿��浹");

	//		// �¿��浹�� �浹 ���� Ȯ�� =========> Stay������ �浹���¿��� ������ �ٲ�� ��� �������� �Ͼ��. Stay������ ��ġ�� �Ǵ�����.
	//		// �׷��� �ѵ�, Stay���ε� �ʹ� ó������ ���� �ʾ�? �ϴ� MoveDir�� Ű�Է½ÿ��� �ߵ��� ���̴�.
	//		if (m_vecMoveDir.x < 0 && groundToMe.x < 0)
	//			m_pRigid->SetDirSpeed(Dir::LEFT, 0);
	//		if (m_vecMoveDir.x > 0 && groundToMe.x > 0)
	//			m_pRigid->SetDirSpeed(Dir::RIGHT, 0);
	//	}

	//	if (groundToMe.Normalized().y >= 0.690f)			// ���� �ٴ� �Ʒ� �� Ÿ�ϰ� �̸� �����浹 ���� �ʿ䰡 ������ 
	//	{
	//		Logger::Debug(L"�����浹");

	//		SetPos(Vector(GetCollider()->GetPos().x, pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2 - GetCollider()->GetScale().y / 2 + 0.0001f));			// �ʿ��Ѱ�?


	//		m_pRigid->SetGravitySpeed(0);

	//		m_pRigid->m_bIsOnGround = true;

	//	}
	//}
	//else if (pOtherCollider->GetObjName() == L"Wall")
	//{
	//	Vector ground = Vector(pOtherCollider->GetPos().x, pOtherCollider->GetPos().y);
	//	Vector groundToMe = ground - GetCollider()->GetPos();
	//	//if (groundToMe.Normalized().y < 0.70f)	// �������� �浹 ������ ����
	//	{
	//		Logger::Debug(L"�¿��浹");

	//		// �¿��浹�� �浹 ���� Ȯ�� =========> Stay������ �浹���¿��� ������ �ٲ�� ��� �������� �Ͼ��. Stay������ ��ġ�� �Ǵ�����.
	//		// �׷��� �ѵ�, Stay���ε� �ʹ� ó������ ���� �ʾ�? �ϴ� MoveDir�� Ű�Է½ÿ��� �ߵ��� ���̴�.
	//		if (m_vecMoveDir.x < 0 && groundToMe.x < 0)
	//			m_pRigid->SetDirSpeed(Dir::LEFT, 0);
	//		if (m_vecMoveDir.x > 0 && groundToMe.x > 0)
	//			m_pRigid->SetDirSpeed(Dir::RIGHT, 0);
	//	}
	//}
}

void CMonster01::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		//if (GetCollider()->GetPos().y < pOtherCollider->GetPos().y)
		//m_pRigid->m_bIsOnGround = false;
		//if (m_uiNotBlockingCount > 0)
		//{
		//	m_uiNotBlockingCount--;
		//}
		//else
			m_pRigid->SetGroundCount(-1);
	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		if (pOtherCollider->GetPos().x < GetCollider()->GetPos().x)
			//m_pRigid->SetDirSpeed(Dir::LEFT, 1);
			m_pRigid->SetCollisionConunt(Dir::LEFT, -1);
		else if (pOtherCollider->GetPos().x > GetCollider()->GetPos().x)
			//m_pRigid->SetDirSpeed(Dir::RIGHT, 1);
			m_pRigid->SetCollisionConunt(Dir::RIGHT, -1);
	}
}

#include "framework.h"
#include "CMonster01.h"

#include "CRigidBody.h"
#include "CGameManager.h"
#include "CPlayerAttack.h"
#include "CMonsterAttack.h"



CMonster01::CMonster01()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_strName = L"BigKnight";
	m_status = STATUS::IDLE;

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;
	m_pDieImage = nullptr;

	m_fAttackAPlayTime = 0;
	m_fStatusTimer = 0;
	m_fAttackACool = 0;
	m_fAttackBCool = 0;
	//m_fThinkTime = 0;
	m_bMakeAttack = false;

	m_fRushSpeed = 550;
	m_meleeAttack = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);


	m_iHp = 200;
	m_iCurHp = 200;
	m_iAtt = 15;
	m_fSpeed = 100.f;
}

CMonster01::~CMonster01()
{
}


void CMonster01::Init()
{
	CMonster::Init();

	m_pIdleImage = RESOURCE->LoadImg(L"BigKnightIdle", L"Image\\big_knight_idle.png");
	m_pMoveImage = RESOURCE->LoadImg(L"BigKnightMove", L"Image\\big_knight_move.png");
	m_pAttackImage = RESOURCE->LoadImg(L"BigKnightAttack", L"Image\\big_knight_attackA.png");
	m_pAttackBImage = RESOURCE->LoadImg(L"BigKnightAttackB", L"Image\\big_knight_attackB.png");
	m_pDieImage = RESOURCE->LoadImg(L"BigKnightDie", L"Image\\big_knight_die.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Idle", m_pIdleImage, Vector(0.f, 20.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"Move", m_pMoveImage, Vector(0.f, 20.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.2f, 8);
	m_pAnimator->CreateAnimation(L"AttackA", m_pAttackImage, Vector(0.f, 20.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.1f, 20);
	m_pAnimator->CreateAnimation(L"AttackB", m_pAttackBImage, Vector(0.f, 20.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.1f, 2, false);
	m_pAnimator->CreateAnimation(L"Die", m_pDieImage, Vector(0.f, 20.f), Vector(150.f, 145.f), Vector(160.f, 0.f), 0.1f, 1, false);

	m_fAttackAPlayTime = m_pAnimator->FindAnimation(L"AttackA")->GetFullTime();
	
	m_pAnimator->Play(L"Idle", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_bIsRigidBody = true;
	
}

void CMonster01::Update()
{
	CUnit::Update();

	CPlayer* pPlayer = GAME->GetPlayer();
	m_TargetObj = pPlayer;

	Vector distance = m_TargetObj->GetPos() - m_vecPos;


	if (m_iCurHp <= 0) m_status = STATUS::DIE;			// 우선순위

	switch (m_status)
	{
	case STATUS::IDLE:
		// 플레이어가 가까이 오는지 확인
		if (abs(distance.y) < 100.f &&
			abs(distance.x) < 300.f && m_fAttackACool <= 0)
		{
			m_status = STATUS::MOVE;
		}

		break;
	case STATUS::MOVE:
		// 플레이어쪽으로 이동

		MoveToTargetPos();

		if (abs(distance.x) > 350.f)
		{
			m_status = STATUS::IDLE;
		}
		else if (abs(distance.x) < 250.f && m_fAttackBCool <= 0)
		{

			m_status = STATUS::ATTACKB_READY;
			m_fStatusTimer = 1.5f;			// 상태 유지 시간 설정
			m_fRushTargetPosX = m_TargetObj->GetPos().x;		// 목표의 위치를 가져옴
			m_bMakeAttack = false;

		}
		else if (abs(distance.x) < 100.f)
		{
			if (m_fAttackACool <= 0)			// 쿨타임 0이면
			{
				m_status = STATUS::ATTACKA;
				m_fStatusTimer = m_fAttackAPlayTime;		// 상태 유지 시간 설정
				m_bMakeAttack = false;
			}
			else
			{
				m_status = STATUS::IDLE;
			}
		}

		break;
	case STATUS::CONFRONT:
		break;
	case STATUS::ATTACKA:
		m_pRigid->SetVelocityX(0);
		m_fStatusTimer -= DT;
		if (m_fStatusTimer <= 1.f && !m_bMakeAttack)			// 상태 변경된 후 1초가 지나고 공격 콜라이더 생성 
		{
			// 공격 범위 생성
			CMonsterAttack* pAttack = new CMonsterAttack;
			pAttack->SetPos(m_vecPos);
			pAttack->SetOffset(Vector(m_vecLookDir.x * 100, 0));
			pAttack->SetOwner(this);
			pAttack->SetAttackDuration(0.1f);
			pAttack->SetAttack(m_iAtt);
			pAttack->SetDir(m_vecLookDir);
			ADDOBJECT(pAttack);
			m_bMakeAttack = true;
		}
		else if (m_fStatusTimer <= 0)
		{
			m_status = STATUS::IDLE;
			m_fAttackACool = 2.5f;
		}
		break;
	case STATUS::ATTACKB_READY:
		m_pRigid->SetVelocityX(0);
		m_fStatusTimer -= DT;
		//m_vecMoveDir.x = (m_TargetObj->GetPos().x - GetPos().x > 0) ? 1 : -1;		// 준비 중에는 방향 변경 가능
		if (m_fStatusTimer <= 0)
		{
			m_status = STATUS::ATTACKB;
			m_fStatusTimer = 1.5f;
			//m_fRushTargetPosX = m_TargetObj->GetPos().x;		// 준비시간 끝에 목표의 위치를 가져옴
		}
		break;
	case STATUS::ATTACKB:
		m_pRigid->SetVelocityX(0);
		if (!m_bMakeAttack)
		{
			// 공격 범위 생성
			m_meleeAttack = new CMonsterAttack;
			m_meleeAttack->SetPos(m_vecPos);
			m_meleeAttack->SetOffset(Vector(m_vecLookDir.x * 50, 0));
			m_meleeAttack->SetOwner(this);
			m_meleeAttack->SetAttackDuration(m_fStatusTimer * 0.52f);
			m_meleeAttack->SetAttack(m_iAtt * 1.5f);
			m_meleeAttack->SetDir(m_vecLookDir);
			ADDOBJECT(m_meleeAttack);

			m_bMakeAttack = true;
		}

		m_fStatusTimer -= DT;
		if (m_fStatusTimer <= 0)
		{
			m_status = STATUS::IDLE;
			m_fAttackBCool = 5.f;
		}
		else
		{
			float velocity = ((m_fRushTargetPosX - GetPos().x) / m_fStatusTimer) * 5;
			if (velocity > m_fRushSpeed)
			{
				velocity = m_fRushSpeed;
				m_fStatusTimer += DT;							// 속도가 최고 속도라면, 시간을 줄어들게 하지 않는다.
				m_meleeAttack->SetAttackDuration(m_meleeAttack->GetAttackDuration() + DT);
			}
			else if (velocity < -1 * m_fRushSpeed)
			{
				velocity = -1 * m_fRushSpeed;
				m_fStatusTimer += DT;
				m_meleeAttack->SetAttackDuration(m_meleeAttack->GetAttackDuration() + DT);
			}
			m_pRigid->SetVelocityX(velocity);
		}

		
		

		break;
	case STATUS::DIE:
		break;
	}
	

	
	if (m_fAttackACool > 0)
	{
		m_fAttackACool -= DT;
	}
	if (m_fAttackBCool > 0)
	{
		m_fAttackBCool -= DT;
	}
	AnimatorUpdate();
}

void CMonster01::AnimatorUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	m_pAnimator->SetFlip(m_vecLookDir.x == -1);			// 왼쪽을 바라보고 있다면 애니메이션 좌우 반전

	wstring str = L"";


	switch (m_status)
	{
	case STATUS::IDLE:
		str += L"Idle";
		break;
	case STATUS::MOVE:
		str += L"Move";
		break;
	case STATUS::ATTACKA:
		str += L"AttackA";
		break;
	case STATUS::ATTACKB_READY:
		str += L"AttackB";
		break;
	case STATUS::ATTACKB:
		str += L"AttackB";
		break;
	case STATUS::DIE:
		str += L"Die";
		break;
	}
	m_pAnimator->Play(str, false);
}

void CMonster01::Render()
{
}

void CMonster01::Release()
{
}

void CMonster01::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"PlayerAttack" && !m_bGetHit && m_status != STATUS::DIE)
	{

		CAttack* pAttack = (CAttack*)(pOtherCollider->GetOwner());
		pAttack->MakeEffect();

		if (pAttack->GetAttackType() == ATTACK_TYPE::RANGED)
		{
			Vector diff = (GetCollider()->GetPos() - pOtherCollider->GetPos());
			m_pRigid->PowerToX(diff.Normalized().x * 3.f); //diff.Normalized().y * 10
		}
		else if (pAttack->GetAttackType() == ATTACK_TYPE::MELEE)
		{
			m_pRigid->Power(Vector(pAttack->GetOwner()->GetLookDir().x * 2.5f, 1)); //diff.Normalized().y * 10 // 가속도가 되어버리는 문제가 있다.
		}
		

		int attackPoint = pAttack->GetAttack();
		m_iCurHp -= attackPoint;

		m_bGetHit = true;
	}

	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->GroundCollisionEnter(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_pRigid->WallCollisionEnter(GetCollider(), pOtherCollider);


	}
}

void CMonster01::OnCollisionStay(CCollider* pOtherCollider)
{

}

void CMonster01::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->GroundCollisionExit(GetCollider(), pOtherCollider);

	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_pRigid->WallCollisionExit(GetCollider(), pOtherCollider);

	}
}

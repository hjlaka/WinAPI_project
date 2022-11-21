#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"

#include "CRigidBody.h"

#include "CMissile.h"
#include "CPlayerAttack.h"
#include "CSmoke.h"
#include "CGameManager.h"

#include "CStatePlayer.h"
#include "CPlayerIdle.h"




CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";
	m_skulType = SKUL_TYPE::NONE;

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;
	m_pAttackImage = nullptr;
	m_pAttackBImage = nullptr;
	m_pJumpImage = nullptr;
	m_pFallImage = nullptr;
	m_pFallRepeatImage = nullptr;
	m_pDashImage = nullptr;
	m_pJumpAttackImage = nullptr;

	m_pPortrait = nullptr;

	
	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(1, 0);
	m_bIsMove = false;
	m_bIsCanMove = false;
	m_bIsAttack = false;
	m_iAttackCount = 0;
	m_iJumpCount = 0;
	m_bOverPeak = false;
	m_bIsDash = false;
	m_bAttackContinue = false;

	m_fAttackContinue = 0;

	m_fFallTime = 0;
	m_fAttackATime = 0;
	m_fAttackBTime = 0;
	m_fAttackJTime = 0;

	m_fDashCoolTime - 0;

	m_fDashClock = 0;

	m_pPlayerState = nullptr;
	m_state = STATE::IDLE;

	//m_curSkulType = SKUL_TYPE::LITTLE_BONE;
	//m_subSkulType = SKUL_TYPE::HUNTER;

	//

	/*SkillInfo skillEmpty;
	skillEmpty.state = SKILL_STATE::NONE;*/

	m_skillA = nullptr;
	m_skillS = nullptr;

	m_iSkillCount = 2;
	m_fSkillACoolClock = 0;
	m_fSkillSCoolClock = 0;

	//


	//


	m_iHp = 100;
	m_iCurHp = 100;
	m_iAtt = 10;

	m_fSpeed = 300.f;
}


CPlayer::~CPlayer()
{

}

void CPlayer::UpdateSkill()
{
	
	if (m_skillA != nullptr) m_skillA->UpdateCool();
	if (m_skillS != nullptr) m_skillS->UpdateCool();
}

SkillInfo* CPlayer::GetSkillA()
{
	return m_skillA;
}

SkillInfo* CPlayer::GetSkillS()
{
	return m_skillS;
}

void CPlayer::Init()
{

	m_pAnimator = new CAnimator;
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(30, 30), Vector(0, 0));

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_bIsRigidBody = true;


	// 상태 생성 및 초기화 (상태도 컴포넌트로 만들어야 하나?)
	m_pPlayerState = new CPlayerIdle;

}

void CPlayer::Update()
{
	if (GAME->GetGameStatue() == GAME_STATUS::PAUSE)
		return;
	
	// 상태
	CStatePlayer* nextState = m_pPlayerState->HandleInput(this);
	if (nullptr != nextState)
	{
		m_pPlayerState->Exit(this);

		delete m_pPlayerState;
		m_pPlayerState = nextState;

		m_pPlayerState->Enter(this);
	}

	m_pPlayerState->Update(this);



	if (m_bIsCanMove)			// 키보드 조작대로 움직일 수 있는 상태일 경우
	{
		if (BUTTONSTAY(VK_LEFT))
		{
			m_vecMoveDir.x = -1;

		}
		else if (BUTTONSTAY(VK_RIGHT))
		{

			m_vecMoveDir.x = +1;
		}
		else
		{
			m_vecMoveDir.x = 0;
		}
		m_pRigid->SetVelocityX(m_vecMoveDir.x * m_fSpeed);
	}


	if (BUTTONDOWN('R'))
	{
		m_vecPos = Vector(100, 100);
	}


	if (m_fDashCoolTime > 0)
		m_fDashCoolTime -= DT;


	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	UpdateInState();
	UpdateSkill();

	AnimatorUpdate();
}

void CPlayer::Render()
{

	wstring groundCount = to_wstring(m_pRigid->GetGroundCount());

	


}

void CPlayer::Release()
{
	if (nullptr != m_pPlayerState)
		delete m_pPlayerState;

	/*if (nullptr != m_skillA)
		delete m_skillA;

	if (nullptr != m_skillS)
		delete m_skillS;*/
}

void CPlayer::UpdateInState()
{
}

void CPlayer::AnimatorUpdate()
{

}



void CPlayer::CreateMissile()
{
	Logger::Debug(L"미사일 생성");

	CMissile* pMissile = new CMissile();
	pMissile->SetPos(m_vecPos);
	pMissile->SetDir(Vector(1, 0));
	ADDOBJECT(pMissile);

	CMissile* pMissile1 = new CMissile();
	pMissile1->SetPos(m_vecPos);
	pMissile1->SetDir(Vector(1, -1));
	ADDOBJECT(pMissile1);

	CMissile* pMissile2 = new CMissile();
	pMissile2->SetPos(m_vecPos);
	pMissile2->SetDir(Vector(1, 1));
	ADDOBJECT(pMissile2);

	CMissile* pMissile3 = new CMissile();
	pMissile3->SetPos(m_vecPos);
	pMissile3->SetDir(Vector(3, 1));
	ADDOBJECT(pMissile3);

	CMissile* pMissile4 = new CMissile();
	pMissile4->SetPos(m_vecPos);
	pMissile4->SetDir(Vector(3, -1));
	ADDOBJECT(pMissile4);
}

void CPlayer::Jump(float fJumpPower)
{
	/*m_bIsJump = true;
	m_fJumpPower = fJumpPower;*/
}


void CPlayer::Attack()
{
	Logger::Debug(L"공격 생성");

	CPlayerAttack* pAttack = new CPlayerAttack();
	pAttack->SetPos(m_vecPos);
	pAttack->SetOffset(Vector(m_vecLookDir.x * 30, -10));
	pAttack->SetOwner(this);
	pAttack->SetAttackDuration(0.4f);
	//pAttack->SetDir(m_vecLookDir);
	ADDOBJECT(pAttack);
}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{

	if (pOtherCollider->GetObjName() == L"Ground")
	{

		bool isUpDownCollision = m_pRigid->GroundCollisionEnter(GetCollider(), pOtherCollider);

		if (isUpDownCollision)
		{
			m_iJumpCount = 0;
			m_fJumpPower = 0;
			m_fFallTime = 0;
		}

	}
	else if (pOtherCollider->GetObjName() == L"Wall")
	{
		m_pRigid->WallCollisionEnter(GetCollider(), pOtherCollider);
				
	}

	
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"Ground")
	{
		m_pRigid->WallCollisionStay(GetCollider(), pOtherCollider);
	}
	

	//if (pOtherCollider->GetObjName() == L"Ground")
	//{
	//	CCollider* playerColl = GetCollider();
	//	if (playerColl->GetPos().y + playerColl->GetScale().y / 2 > pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2 + 5.f)	// 플레이어가 더 낮게 들어온다.
	//	{
	//		Logger::Debug(L"상하충돌하다가 좌우충돌");		// 상하충돌 탈출이 이루어지지 않고 전환된다는 문제가 있다.

	//		if (m_vecMoveDir.x < 0)
	//		{
	//			//Logger::Debug(L"상하충돌하다가 좌우충돌")
	//			m_pRigid->SetDirSpeed(Dir::LEFT, 0);
	//			//m_pRigid->SetCollisionConunt(Dir::LEFT, +1);
	//			
	//		}


	//		if (m_vecMoveDir.x > 0)
	//		{
	//			m_pRigid->SetDirSpeed(Dir::RIGHT, 0);
	//			//m_pRigid->SetCollisionConunt(Dir::RIGHT, +1);
	//			//SetPos(Vector(pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - GetCollider()->GetScale().x / 2 - 0.1f, GetCollider()->GetPos().y));
	//		}
	//	}
	//}

}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
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

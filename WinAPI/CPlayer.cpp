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


CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(1, 0);
	m_bIsMove = false;
	m_bIsAttack = false;
	m_iAttackCount = 0;
	m_iJumpCount = 0;
	m_bOverPeak = false;
	m_bIsDash = false;
	m_bAttackContinue = false;

	
	m_fFallTime = 0;
	m_fAttackATime = 0;
	m_fAttackBTime = 0;

	m_fDashClock = 0;
	
	m_pPlayerState = nullptr;
	m_state = STATE::IDLE;


	//


	m_iHp = 100;
	m_iCurHp = 100;
	m_iAtt = 10;

	m_fSpeed = 300.f;

}

CPlayer::~CPlayer()
{
	if (nullptr != m_pPlayerState)
		delete m_pPlayerState;
}

void CPlayer::Init()
{

#pragma region Animation Setting
	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\idle_skul.png");
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\move_skul.png");
	m_pAttackImage = RESOURCE->LoadImg(L"PlayerAttack", L"Image\\attackA_skul.png");
	m_pAttackBImage = RESOURCE->LoadImg(L"PlayerAttackB", L"Image\\attackB_skul.png");
	m_pJumpImage = RESOURCE->LoadImg(L"PlayerJump", L"Image\\jump_skul.png");
	m_pFallImage = RESOURCE->LoadImg(L"PlayerFall", L"Image\\fall_skul.png");
	m_pFallRepeatImage = RESOURCE->LoadImg(L"PlayerFallRepeat", L"Image\\fallrepeat_skul.png");
	m_pDashImage = RESOURCE->LoadImg(L"PlayerDash", L"Image\\dash_skul.png");
	m_pJumpAttackImage = RESOURCE->LoadImg(L"PlayerJumpAttack", L"Image\\jumpattack_skul.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"IdleUp", m_pIdleImage, Vector(25.f, 20.f), Vector(50.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleRightUp", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleRightDown", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleDown", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleLeftDown", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleLeftUp", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);

	m_pAnimator->CreateAnimation(L"MoveUp",			m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveRightUp",	m_pMoveImage, Vector(0.f, 20.f), Vector(80.f,  75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveRight",		m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveRightDown",	m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveDown",		m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveLeftDown",	m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveLeft",		m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveLeftUp",		m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	
	m_pAnimator->CreateAnimation(L"AttackA", m_pAttackImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"AttackB", m_pAttackBImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"Jump", m_pJumpImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"Fall", m_pFallImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"FallRepeat", m_pFallRepeatImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 3);
	m_pAnimator->CreateAnimation(L"Dash", m_pDashImage, Vector(0.f, 25.f), Vector(75.f, 50.f), Vector(96.f, 0.f), 0.15f, 1);
	m_pAnimator->CreateAnimation(L"JumpAttack", m_pJumpAttackImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);

	auto attackEnd = [](DWORD_PTR pMe, DWORD_PTR pParam2)
	{
		CPlayer* pPlayer = (CPlayer*)pMe;

		//플레이어의 공격 상태를 해제한다.

		if (pPlayer->m_iAttackCount > 1)
		{

		}

		pPlayer->m_bIsAttack = false;
		pPlayer->m_iAttackCount++;
		
	};

	auto falling = [](DWORD_PTR pMe, DWORD_PTR pParam2)
	{
		CPlayer* pPlayer = (CPlayer*)pMe;


		pPlayer->m_bOverPeak = true;

	
	};

	//m_pAnimator->SetAnimationCallBack(L"AttackA", attackEnd, (DWORD_PTR)this, 0);
	//m_pAnimator->SetAnimationCallBack(L"AttackB", attackEnd, (DWORD_PTR)this, 0);
	//m_pAnimator->SetAnimationCallBack(L"JumpAttack", attackEnd, (DWORD_PTR)this, 0);
	//m_pAnimator->SetAnimationCallBack(L"Fall", falling, (DWORD_PTR)this, 0);
	
#pragma endregion

	m_pAnimator->Play(L"IdleDown", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(30, 30), Vector(0, 0));

	m_pRigid = new CRigidBody;
	AddComponent(m_pRigid);
	m_bIsRigidBody = true;


}

void CPlayer::Update()
{
	
	m_bIsMove = false;
	m_bIsDash = false;


	Logger::Debug(L"x, y: " + to_wstring(m_vecPos.x) + L", " + to_wstring(m_vecPos.y));
	
	
	m_vecMoveDir.x = 0;
	m_pRigid->SetDirectionX(0);


	if (m_state == STATE::IDLE)
	{
		if (BUTTONSTAY(VK_LEFT))
		{
			m_pRigid->SetDirectionX(-1);
			m_pRigid->SetVelocityX(-1 * m_fSpeed);
			m_bIsMove = true;
			m_vecMoveDir.x = -1;

		}
		else if (BUTTONSTAY(VK_RIGHT))
		{
			m_pRigid->SetDirectionX(+1);
			m_pRigid->SetVelocityX(m_fSpeed);
			m_bIsMove = true;
			m_vecMoveDir.x = +1;
		}
		else
		{
			m_vecMoveDir.x = 0;
			m_pRigid->SetDirectionX(0);
		}
	}
	
	



	if (m_bIsAttack)	//공격중일 때
	{
		if (BUTTONDOWN('X') && !m_bAttackContinue)
		{
			m_bAttackContinue = true;
		}

		if (m_state == STATE::ATTACKA)
		{
			m_fAttackATime -= DT;
			if (m_fAttackATime <= 0)
			{
				if (!m_bAttackContinue)
				{
					m_bIsAttack = false;
					m_state = STATE::IDLE;
					return;
				}
				else
				{
					m_state = STATE::ATTACKB;		// 공격 전환.
					m_fAttackBTime = 0.4f;
					m_bAttackContinue = false;
					//Attack();
					if (BUTTONSTAY(VK_RIGHT))
					{
						// 앞으로 가면서 공격
						m_pRigid->SetDirectionX(+1);
						m_pRigid->PowerToX(4500.f);
						m_vecMoveDir.x = +1;
					}
					else if(BUTTONSTAY(VK_LEFT))
					{
						// 앞으로 가면서 공격
						m_pRigid->SetDirectionX(+1);
						m_pRigid->PowerToX(-4500.f);
						m_vecMoveDir.x = +1;
					}
				}
			}
		}
		else if (m_state == STATE::ATTACKB )
		{
			m_fAttackBTime -= DT;
			if (m_fAttackBTime <= 0)
			{
				if (!m_bAttackContinue)
				{
					m_bIsAttack = false;
					m_state = STATE::IDLE;
					return;
				}
				else
				{
					m_state = STATE::ATTACKA;		// 공격 전환.
					m_fAttackATime = 0.5f;
					m_bAttackContinue = false;
					//Attack();
					if (BUTTONSTAY(VK_RIGHT))
					{
						// 앞으로 가면서 공격
						m_pRigid->SetDirectionX(+1);
						m_pRigid->PowerToX(4500.f);
						m_vecMoveDir.x = +1;
					}
					else if (BUTTONSTAY(VK_LEFT))
					{
						// 앞으로 가면서 공격
						m_pRigid->SetDirectionX(+1);
						m_pRigid->PowerToX(-4500.f);
						m_vecMoveDir.x = +1;
					}
				}
			}
			
		}
	}
	else if (BUTTONDOWN('X'))
	{
		m_state = STATE::ATTACKA;
		m_bIsAttack = true;
		Attack();
		m_fAttackATime = 0.5f;
		if (BUTTONSTAY(VK_RIGHT))
		{
			// 앞으로 가면서 공격
			m_pRigid->SetDirectionX(+1);
			m_pRigid->PowerToX(4500.f);
			m_vecMoveDir.x = +1;
		}
		else if (BUTTONSTAY(VK_LEFT))
		{
			// 앞으로 가면서 공격
			m_pRigid->SetDirectionX(+1);
			m_pRigid->PowerToX(-4500.f);
			m_vecMoveDir.x = +1;
		}
	}






	if (BUTTONDOWN('Z') && m_fDashClock <= 0)
	{
		m_fDashClock = 0.3f;
	}
	if (m_fDashClock > 0)
	{
		m_fDashClock -= DT;
		m_bIsDash = true;
		m_pRigid->SetGravitySpeed(0);
		m_pRigid->PowerToX(m_vecLookDir.x * 500.f);
	}

	if (BUTTONSTAY('R'))
	{
		m_vecPos = Vector(100, 100);
	}

	if (BUTTONDOWN('C') && m_iJumpCount < 2)
	{
		
		m_bOverPeak = false;
		m_pRigid->PowerToY(-550.f);
		m_iJumpCount++;

		Logger::Debug(L"Jump!");
		if (m_iJumpCount == 2)
		{
			CSmoke* pSmoke = new CSmoke();
			pSmoke->SetPos(m_vecPos.x, m_vecPos.y);
			pSmoke->SetImgRate(1.2f);
			ADDOBJECT(pSmoke);
		}
	}

	if (m_pRigid->GetGroundCount() == 0 && m_pRigid->GetGravitySpeed() >= 0)
	{
		m_fFallTime += DT;
	}

	UpdateInState();

	AnimatorUpdate();
}

void CPlayer::Render()
{

	wstring groundCount = to_wstring(m_pRigid->GetGroundCount());

	RENDERMESSAGE(L"오른쪽 충돌 갯수: " + to_wstring(m_pRigid->m_arrCollisionCount[(int)Dir::RIGHT]));
	RENDERMESSAGE(L"왼쪽 충돌 갯수: " + to_wstring(m_pRigid->m_arrCollisionCount[(int)Dir::LEFT]));
	RENDERMESSAGE(L"플레이어 체력: " + to_wstring(m_iCurHp));
	RENDERMESSAGE(L"플레이어 상태: " + to_wstring((int)m_state));


	RENDERMESSAGE(to_wstring(GetCollider()->GetPos().y));

	RENDER->FillCircle(GetCollider()->GetPos().x, GetCollider()->GetPos().y, 5.f);


}

void CPlayer::Release()
{
}

void CPlayer::UpdateInState()
{
}

void CPlayer::AnimatorUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	wstring str = L"";

	if (m_bIsDash)
	{
		str += L"Dash";
		m_pAnimator->Play(str, false);
		return;
	}

	if (m_pRigid->GetGroundCount() == 0)
	{
		
		if (m_bIsAttack)
		{
			str += L"JumpAttack";
			m_pAnimator->Play(str, false);
			return;
		}

		if (m_pRigid->GetGravitySpeed() < 0)
		{
			str += L"Jump";
			m_pAnimator->Play(str, false);
			return;
		}
		//else if(!m_bOverPeak)
		else if(m_fFallTime <= 0.3f)
		{
			str += L"Fall";
			m_pAnimator->Play(str, false);
			//m_bOverPeak = true;				// 다 재생되고 바뀌어야 한다.
			return;
		}
		else
		{
			str += L"FallRepeat";
			m_pAnimator->Play(str, false);
			return;
		}
	}
	

	if (m_bIsAttack)
	{
		
		if (m_state == STATE::ATTACKA)
		{
			str += L"AttackA";
			m_pAnimator->Play(str, false);
			
			return;
		}
		else if(m_state == STATE::ATTACKB)
		{
			str += L"AttackB";
			m_pAnimator->Play(str, false);
			
			return;
		}
	}
		
	

	if (m_bIsMove)	str += L"Move";
	else			str += L"Idle";

	if (m_vecLookDir.x > 0) str += L"Right";
	else if (m_vecLookDir.x < 0) str += L"Left";

	if (m_vecLookDir.y > 0) str += L"Up";
	else if (m_vecLookDir.y < 0) str += L"Down";

	m_pAnimator->Play(str, false);
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
	pAttack->SetAttackDuration(0.8f);
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

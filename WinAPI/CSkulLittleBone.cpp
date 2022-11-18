#include "framework.h"
#include "CSkulLittleBone.h"

#include "CShootedHead.h"
#include "CRigidBody.h"

CSkulLittleBone::CSkulLittleBone()
{
	m_pHead = nullptr;

	m_pShootHead = nullptr;
	m_pHeadIsI = nullptr;


	m_pIdleHeadlessImage = nullptr;
	m_pMoveHeadlessImage = nullptr;
	m_pAttackHeadlessImage = nullptr;
	m_pAttackBHeadlessImage = nullptr;
	m_pJumpHeadlessImage = nullptr;
	m_pFallHeadlessImage = nullptr;
	m_pFallRepeatHeadlessImage = nullptr;
	m_pDashHeadlessImage = nullptr;
	m_pJumpAttackHeadlessImage = nullptr;
}

CSkulLittleBone::~CSkulLittleBone()
{
}

void CSkulLittleBone::Init()
{
	CPlayer::Init();

#pragma region Animation Setting
	m_pPortrait = RESOURCE->LoadImg(L"LittleBonePortrait", L"Image\\Skul.png");

	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\idle_skul.png");
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\move_skul.png");
	m_pAttackImage = RESOURCE->LoadImg(L"PlayerAttack", L"Image\\attackA_skul.png");
	m_pAttackBImage = RESOURCE->LoadImg(L"PlayerAttackB", L"Image\\attackB_skul.png");
	m_pJumpImage = RESOURCE->LoadImg(L"PlayerJump", L"Image\\jump_skul.png");
	m_pFallImage = RESOURCE->LoadImg(L"PlayerFall", L"Image\\fall_skul.png");
	m_pFallRepeatImage = RESOURCE->LoadImg(L"PlayerFallRepeat", L"Image\\fallrepeat_skul.png");
	m_pDashImage = RESOURCE->LoadImg(L"PlayerDash", L"Image\\dash_skul.png");
	m_pJumpAttackImage = RESOURCE->LoadImg(L"PlayerJumpAttack", L"Image\\jumpattack_skul.png");
	m_pShootHead = RESOURCE->LoadImg(L"PlayerSkillA", L"Image\\skillA_skul.png");
	m_pHeadIsI = RESOURCE->LoadImg(L"PlayerSkillB", L"Image\\skillB_skul.png");

	m_pIdleHeadlessImage = RESOURCE->LoadImg(L"PlayerIdle_Headless", L"Image\\idle_headless_skul.png");
	m_pMoveHeadlessImage = RESOURCE->LoadImg(L"PlayerMove_Headless", L"Image\\move_headless_skul.png");
	m_pAttackHeadlessImage = RESOURCE->LoadImg(L"PlayerAttack_Headless", L"Image\\attackA_headless_skul.png");
	m_pAttackBHeadlessImage = RESOURCE->LoadImg(L"PlayerAttackB_Headless", L"Image\\attackB_headless_skul.png");
	m_pJumpHeadlessImage = RESOURCE->LoadImg(L"PlayerJump_Headless", L"Image\\jump_headless_skul.png");
	m_pFallHeadlessImage = RESOURCE->LoadImg(L"PlayerFall_Headless", L"Image\\fall_headless_skul.png");
	m_pFallRepeatHeadlessImage = RESOURCE->LoadImg(L"PlayerFallRepeat_Headless", L"Image\\fallrepeat_headless_skul.png");
	m_pDashHeadlessImage = RESOURCE->LoadImg(L"PlayerDash_Headless", L"Image\\dash_headless_skul.png");
	m_pJumpAttackHeadlessImage = RESOURCE->LoadImg(L"PlayerJumpAttack_Headless", L"Image\\jumpattack_headless_skul.png");

	m_pAnimator->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"AttackA", m_pAttackImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"AttackB", m_pAttackBImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"Jump", m_pJumpImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"Fall", m_pFallImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"FallRepeat", m_pFallRepeatImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 3);
	m_pAnimator->CreateAnimation(L"Dash", m_pDashImage, Vector(0.f, 25.f), Vector(75.f, 50.f), Vector(96.f, 0.f), 0.15f, 1);
	m_pAnimator->CreateAnimation(L"JumpAttack", m_pJumpAttackImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"ShootHead", m_pShootHead, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"HeadIsI", m_pHeadIsI, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.05f, 9);

	m_pAnimator->CreateAnimation(L"IdleRight_Headless", m_pIdleHeadlessImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"IdleLeft_Headless", m_pIdleHeadlessImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
	m_pAnimator->CreateAnimation(L"MoveRight_Headless", m_pMoveHeadlessImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"MoveLeft_Headless", m_pMoveHeadlessImage, Vector(0.f, 20.f), Vector(80.f, 75.f), Vector(96.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"AttackA_Headless", m_pAttackHeadlessImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"AttackB_Headless", m_pAttackBHeadlessImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"Jump_Headless", m_pJumpHeadlessImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"Fall_Headless", m_pFallHeadlessImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 2);
	m_pAnimator->CreateAnimation(L"FallRepeat_Headless", m_pFallRepeatHeadlessImage, Vector(20.f, 25.f), Vector(50.f, 50.f), Vector(96.f, 0.f), 0.15f, 3);
	m_pAnimator->CreateAnimation(L"Dash_Headless", m_pDashHeadlessImage, Vector(0.f, 25.f), Vector(75.f, 50.f), Vector(96.f, 0.f), 0.15f, 1);
	m_pAnimator->CreateAnimation(L"JumpAttack_Headless", m_pJumpAttackHeadlessImage, Vector(0.f, 20.f), Vector(100.f, 75.f), Vector(96.f, 0.f), 0.1f, 4);
#pragma endregion

	m_pAnimator->Play(L"IdleRight", false);


	m_pHead = new CShootedHead;
	m_pHead->SetOwner(this);
	m_pHead->SetPos(GetPos());
	ADDOBJECT(m_pHead);

	SkillSetUp();
}

void CSkulLittleBone::Update()
{
	CPlayer::Update();

	//m_bHeadOn = m_pHead->GetHeadOn();
	/*if (!(m_pHead->GetHeadOn()))
	{
		m_vecHeadPos = m_pHead->GetPos();
	}*/

	if (m_pHead->GetHeadOn())				// �����ұ�?
	{
		skillHeadIsI.bCondition = false;
	}
	else
	{
		skillHeadIsI.bCondition = true;
	}
}

void CSkulLittleBone::SkillSetUp()
{
	//SkillInfo skillShootHead;
	skillShootHead.strName = L"�ΰ��� ��ô";
	skillShootHead.fCool = 6.f;
	skillShootHead.fCurCool = 0.f;
	skillShootHead.state = SKILL_STATE::READY;
	skillShootHead.strAniName = L"ShootHead";
	skillShootHead.fMotionTime = m_pAnimator->FindAnimation(L"ShootHead")->GetFullTime();		// nullptr�� ����?
		/* m_pAnimator->FindAnimation(L"ShootHead"); ���� duration�� count �� �����´�.*/
	skillShootHead.strDescription = L"�ڽ��� �Ӹ��� ���� ������������ �����ϴ�. \n���� �Ӹ��� ȸ���ϸ� ��Ÿ���� �ʱ�ȭ�˴ϴ�.";
	skillShootHead.bCondition = true;
	skillShootHead.pImg = RESOURCE->LoadImg(L"SkillShootHead", L"Image\\SkullThrowing.png");


	//SkillInfo skillHeadIsI;
	skillHeadIsI.strName = L"�Ӹ��� ��ü";
	skillHeadIsI.fCool = 3.f;
	skillHeadIsI.fCurCool = 0.f;
	skillHeadIsI.state = SKILL_STATE::COOLING;
	skillHeadIsI.strAniName = L"HeadIsI";
	skillHeadIsI.fMotionTime = m_pAnimator->FindAnimation(L"HeadIsI")->GetFullTime();
	skillHeadIsI.strDescription = L"�Ӹ��� ���� ������ �� �Ӹ��� �̵��մϴ�.";
	skillHeadIsI.bCondition = false;
	skillHeadIsI.pImg = RESOURCE->LoadImg(L"SkillHeadIsI", L"Image\\Rebone.png");


	m_skillA = &skillShootHead;		// ���� ���� (?)
	m_skillS = &skillHeadIsI;
}



void CSkulLittleBone::ReturnHead()
{
	m_pHead->HeadInit();
	m_skillA->ReadySkill();
}

void CSkulLittleBone::AnimatorUpdate()
{
	/*if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;*/

	wstring str = L"";


	switch (m_state)
	{
	case STATE::JUMPATTACK:
		str += L"JumpAttack";
		break;
	case STATE::ATTACKA:
		str += L"AttackA";
		break;
	case STATE::ATTACKB:
		str += L"AttackB";
		break;
	case STATE::DASH:
		str += L"Dash";
		break;
	case STATE::IDLE:
		str += L"Idle";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";
		break;
	case STATE::JUMP:
		str += L"Jump";
		break;
	case STATE::MOVE:
		str += L"Move";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";
		break;
	case STATE::FALL:
		if (m_fFallTime <= 0.3f)
			str += L"Fall";
		else
			str += L"FallRepeat";
		break;		
	case STATE::SKILLA:
		str += m_skillA->strAniName;
		m_pAnimator->Play(str, false);
		return;
	case STATE::SKILLS:
		str += m_skillS->strAniName;
		m_pAnimator->Play(str, false);
		return;

		
	}
	if (!(m_pHead->GetHeadOn()))
	{
		str += L"_Headless";
	}

	m_pAnimator->Play(str, false);
}



void CSkulLittleBone::SkillA()
{
	if (m_skillA->state == SKILL_STATE::READY)
	{
		Logger::Debug(L"��ų ���. �ٶ󺸴� ��: " + to_wstring(m_vecLookDir.x));
		//Logger::Debug(L"")
		m_pHead->GetRigidBody()->InitWallCollision();
		m_pHead->SetPos(GetPos() + Vector(m_vecLookDir.x * 10, -20));
		//m_pHead->GetRigidBody()->PowerToX(m_vecLookDir.x * 400.f);
		m_pHead->GetRigidBody()->SetVelocityX(m_vecLookDir.x * 400.f);
		m_pHead->SetAttackDuration(6.f);
		m_pRigid->SetGravitySpeed(0);
		//m_pHead->GetRigidBody()->

		m_pHead->SetHeadOn(false);
		m_skillA->UseSkill();

	}
	
	// ���� �Ŀ� ȸ��? SkillA�� ������ ������Ʈ�� ���¿� ���� ȸ��?		- ���߿� ��� ������ �Ǿ����� ã�Ⱑ ������?
	// �ƴϸ� ������ ���¸� ������Ʈ �� ��, ���ۿ� ���� ȸ��?
}

void CSkulLittleBone::SkillS()
{
	//if (m_skillS.state == SKILL_STATE::READY)
	{
		Logger::Debug(L"��ų ���S " + to_wstring(m_vecLookDir.x));
		// �Ӹ��� �÷��̾�� ���� ��츸.
		// �÷��̾� ���� �̵�
		// ���� �̵� �ִϸ��̼� ���
		if (!(m_pHead->GetHeadOn()))
		{
			//m_vecPos = m_vecHeadPos - Vector(0, m_vecScale.y);
			m_vecPos = m_pHead->GetPos();
			m_skillS->UseSkill();
			m_pRigid->SetGravitySpeed(0);
			ReturnHead();
		}
		
	}
}

//void CSkulLittleBone::SkillAction()
//{
//}



void CSkulLittleBone::Render()
{
	//RENDERMESSAGE(L" " + to_wstring(m_pRigid->m_arrCollisionCount[(int)Dir::Dow]));
	RENDERMESSAGE(L"���� �浹 ����: " + to_wstring(m_pHead->GetRigidBody()->m_arrCollisionCount[(int)Dir::LEFT]));
	RENDERMESSAGE(L"������ �浹 ����: " + to_wstring(m_pHead->GetRigidBody()->m_arrCollisionCount[(int)Dir::RIGHT]	));
	RENDERMESSAGE(L"���� �浹 ����: " + to_wstring(m_pHead->GetRigidBody()->m_arrCollisionCount[(int)Dir::UP]));
	RENDERMESSAGE(L"�Ʒ��� �浹 ����: " + to_wstring(m_pHead->GetRigidBody()->m_arrCollisionCount[(int)Dir::DOWN]));
	RENDERMESSAGE(L"���� �ӵ�: " + to_wstring(m_pHead->GetRigidBody()->m_arrDirSpeed[(int)Dir::LEFT]));
	RENDERMESSAGE(L"������ �ӵ�: " + to_wstring(m_pHead->GetRigidBody()->m_arrDirSpeed[(int)Dir::RIGHT]));
	RENDERMESSAGE(L"���� �ӵ�: " + to_wstring(m_pHead->GetRigidBody()->m_arrDirSpeed[(int)Dir::UP]));
	RENDERMESSAGE(L"�Ʒ��� �ӵ�: " + to_wstring(m_pHead->GetRigidBody()->m_arrDirSpeed[(int)Dir::DOWN]));
	RENDERMESSAGE(L"�Ӹ� ����: " + to_wstring(m_pHead->GetHeadOn()));




	CPlayer::Render();
	RENDER->Text(L"�÷��̾� ��ġ:" + to_wstring((int)GetPos().x) + L", " + to_wstring((int)GetPos().y), GetPos().x, GetPos().y + 90, GetPos().x + 200, GetPos().y + 190);
	RENDER->Text(L"�Ӹ� ����:" + to_wstring((int)m_pHead->GetHeadOn()), GetPos().x, GetPos().y + 100, GetPos().x + 100, GetPos().y + 200);
	RENDER->Text(L"�Ӹ� ��ġ:" + to_wstring((int)m_pHead->GetPos().x) + L", " + to_wstring((int)m_pHead->GetPos().y), GetPos().x, GetPos().y + 110, GetPos().x + 200, GetPos().y + 210);
	RENDER->Text(L"��ųA��:" + to_wstring((int)m_skillA->fCurCool), GetPos().x, GetPos().y + 120, GetPos().x + 100, GetPos().y + 220);
}

void CSkulLittleBone::Enter()
{
}

void CSkulLittleBone::Exit()
{
	ReturnHead();
	// ��Ÿ�ӵ� �ʱ�ȭ �Ǿ�� �ұ�?
	m_skillA->ReadySkill();
	m_skillS->ReadySkill();
	
}


void CSkulLittleBone::OnCollisionStay(CCollider* pOtherCollider)
{
	CPlayer::OnCollisionStay(pOtherCollider);

	if (pOtherCollider->GetObjName() == L"�� �ΰ���")
	{
		if (!(m_pHead->GetHeadOn()))
		{
			Logger::Debug(L"�ΰ��� ����");
			ReturnHead();
		}
	}
}

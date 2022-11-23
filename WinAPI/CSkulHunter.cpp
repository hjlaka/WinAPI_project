#include "framework.h"
#include "CSkulHunter.h"

CSkulHunter::CSkulHunter()
{
	m_skulType = SKUL_TYPE::HUNTER;
}

CSkulHunter::~CSkulHunter()
{
}

void CSkulHunter::Init()
{
	CPlayer::Init();

	m_pPortrait = RESOURCE->LoadImg(L"HunterPortrait", L"Image\\Hunter.png");

	m_pIdleImage = RESOURCE->LoadImg(L"HunterIdle", L"Image\\hunter_idle.png");
	m_pMoveImage = RESOURCE->LoadImg(L"HunterMove", L"Image\\hunter_move.png");

	m_pAnimator->CreateAnimation(L"Idle", m_pIdleImage, Vector(0.f, 10.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 7);
	m_pAnimator->CreateAnimation(L"Move", m_pMoveImage, Vector(0.f, 10.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.05f, 7);
	m_pAnimator->Play(L"Idle", false);

	SkillSetUp();
}

void CSkulHunter::Update()
{
	CPlayer::Update();
}

void CSkulHunter::AnimatorUpdate()
{

	m_pAnimator->SetFlip(m_vecLookDir.x == -1);			// 왼쪽을 바라보고 있다면 애니메이션 좌우 반전

	wstring str = L"";


	switch (m_state)
	{
	/*case STATE::JUMPATTACK:
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
		break;*/
	case STATE::IDLE:
		str += L"Idle";
		break;
	/*case STATE::JUMP:
		str += L"Jump";
		break;*/
	case STATE::MOVE:
		str += L"Move";
		break;
	/*case STATE::FALL:
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
	case STATE::DIE:
		str += L"Die";
		m_pAnimator->Play(str, false);
		return;*/
	default:
		str += L"Idle";
		break;

	}

	m_pAnimator->Play(str, false);
}

void CSkulHunter::SkillSetUp()
{
	ImmovableShot.strName = L"고정 사격";
	ImmovableShot.fCool = 16.f;
	ImmovableShot.fCurCool = 0.f;
	ImmovableShot.state = SKILL_STATE::READY;
	//ImmovableShot.strAniName = L"ShootHead";
	//ImmovableShot.fMotionTime = m_pAnimator->FindAnimation(L"ShootHead")->GetFullTime();
	ImmovableShot.strDescription = L"제자리에서 다수의 화살을 발사해 물리데미지를 입힙니다.";
	ImmovableShot.bCondition = true;
	ImmovableShot.pImg = RESOURCE->LoadImg(L"ImmovableShot", L"Image\\ImmovableShot.png");


	MultipleShot.strName = L"멀티플 샷";
	MultipleShot.fCool = 10.f;
	MultipleShot.fCurCool = 0.f;
	MultipleShot.state = SKILL_STATE::READY;
	//MultipleShot.strAniName = L"HeadIsI";
	//MultipleShot.fMotionTime = m_pAnimator->FindAnimation(L"HeadIsI")->GetFullTime();
	MultipleShot.strDescription = L"전방으로 다수의 화살을 발사해 물리데미지를 입힙니다.";
	MultipleShot.bCondition = true;
	MultipleShot.pImg = RESOURCE->LoadImg(L"MultipleShot", L"Image\\MultipleShot.png");

	SiegeShot.strName = L"시즈 샷";
	SiegeShot.fCool = 13.f;
	SiegeShot.fCurCool = 0.f;
	SiegeShot.state = SKILL_STATE::READY;
	//MultipleShot.strAniName = L"HeadIsI";
	//MultipleShot.fMotionTime = m_pAnimator->FindAnimation(L"HeadIsI")->GetFullTime();
	SiegeShot.strDescription = L"적을 관통하는 다수의 화살을 쏴올려 물리데미지를 입힙니다.";
	SiegeShot.bCondition = true;
	SiegeShot.pImg = RESOURCE->LoadImg(L"SiegeShot", L"Image\\SiegeShot.png");


	m_skillA = &ImmovableShot;		// 원본 복사 (?)
	m_skillS = &MultipleShot;
}

void CSkulHunter::SkillA()
{
}

void CSkulHunter::SkillS()
{
}

void CSkulHunter::Enter()
{
}

void CSkulHunter::Exit()
{
	CPlayer::Exit();
}



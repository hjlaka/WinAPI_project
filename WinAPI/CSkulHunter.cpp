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
	m_pAnimator->CreateAnimation(L"HunterIdleRight", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 7);
	m_pAnimator->Play(L"HunterIdleRight", false);

	SkillSetUp();
}

void CSkulHunter::Update()
{
	CPlayer::Update();
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
}



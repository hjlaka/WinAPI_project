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
	ImmovableShot.strName = L"���� ���";
	ImmovableShot.fCool = 16.f;
	ImmovableShot.fCurCool = 0.f;
	ImmovableShot.state = SKILL_STATE::READY;
	//ImmovableShot.strAniName = L"ShootHead";
	//ImmovableShot.fMotionTime = m_pAnimator->FindAnimation(L"ShootHead")->GetFullTime();
	ImmovableShot.strDescription = L"���ڸ����� �ټ��� ȭ���� �߻��� ������������ �����ϴ�.";
	ImmovableShot.bCondition = true;
	ImmovableShot.pImg = RESOURCE->LoadImg(L"ImmovableShot", L"Image\\ImmovableShot.png");


	MultipleShot.strName = L"��Ƽ�� ��";
	MultipleShot.fCool = 10.f;
	MultipleShot.fCurCool = 0.f;
	MultipleShot.state = SKILL_STATE::READY;
	//MultipleShot.strAniName = L"HeadIsI";
	//MultipleShot.fMotionTime = m_pAnimator->FindAnimation(L"HeadIsI")->GetFullTime();
	MultipleShot.strDescription = L"�������� �ټ��� ȭ���� �߻��� ������������ �����ϴ�.";
	MultipleShot.bCondition = true;
	MultipleShot.pImg = RESOURCE->LoadImg(L"MultipleShot", L"Image\\MultipleShot.png");

	SiegeShot.strName = L"���� ��";
	SiegeShot.fCool = 13.f;
	SiegeShot.fCurCool = 0.f;
	SiegeShot.state = SKILL_STATE::READY;
	//MultipleShot.strAniName = L"HeadIsI";
	//MultipleShot.fMotionTime = m_pAnimator->FindAnimation(L"HeadIsI")->GetFullTime();
	SiegeShot.strDescription = L"���� �����ϴ� �ټ��� ȭ���� ���÷� ������������ �����ϴ�.";
	SiegeShot.bCondition = true;
	SiegeShot.pImg = RESOURCE->LoadImg(L"SiegeShot", L"Image\\SiegeShot.png");


	m_skillA = &ImmovableShot;		// ���� ���� (?)
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



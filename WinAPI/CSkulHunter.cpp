#include "framework.h"
#include "CSkulHunter.h"

CSkulHunter::CSkulHunter()
{
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
}

void CSkulHunter::Update()
{
	CPlayer::Update();
}

void CSkulHunter::SkillSetUp()
{
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



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

	m_pIdleImage = RESOURCE->LoadImg(L"HunterIdle", L"Image\\PlayerIdle.png");
	m_pAnimator->CreateAnimation(L"HunterIdleRight", m_pIdleImage, Vector(0.f, 20.f), Vector(85.f, 75.f), Vector(96.f, 0.f), 0.5f, 4);
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



#include "framework.h"
#include "CSmoke.h"

CSmoke::CSmoke()
{
	
}

CSmoke::~CSmoke()
{
}

void CSmoke::Init()
{
	m_pEffectImage = RESOURCE->LoadImg(L"DoubleJump", L"Image\\DoubleJump_Smoke.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"DoubleJump", m_pEffectImage, Vector(0.f, 0.f), Vector(96.f, 100.f), Vector(96.f, 0.f), 0.05f, 10);
	m_pAnimator->Play(L"DoubleJump", false);
	SetImgRate(1.2f);
	AddComponent(m_pAnimator);

	m_fPlayTime = m_pAnimator->FindAnimation(L"DoubleJump")->GetFullTime();
}

void CSmoke::Update()
{
	if (m_fPlayTime <= 0) DELETEOBJECT(this);

	m_fPlayTime -= DT;
}

void CSmoke::Render()
{
}

void CSmoke::Release()
{
}

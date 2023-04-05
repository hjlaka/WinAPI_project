#include "framework.h"
#include "CDashSmoke.h"

CDashSmoke::CDashSmoke()
{

}

CDashSmoke::~CDashSmoke()
{
}

void CDashSmoke::Init()
{
	m_pEffectImage = RESOURCE->LoadImg(L"DashSmoke", L"Image\\dash_smoke_midium.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"DashSmoke", m_pEffectImage, Vector(0.f, 0.f), Vector(96.f, 100.f), Vector(96.f, 0.f), 0.05f, 24);
	m_pAnimator->Play(L"DashSmoke", false);
	SetImgRate(1.2f);
	AddComponent(m_pAnimator);

	m_fPlayTime = m_pAnimator->FindAnimation(L"DashSmoke")->GetFullTime();
}

void CDashSmoke::Update()
{
	if (m_fPlayTime <= 0) DELETEOBJECT(this);

	m_fPlayTime -= DT;
}

void CDashSmoke::Render()
{
}

void CDashSmoke::Release()
{
}

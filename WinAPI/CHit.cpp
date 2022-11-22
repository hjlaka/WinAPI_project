#include "framework.h"
#include "CHit.h"

CHit::CHit()
{
	
}



CHit::~CHit()
{
}

void CHit::Init()
{
	m_pEffectImage = RESOURCE->LoadImg(L"HitEffect", L"Image\\hit_effect.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Hit", m_pEffectImage, Vector(0.f, 0.f), Vector(196.f, 200.f), Vector(196.f, 0.f), 0.05f, 10);
	m_pAnimator->Play(L"Hit", false);
	SetImgRate(0.5f);
	AddComponent(m_pAnimator);

	m_pAnimator->SetFlip(m_vecDir.x == -1);
	m_fPlayTime = m_pAnimator->FindAnimation(L"Hit")->GetFullTime();
}

void CHit::Update()
{
	if (m_fPlayTime <= 0) DELETEOBJECT(this);

	m_fPlayTime -= DT;
}

void CHit::Render()
{
}

void CHit::Release()
{
}

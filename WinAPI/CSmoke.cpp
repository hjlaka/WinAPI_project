#include "framework.h"
#include "CSmoke.h"

CSmoke::CSmoke()
{
	m_pAnimator = nullptr;
	m_pSmokeImage = nullptr;
}

CSmoke::~CSmoke()
{
}

void CSmoke::Init()
{
	m_pSmokeImage = RESOURCE->LoadImg(L"DoubleJump", L"Image\\DoubleJump_Smoke.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"DoubleJump", m_pSmokeImage, Vector(0.f, 0.f), Vector(96.f, 100.f), Vector(96.f, 0.f), 0.05f, 10);

	auto end = [](DWORD_PTR pMe, DWORD_PTR pParam2)
	{
		CSmoke* pSmoke = (CSmoke*)pMe;
		DELETEOBJECT(pSmoke);
	};
	
	m_pAnimator->SetAnimationCallBack(L"DoubleJump", end, (DWORD_PTR)this, 0);


	m_pAnimator->Play(L"DoubleJump", false);
	AddComponent(m_pAnimator);

}

void CSmoke::Update()
{
}

void CSmoke::Render()
{
}

void CSmoke::Release()
{
}

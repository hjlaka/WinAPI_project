#include "framework.h"
#include "CGate.h"
#include "CAnimator.h"
#include "CCollider.h"

CGate::CGate()
{
	m_layer = Layer::Object;
	m_pAnimator = nullptr;
	m_bIsOpen = false;
}

CGate::~CGate()
{
}

void CGate::Init()
{
	m_pAnimator = new CAnimator;

	CImage* gateImg = RESOURCE->LoadImg(L"NormalGate", L"Image\\gate_normal.png");
	m_pAnimator->CreateAnimation(L"NormalGateClose", gateImg, Vector(0.f, 20.f), Vector(192.f, 150.f), Vector(192.f, 0.f), 0.5f, 1);
	m_pAnimator->CreateAnimation(L"NormalGateOpen", gateImg, Vector(192.f, 20.f), Vector(192.f, 150.f), Vector(192.f, 0.f), 0.1f, 8);

	m_pAnimator->Play(L"NormalGateOpen", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(250.f, 180.f), Vector(0, 0));
}

void CGate::Update()
{
}

void CGate::Render()
{
}

void CGate::Release()
{
}

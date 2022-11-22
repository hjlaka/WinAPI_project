#include "framework.h"
#include "CEffect.h"

CEffect::CEffect()
{
	m_pAnimator = nullptr;
	m_fPlayTime = 0;
	m_vecDir = Vector(1, 0);
	m_layer = Layer::Effect;
}


CEffect::~CEffect()
{
}

void CEffect::SetDir(Vector dir)
{
	m_vecDir = dir;
}

void CEffect::Init()
{

}

void CEffect::Update()
{

}

void CEffect::Render()
{
}

void CEffect::Release()
{
}

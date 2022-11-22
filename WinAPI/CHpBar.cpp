#include "framework.h"
#include "CHpBar.h"
#include "CUnit.h"

CHpBar::CHpBar()
{
	m_bIsVisible = true;
	m_vecPos = Vector(0,0);
	m_vecScale = Vector(80, 8);
	m_fHpRate = 1.f;

}

CHpBar::~CHpBar()
{
}

void CHpBar::SetVisible(bool isVisible)
{
	m_bIsVisible = isVisible;
}

void CHpBar::Init()
{
	m_pHpImage = RESOURCE->LoadImg(L"EnemyHp", L"Image\\EnemyHealthBar.png");
}

void CHpBar::Update()
{
	m_vecPos.x = GetOwner()->GetPos().x - m_vecScale.x * 0.5f;
	m_vecPos.y = GetOwner()->GetPos().y + GetOwner()->GetScale().y * 0.5f + 10.f;

	CUnit* pUnit = static_cast<CUnit*>(GetOwner());
	if (pUnit != nullptr)
	{
		m_fHpRate = (float)pUnit->GetCurHp() / pUnit->GetHp();
	}
	
}

void CHpBar::Render()
{
	if (m_bIsVisible)
	{
		RENDER->FillRect(
			m_vecPos.x,
			m_vecPos.y,
			m_vecPos.x + m_vecScale.x,
			m_vecPos.y + m_vecScale.y,
			Color(0, 0, 0, 1)
		);

		RENDER->Image(
			m_pHpImage,
			m_vecPos.x,
			m_vecPos.y,
			m_vecPos.x + (m_vecScale.x * m_fHpRate),
			m_vecPos.y + m_vecScale.y
		);
	}
}

void CHpBar::Release()
{
}

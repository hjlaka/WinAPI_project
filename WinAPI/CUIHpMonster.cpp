#include "framework.h"
#include "CUIHpMonster.h"

#include "CUnit.h"

CUIHpMonster::CUIHpMonster()
{
	m_layer = Layer::Ui;		// 인게임 유아이?
	m_bScreenFixed = false;
}

CUIHpMonster::~CUIHpMonster()
{
}

void CUIHpMonster::Init()
{
}


void CUIHpMonster::Update()
{
	if (nullptr != m_pOwner)
	{
		m_vecPos.x = m_pOwner->GetPos().x - GetScale().x / 2;
		m_vecPos.y = m_pOwner->GetPos().y + m_pOwner->GetScale().y / 2 + 10.f;

		m_fHpRate = (float)m_pOwner->GetCurHp() / m_pOwner->GetHp();
	}
}

void CUIHpMonster::Render()
{

	RENDER->FillRect(
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + (m_vecScale.x * m_fHpRate),
		m_vecRenderPos.y + m_vecScale.y,
		Color(0, 255, 0, 1)
	);


	RENDER->Text(to_wstring(m_pOwner->GetCurHp()),
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y);
}


void CUIHpMonster::Release()
{
}

void CUIHpMonster::OnMouseEnter()
{
}

void CUIHpMonster::OnMouseOver()
{
}

void CUIHpMonster::OnMouseExit()
{
}

void CUIHpMonster::OnMouseUp()
{
}

void CUIHpMonster::OnMouseDown()
{
}

void CUIHpMonster::OnMouseClicked()
{
}

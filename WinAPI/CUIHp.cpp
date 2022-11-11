#include "framework.h"
#include "CUIHp.h"

#include "CUnit.h"

CUIHp::CUIHp()
{
	//m_iHp = 0;
	//m_iCurHp = 0;
	m_layer = Layer::Ui;
	//m_bScreenFixed = true;
}

CUIHp::~CUIHp()
{
}

void CUIHp::SetOwner(CUnit* pOwner)
{
	m_pOwner = pOwner;
}

void CUIHp::Init()
{
}



void CUIHp::Update()
{
	if (!m_bScreenFixed && nullptr != m_pOwner)
	{
		m_vecPos.x = m_pOwner->GetPos().x - GetScale().x / 2;
		m_vecPos.y = m_pOwner->GetPos().y + m_pOwner->GetScale().y/2 + 10.f;
	}
}

void CUIHp::Render()
{
	RENDER->FillRect(
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y,
		Color(0, 255, 0, 1)
	);


	RENDER->Text(to_wstring(m_pOwner->GetCurHp()),
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y);
}

void CUIHp::Release()
{
}

void CUIHp::OnMouseEnter()
{
}

void CUIHp::OnMouseOver()
{
}

void CUIHp::OnMouseExit()
{
}

void CUIHp::OnMouseUp()
{
}

void CUIHp::OnMouseDown()
{
}

void CUIHp::OnMouseClicked()
{
}

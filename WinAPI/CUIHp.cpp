#include "framework.h"
#include "CUIHp.h"

#include "CUnit.h"

CUIHp::CUIHp()
{
	m_layer = Layer::Ui;
	m_fHpRate = 1.f;
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
	m_pImg = RESOURCE->LoadImg(L"PlayerHp", L"Image\\Player_HealthBar.png");
}



void CUIHp::Update()
{
	if (m_pOwner != nullptr)
	{
		m_fHpRate = (float)m_pOwner->GetCurHp() / m_pOwner->GetHp();
		if (m_fHpRate < 0) m_fHpRate = 0.f;
	}
}

void CUIHp::Render()
{
	int curHp = m_pOwner->GetCurHp();
	if (curHp < 0) curHp = 0;

	if (nullptr != m_pImg)
	{
		RENDER->Image(
			m_pImg,
			m_vecRenderPos.x,
			m_vecRenderPos.y,
			m_vecRenderPos.x + (m_vecScale.x * m_fHpRate),
			m_vecRenderPos.y + m_vecScale.y
		);
	}
	else
	{
		RENDER->FillRect(
			m_vecRenderPos.x,
			m_vecRenderPos.y,
			m_vecRenderPos.x + (m_vecScale.x * m_fHpRate),
			m_vecRenderPos.y + m_vecScale.y,
			Color(0, 255, 0, 1)
		);	
	}

	

	RENDER->Text(to_wstring(curHp) + L"/" + to_wstring(m_pOwner->GetHp()),
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

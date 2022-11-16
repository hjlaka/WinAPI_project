#include "framework.h"
#include "CUISkill.h"

CUISkill::CUISkill()
{
	m_pLinkedValue = nullptr;
}

CUISkill::~CUISkill()
{
}

void CUISkill::SetLinkedValue(const SkillInfo* skill)
{
	m_pLinkedValue = skill;
}

void CUISkill::Init()
{
}
void CUISkill::Update()
{
}

void CUISkill::Render()
{
	if (nullptr == m_pLinkedValue || SKILL_STATE::NONE == m_pLinkedValue->state)
		return;


	RENDER->FillRect(
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y,
		Color(0, 255, 0, 1)
	);


	RENDER->Text(to_wstring(m_pLinkedValue->fCurCool),
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y);
}



void CUISkill::Release()
{
}

void CUISkill::OnMouseEnter()
{
}

void CUISkill::OnMouseOver()
{
}

void CUISkill::OnMouseExit()
{
}

void CUISkill::OnMouseUp()
{
}

void CUISkill::OnMouseDown()
{
}

void CUISkill::OnMouseClicked()
{
}

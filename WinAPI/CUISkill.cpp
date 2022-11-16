#include "framework.h"
#include "CUISkill.h"

CUISkill::CUISkill()
{
	m_pLinkedSkill = nullptr;
}

CUISkill::~CUISkill()
{
}

void CUISkill::SetLinkedSkill(const SkillInfo* skill)
{
	m_pLinkedSkill = skill;
}

void CUISkill::Init()
{
}
void CUISkill::Update()
{
}

void CUISkill::Render()
{
	if (nullptr == m_pLinkedSkill || SKILL_STATE::NONE == m_pLinkedSkill->state)
		return;


	RENDER->FillRect(
		m_vecRenderPos.x,
		m_vecRenderPos.y,
		m_vecRenderPos.x + m_vecScale.x,
		m_vecRenderPos.y + m_vecScale.y,
		Color(0, 255, 0, 1)
	);


	RENDER->Text(to_wstring(m_pLinkedSkill->fCurCool),
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

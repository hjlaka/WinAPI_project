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

void CUIHpMonster::Render()
{
}

void CUIHpMonster::Update()
{
	if (nullptr != m_pOwner)
	{
		m_vecPos.x = m_pOwner->GetPos().x - GetScale().x / 2;
		m_vecPos.y = m_pOwner->GetPos().y + m_pOwner->GetScale().y / 2 + 10.f;
	}
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

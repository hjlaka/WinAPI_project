#include "framework.h"
#include "CUIFrame.h"

CUIFrame::CUIFrame()
{
	m_pImg = nullptr;
}

CUIFrame::~CUIFrame()
{
}

void CUIFrame::SetImage(CImage* pImg)
{
	m_pImg = pImg;
}

void CUIFrame::Init()
{
}

void CUIFrame::Render()
{
	if (nullptr != m_pImg)
	{
		RENDER->FrameImage(
			m_pImg,
			m_vecRenderPos.x - m_pImg->GetWidth() * 0.5f,
			m_vecRenderPos.y - m_pImg->GetHeight() * 0.5f,
			m_vecRenderPos.x + m_pImg->GetWidth() * 0.5f,
			m_vecRenderPos.y + m_pImg->GetHeight() * 0.5f,
			0,
			0,
			m_pImg->GetWidth(),
			m_pImg->GetHeight()
		);
	}
}

void CUIFrame::Update()
{
}

void CUIFrame::Release()
{
}

void CUIFrame::OnMouseEnter()
{
}

void CUIFrame::OnMouseOver()
{
}

void CUIFrame::OnMouseExit()
{
}

void CUIFrame::OnMouseUp()
{
}

void CUIFrame::OnMouseDown()
{
}

void CUIFrame::OnMouseClicked()
{
}

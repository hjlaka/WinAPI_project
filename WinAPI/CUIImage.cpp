#include "framework.h"
#include "CUIImage.h"

CUIImage::CUIImage()
{
}

CUIImage::~CUIImage()
{
}

void CUIImage::SetImage(CImage* pImg)
{
	m_pImg = pImg;
}

void CUIImage::Init()
{
}

void CUIImage::Render()
{
	if (nullptr != m_pImg)
	{
		RENDER->FrameImage(
			m_pImg,
			m_vecRenderPos.x - m_vecScale.x * 0.5f,
			m_vecRenderPos.y - m_vecScale.y * 0.5f,
			m_vecRenderPos.x + m_vecScale.x * 0.5f,
			m_vecRenderPos.y + m_vecScale.y * 0.5f,
			0,
			0,
			m_pImg->GetWidth(),
			m_pImg->GetHeight()
		);
	}
	else
	{
		RENDER->FillRect(
			m_vecRenderPos.x - m_vecScale.x * 0.5f,
			m_vecRenderPos.y - m_vecScale.y * 0.5f,
			m_vecRenderPos.x + m_vecScale.x * 0.5f,
			m_vecRenderPos.y + m_vecScale.y * 0.5f,
			Color(0, 255, 0, 1)
		);
	}
}

void CUIImage::Update()
{
}

void CUIImage::Release()
{
}

void CUIImage::OnMouseEnter()
{
}

void CUIImage::OnMouseOver()
{
}

void CUIImage::OnMouseExit()
{
}

void CUIImage::OnMouseUp()
{
}

void CUIImage::OnMouseDown()
{
}

void CUIImage::OnMouseClicked()
{
}

#include "framework.h"
#include "CBackGround.h"

CBackGround::CBackGround()
{
	m_vecPos = Vector(0, 0);

	m_pBGImg = nullptr;
}

CBackGround::~CBackGround()
{
}

void CBackGround::SetImage(CImage* bgImg)
{
	m_pBGImg = bgImg;
}

void CBackGround::Init()
{
}

void CBackGround::Update()
{
}

void CBackGround::Render()
{
	// 배경이미지 표현 갱신
	if (nullptr != m_pBGImg)
	{
		Vector pos = m_vecPos;	// 배경이 그려질 위치 확인

		// 배경 이미지 그리기
		RENDER->FrameImage(
			m_pBGImg,
			pos.x,
			pos.y,
			pos.x + m_pBGImg->GetWidth(),
			pos.y + m_pBGImg->GetHeight(),
			0,
			0,
			m_pBGImg->GetWidth(),
			m_pBGImg->GetHeight()
		);
	}
}

void CBackGround::Release()
{
}

#include "framework.h"
#include "CBackGround.h"

CBackGround::CBackGround()
{
	m_vecPos = Vector(0, 0);

	m_pBGImg = nullptr;

	m_fStartX = 0;
	m_fEndX = 0;
	m_fZPos = 0;
}

CBackGround::~CBackGround()
{
}

void CBackGround::SetImage(CImage* bgImg)
{
	m_pBGImg = bgImg;
	m_fStartX = m_vecPos.x;
	m_fEndX = m_vecPos.x + m_pBGImg->GetWidth();
}

void CBackGround::SetZPos(float zPos)
{
	m_fZPos = zPos;
}

float CBackGround::GetStartX()
{
	return m_fStartX;
}

float CBackGround::GetEndX()
{
	return m_fEndX;
}

void CBackGround::Init()
{
}

void CBackGround::Update()
{
	//Z값에 따라서 카메라와 함께 움직인다.

	if (m_pBGImg != nullptr && m_fZPos > 0)
	{
		m_vecPos = Vector(CAMERA->GetLookAt().x * m_fZPos, (m_vecPos.y + CAMERA->GetLookAt().y) * -0.001f) + Vector(WINSIZEX * -0.5f, WINSIZEY * 0.25f);
	}
	
}

void CBackGround::Render()
{


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

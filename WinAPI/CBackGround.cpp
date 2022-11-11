#include "framework.h"
#include "CBackGround.h"

CBackGround::CBackGround()
{
	m_vecPos = Vector(0, 0);

	m_pBGImg = nullptr;

	m_fStartX = 0;
	m_fEndX = 0;
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
}

void CBackGround::Render()
{
	// ����̹��� ǥ�� ����
	if (nullptr != m_pBGImg)
	{
		Vector pos = m_vecPos;	// ����� �׷��� ��ġ Ȯ��

		// ��� �̹��� �׸���
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

#include "framework.h"
#include "CAnimation.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CAnimator.h"
#include "CGameObject.h"

CAnimation::CAnimation()
{
	m_pAnimator = nullptr;

	m_strName = L"";
	m_pImage = nullptr;
	m_iCurFrame = 0;
	m_fAccTime = 0;
	m_bRepeat = true;

	m_pCallback = nullptr;
	m_pParam1 = 0;
	m_pParam2 = 0;

	m_fRate = 1.f;
	m_fduration = 0;
	m_uiFrameCount = 0;

	m_bFlip = false;

}

CAnimation::~CAnimation()
{
}

const wstring& CAnimation::GetName()
{
	return m_strName;
}

void CAnimation::SetLastCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2)
{
	m_pCallback = pCallback;
	m_pParam1 = pParam1;
	m_pParam2 = pParam2;
}

void CAnimation::RunCallback()
{
	m_pCallback(m_pParam1, m_pParam2);
}

float CAnimation::GetFullTime()
{
	return m_fduration * (float)m_uiFrameCount;
}

void CAnimation::SetFlip(bool flip)
{
	m_bFlip = flip;
}

void CAnimation::SetName(const wstring& name)
{
	m_strName = name;
}

void CAnimation::Create(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat)
{
	m_fduration = duration;	//������ ���� ���ӽð�
	m_uiFrameCount = count;	//������ ����

	m_pImage = pImg;	// ������ �̹����� ���ִ� �̹��� ����
	m_bRepeat = repeat;	// �ݺ�����

	// �ٵ��ǽ� ������ �̹����� ����ų ��ġ�� ����
	// lt		: ������ �̹����� ������� ��ǥ
	// step		: ������ �̹����� ����
	// slice	: ������ �̹����� ũ��
	// duration : ������ �̹����� ���ӽð�
	AniFrame frame;
	for (UINT i = 0; i < count; i++)
	{
		frame.lt = lt + step * i;
		frame.slice = slice;
		frame.duration = duration;

		m_vecFrame.push_back(frame);
	}

}

void CAnimation::Replay()
{
	// �ִϸ��̼� ����� : ���� �����Ӱ� �����ð��� �ʱ�ȭ
	m_iCurFrame = 0;
	m_fAccTime = 0;
}

void CAnimation::Init()
{
	
}

void CAnimation::Update()
{
	// ���� �÷������� �������� �����ð�
	m_fAccTime += DT;

	// �����ð��� ���� �÷������� �������� ���ӽð����� Ŀ���� ���
	// -> ���� �������� ������� �ϴ� ���
	if (m_vecFrame[m_iCurFrame].duration < m_fAccTime)
	{
		m_iCurFrame++;	// ���� �÷������� �������� �ε����� �ϳ� ����
		m_fAccTime = 0;	// ���� �÷������� �������� �����ð� �ʱ�ȭ

		// ���� �÷������� �������� ������ �������̾��� ���
		if (m_iCurFrame == m_vecFrame.size())
		{
			// �ݺ� �ִϸ��̼��̶�� ó������, �ƴ϶�� �������� �ٽ� ���
			if (m_bRepeat)	m_iCurFrame = 0;
			else			m_iCurFrame--;

			// ������ �����ӿ� ����� �ݹ� �Լ��� �ִٸ� ����
			if (nullptr != m_pCallback)
				m_pCallback(m_pParam1, m_pParam2);
		}
	}
}

void CAnimation::Render()
{
	Vector pos = m_pAnimator->GetOwner()->GetPos();	// �ִϸ��̼��� �׷��� ��ġ Ȯ��
	AniFrame frame = m_vecFrame[m_iCurFrame];		// �ִϸ��̼��� �׷��� ������ Ȯ��

	m_fRate = m_pAnimator->GetOwner()->GetImgRate();		// �̹��� ���ҽ� ����

	// ������ �̹��� �׸���
	RENDER->FrameImage(
		m_pImage,
		pos.x - frame.slice.x * 0.5f * m_fRate,
		pos.y - frame.slice.y * 0.5f * m_fRate,
		pos.x + frame.slice.x * 0.5f * m_fRate,
		pos.y + frame.slice.y * 0.5f * m_fRate,
		frame.lt.x,
		frame.lt.y,
		frame.lt.x + frame.slice.x,
		frame.lt.y + frame.slice.y,
		m_bFlip
	);
}

void CAnimation::Release()
{
}

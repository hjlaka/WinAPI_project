#pragma once

class CAnimator;
class CImage;

struct AniFrame
{
	Vector	lt;
	Vector	slice;
	float	duration;
};

typedef void(*CallbackFunc)(DWORD_PTR, DWORD_PTR);

class CAnimation
{
	friend CAnimator;
public:
	CAnimation();
	virtual ~CAnimation();

private:
	CAnimator*			m_pAnimator;	// 애니메이터

	wstring				m_strName;		// 애니메이션 이름
	CImage*				m_pImage;		// 애니메이션 이미지
	vector<AniFrame>	m_vecFrame;		// 애니메이션의 프레임 정보들
	UINT				m_iCurFrame;	// 현재 플레이중인 프레임의 인덱스
	float				m_fAccTime;		// 현재 플레이중인 프레임의 축적시간
	bool				m_bRepeat;		// 애니메이션의 반복 여부

	CallbackFunc		m_pCallback;		// 애니메이션 마지막에 들어갈 함수
	DWORD_PTR			m_pParam1;
	DWORD_PTR			m_pParam2;

	float				m_fRate;			// 이미지 배율

public:
	const wstring& GetName();

	void SetLastCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2);
	void RunCallback();

private:
	void SetName(const wstring& name);

	void Create(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat);	// 애니메이션 생성
	void Replay();	// 애니메이션 처음부터 다시 시작

private:
	void Init();
	void Update();
	void Render();
	void Release();
};

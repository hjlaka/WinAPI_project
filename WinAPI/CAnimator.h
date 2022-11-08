#pragma once
#include "CComponent.h"

class CAnimation;
class CImage;

typedef void(*CallbackFunc)(DWORD_PTR, DWORD_PTR);

class CAnimator : public CComponent
{
public:
	CAnimator();
	virtual ~CAnimator();

private:
	map<wstring, CAnimation*>	m_mapAni;	// 애니메이션들을 담기 위한 자료구조
	CAnimation* m_pCurAni;					// 현재 애니메이션

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

public:
	void CreateAnimation(const wstring& aniName, CImage* pImg,	// 애니메이션 생성
		Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat = true);
	void RemoveAnimation(const wstring& aniName);				// 애니메이션 삭제
	CAnimation* FindAnimation(const wstring& aniName);			// 애니메이션 탐색

	void SetAnimationCallBack(const wstring& aniName, CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2);

	void Play(const wstring& aniName, bool trigger = false);	// 애니메이션 재생
	void Stop();												// 애니메이션 종료
};


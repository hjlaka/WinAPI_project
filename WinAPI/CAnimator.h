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
	map<wstring, CAnimation*>	m_mapAni;	// �ִϸ��̼ǵ��� ��� ���� �ڷᱸ��
	CAnimation* m_pCurAni;					// ���� �ִϸ��̼�

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

public:
	void CreateAnimation(const wstring& aniName, CImage* pImg,	// �ִϸ��̼� ����
		Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat = true);
	void RemoveAnimation(const wstring& aniName);				// �ִϸ��̼� ����
	CAnimation* FindAnimation(const wstring& aniName);			// �ִϸ��̼� Ž��

	void SetAnimationCallBack(const wstring& aniName, CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2);

	void Play(const wstring& aniName, bool trigger = false);	// �ִϸ��̼� ���
	void Stop();												// �ִϸ��̼� ����
};


#pragma once

class CCore;

class CTimeManager : public SingleTon<CTimeManager>
{
	friend SingleTon<CTimeManager>;
	friend CCore;
private:
	CTimeManager();
	virtual ~CTimeManager();

	UINT	m_uiFPS;	// FPS : �ֻ���(������), 1�ʴ� �׷��� ȭ�� ��
	float	m_fDT;		// Delta Time : �����ð�, 1�����Ӵ� �ҿ�� �ð�

	float m_fTimeScale;		// �ð� �帣�� �ӵ�

	UINT	updateCount;
	float	updateOneSecond;
	chrono::high_resolution_clock::time_point prevTime;	// ������������ �ð�
	chrono::high_resolution_clock::time_point curTime;	// ������������ �ð�

	void Init();
	void Update();
	void Release();

public:
	UINT GetFPS();
	float GetDT();
	float GetScaledDT();
	void SetTimeScale(float scale);
};

#define	TIME		CTimeManager::GetInstance()
#define FPS			CTimeManager::GetInstance()->GetFPS()
#define DT			CTimeManager::GetInstance()->GetScaledDT()
#define NONSCALED_DT CTimeManager::GetInstance()->GetDT()

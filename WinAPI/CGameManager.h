#pragma once

class CPlayer;

class CCore;

class CGameManager : public SingleTon<CGameManager>
{
	friend CCore;
	friend SingleTon<CGameManager>;

private:
	CGameManager();
	virtual ~CGameManager();

public:
	CPlayer* m_pPlayer;
	float	m_fBGEndX;

public:
	CPlayer* GetPlayer();
	float GetBGEndX();
	void SetPlayer(CPlayer* player);
	void SetBGEndX(float endX);


private:
	void Init();
	void Release();

};

#define GAME CGameManager::GetInstance()


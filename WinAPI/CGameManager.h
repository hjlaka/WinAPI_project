#pragma once

class CPlayer;

class CCore;
class CMainUI;
class CUI;

class CGameManager : public SingleTon<CGameManager>
{
	friend CCore;
	friend SingleTon<CGameManager>;

private:
	CGameManager();
	virtual ~CGameManager();

private:
	CPlayer* m_pPlayer;
	CPlayer* m_pPlayer2;


	float	m_fBGEndX;
	CMainUI* m_pMainUI;

public:
	CPlayer* GetPlayer();
	float GetBGEndX();
	void SetPlayer(CPlayer* pPlayer);
	void SetPlayer(CPlayer* pPlayer, CPlayer* pPlayer2);
	void SetBGEndX(float endX);

	void AddToMainUI(CUI* pUI);


	void SwitchSkul();



private:
	void Init();
	void Release();

};

#define GAME CGameManager::GetInstance()
#define ADDMAINUI(pUI) CGameManager::GetInstance()->AddToMainUI(pUI);


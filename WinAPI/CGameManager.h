#pragma once

class CPlayer;

class CCore;
class CMainUI;
class CUI;
class CUIHp;
class CUISkill;

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


	float		m_fBGEndX;
	CMainUI*	m_pMainUI;
	//CUIHp*		pPlayerHpUI;
	//CUISkill*	pPlayerSkillAUI;
	//CUISkill*	pPlayerSkillSUI;


public:
	CPlayer* GetPlayer();
	float GetBGEndX();
	CMainUI* GetMainUI();


	void SetPlayer(CPlayer* pPlayer);
	void SetPlayer(CPlayer* pPlayer, CPlayer* pPlayer2);
	void SetBGEndX(float endX);
	void SetMainUI(CMainUI* pMainUI);

	void AddToMainUI(CUI* pUI);


	void SwitchSkul();
	void EnterSkul();



private:
	void Init();
	void Release();

};

#define GAME CGameManager::GetInstance()
#define ADDMAINUI(pUI) CGameManager::GetInstance()->AddToMainUI(pUI);


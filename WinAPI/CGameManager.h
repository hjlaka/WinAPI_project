#pragma once
#include "CPlayer.h"

class CPlayer;

class CCore;
class CMainUI;
class CUI;
class CUIHp;
class CUISkill;




struct PlayerInfo
{
	// 스컬 공통으로 공유할 플레이어 스탯
	SKUL_TYPE type1;
	SKUL_TYPE type2;

	int		m_iHp;			// 최대 Hp
	int		m_iCurHp;		// 현재 Hp

};

enum class GAME_STATUS {ACT, PAUSE};

class CGameManager : public SingleTon<CGameManager>
{
	friend CCore;
	friend SingleTon<CGameManager>;

private:
	CGameManager();
	virtual ~CGameManager();

private:

	GAME_STATUS m_gameStatus;

	CPlayer* m_pPlayer;
	CPlayer* m_pPlayer2;

	PlayerInfo m_playerInfo;


	float		m_fBGEndX;
	CMainUI*	m_pMainUI;


public:
	CPlayer* GetPlayer();
	float GetBGEndX();
	CMainUI* GetMainUI();
	GAME_STATUS GetGameStatue();

	void SavePlayerInfo();
	PlayerInfo& LoadPlayerInfo();
	CPlayer* CreateSkul();
	CPlayer* CreateSecondSkul();


	void SetPlayer(CPlayer* pPlayer);
	void SetPlayer(CPlayer* pPlayer, CPlayer* pPlayer2);
	void SetBGEndX(float endX);
	void SetMainUI(CMainUI* pMainUI);

	void AddToMainUI(CUI* pUI);

	void PauseGame();
	void ResumeGame();



	void SwitchSkul();
	void EnterSkul();



private:
	void Init();
	void Release();

};

#define GAME CGameManager::GetInstance()
#define ADDMAINUI(pUI) CGameManager::GetInstance()->AddToMainUI(pUI);


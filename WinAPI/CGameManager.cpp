#include "framework.h"
#include "CGameManager.h"

#include "CMainUI.h"
#include "CPlayer.h"

CGameManager::CGameManager()
{
	m_pPlayer = nullptr;
	m_pPlayer2 = nullptr;
}

CGameManager::~CGameManager()
{
}

CPlayer* CGameManager::GetPlayer()
{
	return m_pPlayer;
}

float CGameManager::GetBGEndX()
{
	return m_fBGEndX;
}

void CGameManager::SetPlayer(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CGameManager::SetPlayer(CPlayer* pPlayer, CPlayer* pPlayer2)
{
	m_pPlayer = pPlayer;
	m_pPlayer2 = pPlayer2;
}

void CGameManager::SetBGEndX(float bgEndX)
{
	m_fBGEndX = bgEndX;
}

void CGameManager::AddToMainUI(CUI* pUI)
{
	m_pMainUI->AddChildUI(pUI);
}

void CGameManager::SwitchSkul()
{
	if (nullptr == m_pPlayer2)
		return;

	m_pPlayer->Exit();
	DELETEOBJECT(m_pPlayer);
	ADDOBJECT(m_pPlayer2);
	m_pPlayer2->Enter();

	CPlayer* temp = m_pPlayer;
	m_pPlayer = m_pPlayer2;
	m_pPlayer2 = m_pPlayer;

}

void CGameManager::Init()
{
	m_pMainUI = new CMainUI;
}

void CGameManager::Release()
{
	if(m_pPlayer2 != nullptr)
		delete m_pPlayer2;
}

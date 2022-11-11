#include "framework.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
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

void CGameManager::SetPlayer(CPlayer* player)
{
	m_pPlayer = player;
}

void CGameManager::SetBGEndX(float bgEndX)
{
	m_fBGEndX = bgEndX;
}

void CGameManager::Init()
{
}

void CGameManager::Release()
{
}

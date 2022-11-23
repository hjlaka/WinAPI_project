#include "framework.h"
#include "CGameManager.h"

#include "CMainUI.h"
#include "CUIFrame.h"
#include "CUIHp.h"
#include "CUISkill.h"
#include "CUIImage.h"

#include "CSkulLittleBone.h"
#include "CSkulHunter.h"

CGameManager::CGameManager()
{
	m_pMainUI = nullptr;
	m_pPlayer = nullptr;
	m_pPlayer2 = nullptr;
	m_fBGEndX = 0;

	m_gameStatus = GAME_STATUS::ACT;

	m_fRenderRate = 1.f;

	m_bIsDebugMode = false;

}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	m_playerInfo.type1 = SKUL_TYPE::LITTLE_BONE;
	m_playerInfo.type2 = SKUL_TYPE::NONE;

}

void CGameManager::Update()
{
	if (BUTTONDOWN('B'))
	{
		m_bIsDebugMode = !m_bIsDebugMode;
	}
}

CPlayer* CGameManager::GetPlayer()
{
	return m_pPlayer;
}

float CGameManager::GetBGEndX()
{
	return m_fBGEndX;
}

CMainUI* CGameManager::GetMainUI()
{
	return m_pMainUI;
}

GAME_STATUS CGameManager::GetGameStatue()
{
	return m_gameStatus;
}

float CGameManager::GetRenderRate()
{
	return m_fRenderRate;
}

bool CGameManager::GetIsDebugMode()
{
	return m_bIsDebugMode;
}

void CGameManager::SavePlayerInfo()
{
	// 스컬 타입 저장
	m_playerInfo.type1 = m_pPlayer->m_skulType;
	m_playerInfo.type2 = m_pPlayer2->m_skulType;

	// 체력 저장
	m_playerInfo.m_iHp = m_pPlayer->m_iHp;
	m_playerInfo.m_iCurHp = m_pPlayer->m_iCurHp;
}

PlayerInfo& CGameManager::LoadPlayerInfo()
{
	return m_playerInfo;
}

CPlayer* CGameManager::CreateSkul()
{
	
	switch (m_playerInfo.type1)
	{
	case SKUL_TYPE::NONE:
		break;
	case SKUL_TYPE::LITTLE_BONE:
		m_pPlayer = new CSkulLittleBone;
		//ADDOBJECT(m_pPlayer);					// 한 프레임 뒤에 생성.
		break;
	case SKUL_TYPE::HUNTER:
		m_pPlayer = new CSkulHunter;
		break;
	}

	m_pPlayer->SetCurHp(m_playerInfo.m_iCurHp);

	return m_pPlayer;
}

CPlayer* CGameManager::CreateSecondSkul()
{
	switch (m_playerInfo.type2)
	{
	case SKUL_TYPE::NONE:
		break;
	case SKUL_TYPE::LITTLE_BONE:
		m_pPlayer2 = new CSkulLittleBone;
		break;
	case SKUL_TYPE::HUNTER:
		m_pPlayer2 = new CSkulHunter;
		break;
	}

	return m_pPlayer2;
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

void CGameManager::SetMainUI(CMainUI* pMainUI)
{
	m_pMainUI = pMainUI;
}

void CGameManager::AddToMainUI(CUI* pUI)
{
	m_pMainUI->AddChildUI(pUI);
}

void CGameManager::PauseGame()
{
	m_gameStatus = GAME_STATUS::PAUSE;
	CAMERA->FadeOut(2.f);
	CAMERA->HalfFadeOut(0.f, 1.f);
	TIME->SetTimeScale(0);
}

void CGameManager::ResumeGame()
{
	m_gameStatus = GAME_STATUS::ACT;
	TIME->SetTimeScale(1.f);
}

void CGameManager::SwitchSkul()
{
	if (nullptr == m_pPlayer2)
		return;

	m_pPlayer->Exit();
	m_pPlayer->SetIsActive(false);

	Vector playerPos = m_pPlayer->m_vecPos;

	//DELETEOBJECT(m_pPlayer);
	//ADDOBJECT(m_pPlayer2);
	m_pPlayer2->SetPos(playerPos);
	m_pPlayer2->SetCurHp(m_pPlayer->GetCurHp());
	m_pPlayer2->Enter();
	m_pPlayer2->SetIsActive(true);

	CPlayer* temp = m_pPlayer;
	m_pPlayer = m_pPlayer2;
	m_pPlayer2 = temp;

	LinkSkulToUI();

}

void CGameManager::LinkSkulToUI()
{
	//UI를 현재 스컬과 연결시킨다.

	if (nullptr == m_pPlayer)
		return;

	m_pMainUI->pPlayerPortrait->SetImage(m_pPlayer->m_pPortrait);
	m_pMainUI->pPlayerHpUI->SetOwner(m_pPlayer);
	m_pMainUI->pPlayerSkillAUI->SetLinkedSkill(m_pPlayer->GetSkillA());
	m_pMainUI->pPlayerSkillSUI->SetLinkedSkill(m_pPlayer->GetSkillS());
	
}



void CGameManager::Release()
{
	/*if(m_pPlayer2 != nullptr)
		delete m_pPlayer2;*/

	/*if (m_pMainUI != nullptr)
		delete m_pMainUI;*/
}

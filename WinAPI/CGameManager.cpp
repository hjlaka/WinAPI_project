#include "framework.h"
#include "CGameManager.h"

#include "CMainUI.h"
#include "CPlayer.h"
#include "CUIFrame.h"
#include "CUIHp.h"
#include "CUISkill.h"

CGameManager::CGameManager()
{
	m_pMainUI = nullptr;
	m_pPlayer = nullptr;
	m_pPlayer2 = nullptr;
	m_fBGEndX = 0;

	/*pPlayerHpUI = nullptr;
	pPlayerSkillAUI = nullptr;
	pPlayerSkillSUI = nullptr;*/
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
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

CMainUI* CGameManager::GetMainUI()
{
	return m_pMainUI;
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
	m_pPlayer2->Enter();
	m_pPlayer2->SetIsActive(true);

	CPlayer* temp = m_pPlayer;
	m_pPlayer = m_pPlayer2;
	m_pPlayer2 = temp;

	EnterSkul();

}

void CGameManager::EnterSkul()
{
	//UI를 현재 스컬과 연결시킨다.

	if (nullptr == m_pPlayer)
		return;

	m_pMainUI->pPlayerHpUI->SetOwner(m_pPlayer);
	m_pMainUI->pPlayerSkillAUI->SetLinkedSkill(m_pPlayer->GetSkillA());
	m_pMainUI->pPlayerSkillSUI->SetLinkedSkill(m_pPlayer->GetSkillS());

	//CAMERA->SetTargetPos(m_pPlayer->GetPos() + Vector(0, -100.f), .1f);

	
}



void CGameManager::Release()
{
	/*if(m_pPlayer2 != nullptr)
		delete m_pPlayer2;*/

	/*if (m_pMainUI != nullptr)
		delete m_pMainUI;*/
}

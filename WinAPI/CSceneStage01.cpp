#include "framework.h"
#include "CSceneStage01.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"
#include "CPathManager.h"

#include "CPlayer.h"
#include "CSkulLittleBone.h"
#include "CSkulHunter.h"
#include "CMonster01.h"
#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"
#include "CBackGround.h"

#include "CUIHp.h"
#include "CUIHpMonster.h"
#include "CUISkill.h"
#include "CUIFrame.h"

#include "CGameManager.h"
#include "Skill.h"
#include "CMainUI.h"

#include "CGate.h"

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	
}

void CSceneStage01::Enter()  
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage01.tile");
	
	// 게임 초기 설정
	CBackGround* pBG1 = new CBackGround;
	pBG1->SetImage(RESOURCE->LoadImg(L"BGStage01_1", L"Image\\stage01_1.png"));
	pBG1->SetPos(0, 0);
	pBG1->SetZPos(0.1f);
	AddGameObject(pBG1);

	CBackGround* pBG2 = new CBackGround;
	pBG2->SetImage(RESOURCE->LoadImg(L"BGStage01_2", L"Image\\stage01_2.png"));
	pBG2->SetPos(0, 0);
	pBG2->SetZPos(0.15f);
	AddGameObject(pBG2);

	CBackGround* pBG3 = new CBackGround;
	pBG3->SetImage(RESOURCE->LoadImg(L"BGStage01_3", L"Image\\stage01_3.png"));
	pBG3->SetPos(0, 0);
	pBG3->SetZPos(0.2f);
	AddGameObject(pBG3);

	CBackGround* pBG = new CBackGround;
	pBG->SetImage(RESOURCE->LoadImg(L"BGStage01", L"Image\\stage01_map.png"));
	pBG->SetPos(0, 0);
	AddGameObject(pBG);
	GAME->SetBGEndX(pBG->GetEndX());														// 배경 끝값 설정


	CMainUI* pMainUI = new CMainUI;
	GAME->SetMainUI(pMainUI);																// 메인 UI 생성
	AddGameObject(pMainUI);


	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	CAMERA->SetLookAt(Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));

	// 씬에 필요한 오브젝트 생성

	// 스컬 생성 - 게임 매니저가 저장된 값을 기반으로 스컬을 생성한 후 반환한다.

	CPlayer* pPlayer = GAME->CreateSkul();
	pPlayer->SetPos(200, 700);
	CPlayer* pPlayer2 = GAME->CreateSecondSkul();

	AddGameObject(pPlayer);

	if (pPlayer2 != nullptr)
	{
		pPlayer2->SetIsActive(false);
		AddGameObject(pPlayer2);
	}

	GAME->LinkSkulToUI();
	//pPlayer = new CSkulLittleBone;
	//pPlayer->SetPos(200, 700);
	////pPlayer->SetImgRate(1.2f);
	//AddGameObject(pPlayer);
	//GAME->SetPlayer(pPlayer);
	//pPlayer->SetIsActive(true);

	//GAME->LinkSkulToUI();

	//CPlayer* pPlayer2 = new CSkulHunter;
	//pPlayer2->SetPos(400, WINSIZEY * 0.5f);
	////pPlayer2->SetImgRate(1.2f);
	//GAME->SetPlayer(pPlayer, pPlayer2);
	//AddGameObject(pPlayer2);
	//pPlayer2->SetIsActive(false);

	CMonster01* pMonster = new CMonster01;
	pMonster->SetPos(900, 680);
	//pMonster->SetImgRate(1.2f);
	AddGameObject(pMonster);

	CGate* pGate = new CGate(GroupScene::Lobby);
	pGate->SetPos(2700, 1110 - 35);
	//pGate->SetImgRate(1.2f);
	AddGameObject(pGate);
	

}

void CSceneStage01::Update()
{
	if (BUTTONDOWN('1'))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}

	if (BUTTONDOWN('2'))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage02, 0.25f);
	}

	if (BUTTONDOWN(VK_ESCAPE))
	{
		if (GAME->GetGameStatue() == GAME_STATUS::ACT)
			GAME->PauseGame();
		else if (GAME->GetGameStatue() == GAME_STATUS::PAUSE)
			GAME->ResumeGame();
	}

	CAMERA->SetTargetPos(GAME->GetPlayer()->GetPos() + Vector(0, -100.f), .1f);

	if (BUTTONDOWN('W'))
	{
		GAME->SwitchSkul();
	}

	
}

void CSceneStage01::Render()
{

}

void CSceneStage01::Exit()
{
	// 플레이어 정보 저장
	GAME->SavePlayerInfo();

	// 현재씬에 추가된 오브젝트들 삭제.
	DeleteAll();

}

void CSceneStage01::Release()
{

}

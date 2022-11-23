#include "framework.h"
#include "CSceneLobby.h"
#include "CBackGround.h"
#include "CGameManager.h"
#include "CPlayer.h"
#include "CSkulLittleBone.h"
#include "CMainUI.h"
#include "CCameraController.h"
#include "CGate.h"

CSceneLobby::CSceneLobby()
{
}

CSceneLobby::~CSceneLobby()
{
}

void CSceneLobby::Init()
{
	

}

void CSceneLobby::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\StageLobby.tile");

	// 배경 이미지 추가
	CBackGround* pBG1 = new CBackGround;
	pBG1->SetImage(RESOURCE->LoadImg(L"BGStage01_1", L"Image\\stage01_1.png"));
	pBG1->SetPos(0, 1000);
	pBG1->SetZPos(0.1f);
	AddGameObject(pBG1);

	CBackGround* pBG2 = new CBackGround;
	pBG2->SetImage(RESOURCE->LoadImg(L"BGStage01_2", L"Image\\stage01_2.png"));
	pBG2->SetPos(0, 1000);
	pBG2->SetZPos(0.15f);
	AddGameObject(pBG2);

	CBackGround* pBG3 = new CBackGround;
	pBG3->SetImage(RESOURCE->LoadImg(L"BGStage01_3", L"Image\\stage01_3.png"));
	pBG3->SetPos(0, 1000);
	pBG3->SetZPos(0.2f);
	AddGameObject(pBG3);

	CBackGround* pBG = new CBackGround;
	pBG->SetImage(RESOURCE->LoadImg(L"BGStageLobby", L"Image\\stageLobby_outer.png"));
	pBG->SetPos(0, 0);
	AddGameObject(pBG);
	GAME->SetBGEndX(pBG->GetEndX());


	// 메인 UI 생성

	CMainUI* pMainUI = new CMainUI;
	GAME->SetMainUI(pMainUI);																
	AddGameObject(pMainUI);


	CAMERA->SetLookAt(Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));

	// 스컬 생성 - 게임 매니저가 저장된 값을 기반으로 스컬을 생성한 후 반환한다.

	CPlayer* pPlayer = GAME->CreateSkul();
	pPlayer->SetPos(100, 100);
	CPlayer* pPlayer2 = GAME->CreateSecondSkul();

	AddGameObject(pPlayer);

	if (pPlayer2 != nullptr)
	{
		pPlayer2->SetIsActive(false);
		AddGameObject(pPlayer2);
	}
	
	GAME->LinkSkulToUI();


	// 문 생성

	CGate* pGate = new CGate(GroupScene::Stage01);
	pGate->SetPos(1400, 600 - 35);
	AddGameObject(pGate);
}

void CSceneLobby::Update()
{
	if (BUTTONDOWN('1'))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
	// 스컬 변경
	if (BUTTONDOWN(VK_SPACE))
	{
		GAME->SwitchSkul();
	}
	CAMERA->SetTargetPos(GAME->GetPlayer()->GetPos() + Vector(0, -100.f), .1f);
}

void CSceneLobby::Render()
{
}

void CSceneLobby::Exit()
{
	// 플레이어 정보 저장
	GAME->SavePlayerInfo();

	// 현재씬에 추가된 오브젝트들 삭제.
	DeleteAll();
}

void CSceneLobby::Release()
{
}

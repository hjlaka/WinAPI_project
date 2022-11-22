#include "framework.h"
#include "CSceneStage02.h"
#include "CBackGround.h"
#include "CGameManager.h"
#include "CPlayer.h"
#include "CSkulLittleBone.h"
#include "CMainUI.h"
#include "CCameraController.h"

CSceneStage02::CSceneStage02()
{
}

CSceneStage02::~CSceneStage02()
{
}

void CSceneStage02::Init()
{
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
	pBG->SetImage(RESOURCE->LoadImg(L"BGStage02", L"Image\\stage02_map.png"));
	pBG->SetPos(0, 0);
	AddGameObject(pBG);
	GAME->SetBGEndX(pBG->GetEndX());






}

void CSceneStage02::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage02.tile");

	CMainUI* pMainUI = new CMainUI;
	GAME->SetMainUI(pMainUI);																// 메인 UI 생성
	AddGameObject(pMainUI);


	// 스컬 생성 - 게임 매니저가 저장된 값을 기반으로 스컬을 생성한 후 반환한다.

	CPlayer* pPlayer = GAME->CreateSkul();
	CPlayer* pPlayer2 = GAME->CreateSecondSkul();
	pPlayer2->SetIsActive(false);

	AddGameObject(pPlayer);
	AddGameObject(pPlayer2);
		

	GAME->EnterSkul();
}

void CSceneStage02::Update()
{
	if (BUTTONDOWN('1'))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
	if (BUTTONDOWN('W'))
	{
		GAME->SwitchSkul();
	}
	CAMERA->SetTargetPos(GAME->GetPlayer()->GetPos() + Vector(0, -100.f), .1f);
}

void CSceneStage02::Render()
{
}

void CSceneStage02::Exit()
{
}

void CSceneStage02::Release()
{
}

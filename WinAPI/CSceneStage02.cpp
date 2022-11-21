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
	GAME->SetBGEndX(pBG->GetEndX());






}

void CSceneStage02::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage02.tile");

	CMainUI* pMainUI = new CMainUI;
	GAME->SetMainUI(pMainUI);																// 메인 UI 생성
	AddGameObject(pMainUI);


	CPlayer* pPlayer = new CSkulLittleBone;
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	pPlayer->SetImgRate(1.2f);
	AddGameObject(pPlayer);
	GAME->SetPlayer(pPlayer);
	pPlayer->SetIsActive(true);

	GAME->EnterSkul();
}

void CSceneStage02::Update()
{
	if (BUTTONDOWN('1'))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
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

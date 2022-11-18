#include "framework.h"
#include "CSceneStage02.h"
#include "CBackGround.h"
#include "CGameManager.h"
#include "CPlayer.h"

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
	LoadTile(GETPATH + L"Tile\\Stage01.tile");

	CPlayer* pPlayer = GAME->GetPlayer();
	pPlayer->SetPos(100, 100);
	AddGameObject(pPlayer);
}

void CSceneStage02::Update()
{
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

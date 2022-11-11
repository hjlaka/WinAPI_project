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
#include "CMonster01.h"
#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"
#include "CBackGround.h"

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	CBackGround* pBG = new CBackGround;
	pBG->SetImage(RESOURCE->LoadImg(L"BGStage01", L"Image\\stage01_map.png"));
	pBG->SetPos(0, 0);
	AddGameObject(pBG);

	pPlayer = new CPlayer();
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	pPlayer->SetImgRate(1.5f);
	AddGameObject(pPlayer);

	CMonster01* pMonster = new CMonster01();
	pMonster->SetPos(900, WINSIZEY * 0.2f);
	AddGameObject(pMonster);

	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

	
	
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage01.tile");	
	//LoadBackGroundImage(GETPATH + L"Stage01_map.png");
	

	CAMERA->SetTargetObj(pPlayer);
}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneStage01::Render()
{
	//// 배경이미지 표현 갱신
	//if (nullptr != m_pBGImg)
	//{
	//	Logger::Debug(L"배경이미지 그리기 진입");
	//	Vector pos = CAMERA->WorldToScreenPoint(Vector(0, 0));	// 배경이 그려질 위치 확인

	//	// 배경 이미지 그리기
	//	RENDER->FrameImage(
	//		m_pBGImg,
	//		pos.x,
	//		pos.y,
	//		pos.x + m_pBGImg->GetWidth(),
	//		pos.y + m_pBGImg->GetHeight(),
	//		0,
	//		0,
	//		m_pBGImg->GetWidth(),
	//		m_pBGImg->GetHeight()
	//	);
	//}
}

void CSceneStage01::Exit()
{
}

void CSceneStage01::Release()
{
}

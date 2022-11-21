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



	



	
	
}

void CSceneStage01::Enter()  
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage01.tile");
	//LoadBackGroundImage(GETPATH + L"Stage01_map.png");


	//CAMERA->SetTargetObj(pPlayer);
	
	// 씬에 필요한 오브젝트 생성
	pPlayer = new CSkulLittleBone;
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	pPlayer->SetImgRate(1.2f);
	AddGameObject(pPlayer);
	GAME->SetPlayer(pPlayer);
	pPlayer->SetIsActive(true);

	GAME->EnterSkul();

	CPlayer* pPlayer2 = new CSkulHunter;
	pPlayer2->SetPos(400, WINSIZEY * 0.5f);
	pPlayer2->SetImgRate(1.2f);
	GAME->SetPlayer(pPlayer, pPlayer2);
	AddGameObject(pPlayer2);
	pPlayer2->SetIsActive(false);

	CMonster01* pMonster = new CMonster01;
	pMonster->SetPos(900, WINSIZEY * 0.2f);
	pMonster->SetImgRate(1.2f);
	AddGameObject(pMonster);

	CGate* pGate = new CGate;
	pGate->SetPos(2100, 1250);
	pGate->SetImgRate(1.2f);
	AddGameObject(pGate);

	

	/*CUIFrame* pPlayerUI = new CUIFrame;
	CImage* pPlayerFrameImg = RESOURCE->LoadImg(L"PlayerFrame", L"Image\\Player_Normal_Frame.png");
	pPlayerFrameImg->SetImageRate(2.f);
	pPlayerUI->SetImage(pPlayerFrameImg);
	pPlayerUI->SetPos(180.f, 650.f);
	pPlayerUI->SetScale(Vector(300.f, 100.f));
	AddGameObject(pPlayerUI);*/

	/*CUIHpMonster* pMonsterUI = new CUIHpMonster;
	pMonsterUI->SetOwner(pMonster);
	pMonsterUI->SetScale(Vector(80.f, 10.f));
	AddGameObject(pMonsterUI);*/

	

	


	

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
	// 플레이어 정보 저장
	GAME->SavePlayerInfo();

	// 현재씬에 추가된 오브젝트들 삭제.
	DeleteAll();

}

void CSceneStage01::Release()
{

}

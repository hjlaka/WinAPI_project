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

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
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

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\Stage01.tile");
	//LoadBackGroundImage(GETPATH + L"Stage01_map.png");


	//CAMERA->SetTargetObj(pPlayer);
	
	pPlayer = new CSkulLittleBone;
	pPlayer->SetPos(200, WINSIZEY * 0.5f);
	pPlayer->SetImgRate(1.2f);
	AddGameObject(pPlayer);
	GAME->SetPlayer(pPlayer);

	CPlayer* pPlayer2 = new CSkulHunter;
	pPlayer2->SetPos(400, WINSIZEY * 0.5f);
	pPlayer2->SetImgRate(1.2f);
	GAME->SetPlayer(pPlayer, pPlayer2);

	CMonster01* pMonster = new CMonster01;
	pMonster->SetPos(900, WINSIZEY * 0.2f);
	pMonster->SetImgRate(1.2f);
	AddGameObject(pMonster);


	CUIFrame* pPlayerUI = new CUIFrame;
	CImage* pPlayerFrameImg = RESOURCE->LoadImg(L"PlayerFrame", L"Image\\Player_Normal_Frame.png");
	pPlayerFrameImg->SetImageRate(2.f);
	pPlayerUI->SetImage(pPlayerFrameImg);
	pPlayerUI->SetPos(180.f, 650.f);
	pPlayerUI->SetScale(Vector(300.f, 100.f));
	AddGameObject(pPlayerUI);

	CUIHpMonster* pMonsterUI = new CUIHpMonster;
	pMonsterUI->SetOwner(pMonster);
	pMonsterUI->SetScale(Vector(80.f, 10.f));
	AddGameObject(pMonsterUI);

	CUIHp* pPlayerHpUI = new CUIHp;
	pPlayerHpUI->SetPos(-60.f, 25.f);
	pPlayerHpUI->SetOwner(pPlayer);
	pPlayerHpUI->SetScale(Vector(250.f, 30.f));
	pPlayerUI->AddChildUI(pPlayerHpUI);
	//AddGameObject(pPlayerHpUI);

	

	CUISkill* pPlayerSkillAUI = new CUISkill;
	pPlayerSkillAUI->SetPos(-50.f, 30.f);
	pPlayerSkillAUI->SetScale(Vector(50.f, -50.f));
	pPlayerSkillAUI->SetLinkedSkill(pPlayer->GetSkillA());
	pPlayerUI->AddChildUI(pPlayerSkillAUI);
	//AddGameObject(pPlayerSkillAUI);

	CUISkill* pPlayerSkillSUI = new CUISkill;
	pPlayerSkillSUI->SetPos(0.f, 30.f);
	pPlayerSkillSUI->SetScale(Vector(50.f, -50.f));
	pPlayerSkillSUI->SetLinkedSkill(pPlayer->GetSkillS());
	pPlayerUI->AddChildUI(pPlayerSkillSUI);
	//AddGameObject(pPlayerSkillSUI);

	


	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);

}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}

	CAMERA->SetTargetPos(GAME->GetPlayer()->GetPos() + Vector(0, -100.f), .1f);

	
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

	// 현재씬에 추가된 오브젝트들 삭제.

	DeleteAll();

}

void CSceneStage01::Release()
{
}

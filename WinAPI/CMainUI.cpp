#include "framework.h"
#include "CMainUI.h"
#include "CUIFrame.h"
#include "CUIHp.h"
#include "CUISkill.h"
#include "CUIImage.h"

CMainUI::CMainUI()
{
	pPlayerPortrait = nullptr;
	pPlayerHpUI = nullptr;
	pPlayerSkillAUI = nullptr;
	pPlayerSkillSUI = nullptr;
	pPlayer2Portrait = nullptr;
	pPlayer2SkillAUI = nullptr;
	pPlayer2SkillSUI = nullptr;
}

CMainUI::~CMainUI()
{
}

void CMainUI::Init()
{

	CUIFrame* pPlayerUI = new CUIFrame;
	CImage* pPlayerFrameImg = RESOURCE->LoadImg(L"PlayerFrame", L"Image\\Player_Normal_Frame.png");
	pPlayerFrameImg->SetImageRate(2.f);
	pPlayerUI->SetImage(pPlayerFrameImg);
	pPlayerUI->SetPos(180.f, 650.f);
	pPlayerUI->SetScale(Vector(300.f, 100.f));
	AddChildUI(pPlayerUI);

	pPlayerSkill2Frame = new CUIFrame;
	CImage* pPlayerSkill2FrameImg = RESOURCE->LoadImg(L"PlayerSkillFrame", L"Image\\Player_Skill2_Frame.png");
	pPlayerSkill2FrameImg->SetImageRate(2.f);
	pPlayerSkill2Frame->SetImage(pPlayerSkill2FrameImg);
	pPlayerSkill2Frame->SetPos(30.f, -10.f);
	pPlayerSkill2Frame->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayerSkill2Frame);




		


	// 이미지
	pPlayerPortrait = new CUIImage;
	pPlayerPortrait->SetPos(-110.f, -20.f);
	pPlayerPortrait->SetScale(Vector(90.f, 90.f));
	pPlayerUI->AddChildUI(pPlayerPortrait);

	pPlayerHpUI = new CUIHp;
	pPlayerHpUI->SetPos(-81.f, 22.f);
	pPlayerHpUI->SetScale(Vector(234.f, 20.f));
	pPlayerUI->AddChildUI(pPlayerHpUI);
	//AddGameObject(pPlayerHpUI);

	pPlayerSkillAUI = new CUISkill;
	pPlayerSkillAUI->SetPos(-53.f, -37.f);
	pPlayerSkillAUI->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayerSkillAUI);
	//AddGameObject(pPlayerSkillAUI);

	pPlayerSkillSUI = new CUISkill;
	pPlayerSkillSUI->SetPos(7.f, -37.f);
	pPlayerSkillSUI->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayerSkillSUI);
	//AddGameObject(pPlayerSkillSUI);


	// 서브 스컬 프레임

	pPlayer2PortraitFrame = new CUIFrame;
	CImage* tempImg = RESOURCE->LoadImg(L"SubPlayerPortraitFrame", L"Image\\Player_Subskull_Frame.png");
	tempImg->SetImageRate(2.f);
	pPlayer2PortraitFrame->SetImage(tempImg);
	pPlayer2PortraitFrame->SetPos(-136.f, 30.f);
	pPlayer2PortraitFrame->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayer2PortraitFrame);

	pPlayer2SkillAUIFrame = new CUIFrame;
	tempImg = RESOURCE->LoadImg(L"SubPlayerSkillAFrame", L"Image\\Player_Subskill1_Frame.png");
	tempImg->SetImageRate(2.f);
	pPlayer2SkillAUIFrame->SetImage(tempImg);
	pPlayer2SkillAUIFrame->SetPos(90.f, -5.f);
	pPlayer2SkillAUIFrame->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayer2SkillAUIFrame);

	pPlayer2SkillSUIFrame = new CUIFrame;
	tempImg = RESOURCE->LoadImg(L"SubPlayerSkillSFrame", L"Image\\Player_Subskill2_Frame.png");
	tempImg->SetImageRate(2.f);
	pPlayer2SkillSUIFrame->SetImage(tempImg);
	pPlayer2SkillSUIFrame->SetPos(130.f, -5.f);
	pPlayer2SkillSUIFrame->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayer2SkillSUIFrame);

	// 서브 스컬 이미지
	pPlayer2Portrait = new CUIImage;
	pPlayer2Portrait->SetPos(-135.f, 28.f);
	pPlayer2Portrait->SetScale(Vector(40.f, 40.f));
	pPlayerUI->AddChildUI(pPlayer2Portrait);


	pPlayer2SkillAUI = new CUISkill;
	pPlayer2SkillAUI->SetPos(-53.f, -37.f);
	pPlayer2SkillAUI->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayer2SkillAUI);
	//AddGameObject(pPlayerSkillAUI);

	pPlayer2SkillSUI = new CUISkill;
	pPlayer2SkillSUI->SetPos(7.f, -37.f);
	pPlayer2SkillSUI->SetScale(Vector(50.f, 50.f));
	pPlayerUI->AddChildUI(pPlayer2SkillSUI);
	//AddGameObject(pPlayerSkillSUI);

	pPlayer2SkillAUI->SetIsActive(false);
	pPlayer2SkillSUI->SetIsActive(false);

}

void CMainUI::Render()
{
}

void CMainUI::Update()
{
}

void CMainUI::Release()
{
}

void CMainUI::OnMouseEnter()
{
}

void CMainUI::OnMouseOver()
{
}

void CMainUI::OnMouseExit()
{
}

void CMainUI::OnMouseUp()
{
}

void CMainUI::OnMouseDown()
{
}

void CMainUI::OnMouseClicked()
{
}

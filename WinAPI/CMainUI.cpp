#include "framework.h"
#include "CMainUI.h"
#include "CUIFrame.h"
#include "CUIHp.h"
#include "CUISkill.h"
#include "CUIImage.h"

CMainUI::CMainUI()
{
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

	pPlayerPortrait = new CUIImage;
	pPlayerPortrait->SetPos(-110.f, -20.f);
	pPlayerPortrait->SetScale(Vector(80.f, 80.f));
	pPlayerUI->AddChildUI(pPlayerPortrait);

	pPlayerHpUI = new CUIHp;
	pPlayerHpUI->SetPos(-81.f, 22.f);
	pPlayerHpUI->SetScale(Vector(234.f, 20.f));
	pPlayerUI->AddChildUI(pPlayerHpUI);
	//AddGameObject(pPlayerHpUI);

	pPlayerSkillAUI = new CUISkill;
	pPlayerSkillAUI->SetPos(-50.f, 10.f);
	pPlayerSkillAUI->SetScale(Vector(50.f, -50.f));
	pPlayerUI->AddChildUI(pPlayerSkillAUI);
	//AddGameObject(pPlayerSkillAUI);

	pPlayerSkillSUI = new CUISkill;
	pPlayerSkillSUI->SetPos(10.f, 10.f);
	pPlayerSkillSUI->SetScale(Vector(50.f, -50.f));
	pPlayerUI->AddChildUI(pPlayerSkillSUI);
	//AddGameObject(pPlayerSkillSUI);
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

#include "framework.h"
#include "CMainUI.h"
#include "CUIFrame.h"
#include "CUIHp.h"
#include "CUISkill.h"

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

	pPlayerHpUI = new CUIHp;
	pPlayerHpUI->SetPos(-80.f, 20.f);
	pPlayerHpUI->SetScale(Vector(200.f, 25.f));
	pPlayerUI->AddChildUI(pPlayerHpUI);
	//AddGameObject(pPlayerHpUI);

	pPlayerSkillAUI = new CUISkill;
	pPlayerSkillAUI->SetPos(-50.f, 30.f);
	pPlayerSkillAUI->SetScale(Vector(50.f, -50.f));
	pPlayerUI->AddChildUI(pPlayerSkillAUI);
	//AddGameObject(pPlayerSkillAUI);

	pPlayerSkillSUI = new CUISkill;
	pPlayerSkillSUI->SetPos(0.f, 30.f);
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

#include "framework.h"
#include "CSceneTitle.h"

#include "WinAPI.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"

CSceneTitle::CSceneTitle()
{
	m_pBGImg = nullptr;
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{
	m_pBGImg = RESOURCE->LoadImg(L"TitileBackGround", L"Image\\Title_Art.png");
	m_pLogoImg = RESOURCE->LoadImg(L"TitileLogo", L"Image\\Title_Logo.png");
	m_pTextImg = RESOURCE->LoadImg(L"TitileText", L"Image\\title_text.png");
}

void CSceneTitle::Enter()
{
	CAMERA->FadeIn(0.25f);
}

void CSceneTitle::Update()
{
	if (BUTTONDOWN(VK_F1))
	{
		CHANGESCENE(GroupScene::TileTool);
	}
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Lobby, 0.25f);
	}
}

void CSceneTitle::Render()
{
	RENDER->Image(m_pBGImg,
		0,
		0,
		WINSIZEX,
		WINSIZEY);

	RENDER->Image(
		m_pLogoImg,
		WINSIZEX * 0.5f - m_pLogoImg->GetWidth() * 0.5f,
		WINSIZEY * 0.5f - m_pLogoImg->GetHeight() * 0.5f,
		WINSIZEX * 0.5f + m_pLogoImg->GetWidth() * 0.5f,
		WINSIZEY * 0.5f + m_pLogoImg->GetHeight() * 0.5f );

	RENDER->Image(
		m_pTextImg,
		WINSIZEX * 0.5f - m_pTextImg->GetWidth() * 0.5f,
		WINSIZEY * 0.7f - m_pTextImg->GetHeight() * 0.5f,
		WINSIZEX * 0.5f + m_pTextImg->GetWidth() * 0.5f,
		WINSIZEY * 0.7f + m_pTextImg->GetHeight() * 0.5f);
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}

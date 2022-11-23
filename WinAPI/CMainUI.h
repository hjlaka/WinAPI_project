#pragma once
#include "CUI.h"

class CUIHp;
class CUISkill;
class CUIFrame;
class CImage;
class CUIImage;

class CMainUI : public CUI
{
public:
	CMainUI();
	virtual ~CMainUI();

public:

	CUIImage* pPlayerPortrait;

	CUIFrame* pPlayerSkill2Frame;

	CUIHp*	  pPlayerHpUI;
	CUISkill* pPlayerSkillAUI;
	CUISkill* pPlayerSkillSUI;

	CUIFrame* pPlayer2PortraitFrame;
	CUIFrame* pPlayer2SkillAUIFrame;
	CUIFrame* pPlayer2SkillSUIFrame;

	CUIImage* pPlayer2Portrait;
	CUISkill* pPlayer2SkillAUI;
	CUISkill* pPlayer2SkillSUI;

private:
	void Init() override;
	void Render() override;
	void Update() override;
	void Release() override;

	void OnMouseEnter() final;
	void OnMouseOver() final;
	void OnMouseExit() final;
	void OnMouseUp() final;
	void OnMouseDown() final;
	void OnMouseClicked() final;
};


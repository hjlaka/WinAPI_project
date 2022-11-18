#pragma once
#include "CUI.h"

class CUIHp;
class CUISkill;
class CImage;

class CMainUI : public CUI
{
public:
	CMainUI();
	virtual ~CMainUI();

public:

	CImage* pPlayerPortrait;


	CUIHp* pPlayerHpUI;
	CUISkill* pPlayerSkillAUI;
	CUISkill* pPlayerSkillSUI;

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


#pragma once
#include "CUI.h"
class CMainUI : public CUI
{
public:
	CMainUI();
	virtual ~CMainUI();

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


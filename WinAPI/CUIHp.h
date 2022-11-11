#pragma once
#include "CUI.h"
class CUIHp : public CUI
{
public:

	CUIHp();
	virtual ~CUIHp();

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


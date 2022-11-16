#pragma once
#include "CUI.h"

class CImage;

class CUIFrame : public CUI
{
public:
	CUIFrame();
	virtual ~CUIFrame();


private:
	CImage* m_pImg;

public:
	void SetImage(CImage* pImg);

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


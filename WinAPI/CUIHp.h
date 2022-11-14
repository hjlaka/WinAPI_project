#pragma once
#include "CUI.h"

class CUnit;


class CUIHp : public CUI
{
public:

	CUIHp();
	virtual ~CUIHp();


protected:

	CUnit* m_pOwner;
	float m_fHpRate;

	/*int m_iHp;
	int m_iCurHp;*/

public:

	void SetOwner(CUnit* pUnit);


protected:
	virtual void Init() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void Release() override;

	void OnMouseEnter();
	void OnMouseOver();
	void OnMouseExit();
	void OnMouseUp();
	void OnMouseDown();
	void OnMouseClicked();
};


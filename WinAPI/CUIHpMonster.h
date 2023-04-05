#pragma once
#include "CUIHp.h"
class CUIHpMonster : public CUIHp
{
public:
	CUIHpMonster();
	virtual ~CUIHpMonster();

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


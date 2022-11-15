#pragma once
#include "CUI.h"
#include "Skill.h"
class CUISkill : public CUI
{
public:
	CUISkill();
	virtual ~CUISkill();

private:

	const SkillInfo* m_pLinkedValue;

public:
	void SetLinkedValue(const SkillInfo* skill);

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void OnMouseEnter();
	void OnMouseOver();
	void OnMouseExit();
	void OnMouseUp();
	void OnMouseDown();
	void OnMouseClicked();
};


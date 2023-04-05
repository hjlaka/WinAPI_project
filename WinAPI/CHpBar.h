#pragma once
#include "CComponent.h"
class CHpBar : public CComponent
{
public:
	CHpBar();
	virtual ~CHpBar();

private:

	bool m_bIsVisible;
	Vector m_vecPos;
	Vector m_vecScale;
	float m_fHpRate;
	CImage* m_pHpImage;

public:
	void SetVisible(bool visible);

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};


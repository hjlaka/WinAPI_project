#pragma once
#include "CGameObject.h"

class CAnimator;

class CGate : public CGameObject
{
public:
	CGate();
	virtual ~CGate();


private:
	CAnimator* m_pAnimator;
	bool m_bIsOpen;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};


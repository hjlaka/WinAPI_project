#pragma once
#include "CGameObject.h"

class CAnimator;

class CGate : public CGameObject
{
public:
	CGate(GroupScene dstScene);
	virtual ~CGate();


private:
	CAnimator* m_pAnimator;
	bool m_bIsOpen;
	GroupScene m_dstScene;
	
public:
	void GoToNext();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};


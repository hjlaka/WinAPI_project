#pragma once
#include "CGameObject.h"
class CSmoke : public CGameObject
{
public:
	CSmoke();
	virtual ~CSmoke();


private:
	CAnimator*	m_pAnimator;
	CImage*		m_pSmokeImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};


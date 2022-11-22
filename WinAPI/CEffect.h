#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CEffect : public CGameObject
{
public:
	CEffect();
	virtual ~CEffect();


protected:
	CAnimator*	m_pAnimator;
	CImage*		m_pEffectImage;

	Vector		m_vecDir;			// ¿Ã∆Â∆Æ πÊ«‚
	float		m_fPlayTime;		// √— ¿Ã∆Â∆Æ ¡ˆº” Ω√∞£

public:

	void SetDir(Vector dir);

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};


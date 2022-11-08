#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;
class CRigidBody;

class CMonster01 : public CMonster
{
public:
	CMonster01();
	virtual ~CMonster01();

private:
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;


public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


#pragma once
#include "CUnit.h"

class CImage;
class CAnimator;
class CRigidBody;

class CPlayer : public CUnit
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;
	CImage* m_pAttackImage;
	CImage* m_pJumpImage;
	CImage* m_pFallImage;
	CImage* m_pFallRepeatImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;
	bool m_bIsAttack;
	bool m_bOverPeak;
	UINT m_iJumpCount;

	float m_fSpeed = 200.0f;
	float m_fJumpPower = 100.f;




private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	void CreateMissile();
	void Jump(float fJumpPower);


	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
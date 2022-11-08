#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;
class CRigidBody;

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;
	CImage* m_pAttackImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;
	bool m_bIsAttack;
	UINT m_iJumpCount;

	float m_fSpeed = 200.0f;
	float m_fJumpPower = 100.f;

	CRigidBody* m_pRigid;

public:

	void CollisionX();
	void CollisionY();
	void Collision();
	void CollisionExitY();
	void CollisionExitX();
	void CollisionExit();

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
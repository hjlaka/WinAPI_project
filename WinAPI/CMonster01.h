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
	CImage* m_pAttackImage;
	CImage* m_pAttackBImage;
	CImage* m_pDieImage;

	float m_fAttackAPlayTime;
	float m_fStatusTimer;
	float m_fAttackACool;
	float m_fAttackBCool;
	//float m_fThinkTime;
	bool m_bMakeAttack;

	CAttack* m_meleeAttack;

	float m_fRushSpeed;
	float m_fRushTargetPosX;

private:

	void AnimatorUpdate() override;


public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


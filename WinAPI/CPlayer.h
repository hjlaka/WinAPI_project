#pragma once
#include "CUnit.h"

class CImage;
class CAnimator;
class CRigidBody;
class CStatePlayer;
class CPlayerJumping;

enum class STATE {IDLE, ATTACKA, ATTACKB, MOVE, DASH, JUMP, JUMPATTACK};
enum class SKUL_TYPE {LITTLE_BONE, HUNTER};

class CPlayer : public CUnit
{
	friend CPlayerJumping;

public:
	CPlayer();
	virtual ~CPlayer();

public:
	CStatePlayer* m_pPlayerState;
	STATE m_state;

private:
	SKUL_TYPE m_curSkulType;
	SKUL_TYPE m_subSkulType;

	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;
	CImage* m_pAttackImage;
	CImage* m_pAttackBImage;
	CImage* m_pJumpImage;
	CImage* m_pFallImage;
	CImage* m_pFallRepeatImage;
	CImage* m_pDashImage;
	CImage* m_pJumpAttackImage;

	Vector m_vecMoveDir;
	
	bool m_bIsMove;
	bool m_bIsAttack;
	bool m_bAttackContinue;
	int m_iAttackCount;
	bool m_bOverPeak;
	bool m_bIsDash;
	UINT m_iJumpCount;


	float m_fAttackContinue;		// 후속 공격으로 연계되는 시간

	float m_fFallTime;
	float m_fAttackATime;
	float m_fAttackBTime;

	float m_fJumpPower = 100.f;

	float m_fDashClock;


	// 스킬


	int m_iSkillCount;

protected:
	virtual void SkillA() {};
	virtual void SkillS() {};




private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void UpdateInState();
	void AnimatorUpdate();
	void CreateMissile();
	void Jump(float fJumpPower);
	void Attack();


	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
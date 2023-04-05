#pragma once
#include "CUnit.h"
#include "Skill.h"



class CImage;
class CAnimator;
class CRigidBody;
class CStatePlayer;


class CPlayerIdle;
class CPlayerMoving;
class CPlayerJumping;
class CPlayerDashing;
class CPlayerAttackA;
class CPlayerAttackB;
class CPlayerJumpAttack;
class CPlayerSkillA;
class CPlayerSkillS;
class CPlayerFalling;
class CPlayerDie;








class CGameManager;

enum class STATE {IDLE, ATTACK, ATTACKA, ATTACKB, MOVE, DASH, JUMP, JUMPATTACK, FALL, SKILLA, SKILLS, DIE};
enum class SKUL_TYPE {NONE, LITTLE_BONE, HUNTER};

class CPlayer : public CUnit
{
	friend CGameManager;
	friend CPlayerJumping;
	friend CPlayerDashing;
	friend CPlayerIdle;
	friend CPlayerMoving;
	friend CPlayerAttackA;
	friend CPlayerAttackB;
	friend CPlayerJumpAttack;
	friend CPlayerSkillA;
	friend CPlayerSkillS;
	friend CPlayerFalling;
	friend CPlayerDie;



public:
	CPlayer();
	virtual ~CPlayer();

public:
	CStatePlayer* m_pPlayerState;
	STATE m_state;


protected:

	SKUL_TYPE m_skulType;
	//SKUL_TYPE m_subSkulType;

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
	CImage* m_pDieImage;

	CImage* m_pPortrait;
	

	
	
	bool m_bIsMove;
	bool m_bIsCanMove;
	bool m_bIsAttack;
	bool m_bAttackContinue;
	int m_iAttackCount;
	bool m_bOverPeak;
	bool m_bIsDash;
	bool m_bIsInvincible;			// 무적 상태
	UINT m_iJumpCount;


	float m_fAttackContinue;		// 후속 공격으로 연계되는 시간

	float m_fFallTime;
	float m_fAttackATime;
	float m_fAttackBTime;
	float m_fAttackJTime;

	float m_fDashCoolTime;

	float m_fJumpPower;

	float m_fDashClock;

	

public:


protected:


	// 스킬
	SkillInfo* m_skillA;
	SkillInfo* m_skillS;

	int m_iSkillCount;

	float m_fSkillACoolClock;
	float m_fSkillSCoolClock;

protected:
	virtual void SkillSetUp() {};
	virtual void SkillA() {};
	virtual void SkillS() {};
	//virtual void SkillAction(SkillInfo skill) {};

	void UpdateSkill();

public:
	SkillInfo* GetSkillA();
	SkillInfo* GetSkillS();




protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	virtual void AnimatorUpdate();
	void Jump(float fJumpPower);
	virtual void Attack(Vector offset);
	virtual void JumpAttack();

	virtual void Enter() = 0;
	virtual void Exit();


	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};
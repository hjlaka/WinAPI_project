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








class CGameManager;

enum class STATE {IDLE, ATTACK, ATTACKA, ATTACKB, MOVE, DASH, JUMP, JUMPATTACK, FALL, SKILLA, SKILLS};
enum class SKUL_TYPE {LITTLE_BONE, HUNTER};

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



public:
	CPlayer();
	virtual ~CPlayer();

public:
	CStatePlayer* m_pPlayerState;
	STATE m_state;

private:

	//CPlayerJumping jump;
	//CPlayerDashing dash;
	//CPlayerIdle idle;
	//CPlayerMoving move;
	//CPlayerAttackB attack;
	//CPlayerSkillA skillA;
	//CPlayerFalling fall;


protected:
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
	CImage* m_pShootHead;
	CImage* m_pHeadIsI;

	CImage* m_pIdleHeadlessImage;
	CImage* m_pMoveHeadlessImage;
	CImage* m_pAttackHeadlessImage;
	CImage* m_pAttackBHeadlessImage;
	CImage* m_pJumpHeadlessImage;
	CImage* m_pFallHeadlessImage;
	CImage* m_pFallRepeatHeadlessImage;
	CImage* m_pDashHeadlessImage;
	CImage* m_pJumpAttackHeadlessImage;

	Vector m_vecMoveDir;
	
	bool m_bIsMove;
	bool m_bIsCanMove;
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
	float m_fAttackJTime;

	float m_fJumpPower = 100.f;

	float m_fDashClock;


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

	void UpdateInState();
	virtual void AnimatorUpdate();
	void CreateMissile();
	void Jump(float fJumpPower);
	void Attack();

	virtual void Enter() = 0;
	virtual void Exit() = 0;


	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};
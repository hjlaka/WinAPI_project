#pragma once
#include "CPlayer.h"
#include "Skill.h"

class CShootedHead;



class CSkulLittleBone : public CPlayer
{

	//렌더링 내용이 다름
	//스킬이 다름
	//스테이터스 수치 등이 다름

public:
	CSkulLittleBone();
	virtual ~CSkulLittleBone();

private:

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

private:

	CShootedHead* m_pHead;

	SkillInfo skillShootHead;
	SkillInfo skillHeadIsI;


private:

	void ReturnHead();
	void AnimatorUpdate();

private:

	void SkillSetUp() override;
	void SkillA() override;
	void SkillS() override;
	//void SkillAction(SkillInfo skill) override;

private:

	void Init() override;
	void Update() override;
	void Render() override;

	void Enter() override;
	void Exit() override;

	//void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;

};


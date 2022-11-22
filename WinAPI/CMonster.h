#pragma once
#include "CUnit.h"

class CHpBar;

enum class STATUS { IDLE, CONFRONT, MOVE, ATTACK, HIT, DIE };

class CMonster : public CUnit
{
public:
	CMonster();
	virtual ~CMonster();

protected:
	STATUS m_status;
	Vector m_vecTargetPos;
	CGameObject* m_TargetObj;
	CHpBar* m_hpBar;

protected:

	virtual void MoveToTargetPos();
	virtual void AnimatorUpdate() {};

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


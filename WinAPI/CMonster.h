#pragma once
#include "CUnit.h"

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

protected:

	virtual void MoveToTargetPos();
	virtual void AnimatorUpdate() {};

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


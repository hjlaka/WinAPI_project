#pragma once
#include "CGameObject.h"

class CUnit;

enum class ATTACK_TYPE { MELEE, RANGED };

class CAttack : public CGameObject
{
public:
	CAttack();
	virtual ~CAttack();

protected:

	CUnit* m_pOwner;		// 공격 주인
	float m_fDuration;		// 공격 지속시간
	Vector m_vecOffset;		// 공격 위치 조정값
	ATTACK_TYPE	m_type;		// 공격 타입

public:

	ATTACK_TYPE GetAttackType();
	CUnit* GetOwner();

	void SetOwner(CUnit* owner);
	void SetAttackDuration(float duration);
	void SetOffset(Vector offset);

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


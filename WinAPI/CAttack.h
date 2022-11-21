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

	CUnit* m_pOwner;		// ���� ����
	float m_fDuration;		// ���� ���ӽð�
	Vector m_vecOffset;		// ���� ��ġ ������
	ATTACK_TYPE	m_type;		// ���� Ÿ��

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


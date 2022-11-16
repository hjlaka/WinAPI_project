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
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


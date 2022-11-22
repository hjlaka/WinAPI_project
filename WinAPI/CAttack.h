#pragma once
#include "CGameObject.h"

class CUnit;

enum class ATTACK_TYPE { MELEE, RANGED };

struct AttackFrame
{
	Vector	pos;		// �ݶ��̴� ��ġ
	float	duration;	// ���� �ð�
};

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

	int		m_iAttack;			// ���ݷ�
	Vector	m_vecDir;			// ���� ����	



	vector<AttackFrame> m_vAttackFlow;		// ���� �帧
	UINT				m_iCurFrame;		// ���� �÷������� �������� �ε���
	float				m_fAccTime;			// ���� �÷������� �������� �����ð�
	

public:

	

	ATTACK_TYPE GetAttackType();
	CUnit* GetOwner();
	int GetAttack();
	Vector GetDir();

	void SetOwner(CUnit* owner);
	void SetAttackDuration(float duration);
	void SetOffset(Vector offset);

	void SetAttack(int attack);					// ���ݷ� ����
	void SetDir(Vector dir);					// ���� ���� ����

	void SetAttackFrame(Vector pos, float duration);

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


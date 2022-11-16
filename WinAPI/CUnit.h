#pragma once
#include "CGameObject.h"
#include "CAttack.h"

class CRigidBody;

// �÷��̾�� ���Ϳ��� ��� ��ӽ�ų Ŭ����
/*

���� ����

1. �߷��� �޴´�. (������Ʈ�� �̹� ������)
2. ���� ���� ����.



*/
class CUnit : public CGameObject
{
public:

	CUnit();
	virtual ~CUnit();


protected:

	Vector m_vecLookDir;


	CRigidBody* m_pRigid;

	int			m_iHp;			// ü��
	int			m_iCurHp;			// ���� ü��
	int			m_iAtt;			// ���ݷ�

	float		m_fSpeed;			// �ӵ�

	bool m_bGetHit;	
	float m_fInvincibleTime;


public:

	int GetHp();
	int GetCurHp();
	int GetAttack();
	float GetSpeed();
	Vector GetLookDir();


protected:
	void SetHp(int hp);
	void SetCurHp(int curHp);
	void SetAttack(int att);
	void SetSpeed(float spd);




public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


#pragma once
#include "CGameObject.h"

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

	CRigidBody* m_pRigid;

	UINT m_uiHp;			// ü��
	UINT m_uiCurHp;			// ���� ü��
	UINT m_uiAtt;			// ���ݷ�



public:

	void CollisionX();
	void CollisionY();
	void Collision();
	void CollisionExitY();
	void CollisionExitX();
	void CollisionExit();

public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


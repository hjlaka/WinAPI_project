#pragma once
#include "CPlayerAttack.h"
#include "CRigidBody.h"
class CShootedHead : public CPlayerAttack
{
public:
	CShootedHead();
	virtual ~CShootedHead();

private:
	Vector m_vecDir;
	CRigidBody* m_pRigid;
	bool m_bHeadOn;

public:
	CRigidBody* GetRigidBody();
	void SetHeadOn(bool value);
	bool GetHeadOn();

public:
	void HeadInit();

private:
	void Init() override;
	void Update() override;
	//void Render() override;
	//void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


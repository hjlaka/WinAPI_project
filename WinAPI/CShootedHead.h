#pragma once
#include "CPlayerAttack.h"


class CRigidBody;
class CImage;

class CShootedHead : public CPlayerAttack
{
public:
	CShootedHead();
	virtual ~CShootedHead();

private:
	Vector m_vecDir;
	CRigidBody* m_pRigid;
	bool m_bHeadOn;
	CImage* m_pImg;
	float m_fSpeed;

public:
	CRigidBody* GetRigidBody();
	void SetHeadOn(bool value);
	bool GetHeadOn();
	void SetDir(Vector dir);

	void Shoot(Vector headPos, Vector lookDir);

public:
	void HeadInit();

private:
	void Init() override;
	void Update() override;
	void Render() override;


	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


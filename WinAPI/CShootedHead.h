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

public:
	CRigidBody* GetRigidBody();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};


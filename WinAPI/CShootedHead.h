#pragma once
#include "CPlayerAttack.h"
#include "CRigidBody.h"
class CShootedHead : public CPlayerAttack
{
public:
	CShootedHead();
	virtual ~CShootedHead();

private:
	CRigidBody* m_pRigid;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};


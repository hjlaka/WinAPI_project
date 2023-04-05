#pragma once
#include "CAttack.h"
class CMonsterAttack : public CAttack
{
public:
	CMonsterAttack();
	virtual ~CMonsterAttack();

protected:

public:

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


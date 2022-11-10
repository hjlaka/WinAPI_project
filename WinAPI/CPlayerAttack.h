#pragma once
#include "CAttack.h"
class CPlayerAttack : public CAttack
{
public:
	CPlayerAttack();
	virtual ~CPlayerAttack();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


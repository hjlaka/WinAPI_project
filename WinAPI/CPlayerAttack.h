#pragma once
#include "CAttack.h"
class CPlayerAttack : public CAttack
{
public:
	CPlayerAttack();
	virtual ~CPlayerAttack();

protected:
	float m_fAttack;

public:
	float GetAttack();
	void SetAttack(float attack);



private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


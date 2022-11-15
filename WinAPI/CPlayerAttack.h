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

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


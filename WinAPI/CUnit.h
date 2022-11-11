#pragma once
#include "CGameObject.h"

class CRigidBody;

// 플레이어와 몬스터에게 모두 상속시킬 클래스
/*

공통 사항

1. 중력을 받는다. (컴포넌트로 이미 적용함)
2. 땅에 발을 디딘다.



*/
class CUnit : public CGameObject
{
public:

	CUnit();
	virtual ~CUnit();


protected:

	CRigidBody* m_pRigid;

	UINT m_uiHp;			// 체력
	UINT m_uiCurHp;			// 현재 체력
	UINT m_uiAtt;			// 공격력

	bool m_bGetHit;	
	float m_fInvincibleTime;




public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


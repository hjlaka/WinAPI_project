#pragma once
#include "CGameObject.h"
#include "CAttack.h"

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

	Vector m_vecLookDir;


	CRigidBody* m_pRigid;

	int			m_iHp;			// 체력
	int			m_iCurHp;			// 현재 체력
	int			m_iAtt;			// 공격력

	float		m_fSpeed;			// 속도

	bool m_bGetHit;	
	float m_fInvincibleTime;


public:

	int GetHp();
	int GetCurHp();
	int GetAttack();
	float GetSpeed();
	Vector GetLookDir();


protected:
	void SetHp(int hp);
	void SetCurHp(int curHp);
	void SetAttack(int att);
	void SetSpeed(float spd);




public:

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};


#pragma once
#include "CGameObject.h"

class CUnit;

enum class ATTACK_TYPE { MELEE, RANGED };

struct AttackFrame
{
	Vector	pos;		// 콜라이더 위치
	float	duration;	// 지속 시간
};

class CAttack : public CGameObject
{
public:
	CAttack();
	virtual ~CAttack();

protected:

	CUnit* m_pOwner;		// 공격 주인
	float m_fDuration;		// 공격 지속시간
	Vector m_vecOffset;		// 공격 위치 조정값
	ATTACK_TYPE	m_type;		// 공격 타입

	int		m_iAttack;			// 공격력
	Vector	m_vecDir;			// 공격 방향	



	vector<AttackFrame> m_vAttackFlow;		// 공격 흐름
	UINT				m_iCurFrame;		// 현재 플레이중인 프레임의 인덱스
	float				m_fAccTime;			// 현재 플레이중인 프레임의 축적시간
	

public:

	

	ATTACK_TYPE GetAttackType();
	CUnit* GetOwner();
	int GetAttack();
	Vector GetDir();

	void SetOwner(CUnit* owner);
	void SetAttackDuration(float duration);
	void SetOffset(Vector offset);

	void SetAttack(int attack);					// 공격력 설정
	void SetDir(Vector dir);					// 공격 방향 설정

	void SetAttackFrame(Vector pos, float duration);

protected:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollisionEnter(CCollider* pOtherCollider) override;
	virtual void OnCollisionStay(CCollider* pOtherCollider) override;
	virtual void OnCollisionExit(CCollider* pOtherCollider) override;
};


#pragma once
#include "CComponent.h"

enum class Dir { LEFT, RIGHT, UP, DOWN };
class CPlayer;
class CMonster01;

class CRigidBody : public CComponent
{
	friend CPlayer;
	friend CMonster01;
private:

public:

	CRigidBody();
	virtual ~CRigidBody();


private:


	float m_fGravity;

	bool m_bIsGravity;
	bool m_bIsFrictional;

	bool m_bIsOnGround;
	UINT m_uiNotBlockingCount;

	float m_fSpeed;
	float m_fMultiSpeed;

	int m_arrDirSpeed[4] = {1, 1, 1, 1};
	int m_arrCollisionCount[4] = { 0, 0, 0, 0 };

	float m_fForceX;
	float m_fFriction;
	Vector m_vecForce;
	
	Vector m_vecVelocity;

	bool isUpDownCol;


public:

	bool GetIsGravity();
	bool GetIsFrictional();
	int GetGroundCount();
	float GetGravitySpeed();
	int GetCollisionCont(Dir dir);

	void SetIsGravity(bool isGravity);
	void SetIsFrictional(bool isFrictional);
	void SetGravitySpeed(float speed);
	void SetDirectionX(int dirX);
	void SetDirectionY(int dirY);
	void SetSpeed(float spd);
	void SetMultiSpeed(float spd);
	void SetFriction(float friction);

	void SetDirSpeed(Dir dir, float spd);
	void SetCollisionConunt(Dir dir, int value);

	void SetVelocityX(float x);

	void UpdateVelocityX();
	void UpdateVelocityY();


	bool GroundCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider);
	void WallCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider);
	void GroundCollisionExit(CCollider* myCollider, CCollider* pOtherCollider);
	void WallCollisionExit(CCollider* myCollider, CCollider* pOtherCollider);
	void WallCollisionStay(CCollider* myCollider, CCollider* pOtherCollider);


	void PowerToY(float y);
	void PowerToX(float x);
	void Power(Vector force);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


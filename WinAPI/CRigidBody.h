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

	float m_fGravitySpeed;
	float m_fGravity;
	float m_fLaunchSpeed;
	bool m_bIsGravity;
	int m_iGroundCount;
	bool m_bIsOnGround;
	UINT m_uiNotBlockingCount;

	float m_fSpeed;
	float m_fMultiSpeed;
	Vector m_vecDir;
	int m_arrDirSpeed[4] = {1, 1, 1, 1};
	int m_arrCollisionCount[4] = { 0, 0, 0, 0 };


public:

	bool GetIsGravity();
	int GetGroundCount();
	Vector GetValidDir();
	float GetGravitySpeed();
	int GetCollisionCont(Dir dir);

	void SetIsGravity(bool isGravity);
	void SetGravitySpeed(float speed);
	void SetGroundCount(int value);
	void SetDirectionX(int dirX);
	void SetDirectionY(int dirY);
	void SetSpeed(float spd);
	void SetMultiSpeed(float spd);

	void SetDirSpeed(Dir dir, float spd);
	void SetCollisionConunt(Dir dir, int value);


	void GroundCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider);
	void WallCollisionEnter(CCollider* myCollider, CCollider* pOtherCollider);
	void GroundCollisionExit(CCollider* myCollider, CCollider* pOtherCollider);
	void WallCollisionExit(CCollider* myCollider, CCollider* pOtherCollider);


	void PowerToY(float y);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


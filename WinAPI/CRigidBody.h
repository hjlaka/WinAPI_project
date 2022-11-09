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

	float m_fSpeed;
	Vector m_vecDir;
	int m_arrDirSpeed[4] = {1, 1, 1, 1};


public:

	bool GetIsGravity();
	int GetGroundCount();
	Vector GetValidDir();
	float GetGravitySpeed();

	void SetIsGravity(bool isGravity);
	void SetGravitySpeed(float speed);
	void SetGroundCount(int value);
	void SetDirectionX(int dirX);
	void SetDirectionY(int dirY);
	void SetSpeed(float spd);

	void SetDirSpeed(Dir dir, float spd);

	void PowerToY(float y);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


#pragma once
#include "CComponent.h"
class CRigidBody : public CComponent
{

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

	float m_fSpeed;
	Vector m_vecDir;
	float m_fDirSpeed[];


public:

	bool GetIsGravity();
	int GetGroundCount();

	void SetIsGravity(bool isGravity);
	void SetGravitySpeed(float speed);
	void SetGroundCount(int value);
	void SetDirectionX(int dirX);
	void SetDirectionY(int dirY);
	void SetSpeed(float spd);

	void PowerToY(float y);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


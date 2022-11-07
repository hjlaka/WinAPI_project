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
	float m_fAcceleartion;
	bool m_bIsGravity;
	bool m_bOnGround;


public:

	bool GetIsGravity();

	void SetIsGravity(bool isGravity);
	void SetGravitySpeed(float speed);
	void SetOnGround(bool onGround);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


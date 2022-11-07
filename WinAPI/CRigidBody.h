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
	UINT m_uiGroundCount;


public:

	bool GetIsGravity();

	void SetIsGravity(bool isGravity);
	void SetGravitySpeed(float speed);
	void SetGroundCount(UINT value);

	void PowerToY(float y);

public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


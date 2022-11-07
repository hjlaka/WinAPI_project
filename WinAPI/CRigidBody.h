#pragma once
#include "CComponent.h"
class CRigidBody : public CComponent
{

private:

public:

	CRigidBody();
	virtual ~CRigidBody();

	bool m_bIsGravity;

	bool GetIsGravity();

	void SetIsGravity(bool isGravity);


public:

	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};


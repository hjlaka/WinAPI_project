#pragma once
#include "CEffect.h"
class CSmoke : public CEffect
{
public:
	CSmoke();
	virtual ~CSmoke();

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};


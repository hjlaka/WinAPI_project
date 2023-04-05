#pragma once
#include "CEffect.h"
class CHit : public CEffect
{
public:
	CHit();
	virtual ~CHit();

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};


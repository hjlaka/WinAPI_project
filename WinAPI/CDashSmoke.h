#include "CEffect.h"

class CDashSmoke : public CEffect
{
public:
	CDashSmoke();
	virtual ~CDashSmoke();

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};
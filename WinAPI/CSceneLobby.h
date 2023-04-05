#pragma once
#include "CScene.h"
class CSceneLobby : public CScene
{
public:
	CSceneLobby();
	virtual ~CSceneLobby();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};


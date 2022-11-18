#pragma once
#include "CScene.h"
class CSceneStage02 : public CScene
{
public:
	CSceneStage02();
	virtual ~CSceneStage02();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};


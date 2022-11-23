#pragma once
#include "CPlayer.h"
class CSkulHunter : public CPlayer
{

	//렌더링 내용이 다름
	//스킬이 다름
	//스테이터스 수치 등이 다름

public:
	CSkulHunter();
	virtual ~CSkulHunter();

private:

	SkillInfo ImmovableShot;
	SkillInfo MultipleShot;
	SkillInfo SiegeShot;

private:

	void SkillSetUp() override;
	void SkillA() override;
	void SkillS() override;
	//void SkillAction(SkillInfo skill) override;

	void AnimatorUpdate() override;

private:

	void Enter() override;
	void Exit() override;

	void Init() override;
	void Update() override;
	//void Render() override;

	//void OnCollisionStay(CCollider* pOtherCollider) override;
};


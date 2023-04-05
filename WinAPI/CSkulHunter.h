#pragma once
#include "CPlayer.h"
class CSkulHunter : public CPlayer
{

	//������ ������ �ٸ�
	//��ų�� �ٸ�
	//�������ͽ� ��ġ ���� �ٸ�

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


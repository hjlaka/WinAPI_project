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

	void SkillSetUp() override;
	void SkillA() override;
	void SkillS() override;
	//void SkillAction(SkillInfo skill) override;

private:

	//void Init() override;
	//void Update() override;
	//void Render() override;

	//void OnCollisionStay(CCollider* pOtherCollider) override;
};


#pragma once
#include "CPlayer.h"
#include "Skill.h"

class CShootedHead;



class CSkulLittleBone : public CPlayer
{

	//������ ������ �ٸ�
	//��ų�� �ٸ�
	//�������ͽ� ��ġ ���� �ٸ�

public:
	CSkulLittleBone();
	virtual ~CSkulLittleBone();

private:
	bool m_bHeadOn;
	Vector m_vecHeadPos;
	CShootedHead* m_pHead;

public:


	bool GetHeadOn();

	void SetHeadOn(bool headOn);


private:

	void SkillSetUp() override;
	void SkillA() override;
	void SkillS() override;
	//void SkillAction(SkillInfo skill) override;

private:

	void Init() override;
	void Render() override;

};


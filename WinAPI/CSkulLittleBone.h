#pragma once
#include "CPlayer.h"
#include "Skill.h"

class CShootedHead;



class CSkulLittleBone : public CPlayer
{

	//렌더링 내용이 다름
	//스킬이 다름
	//스테이터스 수치 등이 다름

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


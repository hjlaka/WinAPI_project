#pragma once
#include "CPlayer.h"
class CSkulLittleBone : public CPlayer
{

	//렌더링 내용이 다름
	//스킬이 다름
	//스테이터스 수치 등이 다름

public:
	CSkulLittleBone();
	virtual ~CSkulLittleBone();


private:

	void SkillA() override;
	void SkillS() override;

};


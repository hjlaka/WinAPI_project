#pragma once
#include "CPlayer.h"
class CSkulLittleBone : public CPlayer
{

	//������ ������ �ٸ�
	//��ų�� �ٸ�
	//�������ͽ� ��ġ ���� �ٸ�

public:
	CSkulLittleBone();
	virtual ~CSkulLittleBone();


private:

	void SkillA() override;
	void SkillS() override;

};


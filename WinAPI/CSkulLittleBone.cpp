#include "framework.h"
#include "CSkulLittleBone.h"

#include "CShootedHead.h"

CSkulLittleBone::CSkulLittleBone()
{
}

CSkulLittleBone::~CSkulLittleBone()
{
}

void CSkulLittleBone::SkillA()
{
	CShootedHead* head = new CShootedHead;
	head->SetPos(GetPos());
	head->GetRigidBody()->PowerToX(300.f);
	ADDOBJECT(head);
}

void CSkulLittleBone::SkillS()
{
}

#pragma once
#include "framework.h"

class CUnit;
class CGameObject;

enum class SKILL_STATE {NONE, COOLING, READY};

struct SkillInfo
{
	wstring strName;
	float fCool;
	float fCurCool;
	SKILL_STATE state;
	float fMotionTime;
	wstring strAniName;
	wstring strDescription;
	bool bCondition;
	//CGameObject* pObj;	

	SkillInfo() { strName = L""; fCool = 0; fCurCool = 0; state = SKILL_STATE::NONE; fMotionTime = 0; strAniName = L"", strDescription = L""; bCondition = true; }

	void UseSkill()
	{
		if (SKILL_STATE::NONE == state)
			return;

		fCurCool = fCool;
		state = SKILL_STATE::COOLING;
	}

	void UpdateCool()
	{
		if (SKILL_STATE::NONE == state)
			return;

		if (SKILL_STATE::COOLING == state)
		{
			if(fCurCool > 0)
				fCurCool -= DT;
			else
			{
				fCurCool = 0;
				if (bCondition)
					state = SKILL_STATE::READY;
			}
				
		}
		
	}

	void ReadySkill()
	{
		if (SKILL_STATE::NONE == state)
			return;

		state = SKILL_STATE::READY;
		fCurCool = 0;

	}
};
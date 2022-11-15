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
	wstring strDescription;
	//CGameObject* pObj;	

	SkillInfo() { strName = L""; fCool = 0; fCurCool = 0; state = SKILL_STATE::NONE; strDescription = L"";  }

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
			fCurCool -= DT;

			if (fCurCool <= 0)
			{
				state = SKILL_STATE::READY;
				fCurCool = 0;
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
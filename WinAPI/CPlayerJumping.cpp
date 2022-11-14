#include "framework.h"
#include "CPlayerJumping.h"
#include "CPlayer.h"
#include "CRigidBody.h"
#include "CSmoke.h"

CPlayerJumping::CPlayerJumping()
{
}

CPlayerJumping::~CPlayerJumping()
{
}

CStatePlayer* CPlayerJumping::HandleInput(CPlayer* player)
{
	return nullptr;
}

void CPlayerJumping::Update(CPlayer* player)
{

		player->m_bOverPeak = false;
		player->m_pRigid->PowerToY(-550.f);
		player->m_iJumpCount++;

		Logger::Debug(L"Jump!");
		if (player->m_iJumpCount == 2)
		{
			CSmoke* pSmoke = new CSmoke();
			pSmoke->SetPos(player->m_vecPos.x, player->m_vecPos.y);
			ADDOBJECT(pSmoke);
		}
}

void CPlayerJumping::Enter(CPlayer* player)
{
}

void CPlayerJumping::Exit(CPlayer* player)
{
}

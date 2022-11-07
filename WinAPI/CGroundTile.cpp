#include "framework.h"
#include "CGroundTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"


#include "CPlayer.h"

CGroundTile::CGroundTile()
{
	m_strName = L"Ground";
	isUpDownCollision = false;
}

CGroundTile::~CGroundTile()
{
}

void CGroundTile::Init()
{
	CTile::Init();

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CGroundTile::Update()
{
	CTile::Update();
}

void CGroundTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CGroundTile::Release()
{
	CTile::Release();
}

void CGroundTile::OnCollisionEnter(CCollider* pOther)
{
	// 땅타일과 충돌했을 경우 처리
	//if (abs(pOther->GetPos().x - GetCollider()->GetPos().x) > GetCollider()->GetScale().x/2)
	//{
	//	//충돌 당시 y 차이가 더 작았다면
	//	//x 축 충돌이다.
	//	Logger::Debug(L"옆충돌");
	//}
	//else if (abs(pOther->GetPos().x - GetCollider()->GetPos().x) < GetCollider()->GetScale().x / 2)
	//{
	//	//충돌 당시 y 차이가 더 작았다면
	//	//x 축 충돌이다.
	//	Logger::Debug(L"상하충돌");
	//}
	CGameObject* pObj = pOther->GetOwner();
	CPlayer* pPlayer = static_cast<CPlayer*>(pObj);
	if (nullptr != pPlayer)
	{
		Vector standard = Vector(GetCollider()->GetPos().x + (GetCollider()->GetScale().x) / 2, GetCollider()->GetPos().y + (GetCollider()->GetScale().y) / 2);
		Vector diff = standard - pOther->GetPos();

		if (diff.Normalized().y > 0.66f)
		{
			Logger::Debug(L"상하충돌");
			isUpDownCollision = true;

			pPlayer->CollisionY();

		}
		else
		{
			Logger::Debug(L"좌우충돌");

			pPlayer->CollisionX();
		}
	}
	
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{
	// 땅타일과 충돌했을 경우 처리

	// 오브젝트와 충돌했다면 해당 오브젝트를 땅 타일 위로 올려준다.
	//CGameObject* pOtherObj = pOther->GetOwner();
	//// 땅 타일 위 
	//float fGroundPosY = GetPos().y;
	//float fGroundSclaeY = GetScale().y;
	//float fObjScaleY = pOtherObj->GetScale().y;

	//float fOnGroundY = fGroundPosY - (fObjScaleY / 2);
	//Vector vecOnGround = Vector(pOtherObj->GetPos().x, fOnGroundY);
	//pOtherObj->SetPos(vecOnGround);
	
	
	// 중력 가속도의 크기와 똑같이 방향만 정 반대로 오브젝트를 밀어올려준다.
	//pOther->GetOwner()->SetPos(pOther->GetOwner()->GetPos() + Vector(0.f, -1.f) * 26.f * DT);
	// 닿은 개수 만큼 속력이 달라진다.

	

	

	
	
	
}

void CGroundTile::OnCollisionExit(CCollider* pOther)
{
	CGameObject* pObj = pOther->GetOwner();
	CPlayer* pPlayer = static_cast<CPlayer*>(pObj);
	if (nullptr != pPlayer)
	{
		if (isUpDownCollision)
		{
			pPlayer->CollisionExitY();
		}
	}
	

}

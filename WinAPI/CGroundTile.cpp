#include "framework.h"
#include "CGroundTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"


#include "CUnit.h"
#include "CGameObject.h"

CGroundTile::CGroundTile()
{
	m_strName = L"Ground";
	m_bIsUpDownCollision = false;
	m_bIsLeftRightCollision = false;
	diffY = 0;
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

	
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{

	
}

void CGroundTile::OnCollisionExit(CCollider* pOther)
{


}

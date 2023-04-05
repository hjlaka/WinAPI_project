#include "framework.h"
#include "CWallTile.h"

CWallTile::CWallTile()
{
	m_strName = L"Wall";
}

CWallTile::~CWallTile()
{
}

void CWallTile::Init()
{
	CTile::Init();

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CWallTile::Update()
{
	CTile::Update();
}

void CWallTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CWallTile::Release()
{
	CTile::Release();
}

void CWallTile::OnCollisionEnter(CCollider* pOther)
{
}

void CWallTile::OnCollisionStay(CCollider* pOther)
{
}

void CWallTile::OnCollisionExit(CCollider* pOther)
{
}

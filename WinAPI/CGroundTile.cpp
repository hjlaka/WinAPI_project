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
	// ��Ÿ�ϰ� �浹���� ��� ó��
	//if (abs(pOther->GetPos().x - GetCollider()->GetPos().x) > GetCollider()->GetScale().x/2)
	//{
	//	//�浹 ��� y ���̰� �� �۾Ҵٸ�
	//	//x �� �浹�̴�.
	//	Logger::Debug(L"���浹");
	//}
	//else if (abs(pOther->GetPos().x - GetCollider()->GetPos().x) < GetCollider()->GetScale().x / 2)
	//{
	//	//�浹 ��� y ���̰� �� �۾Ҵٸ�
	//	//x �� �浹�̴�.
	//	Logger::Debug(L"�����浹");
	//}
	CGameObject* pObj = pOther->GetOwner();
	CPlayer* pPlayer = static_cast<CPlayer*>(pObj);
	if (nullptr != pPlayer)
	{
		Vector standard = Vector(GetCollider()->GetPos().x + (GetCollider()->GetScale().x) / 2, GetCollider()->GetPos().y + (GetCollider()->GetScale().y) / 2);
		Vector diff = standard - pOther->GetPos();

		if (diff.Normalized().y > 0.66f)
		{
			Logger::Debug(L"�����浹");
			isUpDownCollision = true;

			pPlayer->CollisionY();

		}
		else
		{
			Logger::Debug(L"�¿��浹");

			pPlayer->CollisionX();
		}
	}
	
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{
	// ��Ÿ�ϰ� �浹���� ��� ó��

	// ������Ʈ�� �浹�ߴٸ� �ش� ������Ʈ�� �� Ÿ�� ���� �÷��ش�.
	//CGameObject* pOtherObj = pOther->GetOwner();
	//// �� Ÿ�� �� 
	//float fGroundPosY = GetPos().y;
	//float fGroundSclaeY = GetScale().y;
	//float fObjScaleY = pOtherObj->GetScale().y;

	//float fOnGroundY = fGroundPosY - (fObjScaleY / 2);
	//Vector vecOnGround = Vector(pOtherObj->GetPos().x, fOnGroundY);
	//pOtherObj->SetPos(vecOnGround);
	
	
	// �߷� ���ӵ��� ũ��� �Ȱ��� ���⸸ �� �ݴ�� ������Ʈ�� �о�÷��ش�.
	//pOther->GetOwner()->SetPos(pOther->GetOwner()->GetPos() + Vector(0.f, -1.f) * 26.f * DT);
	// ���� ���� ��ŭ �ӷ��� �޶�����.

	

	

	
	
	
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

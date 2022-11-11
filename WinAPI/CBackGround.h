#pragma once
#include "CGameObject.h"

class CImage;

class CBackGround : public CGameObject
{
public:
	CBackGround();
	virtual ~CBackGround();

private:
	CImage* m_pBGImg;
	// z°ª Ãß°¡

	float m_fStartX;
	float m_fEndX;

public:
	void SetImage(CImage* bgImg);

	float GetStartX();
	float GetEndX();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};


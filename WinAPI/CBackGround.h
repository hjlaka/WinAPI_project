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

public:
	void SetImage(CImage* bgImg);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};


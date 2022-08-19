#pragma once

class CGameObject
{
protected:
	double hitDistance;
	POINT m_scale;
	POINT m_pozition;

public:

	CGameObject();
	virtual	~CGameObject();

	virtual void Update() {};
	// 게임오브젝트 == 게임내 보여지는 오브젝트 렌더함수 순수 가상함수로 생성
	virtual void Render(HDC hdc) = 0;

	void SetScale(POINT scale);
	void SetPozition(POINT pos);
	double GetHitDis();
	POINT GetScale();
	POINT GetPozition();

};


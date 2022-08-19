#pragma once

class CGameObject
{
protected:
	double hitDistance;
	POINT size;
	POINT pozition;

public:

	CGameObject();
	~CGameObject();

	virtual void Update() {};
	// 게임오브젝트 == 게임내 보여지는 오브젝트 렌더함수 순수 가상함수로 생성
	virtual void Render(HDC hdc) = 0;

	void SetSize(int x, int y);
	void SetPoint(int x, int y);
	double GetHitDis();
	POINT GetSize();
	POINT GetPozition();

};


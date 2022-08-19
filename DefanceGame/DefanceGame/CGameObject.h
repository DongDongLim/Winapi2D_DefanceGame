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
	// ���ӿ�����Ʈ == ���ӳ� �������� ������Ʈ �����Լ� ���� �����Լ��� ����
	virtual void Render(HDC hdc) = 0;

	void SetSize(int x, int y);
	void SetPoint(int x, int y);
	double GetHitDis();
	POINT GetSize();
	POINT GetPozition();

};


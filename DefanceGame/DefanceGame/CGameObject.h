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
	// ���ӿ�����Ʈ == ���ӳ� �������� ������Ʈ �����Լ� ���� �����Լ��� ����
	virtual void Render(HDC hdc) = 0;

	void SetScale(POINT scale);
	void SetPozition(POINT pos);
	double GetHitDis();
	POINT GetScale();
	POINT GetPozition();

};


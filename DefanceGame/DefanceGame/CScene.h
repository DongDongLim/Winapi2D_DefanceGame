#pragma once

class CGameObject;

class CScene
{
	vector<CGameObject*> m_arrObj[];

public:
	CScene();
	~CScene();

	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;
};


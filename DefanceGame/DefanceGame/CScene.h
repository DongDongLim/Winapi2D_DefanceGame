#pragma once

class CGameObject;

class CScene
{
	vector<CGameObject*> m_arrObj[static_cast<int>(GROUP_GAMEOBJ::SIZE)];
	wstring m_arrName;

public:
	CScene();
	~CScene();

	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;

	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
};


#pragma once

class CGameObject;

class CScene
{
private:
	vector<CGameObject*> m_arrObj[static_cast<int>(GROUP_GAMEOBJ::SIZE)];
	wstring m_strName;

public:
	CScene();
	~CScene();

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	// 씬의 모든 오브젝트와 렌더는 모든 씬이 공통적으로 진행
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
};


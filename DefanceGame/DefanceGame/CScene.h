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

	// ���� ��� ������Ʈ�� ������ ��� ���� ���������� ����
	virtual void update();
	virtual void render(HDC hdc);

	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
};


#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];
	CScene* m_pCurScene;

public:
	void ChangeScene(GROUP_SCENE scene);

	void Update();
	void Render(HDC hDC);
	void Init();

	CScene* GetCurScene();
};


#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];
	CScene* m_pcurScene;

public:
	void ChangScene(GROUP_SCENE scene);

	void Update();
	void Render(HDC hDC);
};


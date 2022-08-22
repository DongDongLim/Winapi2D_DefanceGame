#include "framework.h"
#include "CScene.h"

CSceneManager::CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; ++i)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::ChangeScene(GROUP_SCENE group)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(int)group];
	m_pCurScene->Enter();
}

void CSceneManager::Update()
{
	m_pCurScene->Update();
}

void CSceneManager::Render(HDC hDC)
{
	m_pCurScene->Render(hDC);
}

void CSceneManager::Init()
{

}
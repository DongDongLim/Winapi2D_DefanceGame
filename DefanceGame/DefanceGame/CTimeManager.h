#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	LARGE_INTEGER m_llCurCount;		// 현재 카운트
	LARGE_INTEGER m_llPrevCount;	// 이전 카운트
	LARGE_INTEGER m_llFrequency;	// 초당 카운트 횟수

	unsigned int	m_uiFPS;		// 초당 프레임(업데이트 횟수)
	double			m_dDT;			// 업데이트 당 몇초

public:
	 

	void Update();
	void Init();

	unsigned int	GetFPS() { return m_uiFPS; }
	double			GetDT() { return m_dDT; }
};


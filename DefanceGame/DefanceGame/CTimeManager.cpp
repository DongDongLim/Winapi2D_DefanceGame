#include "framework.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{
	m_llCurCount = {};
	m_llPrevCount = {};
	m_llFrequency = {};
	m_uiFPS = 0;
	m_dDT = 0;
}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::update()
{
	static unsigned int updateCount = 0;
	static double updateOneSecond = 0;

	// https://novemberfirst.tistory.com/36
	QueryPerformanceCounter(&m_llCurCount);
	// 현재 시간과 이전 시간의 카운트 수 차이/ 초당 카운트 수
	// 업데이트 사이에 몇 초가 지나는지 알 수 있음
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart)
		/ m_llFrequency.QuadPart;

	// 이전 시간의 카운터 수를 현재시간으로 초기화(다음에 비교를 위해서)
	m_llPrevCount = m_llCurCount;

	// 프레임 구하기
	++updateCount;
	updateOneSecond += m_dDT;
	if (updateOneSecond > 1.0)
	{
		m_uiFPS = updateCount;
		updateOneSecond = 0;
		updateCount = 0;

	}
}

void CTimeManager::init()
{
	// 현재 시간의 카운트 수(매개변수에 넣어줌)
	QueryPerformanceCounter(&m_llPrevCount);
	// 1초당 진행하는 카운트 수(매개변수에 넣어줌)
	QueryPerformanceFrequency(&m_llFrequency);
}
// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
 
// STL
#include <vector>
#include <list>
#include <chrono> // time함수보다 정밀한 시간체크
#include <string>
#include <map>
#include <cassert>

using std::vector;
using std::wstring;
using std::map;

// 오브젝트 그룹
enum class GROUP_GAMEOBJ
{
	DEFAULT = 0,

	SIZE,
};

enum class GROUP_SCENE
{
	DEFAULT = 0,
	TOOL,

	SIZE,
};

// 헤더파일
#include "USingleTon.h"
#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CCore.h"

// define
#define WINSTARTX	400
#define WINSTARTY	200
#define WINSIZEX	1280
#define WINSIZEY	720
// https://docs.microsoft.com/ko-kr/windows/win32/winmsg/window-styles
#define WINSTYLE WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
#define FPS CTimeManager::getInst()->GetFPS()
#define DT CTimeManager::getInst()->GetDT()

// 전역변수 extern(다른 파일의 전역변수 사용)
extern HINSTANCE hInst;
extern HWND hWnd;

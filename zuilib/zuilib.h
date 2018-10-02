#pragma once

#ifdef UILIB_STATIC
#	define ZUILIB_API 
#else
#	if defined(UILIB_EXPORTS)
#		if	defined(_MSC_VER)
#			define ZUILIB_API __declspec(dllexport)
#		else
#			define ZUILIB_API 
#		endif
#	else
#		if defined(_MSC_VER)
#			define ZUILIB_API __declspec(dllimport)
#		else
#			define ZUILIB_API 
#		endif
#	endif
#endif


//__declspec��һ��Microsoft Visual C++�ض��ı��������Կ��أ�
//�˴���selectany��ʾ��ͷ�ļ�����ȫ�ֱ������������ͷ�ļ���include���ʱ��������������޳�
#define UILIB_COMDAT __declspec(selectany)

#include <Windows.h>
#include <windowsx.h>
#include <windef.h>
#include <CommCtrl.h>
#include <stddef.h>
#include <Richedit.h>
#include <tchar.h>
#include <assert.h>
#include <crtdbg.h>
#include <malloc.h>
#include <stdio.h>

#include "Utils/Utils.h"
#include "Utils/UIDelegate.h"
#include "Core/UIDefine.h"
#include "Core/UIManager.h"
#include "Core/UIBase.h"
#include "Core/UIControl.h"
#include "Core/UIContainer.h"
#include "Core/UIMarkup.h"
#include "Core/UIDlgBuilder.h"
#include "Core/UIRender.h"
#include "Utils/WinImplBase.h"
#include "Utils/WndShadow.h"

#include "Layout/UIVerticalLayout.h"
#include "Layout/UIHorizontalLayout.h"
#include "Layout/UITileLayout.h"
#include "Layout/UITabLayout.h"
#include "Layout/UIChildLayout.h"

#include "Control/UIList.h"
#include "Control/UICombo.h"
#include "Control/UIScrollBar.h"
#include "Control/UITreeView.h"

#include "Control/UILabel.h"
#include "Control/UIText.h"
#include "Control/UIEdit.h"

#include "Control/UIButton.h"
#include "Control/UIOption.h"
#include "Control/UICheckBox.h"

#include "Control/UIProgress.h"
#include "Control/UISlider.h"

#include "Control/UIRichEdit.h"
#include "Control/UIDateTime.h"

#include "Control/UIActiveX.h"
#include "Control/UIWebBrowser.h"
#include "Control/UIGifAnim.h"

#include "Utils/pugiconfig.hpp"
#include "Utils/pugixml.hpp"


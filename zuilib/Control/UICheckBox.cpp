#include "stdafx.h"
#include "UICheckBox.h"

namespace Zuilib
{
	LPCWSTR CCheckBoxUI::GetClass() const
	{
		return DUI_CTR_CHECKBOX;
	}

	LPVOID CCheckBoxUI::GetInterface(LPCWSTR pstrName)
	{
		if( _tcscmp(pstrName, DUI_CTR_CHECKBOX) == 0 ) 
			return static_cast<CCheckBoxUI*>(this);
		return 
			COptionUI::GetInterface(pstrName);
	}

	void CCheckBoxUI::SetCheck(bool bCheck, bool bTriggerEvent)
	{
		Selected(bCheck, bTriggerEvent);
	}

	bool  CCheckBoxUI::GetCheck() const
	{
		return IsSelected();
	}
}

#ifndef __UIHORIZONTALLAYOUT_H__
#define __UIHORIZONTALLAYOUT_H__

#pragma once

namespace Zuilib
{
	class ZUILIB_API CHorizontalLayoutUI : public CContainerUI
	{
	public:
		CHorizontalLayoutUI();

		LPCWSTR GetClass() const;
		LPVOID GetInterface(LPCWSTR pstrName);
		UINT GetControlFlags() const;

		void SetSepWidth(int iWidth);
		int GetSepWidth() const;
		void SetSepImmMode(bool bImmediately);
		bool IsSepImmMode() const;
		void SetAttribute(LPCWSTR pstrName, LPCWSTR pstrValue);
		void DoEvent(TEventUI& event);

		void SetPos(RECT rc, bool bNeedInvalidate = true);
		void DoPostPaint(HDC hDC, const RECT& rcPaint);

		RECT GetThumbRect(bool bUseNew = false) const;

	protected:
		int m_iSepWidth;
		UINT m_uButtonState;
		POINT m_ptLastMouse;
		RECT m_rcNewPos;
		bool m_bImmMode;
	};
}
#endif // __UIHORIZONTALLAYOUT_H__

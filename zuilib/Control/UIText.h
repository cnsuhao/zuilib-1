#ifndef __UITEXT_H__
#define __UITEXT_H__

#pragma once

namespace Zuilib
{
	class ZUILIB_API CTextUI : public CLabelUI
	{
	public:
		CTextUI();
		~CTextUI();

		LPCWSTR GetClass() const;
		UINT GetControlFlags() const;
		LPVOID GetInterface(LPCWSTR pstrName);

		CDuiString* GetLinkContent(int iIndex);

		void DoEvent(TEventUI& event);

		void PaintText(HDC hDC);

	protected:
		enum { MAX_LINK = 8 };
		int m_nLinks;
		RECT m_rcLinks[MAX_LINK];
		CDuiString m_sLinks[MAX_LINK];
		int m_nHoverLink;
	};

} // namespace Zuilib

#endif //__UITEXT_H__
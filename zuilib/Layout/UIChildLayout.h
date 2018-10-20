#ifndef __UICHILDLAYOUT_H__
#define __UICHILDLAYOUT_H__

#pragma once

namespace Zuilib
{
	class ZUILIB_API CChildLayoutUI : public CContainerUI
	{
	public:
		CChildLayoutUI();

		void Init();
		void SetAttribute(LPCWSTR pstrName, LPCWSTR pstrValue);
		void SetChildLayoutXML(CDuiString pXML);
		CDuiString GetChildLayoutXML();
		virtual LPVOID GetInterface(LPCWSTR pstrName);
		virtual LPCWSTR GetClass() const;

	private:
		CDuiString m_pstrXMLFile;
	};
} // namespace Zuilib
#endif // __UICHILDLAYOUT_H__

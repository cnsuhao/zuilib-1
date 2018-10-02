#ifndef __UIMARKUP_H__
#define __UIMARKUP_H__

#pragma once

#include "Utils/pugiconfig.hpp"
#include "Utils/pugixml.hpp"

namespace Zuilib {

enum
{
    XMLFILE_ENCODING_UTF8 = 0,
    XMLFILE_ENCODING_UNICODE = 1,
    XMLFILE_ENCODING_ASNI = 2,
};

typedef pugi::xml_document		XmlDoc;
typedef pugi::xml_node			XmlNode;
typedef pugi::xml_attribute		XmlAttr;
typedef pugi::xml_parse_result	XmlResult;



class CMarkup;
class CMarkupNode;


class ZUILIB_API CMarkup
{
    friend class CMarkupNode;
public:
    CMarkup(LPCTSTR pstrXML = NULL);
    ~CMarkup();

    bool Load(LPCTSTR pstrXML);
    bool LoadFromMem(BYTE* pByte, DWORD dwSize, int encoding = XMLFILE_ENCODING_UTF8);
    bool LoadFromFile(LPCTSTR pstrFilename, int encoding = XMLFILE_ENCODING_UTF8);
    void Release();
    bool IsValid() const;

    void SetPreserveWhitespace(bool bPreserve = true);
    void GetLastErrorMessage(LPTSTR pstrMessage, SIZE_T cchMax) const;
    void GetLastErrorLocation(LPTSTR pstrSource, SIZE_T cchMax) const;

	XmlNode GetRoot();
private:
	//XML�ڵ�Ԫ�����Ͷ��� 
    typedef struct tagXMLELEMENT
    {
        ULONG iStart;	//�ڵ�Ԫ����xml�ļ��е���ʼλ��
        ULONG iChild;	//�ڵ�Ԫ���ӽڵ�
        ULONG iNext;	//�ڵ�Ԫ�ص���һ���ڵ�(�ֵܽڵ�)
        ULONG iParent;	//�ڵ�Ԫ�صĸ��ڵ�
        ULONG iData;	//�ڵ�Ԫ�ص�����
    } XMLELEMENT;

    LPTSTR m_pstrXML;			//ΪCMarkup�洢���Լ���xml�ļ��������ݵ�ָ�뻺����
	XmlDoc m_parser;

    XMLELEMENT* m_pElements;	//����XMLELEMENT���͵Ľڵ�Ԫ����Ϣ�Ļ���������ʵ�Ͽ����в���δԤ�ϵĴ洢�ռ䣻
    ULONG m_nElements;			//ʵ�ʵı���m_pElements����Ч�Ľڵ�Ԫ����
    ULONG m_nReservedElements;	//Ԥ����m_pElements�������ռ��С
    TCHAR m_szErrorMsg[100];
    TCHAR m_szErrorXML[50];
    bool m_bPreserveWhitespace;

private:
    bool _Parse();
    bool _Parse(LPTSTR& pstrText, ULONG iParent);
    XMLELEMENT* _ReserveElement();
    inline void _SkipWhitespace(LPTSTR& pstr) const;
    inline void _SkipWhitespace(LPCTSTR& pstr) const;
    inline void _SkipIdentifier(LPTSTR& pstr) const;
    inline void _SkipIdentifier(LPCTSTR& pstr) const;
    bool _ParseData(LPTSTR& pstrText, LPTSTR& pstrData, char cEnd);
    void _ParseMetaChar(LPTSTR& pstrText, LPTSTR& pstrDest);
    bool _ParseAttributes(LPTSTR& pstrText);
    bool _Failed(LPCTSTR pstrError, LPCTSTR pstrLocation = NULL);
};


#if 0
class ZUILIB_API CMarkupNode
{
    friend class CMarkup;
private:
    CMarkupNode();
    CMarkupNode(CMarkup* pOwner, int iPos);

public:
    bool IsValid() const;

    CMarkupNode GetParent();
    CMarkupNode GetSibling();
    CMarkupNode GetChild();
    CMarkupNode GetChild(LPCTSTR pstrName);

    bool HasSiblings() const;
    bool HasChildren() const;
    LPCTSTR GetName() const;
    LPCTSTR GetValue() const;

    bool HasAttributes();
    bool HasAttribute(LPCTSTR pstrName);
    int GetAttributeCount();
    LPCTSTR GetAttributeName(int iIndex);
    LPCTSTR GetAttributeValue(int iIndex);
    LPCTSTR GetAttributeValue(LPCTSTR pstrName);
    bool GetAttributeValue(int iIndex, LPTSTR pstrValue, SIZE_T cchMax);
    bool GetAttributeValue(LPCTSTR pstrName, LPTSTR pstrValue, SIZE_T cchMax);

private:
    void _MapAttributes();

    enum { MAX_XML_ATTRIBUTES = 64 };

	//�ڵ����Խṹ�嶨�壬iNameΪ��������iValueΪ����ֵ
    typedef struct
    {
        ULONG iName;
        ULONG iValue;
    } XMLATTRIBUTE;

    int m_iPos; //ָ�������Խڵ�������ӵ����(ָCMarkup����)�еĽڵ�Ԫ���еĵ�ǰλ��
    int m_nAttributes; //�ڵ���������
    XMLATTRIBUTE m_aAttributes[MAX_XML_ATTRIBUTES]; //�ڵ�֧�����64�����Ը���
    CMarkup* m_pOwner; //�ýڵ�����ӵ����(ָCMarkup����)
};
#endif // 

} // namespace ZuiLib

#endif // __UIMARKUP_H__

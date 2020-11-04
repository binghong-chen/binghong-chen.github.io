/*
面试题1：赋值运算符重载
*/

#include<iostream>

using namespace std;

class CMyString
{
    public:
        CMyString(char* pData = NULL);
        CMyString(const CMyString& str);
        ~CMyString(void);

        CMyString& operator=(const CMyString& str);    

        void Print();

    private:
        char* m_pData;
};

CMyString::CMyString(char* pData)
{
    // m_pData = pData;

    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    // m_pData = str.m_pData;

    int length = strlen(str.m_pData);
    m_pData = new char[length];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

void CMyString::Print()
{
    cout << m_pData << endl;
}

CMyString& CMyString::operator=(const CMyString& str)
{
    // if(this == &str)
    //     return *this;
    // delete[] m_pData;
    // m_pData = NULL;
    // m_pData = new char[strlen(str.m_pData) + 1];
    // strcpy(m_pData, str.m_pData);

    // return *this;

    if(this != &str)
    {
        CMyString strTemp(str);

        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }

    return *this;
}

void Test1()
{
    cout << "Test1 begins:" << endl;

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    cout << "The expected result is:" << text << endl;

    cout << "The actual result is: ";
    str2.Print();
}

void Test2()
{
    cout << "Test2 begins:" << endl;

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    cout << "The expected result is:" << text << endl;

    cout << "The actual result is: ";
    str1.Print();
}

void Test3()
{
    cout << "Test3 begins:" << endl;

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str2 = str3 = str1;

    cout << "The expected result is:" << text << endl;

    cout << "The actual result is: ";
    str2.Print();

    cout << "The expected result is:" << text << endl;

    cout << "The actual result is: ";
    str3.Print();
}

int main()
{
    Test1();
    Test2();
    Test3();
    
    return 0;
}
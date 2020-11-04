#include<iostream>
using namespace std;

char* MyReplaceBlank(char* string)
{
    // TODO 命名不规范问题，已经修改了
    // TODO 没有做特殊情况检测 防御性编程
    if(string == NULL) return NULL;
    int indexOfString = 0;
    int blankCount = 0;
    char c;
    while((c = string[indexOfString++]) != '\0')
    {
        if(c == ' ') blankCount ++;
    }

    // char* returnString;
    char* returnString = new char[indexOfString + 2 * blankCount];
    indexOfString = 0;
    int indexOfReturnString = 0;
    while(true)
    {
        c = string[indexOfString++];
        if(c == ' ')
        {
            returnString[indexOfReturnString++] = '%';
            returnString[indexOfReturnString++] = '2';
            returnString[indexOfReturnString++] = '0';
        }
        else
        {
            returnString[indexOfReturnString++] = c;
        }
        if(c == '\0') break;
    }

    return returnString;
}

// 在原来的字符串上替换，length为字符串总容量
void ReplaceBlank(char string[], int length)
{
    // TODO 没有做特殊情况检测 防御性编程
    if(string == NULL || length <= 0) return;
    // originalLength为字符串string的实际长度
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++originalLength;
        if(string[i] == ' ') ++numberOfBlank;
        ++i;
    }

    // newLength为把空格替换成'%20'之后的长度
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length) return;  // TODO 防御性编程 超出字符串总容量 退出程序
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

int main()
{
    char* testCase1[7] = {
        "We are happy.",
        "hahaitseasy",
        "",
        " ",
        "  ",
        "   ",
        "Hello      World"
    };

    int numberOfTestCase = 7;
    for(int i=0;i<numberOfTestCase;i++)
    {
        cout << MyReplaceBlank(testCase1[i]) << endl;
    }

    char* nullStr = NULL;
    if(MyReplaceBlank(nullStr) == NULL) cout << "NULL" << endl;

    cout << "---------------------------" << endl;

    char testCase2[7][100] = {
        "We are happy.",
        "hahaitseasy",
        "",
        " ",
        "  ",
        "   ",
        "Hello      World"
    };
    for(int i=0;i<numberOfTestCase;i++)
    {
        ReplaceBlank(testCase2[i], 100);
        cout << testCase2[i] << endl;
    }

    ReplaceBlank(nullStr, 100);
    if(nullStr == NULL) cout << "NULL" << endl;

    return 0;
}
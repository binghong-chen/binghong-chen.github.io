#include<iostream>
using namespace std;

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    char* str3 = "hello world";
    char* str4 = "hello world";

    if(str1 == str2) cout << "str1 and str2 are same." << endl;
    else  cout << "str1 and str2 are not same." << endl;
    // not same

    if(str3 == str4) cout << "str3 and str4 are same." << endl;
    else  cout << "str3 and str4 are not same." << endl;
    // same

    return 0;
}
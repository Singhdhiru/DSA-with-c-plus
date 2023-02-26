#include <iostream>
using namespace std;

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;
    // *attention here
    cout << ch << endl;

    char *c = &ch[0];
    // *prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp; //* jabtak null character n mil jaye tak kuch bhi print kar lega

    cout << p << endl;

    
    char s[] = "abcd";
    char *ptr = s;
    cout << s[0] << " " << ptr[0]; //  * a a->>output

    return 0;
}
#include <iostream>
using namespace std;
void reverse_strinng(char name[], int Ans)
{
    int s = 0;
    int e = Ans - 1;
    while (s < e)
    {
        swap(name[s], name[e]);
        s++;
        e--;
    }
}
int getLenght(char name[])
{
    int lenght = 0;
    for (int i = 0; name[i] != 0; i++)
    {
        lenght++;
    }
    return lenght;
}
int main()
{
    char name[10];
    cout << "enter the char->" << endl;
    cin >> name;
    int Ans = getLenght(name);
    cout << "lengh of string is ->" << Ans << endl;
    reverse_strinng(name, Ans);
    cout << "print the reverse string->" << name << endl;
    return 0;
}
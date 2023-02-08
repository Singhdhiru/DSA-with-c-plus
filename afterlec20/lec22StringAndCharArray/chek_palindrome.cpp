#include <iostream>
using namespace std;
bool chek_palindrome(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (name[s] != name[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}
int get_lenght(char name[])
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
    char name[20];
    cout << "enter the strinng->";
    cin >> name;
    int n = get_lenght(name);
    cout << "string is palindrome or not ->" << chek_palindrome(name, n) << endl;
    return 0;
}
#include <iostream>
using namespace std;

int score = 15;

void a(int &i)
{

    cout << score << " in a" << endl;
    score++; //* yaha per a++ ho gaya isliye sabi jagah reflect kar dega always use refrence variable
    char ch = 'a';
    cout << i << endl;
}

void b(int &i)
{
    cout << score << " in b" << endl;
    cout << i << endl;
}

int main()
{
    cout << score << " in main" << endl;
    int i = 5;
    a(i);
    b(i);

    return 0;
}
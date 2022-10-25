//fahrenhite to  celcius conversion
#include<iostream>
using namespace std;
int main()
{
     float f,c;
   cout << "Enter the temperature in fahreheit" << endl;
   cin>>f;

   c = 5*(f-32)/9;
   cout << f << " fahrenheit is equal to " << c << " degree celsius" << endl;
}
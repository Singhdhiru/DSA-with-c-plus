//making of calculator using switch case
#include <iostream>
using namespace std;
int main() {
  int a, b;
  int sum, sub, multi, divi, modulo;

  while (1) {
    cout << "enter number for addtion +" << endl;
    cout << "enter number for subtraction -" << endl;
    cout << "enter number for division /" << endl;
    cout << "enter number for multiplication *" << endl;
    cout << "enter number for check even or odd %" << endl;
    char operation;
    cout << "enter opertion " << endl;
    cin >> operation;
    switch (operation) {
    case '+':
      cout << "enter a number" << endl;
      cin >> a;
      cout << "enter a second number" << endl;
      cin >> b;
      cout << (a + b) << endl;
      break;
    case '-':
      cout << "enter a number" << endl;
      cin >> a;
      cout << "enter a second number" << endl;
      cin >> b;
      cout << (a - b) << endl;
      break;
    case '/':
      cout << "enter a number" << endl;
      cin >> a;
      cout << "enter a second number" << endl;
      cin >> b;
      cout << (a / b) << endl;
      break;
    case '*':
      cout << "enter a number" << endl;
      cin >> a;
      cout << "enter a second number" << endl;
      cin >> b;
      cout << (a * b) << endl;
      break;
    case '%':
      cout << "enter a number" << endl;
      cin >> a;
      cout << "enter a second number" << endl;
      cin >> b;
      cout << (a % b) << endl;
      break;
    case '@':
      exit(0);
    default:
      cout << "invalid choice" << endl;
    }
  }
}
// cin ka only use hi user se intput lena that sit
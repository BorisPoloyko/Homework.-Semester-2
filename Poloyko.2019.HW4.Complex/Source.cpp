#include <iostream>
#include "Complex.hpp"

using namespace std;

int main()
{
    Complex complex1, complex2;
    cin >> complex1;
    cin >> complex2;
    cout << complex1;
    cout << complex2;
    Complex complex3;
    complex3 = complex1 / complex2;
    cout << complex3;
}

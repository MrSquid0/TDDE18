#include <iostream>
#include "adicion3.h"

using namespace std;

int main (int argc, char *argv[]) {
    int a, b;
    cout << "Introduce el primer valor: ";
    cin >> a;
    cout << "Introduce el segundo valor: ";
    cin >> b;
    
    cout << "suma(" << a << ", " << b << ") = " << suma(a,b) << endl;
    cout << "resta(" << a << ", " << b << ") = " << resta(a,b) << endl;
    
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a11,a12,a21,a22;
    int determinante; 
    
    a11 = 0;
    a12 = 0; 
    a21 = 0;
    a22 = 0;
    determinante = 0; 
    
    cout << "inserisci il a11" << endl;
    std::cin >> a11;
    cout << "inserisci il a12" << endl;
    std::cin >> a12;
    cout << "inserisci il a21" << endl;
    std::cin >> a21;
    cout << "inserisci il a22" << endl;
    std::cin >> a22;
    
    determinante = a11 *  a22 -  a12 * a21;
    cout << "il determinante è " << endl;
    cout <<  determinante << endl;
    
    return 0 ; 
    
}

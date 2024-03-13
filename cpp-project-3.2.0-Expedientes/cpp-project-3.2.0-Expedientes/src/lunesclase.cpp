#include <iostream>
using namespace std;

int main() {
//resta de numero

int resta1, resta2, resta3;

std::cout << "ingrese un numero a restar" << '\n';

cin >> resta1;
resta3 = resta2 = resta1;

std::cout << "resta directa" << '\n';
resta1 = resta1 - resta1;
std::cout << "resultado" << '\n';


//resta 1.b

//resta2

while(resta2>0){
    resta2--;
    std::cout << "resultado parcial:"<< resta2 << '\n';
}
cout << "resultaod:" << resta2 <<endl;

//resta 3


    return 0;
}
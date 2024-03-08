#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cin;
vector <string> identidad{};
int main() {
    identidad.push_back("8888");
    identidad.push_back("5555");
    identidad.push_back("7777");
    string buscar;
    cin >> buscar;
    int index;
    for(int i = 0; i < identidad.size(); i ++){
        if(buscar ==identidad[i]){
            index = i;
        }
    } 
    std::cout << "has escrito: " << identidad[index] << '\n';

    
    
    return 0;
}
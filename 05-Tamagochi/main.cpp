#include <iostream>

#include "pet.hpp"
#include "pet.cpp"

using namespace std;

int main()
{
    Pet p("Bixanuh", 15, 10, 300);
    p.play();
    cout << p.toString() << endl;
    p.play();
    cout << p.toString() << endl;
    p.play();
    cout << p.toString() << endl;
    p.play();
    while(p.testAlive()){
            p.play();
        }
        
    cout << p.toString() << endl;
    
    return 0;
}
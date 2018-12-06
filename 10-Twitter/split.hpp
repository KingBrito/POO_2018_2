// SPLIT.h
#ifndef SPLIT
#define SPLIT
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string line){
     vector<string> saida;
     stringstream ss(line);
     string palavra;
     
     while(ss >> palavra){
         saida.push_back(palavra);
     }
     return saida;
}

template <class T> 
T cast (string palavra){
    T value;
    stringstream(palavra) >> value;
    return value;
}

template <class T>
string vet2str(string prefix, vector<T> vet, string between){
    stringstream ss;
    ss << prefix;
    for(auto&& elem : vet){
        ss << elem.toString() << between;
    }
    return ss;
}


#endif
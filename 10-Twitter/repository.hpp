//REPOSITORY.hpp
#ifndef REPOSITORY
#define REPOSITORY
#include<iostream>
#include<map>
#include<vector>

using namespace std;

template <class T>
class Repository{
    private:
        map<string,T> rep;
        string nomeTipo;
    public:
        Repository(string nomeTipo = " "): nomeTipo(nomeTipo)
        {}

        T* add(string key,T t){
            if(rep.count(key) == 1){
                throw "" + nomeTipo + " " + key + "ja existe";
            }
            rep[key] = t;
            return &rep[key];
        }

        bool exist(string key){
            return rep.count(key);
        }

        void rm(string key){
            if(!rep.erase(key)){
                throw "" + nomeTipo + " " + key + "não existe";
            }
        }

        T& at(string key){
            if(!Repository::exist(key))
                throw "" + nomeTipo + " " + key + "não existe";
            return rep[key];
        }

        std::vector<T> getValue(){
            std::vector<T> value;
            for(auto var: rep)
                value.push_back(var.second);
            return value;
        }

        std::vector<string> getKey(){
            std::vector<string> value;
            for(auto var: rep)
                value.push_back(var.first);
            return value;
        }
};

#endif
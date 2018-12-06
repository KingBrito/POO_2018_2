#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include "repository.hpp"
#include "twitter.hpp"
#include "user.hpp"
#include "tweetgenerator.hpp"

using namespace std;

class Controller{
private:
    Repository <User> r_user;
    Repository <Tweet> r_tw;
    Tweetgenerator twGen;

public:
    Controller():
    r_user("usuario"),r_tw("tweet"),twGen(&r_tw)
    {
    }

    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
        if(op == "help"){
            cout << "help; " << endl;
        }else{
            throw string("fail: comando invalido \n use o help");
        }
    }

    void exec(){
        string line;
        while(true){
            getline(cin,line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            try{
                shell(line);
            }catch(string e){
                cout << e << endl;
            }

        }
    }
};



#endif
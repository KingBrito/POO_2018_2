// GENERATOR    
#ifndef GENERATOR   
#define GENERATOR   
#include <iostream>
#include "twitter.hpp"
#include <sstream>

using namespace std;
class Tweetgenerator
{
private:
    Repository <Tweet> * r_tw;
    int nextId;
public:
    Tweetgenerator(Repository<Tweet> * r_tw){
        this->r_tw = r_tw;
    }
    
    ~Tweetgenerator() { }
    Tweet* create(string username,string msg){
        int id = nextId;
        nextId++;
        return r_tw->add(to_string(id),Tweet(id,username,msg));
    }
};

#endif
// Tweet
#ifndef TWEET
#define TWEET

#include <iostream>
#include <list>
using namespace std;

class Tweet
{
private:
    int idTw;
    string username;
    string msg;
    list<string> likes;
    friend ostream& operator<<(ostream& ss, Tweet twitt);

public:
    Tweet(int idTw,string username,string msg)
    {
        this->idTw = idTw;
        this->username = username;
        this->msg = msg;
    }
    
    ~Tweet() {

    }

    void setIdtw(int value){
    this->idTw = value;
    }
    int getIdtw(){
    return this->idTw;
    }

    void setUsername(string value){
    username = value;
    }
    string getUsername(){
    return username;
    }

    void setMsg(string value){
    msg = value;
    }
    string getMsg(){
    return msg;
    }


    void addLikes(string username){
        
        for(auto&& elem : likes){
            if(elem == username)
                return;
        }
        likes.push_back(username);
    }

    void toString(){
        
        for(auto&& elem : likes)
        {   
            
        }
        
    }

    
};
ostream& operator<<(ostream& ss, Tweet twitt){
    ss << twitt.getIdtw() << " " << twitt.getUsername() << ":" << twitt.getMsg();
    ss << "{";
    for(auto&& elem : twitt.likes)
    {
        ss << " " << elem; 
    }
    ss << "}";
    return ss;
}
#endif
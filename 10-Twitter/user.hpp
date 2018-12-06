// USER.h
#ifndef USER
#define USER
#include <iostream>
#include "twitter.hpp"
#include <sstream>
using namespace std;

class User
{
public:
    string username;
    list<User*> seguidores;
    list<User*> seguidos;
    list<Tweet*> myTweets;
    list<Tweet*> timeline;
    int unreadCount;
    User(string username):username(username)
    { }
    ~User() { 

    }
    void seguir(User * user){
        
        for(auto elem : seguidos){  
            if (elem->username == user->username) {
                return;
            }
        }
        seguidos.push_back(user);
        user->seguidores.push_back(this);
    }
    
    void twittar(Tweet * tweet){
        myTweets.push_front(tweet);
        for(User * user: seguidores){
            user->unreadCount ++;
            user->timeline.push_front(tweet);
        }
    }

    list<Tweet*> getUnread(){
        list<Tweet*> noRead;
        auto it = timeline.begin();        
        
        for(int count = 0; count < unreadCount; count++,it++){
            noRead.push_back(*it);
        }
        unreadCount = 0;
        return noRead;
    }
    list<Tweet*> getTimeline(){
        unreadCount = 0;
        return timeline;
    }
    
};

#endif
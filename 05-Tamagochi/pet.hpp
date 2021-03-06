#ifndef PET_H
#define PET_H

#include <iostream>
#include <sstream>
using namespace std;

class Pet{
private:
    string nome;
    int energyMax, hungryMax, cleanMax; 
    int energy, hungry, clean;   
    int age; // {0};
    int diamond; // {0};
    bool alive {true};
    
    void setValue(int value, int &target, int limit){
        if(value <= 0){
            this->alive = false;
            target = 0;
        }else if(value > limit){
            target = limit;
        }else
            target = value;
    }


public:
    Pet(string nome = "pet", int energyMax = 0, int hungryMax = 0, int cleanMax = 0);
    
    string getNome();  //declaracao
    void setNome(string nome){
        this->nome = nome;
    }
    int getEnergyMax(){
        return energyMax;
    }
    int getHungryMax(){
        return hungryMax;
    }
    int getCleanMax(){
        return cleanMax;
    }
    int getAge();

    string toString(){
        stringstream ss;
        ss << "N:" << nome << ", " 
           << "E:" << energy << "/" << energyMax << ", "
           << "H:" << hungry << "/" << hungryMax << ", "
           << "C:" << clean  << "/" << cleanMax  << ", "
           << "D:" << diamond << ", A:" << age;
        return ss.str();
    }


    void setEnergy(int value){
        setValue(value, energy, energyMax);        
    }
    
    void setHungry(int value){
        setValue(value, hungry, hungryMax);        
    }

    void setClean(int value){
        setValue(value, clean, cleanMax);        
    }

    bool testAlive(){
        if(alive)
            return true;
        cout << "fail: pet esta morto" << endl;
        return false;
    }

    void play(){
        if(!testAlive())
            return;
        setEnergy(energy - 2);
        setHungry(hungry - 1);
        setClean(clean - 3);
        this->age += 1;
        this->diamond +=1;
    }

    void eat(){
        
        setEnergy(energy - 1);
        setHungry(hungry + 4);
        setClean(clean - 2);
        this->age += 1;
    }
    void sleep(){
        setEnergy(energyMax);
        setHungry(hungry - 1);
        setClean(clean - 1);
        this->age +=1;
    }
    void cleaner(){
        setEnergy(energy - 3);
        setHungry(hungry - 1);
        setClean(clean - cleanMax);
        this->age -= 2;
    }

};



#endif

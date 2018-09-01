#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Passageiro
{   string nome;
    int idade;
    

    Passageiro(string nome = "",int idade = 00){
        this->nome = nome;
        this->idade = idade;
    }

    string toString()
    {
        stringstream ss;
        ss << this->nome << ":" << this->idade;
        return ss.str();
    }

};

struct Topic{
    int chairPref;
    vector <Passageiro*> passageiros;


    Topic(int lotMax = 0,int chairPref = 0):
        passageiros(lotMax, __nullptr),
        chairPref(chairPref)
    {
    }

    ~Topic(){
      for(auto elem: passageiros){
        delete(elem);
      }
    }

    int start(int lotMax = 0,int chairPref = 0){
        cin >> chairPref;
        this->chairPref = chairPref;
        return 0;
    }

    string toString()
    {   
        cout << "[" << " ";
        for (int i = 0; i < (int) passageiros.size() ; i++)
        {   
            if ((passageiros[i] == __nullptr) && (passageiros[i]->idade >= 60)){
                cout << "@"<< passageiros[i]->toString();
            }
            else if ((passageiros[i] != __nullptr) && (passageiros[i]->idade <= 60)){
                cout << "#"<< passageiros[i]->toString();
            }
            
            if(i < this->chairPref)
                cout << "@" << " ";
            else if(i > this->chairPref)
                cout << "=" << " ";
        }
        cout << "]";
    }

    int findNormal(){
      for(int i = chairPref; i < (int) passageiros.size(); i++){
        if(passageiros[i] == __nullptr)
            return i;
      }
      return -1;
    }

    int findPref(){
      for(int i = 0; i < this->chairPref; i++){
        if(passageiros[i] == __nullptr)
            return i;
      }
      return -1;
    }

    int find(string nome){
      for(int i = 0; i < (int) passageiros.size();i++){
        if((passageiros[i] != __nullptr) && (passageiros[i]->nome == nome)){
          return i;
        }
      }
      return -1;
    }
    bool inPsger(string nome,int age)
    {  
       if(this->find(nome) != -1){
          cout << "fail: Essa pessoa já está na topique";
          return false;
      }
      int cadPref = findPref();
      int cadNor = findNormal();
      
      if (cadNor == -1 && cadPref == -1){
        cout << "fail: Topique lotada";
        return false;
      }

      int pos;
      if (age >= 60){
            pos = cadPref != -1 ? cadPref : cadNor;
            passageiros[pos] = new Passageiro(nome, age);
            return true;
      }else if(age <= 59){
            pos = cadNor != -1 ? cadNor : cadPref;
            passageiros[pos] = new Passageiro(nome, age);
            return true;
      }else {
        cout << "fail: Operação não reconhecida, faça novamente";
        return false;
      }
        return true;
    }

    bool outPsger(string nome)
    {
        for(int i = 0; i < (int) passageiros.size(); i++){
            if(passageiros[i] != __nullptr && passageiros[i]->nome == nome){
                delete passageiros[i];
                passageiros[i] = __nullptr;
                return true;
            }
        }
        cout << "fail: Passageiro não esta na topique";
        return false;
      
    }



};

struct Controller{
  Topic nene;

  string shell(string linha){
    stringstream userIn(linha);
    stringstream userOut;
    string op;
    userIn >> op;
    if (op == "show")
        nene.toString();
    if(op == "in"){
      string nome;
      int idade;
      userIn >> nome >> idade;
      if(nene.inPsger(nome,idade))
          userOut << "  done";
    }
    if(op == "out"){
      string nome;
      userIn >> nome;
      if(nene.outPsger(nome))
        userOut << " done";
    }
    if(op == "init"){
      int lotMax;
      int chairPref;
      userIn >> lotMax >> chairPref;
      userOut << "  done";
    }
    
  }


  void io(){
    string linha;
      while(1){
        getline(cin,linha);
        if (linha == "end"){
          return;
        }
        cout << shell(linha) << endl;
      }
  }

};

int main(){
    setlocale(LC_ALL, "Portuguese");
    Controller c;
    c.io();
    return 0;
}

// O __nullptr esta dessa maneira por causa do compilador que foi usado // no momento. e não é um erro  
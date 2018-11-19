#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<locale.h>
using namespace std;

template <typename K,typename V>
class Repository
{
private:
    map<K,V> rep;
    string _typename;

public:
    Repository(string _typename = "") {
        this-> _typename = _typename;
     }
     
     void add(K k,V v){
        //  auto it = rep.find(K);
        //  if (it == rep.end()) {
        //      throw "fail: nao existe";
        //  }
        if(rep.count(k) != 0){
            throw string("")+_typename + " " + k + "ja existe";
        }
        rep[k] = v;
     }

     V& get(K k){
         auto it = rep.find(k);
         if (it == rep.end()) {
             throw string("")+_typename + " " + k + "nao existe";
        }
        return *it;
     }

     bool existe(K k){
         return rep.count(k) != 0;
     }

     void remove(K k){
         auto it = rep,find(k);
         if(it == rep.end()){
             throw _typename + " " + k + "nao existe"; 
         }
         rep.erase(it);
     }
    vector<K> getKey(){
        vector<K> values;
        for(auto& par : rep)
        {
            values.push_back(par.first);
        }
        return values;
    }

    vector<V> getValue(){
        vector<V> values;
        for(auto& par : rep)
        {
            values.push_back(par.second);
        }
        return values;
    }

    vector<pair<K,V>> getKValue(){
        vector<pair<K,V>> values;
        for(auto& par : rep)
        {
            values.push_back(par);
        }
        return values;
    }

    

};



class Cliente
{
private:
    string nome;
    string fullname;
    float saldo;
public:
    Cliente(string nome = "", string fullname = "",float saldo = 0.0 ):
        nome(nome),fullname(fullname),saldo(saldo)
    { }
    
    float getSaldo(){
        return this->saldo;
    }
    void setSaldo(float valor){
        this->saldo = valor;
    }
    friend ostream &operator<<(ostream& os, Cliente cliente);

};
ostream &operator<< (ostream &os,Cliente cliente){
    os << cliente.nome << ":" << cliente.fullname << ":" << cliente.saldo;
    return os;
}


class Transaction
{
private:
    int id;
    string idCli;
    float value;
public:
    Transaction(int id = 0,string idCli = "", float value = 0.0):
        id(id),idCli(idCli),value(value) { }
    friend ostream &operator<<( ostream& os, Transaction tt);
    string getIdCli(){
        return idCli;
    }    
};

ostream &operator<<(ostream& os, Transaction tt){
    os << tt.id << ":" << tt.idCli << ":" << tt.value << '\n';
    return os;
}

template<typename T>
T read(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

class Agiota
{
public:
    Repository <string,Cliente> repCli;
    Repository <int,Transaction> repTT;
    float saldo;
    int nextId;

    Agiota(float saldo = 0.0):
        repCli("cliente"),repTT("transação"){
        this->saldo = saldo;
    }
    void pushTransaction(string idCli,float value){
        repTT.add(nextId,Transaction(nextId,idCli,value));
        nextId++;
    }
    void receber(string idCli, float value){
        Cliente& cliente = repCli.get(idCli);
        if(value > cliente.getSaldo())
            throw string("fail: dinheiro demais");
        cliente.setSaldo(cliente.getSaldo() + value);
        this->saldo += value;
        pushTransaction(idCli, -value);
    }

    void emprestar(string idCli,float value){
        if (value > saldo) {
            throw string("fail: saldo insuficiente");
        }
        Cliente& cliente = repCli.get(idCli);
        cliente.setSaldo(cliente.getSaldo() + value);
        this->saldo -= value;
        pushTransaction(idCli,value);
    }
};



class Master
{
private:
    Agiota pcc;
public:
    // ~Master() { }
    void shell(string line){
        std::stringstream ss(line);
        string op;
        ss >> op;
        if(op == "init"){
            pcc = Agiota(read<float>(ss));    
        }
        else if (op == "addCli")
        {
            string nome, fullname;
            ss >> nome;
            getline(ss,fullname);
            pcc.repCli.add(nome,Cliente(nome,fullname.substr(1)));
        }
        else if (op == "resumo")
        {
        for(auto& cli : pcc.repCli.getValue()){
                cout << cli << endl;
            }   
        }
        else if (op == "remove")
        {
            pcc.repCli.remove(read<string>(ss));
        }
        else if (op == "matar")
        {
          string idCli = read<string>(ss);
          pcc.repCli.remove(idCli);
          for(auto& chave : pcc.repTT.getKey()){
              if (pcc.repTT.get(chave).getIdCli() == idCli) {
                  pcc.repTT.remove(chave);
              }
          } 
         }
        
        else if (op == "emprestar")
        {   string nome;
            float saldo;
            ss >> nome >> saldo;
            pcc.emprestar(nome,saldo);
        }
        
        else if (op == "historico")
        {
            for(auto& hist: pcc.repTT.getValue())
               cout << hist << endl;
            
        }
        
        else{
            cout << "fail: comando invalido" << '\n';
        }
    }

    void exec (){
        string line;
        while (true){
            getline(cin, line);
            cout << "$" << line << endl;
            if (line == "end") 
                return;
            try{           
                shell(line);
            }catch(string e){
                cout << e << '\n';
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Master ofpuppets;
    ofpuppets.exec();
    return 0;
}

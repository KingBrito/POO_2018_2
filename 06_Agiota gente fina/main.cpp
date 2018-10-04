#include <iostream>
#include <sstream>
#include <string>
#include <stdbool.h>
#include <list>
#include <vector>

using namespace std;


class Cliente
{
private:
    string nome;
    string apelido;
    float dinheiro;
    bool estado;
    string description;

public:
    Cliente( string nome = "babaca", float dinheiro = 00,
    bool estado = true,string description = "nada"):
        nome(nome),dinheiro(dinheiro),description(description)
        {
            this->estado = estado;
         }
    string getNome(){
        return nome;
    }
    string getApelido(){
        return apelido;
    }
    float getDinheiro(){
        return dinheiro;
    }

    void setApelido(string apelido){
        this->apelido = apelido;
    }
    void setDinheiro(float dinheiro){
        this->dinheiro = dinheiro;

    }
    void addDescription(string description){

    }

};

class Agiota
{
private:
    float money;
    vector<Cliente> babacas;

public:
    Agiota(float money);
    ~Agiota();
    void init(float money){
        this->money = money;
        cout << "   done" << endl;
        // e apaga todas as caracteristicas da outra conta
    }

    void addTr(){
    // int aux = consulta(apelido);
    //     if(aux < 0 && money < dinheiro){
    //         cout << "   fail";
    //         return;
    //     }
    //     babacas[aux].setDinheiro(dinheiro);
    }

    void addCli(Cliente cliente){
        babacas.push_back(cliente);
        return;
    }

    int consulta(string apelido){
        for(int i = 0; i < (int) this->babacas.size(); i++){
            if (this->babacas[i].getApelido() == apelido){
                return i;
            }
        }
        return -1;
    }

    string toString(string option){
        stringstream ss;
        
        for(int i = 0; i < (int)babacas.size(); i++){
            ss << "id:" << i << " " << "[" << babacas[i].getApelido() << 
            " " << endl;
        }
        // id:0 [maria -300]
        return ss.str();
    }

};


struct Master
{
   Agiota pnc;
    string shell (string line){
        stringstream in;
        stringstream out;
        string op;
        in >> op;
            if(op == "help"){
                out << "show; init;";
            }
            else if(op == "init")
            {
                float minicial;
                in >> minicial;
                out << pnc.init(minicial) << endl;
            }else if(op == "show"){
                string option;
                in >> option;
                pnc.toString(option);
            }else if(op == "add"){
                stringstream ss(line);
                string comando;
                getline(ss,comando);
                    if(comando == "cli"){
                        string nome,fullname;
                        getline (ss,nome);
                        getline (ss,fullname);
                        pnc.addCli( Cliente(nome,fullname))
                    }else if(comando == "tr"){
                        
                    }
            }            
    }

   void io(){
       string line;
        while(1){
            getline(cin,line);
            if(line == "end")
                break;
            cout << line << endl;
            cout << " " << shell(line) << endl;
        }   
   }
   
};


int main(int argc, char const *argv[])
{
    Master pupilo;
    pupilo.io();
    return 0;
}

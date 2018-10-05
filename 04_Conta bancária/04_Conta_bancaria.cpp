#include <iostream>
#include <sstream>
#include <string>
#include <locale.h>

using namespace std;


class Banco
{
private:
    int numBank;
    float saldo;

public:
    Banco(int numBank = (int)000 ; float saldo = (int)000):
    numBank(numBank),saldo(saldo)
    {}
    int getSaldo(){
        return saldo;
    }
    int getnumBank(){
        return numBank;
    }

    void saque(int numSaque)
    {   if(numSaque <= 0){
            cout << "Você não tem dinheiro suficiente";
            return;
        }
        this->saldo = numSaque;
        return;
    }
    void deposito(int numDepos){
        this->saldo = numDepos;
        return;
    }
    string toString(){
        stringstream ss;
        ss << "Conta:" << numBank << " " << "Saldo:" << saldo;
        return ss.str();
    }
    string extrato(){
        stringstream ss;
        
        return ss.str();
    }

    bool init(int numBank){
        if(this->numBank == 000){
            this->numBank = numBank;
            return true;
        }else if(this->numBank != 000){
            this->numBank = numBank;
            this->saldo = 0;
            return true; 
       }
    return false;
    }




};

class Master {
    Banco enrolada;
    string makestream (string line){
        stringstream userIn(line);
        stringstream userOut;
        string op;
        userIn >> op;
        if (op == "init"){
            int numBank;
            userIn >> numBank;
            if (enrolada.init(numBank))
                    userOut << "    done";
        }else if(op == "saque"){
            int numSaque;
            userIn >> numSaque;
            enrolada.saque(enrolada.getSaldo() - numSaque);

        }else if(op == "deposito"){
            int numDepos;
            userIn >> numDepos;
            enrolada.deposito(enrolada.getSaldo() + numDepos);
        }else if (op == "show") {
            enrolada.toString();
        }else if(op == "extrato"){

        }
        
        return userOut.str();
    }

    void io(){
        string line;
        while(1){
            getline(cin,line);
            if(line == "end")
                break;
            cout << line << endl;
            cout << "  " << makestream(line) << endl;
        }

    }
};

int main(int argc, char const *argv[])
{   locale(LC_ALL,"PORTUGUESE");
    Master puppet;
    puppet.io();  
    
    return 0;
}

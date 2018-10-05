#include <iostream>
#include <vector>
#include <sstream>
#include <stdbool.h>
#include <stdio.h>

using namespace std;
class Telefone
{   public:
    string label,fone;
    
    Telefone(string label = "", string fone = "") : fone(fone), label(label)
    {
    }

    string toString()
    {
        stringstream ss;
        ss << "[" << label << ":" << fone << "]";
        return ss.str();
    }
   
    bool verificador(string fone)
    {
        string checkNum = ("123456789()");
        if (checkNum.find(fone))
            return true;
        return false;
    }
};

class Contato
{
  private:
    string nome;
    vector<Telefone> fone;

  public:
    Contato(string nome = "Default") : nome(nome)
    {
    }
    bool init(string nome)
    {
        if (this->nome == "Default")
        {
            this->nome = nome;
            return true;
        }
        puts("Já existe um contato");
        return false;
    }
    bool add(Telefone contato)
    {   
        for(auto i = 0; i < fone.size(); i++)
        {
            if(contato.fone == fone[i].fone){
                cout << "Esse numero já existe";
                return false;
            }else if(contato.verificador()){
                cout << "Esse número não está nos padrôes";
                return false;
            }else{
                fone.push_back(contato);
                return true;
            }
        }
        return false;
    }
    bool rm(string foneId)
    {
        for (auto i = 0; i < fone.size(); i++)
        {
            if (foneId == fone[i].label){
                fone.erase(fone.begin() + i);
                return true;
            }         
        }
        return false;
    }
    string toString()
    {
        stringstream ss;
        ss << nome << " ";
        for (auto elem : fone)
            ss << elem.toString();       
        return ss.str();
    }
    bool verificador(string fone)
    {
        string checkNum = ("123456789()");
        if(checkNum.find(fone))
            return true;
        return false;
    }
};


class Master{
    Contato contatos;

    string makestream(string line){
        string op;
        stringstream userIn(line);
        stringstream userOut;

        while (1)
        {
            cin >> op;
            if (op == "help")
            {
                userOut << "help ;init ;add ;del";
            }
            else if ("init")
            {
                string nome;
                userIn >> nome;
                if (contatos.init(nome))
                    userOut << "  done";
            }
            else if (op == "add")
            {
                string label, fone;
                userIn >> label >> fone;
                if (contatos.add(Telefone(label, fone)))
                    userOut << "  done";
            }
            else if (op == "show"){
                contatos.toString();
            }
        }
        return userOut.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin,line);
            if(line == "end")
                break;
            cout << line << endl;
            cout << "  " << makestream(line) << endl;
        }
    }
};


main(int argc, char const *argv[])
{
    Master puppet;
    puppet.exec();
    return 0;
}

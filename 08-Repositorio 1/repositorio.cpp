#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

template<typename K,typename T>
class Repository
{
private:
    map<K,T> rep;
    string _typename;
public:
    Repository(string _typename = "") {
        this->_typename = _typename;
     }
    void add(K k,T t){
        if (rep.count(k) != 0) {
            throw "" + _typename + " " + k + "already exist";
        }
        rep[k] = t;
    }
    void remove(K k){
     auto it = rep.find(k);
     if(it == rep.end()){
        throw "" + _typename + " " + k + "not exist"; 
     }
     rep.erase(it);
    }
    T& get(K k){
        auto it = rep.find(k);
        if(it == rep.end())
           throw string("") + _typename + " " + k + "nao existe"; 
        return *it;
    }
    vector<K> getKey(){
        vector<K> vetor;
        
        for(auto& each : rep)
        {
            vetor.push_back(each.first);
        }
        return vetor;
    }

    vector<T> getValue(){
        vector<T> vetor;
        
        for(auto& each : rep)
        {
            vetor.push_back(each.second);
        }
        return vetor;
    } 
    vector<pair<K,T>> getAll(){
        vector<pair<K,T>> vetor;
        
        for(auto& each: rep)
        {
            vetor.push_back(each);
        }
        return vetor;        
    }
};


class Aluno
{
private:
    int matricula;
    string curso;
    string nome;
public:
    Aluno(int matricula = 0, string curso = "XX", string nome = "None"):
    matricula(matricula),curso(curso),nome(nome)
    { }
    
    int getCodAlu(){
        return this->matricula;
    }
    friend ostream& operator<<(ostream& ss,Aluno aluno);
   
};

ostream& operator<<(ostream& ss,Aluno aluno){
    ss << aluno.matricula << ":" << aluno.curso << ":" << aluno.nome << endl;
    return ss;
}

class Professor
{
private:
    int codigo;
    string nome;
public:
    Professor(int codigo = 0, string nome = ""):
    codigo(codigo),nome(nome)
    { }

    int getCodPro(){
        return this->codigo;
    }
    friend ostream& operator<<(ostream& ss,Professor professor);

};
ostream& operator<<(ostream& ss,Professor professor){
    ss << professor.codigo << ":" << professor.nome << endl;
    return ss;
}

class Disciplina
{
private:
    string codigo;
    string curso;
    string nome;
public:
    Disciplina(string codigo = "",string curso = "",string nome = ""):
    codigo(codigo),curso(curso),nome(nome)
    { }

    string getCodDis(){
        return this->codigo;
    }

    friend ostream& operator<<(ostream& ss,Disciplina displina);

};
ostream& operator<<(ostream& ss,Disciplina displina){
    ss << displina.codigo << ":" << displina.curso << ":" <<displina.nome << endl;
    return ss;
}


class Datacenter
{
public:
    Repository<int,Aluno> repAluno;
    Repository<int,Professor> repProfess;
    Repository<string,Disciplina> repDiscipl;
    
    void getAlu(int codigo){
        Aluno aluno = repAluno.get(codigo);
        
        if (aluno.getCodAlu() == codigo) {
            cout << aluno << endl;
            return;
        }
    }
    void getPro(int codigo){
        Professor& professor = repProfess.get(codigo);
        
        if (professor.getCodPro() == codigo) {
            cout << professor << endl;
            return;
        }
    }
    void getDis(string codigo){
        Disciplina& disciplina = repDiscipl.get(codigo);
        
        if (disciplina.getCodDis() == codigo) {
            cout << disciplina << endl;
            return;
        }
    }
};

string operator+(string s, int i){
    return s + to_string(i);
}

template <typename T>
T read(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

class Master
{
private:
    Datacenter datamine;
public:
    // Master(/* args */) { }
    // ~Master() { }

    void shell(string line){
        stringstream ssin(line);
        string op;
        ssin >> op;

        if(op == "help"){

        }
        else if (op == "addAlu")
        {
            string nome,curso;
            int codigo;
            ssin >> codigo >> curso;
            getline(ssin,nome);
            datamine.repAluno.add(codigo,Aluno(codigo,curso,nome));
        }
        else if (op == "addPro")
        {
            string nome;
            int codigo;
            ssin >> codigo;
            getline(ssin,nome);
            datamine.repProfess.add(codigo,Professor(codigo,nome));
        }
        else if (op == "addDis")
        {
        // $addDis QXD01 estrutura de dados
            string codigo,curso,nome;
            ssin >> codigo >> curso;
            getline(ssin,nome);
            datamine.repDiscipl.add(codigo,Disciplina(codigo,curso,nome));
        }
        else if (op == "getAlu")
        {
           int codigo;
           ssin >> codigo;
           datamine.getAlu(codigo);
        }
        else if (op == "getPro")
        {
           int codigo;
           ssin >> codigo;
           datamine.getPro(codigo);

        }
         else if (op == "getDis")
        {
           string codigo;
           getline(ssin,codigo);
           datamine.getDis(codigo);
        }
         else if (op == "showAlu")
        {
            for(auto& value : datamine.repAluno.getValue())
            {
                cout << value << endl;
            }
        }
        else if (op == "showPro")
        {
            
            for(auto& value : datamine.repProfess.getValue())
            {
                cout << value << endl;
            }
            

        }
        else if (op == "showDis")
        {
            
            for(auto& value : datamine.repDiscipl.getValue())
            {
                cout << value << endl;
            }
            

        }else if (op == "rmAlu")
        {
            datamine.repAluno.remove(read<int> (ssin));
        }else if (op == "rmPro")
        {
            datamine.repProfess.remove(read<int> (ssin));

        }else if (op == "rmDis")
        {
            datamine.repDiscipl.remove(read<string> (ssin));

        }
        else
        {
            cout << "fail: command not valid" << '\n';
        }
        
    }
    void exec(){
        string line;
        while(true){
            getline(cin,line);
            if (line == "end") {
                return;
            }
            try
            {
                shell(line);
            }
            catch(string e)
            {
                cout << e << endl;
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

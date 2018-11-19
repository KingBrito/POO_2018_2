#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Nota
{
public:
    string titulo;
    string texto;
    friend ostream& operator<<(ostream& ss,Nota notas);

    Nota(string titulo = "",string texto = "")
    :titulo(titulo),texto(texto){ }
    // ~Nota() { }
    string getTitulo(){
        return this->titulo;
    }
    string getTexto(){
        return this->texto;
    }
    void setTitulo(string titulo){
        this->titulo = titulo;
    }
    void setTexto(string texto){
        this->texto = texto;
    }
    string toString(){
        return string("") + this->titulo + " " + this->texto;
    }
   
};
ostream& operator<<(ostream& ss,Nota notas){
    ss << "" << notas.getTitulo()<< " " << notas.getTitulo() ;
    return ss;
}

class Usuario
{
private:
    string username;
    string password;
    
    void setPassword(string newPass){
        this->password = newPass;
    }
    friend ostream& operator<<(ostream& ss,Usuario usuario);
public:
    vector<Nota> notas;

    Usuario(string username = "",string password = "")
    :username(username),password(password) { }
    // ~User() { }

    string getUsername(){
        return this->username;
    }

    void addNote(Nota nota){
        for(auto& value : notas){
        if (value.getTitulo() == nota.getTitulo()) {
            throw "fail: this note already exist";
            }  
        }
        notas.push_back(nota);
    }

    void rmNote(Nota nota){
        for(int i = 0; i < (int)this->notas.size(); i++){
            if (notas[i].getTitulo() == nota.getTitulo()){
                notas.erase(notas.begin()+i);
            }
        }
        throw "fail: note not exist";
    }

    void changePass(string oldPass, string newPass){
        if (oldPass == password) {
            setPassword(newPass);
        }else{
            throw "fail: password invalid";
        }
    }

    bool verifyPass(string password){
        return this->password == password;
    }

    void toString(){
        for(auto& value : notas)
        {
            cout << value.toString() << endl;   
        }
    }
};
ostream& operator<<(ostream& ss,Usuario usuario){
    ss << usuario.getUsername() << endl;
    return ss;
}

class Sistema
{
private:
    vector<Usuario> usuarios;
    string adminName;
public:
    Sistema(){
        adminName = "admin";
        usuarios.push_back(Usuario("admin", "admin"));
    }

    Usuario& getUser(string username){
        for(auto& value : usuarios){
            if (value.getUsername() == username) {
                return value;
            }
        }
        throw "fail: username does not exist";
    }

    void addUser(Usuario user){
        for(auto& value : usuarios){   
        if (value.getUsername() == user.getUsername())
            throw "fail: user already exist";        
        }
        usuarios.push_back(user);
    }

    vector<Usuario> getAll(){
        vector<Usuario> vet;
        
        for(auto all: usuarios){
            vet.push_back(all);
        }
        return vet;
    }
    
};


class GerLogin
{
private:
    Usuario * current;
    Sistema * sistema;
public:
    GerLogin(Sistema * sistema){
        this->sistema = sistema;
        this->current = nullptr;
     }
     Usuario& getCurrent(){
         if (current == nullptr) {
             throw "fail: no one logged";
         }
        return *current;
     }
     
     void login(string username,string password){
         if (current != nullptr) {
             throw "fail: already exist someone logged";
         }
         Usuario& usuario = sistema->getUser(username);
         
         if (!usuario.verifyPass(password)) {
             throw "fail: password invalid";
         }
         current = &usuario;         
     }

     void logout(){
         if (this->current == nullptr) {
             throw "fail: no one logged";
         }
         current = nullptr;
     }

};

class Master
{
private:
    Sistema system;
    GerLogin gerLog;
    Usuario * current;

public:
    Master():
    gerLog(&system){
        current = nullptr;
    }
    
    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
        
        if (op == "addUser") {
            string user,pass;
            ss >> user >> pass;
            system.addUser(Usuario(user,pass));
        } 
        else if (op == "showUsers") {
            for(auto& user : system.getAll())
            {
                cout << user << endl;
            }
        }
        else if (op == "showNotes")
        {
            if (current == nullptr) {
                cout << "fail: precisa estar logado para pegar as notas" << endl;
                return;
            }
            for(auto& value: this->current->notas)
                cout << value << endl;
                       
        }
        else if (op == "login")
        {
            string username,pass;
            ss >> username >> pass;
            
        }
        
        else {
            cout << "fail: command invalid" << endl;
        }
    }

    void exec(){
        string line;
    
    while(true){
        getline(cin,line);
        cout << "$" << line << endl;
        if(line == "end")
            return;
        try{
            shell(line);
        }
        catch(const char * e){
            cout << e << endl;
        }
    }
}
};

int main(int argc, char const *argv[])
{
    Master ofpuppets;

    return 0;
}

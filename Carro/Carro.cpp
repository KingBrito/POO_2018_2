#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

struct Carro{
    int pssgr; // Passageiros
    int limPssg; // limite de Passageiros
    float tanq; // tanque
    float limTanq; // limite do tanque
    float km; // quantidade de quilometragem

    Carro(int pssgr = 0, int limPssg = 2, float tanq = 0,float limTanq = 10,float km = 0){
        this->pssgr = pssgr; // Passageiros
        this->limPssg = limPssg; // limite de Passageiros
        this->tanq = tanq; // tanque
        this->limTanq = limTanq; // limite do tanque
        this->km = km; // quantidade de quilometragem
    }

    void show(){
        printf("Passageiros: %d; Tanque %.3f l; Quilometragem %.3f\n",pssgr,tanq,km);
    }

    bool inPsger(){
        if (pssgr < limPssg){
            pssgr+=1;
            puts("  done");
            return true;
        }else{
            puts("fail: limite de pessoas atingido no carro");
            cout<<endl;
            return false;
        }

    }

    bool outPsger(){
        if (pssgr >= 0){
            pssgr-=1;
            puts("  done");
            return true;
        }else{
            puts("fail: nao ha ninguem no carro");
            cout<<endl;
            return false;
        }

    }
    
    void fuel(){
        float qtdGas;
        puts("Coloque a quantidade de combustivel que quer: ");
        cin >> qtdGas;
        
        if(this->tanq == this->limTanq){
            cout << "O tanque não suporta essa quantidade" << endl;
            cout << "Seu tanque tem essa quantidade de combustivel " << this->tanq << endl;
        }
        else if(this->tanq < this->limTanq){

            if((qtdGas + this->tanq) > this->limTanq){
                this->tanq = this->limTanq;
                puts("  done");
            }
            else{
                this->tanq = tanq + qtdGas;
                puts("  done");
            }
        }
    }

    void drive (float km){
        if(this->pssgr == 0){
            puts("  fail: do not have passager in the car");
        
        }
        else if(this->tanq == 0 ){
            puts("  fail: fuel not to endure the travel");
            
        }
        else if(this->tanq < (km / 10)){
            puts("  fail: fuel not to endure the travel");
            
        }else{
            this->tanq = tanq - km / 10;
            this->km = this->km + km;

            puts("  done");
             
        }

    }    



};
int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Carro car;
    string op;

    while(1){
        cin>>op;
        if(op == "help"){
            cout<<"in; out; show; fuel; drive;\n";
        }
        else if(op == "in"){
            car.inPsger();
        }
        else if(op == "show"){
            car.show();
        }
        else if (op == "drive"){
            float km;
            puts("Puts the amount of the km you do want drive: ");
            cin >> km;
            car.drive(km);
        }
        else if (op == "fuel"){
            car.fuel();
        }

    }

}


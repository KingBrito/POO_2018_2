## O que você fez ?
  Fiz o carro com os metodos inPssger(),outPssger(),show(),drive(),fuel().

## Com quem e como você fez ?
  Fiz com a ajuda do monitor. O metodo inPssger(),outPssger() como esta mostrado no codigo foram feitos com um verificador para caso
o usuário tente colocar mais que o limite. Como mostrado abaixo:

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
  
   Para o metodo show(), como o nome já diz mostrar todos os atributos do carro. Como mostrado abaixo:
  
        void show(){
          printf("Passageiros: %d; Tanque %.3f l; Quilometragem %.3f\n",pssgr,tanq,km);
  }
  
    Para o método fuel(),que sua função principal é verificar o tanque e com o valor de entrada carregar,se a quantidade passar do
  limite só carrega a quantidade permitida e não usa o excedente. Como mostrado abaixo:

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
    
  O método drive(),que tem como função principal dirigir e decrementar da quantidade do tanque de combustível,e aumentar a 
quantidade da quilometragem. No caso da verificação, o método, só permite dirigir quando o carro tem combustivel e pessoas.
como mostrado abaixo:
  
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



## O que aprendeu e sabe fazer ?
  Usei meus conhecimentos em programação 

## O que tem dificuldade ainda ?
  Não apresentei nenhuma dificuldade

## Quanto tempo levou pra fazer a atividade 
  Cerca de 1 hora

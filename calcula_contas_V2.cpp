/*Calculo de contas da Republica sua mae v2 
programador: Gabriel Lima Mira 
status code: opem
*/

//declaraço de bibiliotecas

#include<iostream>
#include<string>
#include<limits>
#include <cstdio>

using namespace std;
// delcaraço de estruturas

struct republica{
    string repName;
    float TotalWhater;
    float Totalligth;
    float Totalnet;
    float Totalsinuca;
    float Totalrent;
    float TotalSavingsRep;
    float totalRep;
    
};
struct user{

    int id;
    string name;
    float whater;
    float ligth;
    float net;
    float sinuca;
    float caixaRep;
    float rent;
    float userTotal;
};

/*---------------------prenchedo a estrutura----------------*/
std::string getRepName(){
    std::string name;
    std::cout<<"digite o nome da republica ";
    std::getline(std::cin,name);
    return name;
}
float getWather()
{
    float wather;
    std::cout << "Digite o valor da agua: ";
    std::cin >> wather;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return wather;
}

float getlight()
{
    float light;
    std::cout << "Digite o valor da luz: ";
    std::cin >> light;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return light;
}

float getNet()
{
    float net;
    std::cout << "Digite o valor da net: ";
    std::cin >> net;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return net;
}

float getSinuca(){

    float sinuca;
    std::cout<<"digite o valor da sinuca: ";
    std::cin>> sinuca;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return sinuca;

}

float getRent(){

    float rent;
    std::cout<<"digite o valor total do aluguel: ";
    std::cin>>rent;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return rent;   
}

float getSavings(){

    float savings;
    std::cout<<"digite o valor total do cixinha da republica: ";
    std::cin>>savings;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return savings;   
}


void fill_acouts(republica *fil_counts)
{   fil_counts->repName = getRepName();
    fil_counts->Totalrent = getRent();
    fil_counts->TotalSavingsRep = getSavings();
    fil_counts->TotalWhater = getWather();
    fil_counts->Totalligth = getlight();
    fil_counts->Totalnet = getNet();
    fil_counts->Totalsinuca = getSinuca();
    fil_counts->totalRep = fil_counts->TotalWhater + fil_counts->Totalligth + fil_counts->Totalnet + fil_counts->Totalsinuca + fil_counts->TotalSavingsRep + fil_counts->Totalrent; 
    
}
/*---------------------criaçao de usuario-------------------*/

float divideRent(republica *rent, int qtdUser){

    float rentUser;
    rentUser = rent->Totalrent/qtdUser;
    return rentUser;  
}

float divideNet(republica *net,int qtdUser){

    float netUser;
    netUser = net->Totalnet/qtdUser;
    return netUser;
}

float divideLight(republica *ligth, int qtdUser){
    
    float ligthUser;
    ligthUser = ligth->Totalligth/qtdUser;
    return ligthUser;
}

float divideWater(republica *wather, int qtdUser){

    float watherUser;
    watherUser = wather->TotalWhater/qtdUser;
    return watherUser;
}

float divideSinuca(republica *sinuca, int qtdUser){

    float sinucaUser;
    sinucaUser = sinuca->Totalsinuca/qtdUser;
    return sinucaUser;
}

float divideSavings(republica *savings,int qtdUser){

    float savingsUser;
    savingsUser = savings->TotalSavingsRep/qtdUser;
    return savingsUser;
}

std::string getName(){
    std::string name;
    std::cout<<"digite o nome do universitario: ";
    std::getline(std::cin,name);
    return name;
}
float getIndividualRent(user* newUser, int userId)
{
    std::cout << "Digite o valor do aluguel para " << newUser[userId].name << ": ";
    float rent; 
    std::cin >> rent;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return rent;
}


void createUser(user* newUser, int qtdUser, republica* rep, bool teste){

    if(teste == true){   
        for (int i = 0; i < qtdUser; i++) {
            newUser[i].id = i;
            newUser[i].name = getName();
            newUser[i].caixaRep = divideSavings(rep, qtdUser);
            newUser[i].rent = divideRent(rep, qtdUser);
            newUser[i].whater = divideWater(rep, qtdUser);
            newUser[i].ligth = divideLight(rep, qtdUser);
            newUser[i].net = divideNet(rep, qtdUser);
            newUser[i].sinuca = divideSinuca(rep, qtdUser);
            newUser[i].userTotal =  newUser[i].caixaRep + newUser[i].rent + newUser[i].whater + newUser[i].ligth + newUser[i].net + newUser[i].sinuca;
        }
    }
    else{
            for (int i = 0; i < qtdUser; i++){
            newUser[i].id = i;
            newUser[i].name = getName();
            newUser[i].rent = getIndividualRent(newUser,i);
            newUser[i].caixaRep = divideSavings(rep, qtdUser);
            newUser[i].whater = divideWater(rep, qtdUser);
            newUser[i].ligth = divideLight(rep, qtdUser);
            newUser[i].net = divideNet(rep, qtdUser);
            newUser[i].sinuca = divideSinuca(rep, qtdUser);
            newUser[i].userTotal =  newUser[i].caixaRep + newUser[i].rent + newUser[i].whater + newUser[i].ligth + newUser[i].net + newUser[i].sinuca;
          }
    }
}

void printUsers(const user* newUser, int qtdUser){

    std::cout << "Usuários criados:" << std::endl;

    for (int i = 0; i < qtdUser; i++) {
        std::cout << "ID: " << newUser[i].id << std::endl;
        std::cout << "Nome: " << newUser[i].name << std::endl;
        std::cout << "Caixa da Republica: " << newUser[i].caixaRep << std::endl;
        std::cout << "Aluguel: " << newUser[i].rent << std::endl;
        std::cout << "Água: " << newUser[i].whater << std::endl;
        std::cout << "Luz: " << newUser[i].ligth << std::endl;
        std::cout << "Internet: " << newUser[i].net << std::endl;
        std::cout << "Sinuca: " << newUser[i].sinuca << std::endl;

        std::cout << "-------------------------" << std::endl;
    }
}
/*funçoes relacionadas a criaçao de aruivos */

int creatFile(user *user,republica *republica, int qtdUser){

     FILE *pontArquivo;
        
    //inicializando arquivos
     pontArquivo = fopen("planilha_de_contas.csv","w");

        //verificando o arquivo
    if(pontArquivo == NULL){
        cout<<"\no arquivo nao pode ser aberto ou esta sendo utilizado\n";
    }
        //salvando dados no arquivo 
             fprintf(pontArquivo,"ID;NOME;VALOR_CAIXA;VALOR_QUARTO;VALOR_AGUA;VALOR_LUZ;VALOR_NET;VALOR_SINUCA;VALOR_TOTAL\n");
                for(int i = 0; i < qtdUser; i ++){

                    fprintf(pontArquivo,"%i",user[i].id);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%s",user[i].name.c_str());
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f", user[i].caixaRep);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f", user[i].rent);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f",user [i].whater);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f",user[i].ligth);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f",user[i].net);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f",user[i].sinuca);
                    fprintf(pontArquivo,";");
                    fprintf(pontArquivo,"%.2f\n",user[i].userTotal);
                }
                
                //salvando os dados totas das contas no usuario republica
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%s",republica->repName.c_str());
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->TotalSavingsRep);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->Totalrent);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->TotalWhater);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->Totalligth);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->Totalnet);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",republica->Totalsinuca);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f\n",republica->totalRep);

        //fechando o arquivo 
        fclose(pontArquivo);
    return 0;

}
//apendando arquivo 
int apendeFile(user *user,republica *republica, int qtdUser){

     FILE *pontArquivo;
        
    //inicializando arquivos
     pontArquivo = fopen("planilha_de_contas.csv","a");

        //verificando o arquivo
    if(pontArquivo == NULL){
        cout<<"\no arquivo nao pode ser aberto ou esta sendo utilizado\n";
    }
        //salvando dados no arquivo 
            
                for(int i = 0; i < qtdUser; i ++){

                fprintf(pontArquivo,";");
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f", user[i].caixaRep);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f", user[i].rent);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",user [i].whater);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",user[i].ligth);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",user[i].net);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f",user[i].sinuca);
                fprintf(pontArquivo,";");
                fprintf(pontArquivo,"%.2f\n",user[i].userTotal);
            }
                
            //salvando os dados totas das contas da republica
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->TotalSavingsRep);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->Totalrent);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->TotalWhater);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->Totalligth);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->Totalnet);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f",republica->Totalsinuca);
            fprintf(pontArquivo,";");
            fprintf(pontArquivo,"%.2f\n",republica->totalRep);

        //fechando o arquivo 
        fclose(pontArquivo);

    return 0;

}
/* funçoes gerais*/
bool getUserInput(){

    bool teste;
    std::cout << "O aluguel e dividido igualmente?(digite ""1"" para SIM e ""0"" Para NAO): ";
    std::cin >> teste;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return teste;
}
int getQtdUser(){
    int qtdUser;
    std::cout<<"digite quantidade de usuarios: ";
    std::cin>> qtdUser;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return qtdUser;
}

int criaMenu(){
    int menu;
    std::cout<<"\n SEJA BEM VINDO \n";
    std::cout<<"\n Por favor digite a opcao desejada";
    std::cout<<"\n 1 criar planilha de gastos";
    std::cout<<"\n 2 calcular novas contas  ";
    std::cout<<"\n 0 sair!!";
    std::cin>>menu;

    return menu;
}

int main(void){

    int menu;
    int qtdUser;

    while(true){
    menu = criaMenu();

        switch(menu){

            case 0:
                cout<<"saindo...!!!";
                return 0;
            break;


            case 1://caso para criaçao de arquivo
            { 
                qtdUser = getQtdUser();
                
                user newUser[qtdUser];
                republica rep;
                bool teste;

                teste = getUserInput();

                //chamada de funçao
                fill_acouts(&rep);
                createUser(newUser, qtdUser, &rep, teste);
                printUsers(newUser, qtdUser);
                creatFile(newUser, &rep, qtdUser);

            }
            break;

            case 2:
            { 
                qtdUser = getQtdUser();
                
                user newUser[qtdUser];
                republica rep;
                bool teste;

                teste = getUserInput();

                //chamada de funçao
                fill_acouts(&rep);
                createUser(newUser, qtdUser, &rep, teste);
                printUsers(newUser, qtdUser);
                apendeFile(newUser, &rep, qtdUser);

            }
            break;

             default:
                std::cout << "Opção inválida. Digite novamente.";
             break;



        }
     }        
}

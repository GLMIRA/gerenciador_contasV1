//programade contas da rep sua mae 
//Nome do programador: Gabriel Lima Mira 
/*esse codigo tem como finalidade o calculo de contas
 da Republica de alunos da utfpr*/

//declaraço de bibliotecas

#include <iostream>
#include <string>
#include <limits>
#include <cstdio>
#include<stdio.h>
/*-------------------------------declaraçao de estruturas---------------------------------------*/
struct Moradores
{
    std::string Nome;
    int idade;
    float contasPmorador;
    float aluguel;
    float valorTotal;
};

struct contas
{
    float agua;
    float luz;
    float net;
    float sinuca;
    float caixaRep;
    float totalContas;
};
/*--------------------------------------------Preenche Contas--------------------------------------------*/

float getAgua()
{
    float agua;
    std::cout << "Digite o valor da agua: ";
    std::cin >> agua;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return agua;
}
float getLuz()
{
    float luz;
    std::cout << "Digite o valor da luz: ";
    std::cin >> luz;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return luz;
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
    std::cout<<"digite o valor da sinuca";
    std::cin>> sinuca;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return sinuca;

}

void preencheContas(contas *prenContas)
{
    prenContas->caixaRep = 20;
    prenContas->agua = getAgua();
    prenContas->luz = getLuz();
    prenContas->net = getNet();
    prenContas->sinuca = getSinuca();
    prenContas->totalContas = prenContas->agua + prenContas->luz + prenContas->net + prenContas->sinuca + prenContas->caixaRep; 
    
}

/*-----------------------------------Prenche Moradores--------------------------------------------*/
float divideContas(const contas &contas, Moradores *morador, int qtdMoradores)
{
    
    // Calculando o valor
    for (int i = 0; i < qtdMoradores; i++)
    {
        morador[i].contasPmorador = contas.totalContas/qtdMoradores;
    }

    // Retorna valor na posição zero
    return morador[0].contasPmorador;
}

float calcTotal(Moradores *morador, int i){
    
    float valorTotal = 0.0;
    valorTotal = morador[i].aluguel + morador[i].contasPmorador;

    return valorTotal;
}

void prencheMoradores(Moradores *morador, int qtdMoradores, const contas &conta)
{
    std::string nomes[] = {"Alemao", "Futino", "Jordans", "Mill", "Lucca"};
    float alugueis[] = {500.00, 360.00, 650.00, 550.00, 440.00};
    int idade[] = {24,25,19,20,18};
    for (int i = 0; i < qtdMoradores; i++)
    {
        morador[i].Nome = nomes[i];
        morador[i].idade = idade[i];
        morador[i].contasPmorador = divideContas(conta, morador, qtdMoradores);
        morador[i].aluguel = alugueis[i];
        morador[i].valorTotal = calcTotal(morador, i );
       
    }
}

void mostraMoradores(const Moradores *morador, const contas &conta, int qtdMoradores)
{
    std::cout << "Listando os moradores:\n";
    for (int i = 0; i < qtdMoradores; i++)
    {
        std::cout << "Nome: " << morador[i].Nome << std::endl;
        std::cout << "Idade: " << morador[i].idade << std::endl;
        std::cout << "valor total das contas: "<< conta.totalContas <<std::endl;
        std::cout << "Valor das contas por morador: " << morador[i].contasPmorador << std::endl;
        std::cout << "Valor do aluguel: " << morador[i].aluguel << std::endl;
        std::cout << "Valor total a pagar: " << morador[i].valorTotal << std::endl;
        std::cout << std::endl;
    }
}

/*-------------------------criaçao e gravaço em arquivos--------------------------*/
int criaArquivo(Moradores *morador,contas *conta,int qtdMoradores){

    FILE *pontArquivo;
    pontArquivo = fopen("planilha_de_contas.csv","w");

    if(pontArquivo == NULL){
        std::cout<<"o arquivo nao pode ser aberto";
        return 1;
    }
        fprintf(pontArquivo,"NOME;IDADE;CONTA DE AGUA;CONTA DE LUZ; INTHERNET;MESA DE SINUCA;CAIXA DA REP;TOTAL DE CONTAS;CONTAS POR MORADOR;ALUGUEL;TOTAL A PAGAR\n");
    for(int i=0;i<qtdMoradores;i++){
        fprintf(pontArquivo, "%s", morador[i].Nome.c_str());
        fprintf(pontArquivo,";");
        fprintf(pontArquivo, "%d", morador[i].idade);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->agua);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->luz);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->net);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->sinuca);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->caixaRep);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo,"%.2f",conta->totalContas);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo, "%.2f", morador[i].contasPmorador);
        fprintf(pontArquivo,";");
        fprintf(pontArquivo, "%.2f", morador[i].aluguel);
        fprintf(pontArquivo,";"); 
        fprintf(pontArquivo, "%.2f\n", morador[i].valorTotal);
        
     }

        fclose(pontArquivo);
        return 0;

}
//int apendaArquivo(){}

// funçao menu 

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

// main
int main()
{
    
    while(true){
        
        const int qtdMoradores = 5;
        int menu ;

        menu = criaMenu();

        switch (menu) {
             case 0:
                 std::cout << "Saindo...";
                return 0;
            break;

            case 1:
            {
                Moradores *listaMoradores = new Moradores[qtdMoradores];
                contas contasRep;

                std::cout << "Preencha os valores das contas:\n";
                preencheContas(&contasRep);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Preencha os dados dos moradores:\n";
                prencheMoradores(listaMoradores, qtdMoradores, contasRep);

                std::cout << "Dados dos moradores:\n";
                mostraMoradores(listaMoradores, contasRep, qtdMoradores);

                criaArquivo(listaMoradores, &contasRep, qtdMoradores );

                delete[] listaMoradores;

                break;

            }

            case 2:
                std::cout<<"opcao em construcao";
            break;

            default:
                std::cout << "Opção inválida. Digite novamente.";
             break;
    }

    }

    return 0;
}

#include<bits/stdc++.h>
#include<windows.h>
#define tamanho 20
using namespace std;

char palavra_sec[tamanho];
char chutes[26];
int chutes_dados = 0;

int verifica_letra(char letra);
int chute_feito();
int enforca();
void intro();
void chute();
int chute_feito(char letra);
int ganhou();
void forca();
void getPalavra();
void setPalavra();

int main(int argv, char * argc[])
{
    intro();
    getPalavra();

    do{
        forca();
        chute();
    }while(!ganhou() && !enforca());

    if(ganhou()){
        printf("\nParabens, palavra descoberta!\n\n");

        printf("  \'-=======-'/  \n");
        printf("  _|   .=.   |_  \n");
        printf(" ((|  {{1}}  |)) \n");
        printf("  \|   /|\   |/  \n");
        printf("   \__ '`' __/   \n");
        printf("     _`) (`_     \n");
        printf("   _/_______\_   \n");
        printf("  /___________\  \n");
    }

    else{
        printf("\nNao foi dessa vez, HAHAHAHAHAHA!\n");
        printf("A palavra era -- %s -- \n\n", palavra_sec);

                   printf("          {    } \n");
                   printf("          K,   } \n");
                   printf("         /  `Y`  \n");
                   printf("    _   /   /    \n");
                   printf("   {_'-K.__/     \n");
                   printf("     `/-.__L._   \n");
                   printf("     /  ' /`\_}  \n");
                   printf("    /  ' /       \n");
               printf("____   /  ' /        \n");
        printf(",-'~~~~    ~~/  ' /_        \n");
printf("      ,'             ``~~~%%',      \n");
printf("     (                     %  Y     \n");
printf("    {                      %% I     \n");
printf("   {      -                 %  `.   \n");
printf("   |       ',                %  )   \n");
printf("   |        |   ,..__      __. Y    \n");
printf("   |    .,_./  Y ' / ^Y   J   )|    \n");
printf("   \           |' /   |   |   ||    \n");
printf("    \          L_/    . _ (_,.'(    \n");
printf("     \,   ,      ^^""' / |      )   \n");
printf("       \_  \          /,L]     /    \n");
printf("         '-_`-,       ` `   ./`     \n");
printf("            `-(_            )       \n");
printf("                ^^\..___,.--`       \n");
}


    setPalavra();

    return 0;
}

int verifica_letra(char letra){
    for(int i=0;i < strlen(palavra_sec); i++){
        if(letra == palavra_sec[i])
            return 1;
    }
    return 0;
}

int letra_errada(){
    int erros = 0;

    for(int i=0;i < chutes_dados;i++){
        if(!verifica_letra(chutes[i])){
            erros++;
        }
    }

    return erros;
}

int enforca(){
    return letra_errada() >= 5;
}

int ganhou(){
    for(int i=0;i < strlen(palavra_sec); i++){
        if(!chute_feito(palavra_sec[i])){
            return 0;
        }
    }
    return 1;
}

void intro(){
    printf("/******************/\n");
    printf("/    Forca - xD   */\n");
    printf("/******************/\n\n");
}

void chute(){
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    if(verifica_letra(chute)){
        cout << "Voce acertou: a palavra tem a letra " << chute << "\n\n";
        Sleep(900);
        system("cls");
    }
    else{
        cout << "\nVoce errou: a palavra NAO tem a letra " << chute<< "\n\n";
        Sleep(900);
        system("cls");
    }
    chutes[chutes_dados] = chute;
    chutes_dados++;
}

int chute_feito(char letra){
    int achou = 0;
    for(int i=0;i < chutes_dados;i++){
        if(chutes[i] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void forca(){
    int erros = letra_errada();

    printf(" ________       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/':' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '),(erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i=0;i < strlen(palavra_sec); i++){
        if(chute_feito(palavra_sec[i]))
            cout << palavra_sec[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

void getPalavra(){
    FILE *f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        cout << "Banco de dados de palavras invalido\n\n";
        exit(1);
    }

    int num_palavras;
    fscanf(f, "%d", &num_palavras);

    srand(time(0));
    int random = rand() % num_palavras;

    for(int i=0;i <= random; i++){
        fscanf(f, "%s", palavra_sec);
    }

    fclose(f);
}

void setPalavra(){
    char op;

    cout << "Voce deseja adiciona uma nova palavra no jogo (s/n)? ";
    cin >> op;

    if(op == 'S'){
        char nova_palavra[tamanho];
        cout << "Digite a palavra, em letras maiusculas: ";
        cin >> nova_palavra;

        FILE *f;

        f = fopen("palavras.txt", "r+");
        if(f == 0){
            cout << "Arquivo com erro\n\n";
            exit(1);
        }

        int qtd;
        fscanf(f,"%d", &qtd);
        qtd++;

        fseek(f,0,SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f,0,SEEK_END);
        fprintf(f, "\n%s", nova_palavra);

        fclose(f);
    }
}

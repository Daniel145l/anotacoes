#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    //vetor dinamico
    int tam_anot = 0;
    Nota *bd_anot = (Nota*)malloc(tam_anot * sizeof(Nota));
    if(bd_anot == NULL){
        printf("Erro ao armazenar a memoria\n");
        exit(1);
    }

    char nome[101];

    printf("Como podemos te chamar?\n");
    scanf(" %[^\n]", nome);
    
    int tam_nome = strlen(nome);
    nome[tam_nome] = '\0';

    printf("Seja bem-vindo, %s!\n\n", nome);

    char cmd = 's';

    int id_df;

    do{
        printf("O que faremos hoje, %s?\n\n", nome);
        printf("1 - Escrever uma anotacao\n");
        printf("2 - Ver minhas anotacoes\n");
        printf("3 - Editar uma anotacao\n");
        printf("4 - Apagar uma anotacao\n\n");

        int opc;
        printf("Digite aqui: ");
        scanf("%d", &opc);
        system("cls");
        printf("\n");

        switch (opc)
        {
        case 1:

            printf("Digite o titulo:\n");
            char title[101];
            scanf(" %[^\n]", title);
            int tam_title = strlen(title);
            title[tam_title] = '\0';
            printf("\n");

            printf("Digite o texto:\n");
            char text[501];
            scanf(" %[^\n]", text);
            int tam_txt = strlen(text);
            text[tam_txt] = '\0';
            printf("\n");

            printf("Qual a data dessa anotacao?\n");
            Data date;
            scanf("%d/%d/%d", &date.dia, &date.mes, &date.ano);

            escrever(title, text, date, &tam_anot, &bd_anot);

            printf("\n");
            break;

        case 2:

            ver_anot(tam_anot, &bd_anot);
            break;

        case 3:

            printf("Qual o id do texto a ser editado? ");
            int id_df;
            scanf("%d", &id_df);

            int encontrei = procura_id(id_df, tam_anot, &bd_anot);

            if(!encontrei){
                printf("ID nao encontrado!\n");
                break;
            }


            printf("Digite o novo titulo do texto:\n");
            char new_title[101];
            scanf(" %[^\n]", new_title);
            int tam_new_title = strlen(new_title);
            new_title[tam_new_title] = '\0';

            printf("\nDigite o novo texto:\n");
            char new_txt[501];
            scanf(" %[^\n]", new_txt);
            int tam_new_txt = strlen(new_txt);
            new_txt[tam_new_txt] = '\0';

            printf("\nQual e a nova data da anotacao?\n");
            Data new_date;
            scanf("%d/%d/%d", &new_date.dia, &new_date.mes, &new_date.ano);

            editar(id_df, new_title, new_txt, new_date, tam_anot, &bd_anot);
            break;

        case 4:
            printf("Qual o id do texto a ser deletado? ");
            scanf("%d", &id_df);

            int encontrou = procura_id(id_df, tam_anot, &bd_anot);

            if(!encontrou){
                printf("ID nao encontrado!\n");
                break;
            }

            delete(id_df, &tam_anot, &bd_anot);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

        printf("\nAinda deseja fazer alguma tarefa no sistema? (s/n)\n");
        scanf(" %c", &cmd);
        if(cmd != 's' && cmd != 'n' && cmd != 'S' && cmd != 'N'){
            printf("Opcao invalida!\n");
            printf("Tente mais uma vez: ");
            scanf(" %c", &cmd);
        }

        printf("\n");

    }while(cmd == 's' || cmd == 'S');

    free(bd_anot);
    printf("Ate mais, %s!", nome);

    return 0;
}
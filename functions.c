#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int procura_id(int id_df, int tam_anot, Nota **bd_anot){
    for(int i = 0; i < tam_anot; ++i){
        if((*bd_anot)[i].id == id_df){
            return 1;
        }
    }
    return 0;
}

void escrever(char title[], char text[], Data date, int *tam_anot, Nota **bd_anot){

    Nota *novo_bd = (Nota*)malloc((*tam_anot + 1) * sizeof(Nota));

    for(int i = 0; i < *tam_anot; ++i){

        strcpy(novo_bd[i].title, (*bd_anot)[i].title);
        strcpy(novo_bd[i].content, (*bd_anot)[i].content);
        novo_bd[i].id = (*bd_anot)[i].id;
        novo_bd[i].date.dia = (*bd_anot)[i].date.dia;
        novo_bd[i].date.mes = (*bd_anot)[i].date.mes;
        novo_bd[i].date.ano = (*bd_anot)[i].date.ano;
    }

    strcpy(novo_bd[*tam_anot].title, title);
    strcpy(novo_bd[*tam_anot].content, text);
    novo_bd[*tam_anot].id = (*bd_anot)[*tam_anot - 1].id + 1;
    novo_bd[*tam_anot].date.dia = date.dia;
    novo_bd[*tam_anot].date.mes = date.mes;
    novo_bd[*tam_anot].date.ano = date.ano;

    free(*bd_anot);
    *bd_anot = novo_bd;
    ++(*tam_anot);
}

void ver_anot(int tam_anot, Nota **bd_anot){
    for(int i = 0; i < tam_anot; ++i){
        printf("====================================\n");
        printf("ID: %d\n", (*bd_anot)[i].id);
        printf("TITULO: %s\n", (*bd_anot)[i].title);
        printf("NOTA: %s\n", (*bd_anot)[i].content);
        printf("DATA: %d/%d/%d\n", (*bd_anot)[i].date.dia, (*bd_anot)[i].date.mes, (*bd_anot)[i].date.ano);
        printf("====================================\n\n");
    }
}

void editar(int id_df, char new_title[], char new_text[], Data new_date, int tam_anot, Nota **bd_anot){
    for(int i = 0; i < tam_anot; ++i){
        if((*bd_anot)[i].id == id_df){
            strcpy((*bd_anot)[i].title, new_title);
            strcpy((*bd_anot)[i].content, new_text);
            (*bd_anot)[i].date.dia = new_date.dia;
            (*bd_anot)[i].date.mes = new_date.mes;
            (*bd_anot)[i].date.ano = new_date.ano;
        }
    }
}

void delete(int id_df, int *tam_anot, Nota **bd_anot){

    Nota *novo_bd = (Nota*)malloc((*tam_anot - 1) * sizeof(Nota));

    for(int i = 0, j = 0; i < *tam_anot; ++i){
        if(id_df == (*bd_anot)[i].id){
            continue;
        }else {
            strcpy(novo_bd[j].title, (*bd_anot)[i].title);
            strcpy(novo_bd[j].content, (*bd_anot)[i].content);
            novo_bd[j].id = (*bd_anot)[i].id;
            novo_bd[j].date.dia = (*bd_anot)[i].date.dia;
            novo_bd[j].date.mes = (*bd_anot)[i].date.mes;
            novo_bd[j].date.ano = (*bd_anot)[i].date.ano;
            ++j;
        }
    }

    free(*bd_anot);
    *bd_anot = novo_bd;
    --(*tam_anot);
}
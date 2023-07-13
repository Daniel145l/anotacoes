typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char title[101];
    char content[501];
    Data date;
} Nota;

int procura_id(int id_df, int tam_anot, Nota **bd_anot);

void escrever(char title[], char text[], Data date, int *tam_anot, Nota **bd_anot);

void ver_anot(int tam_anot, Nota **bd_anot);

void editar(int id_df, char new_title[], char new_text[], Data new_date, int tam_anot, Nota **bd_anot);

void delete(int id_df, int *tam_anot, Nota **bd_anot);
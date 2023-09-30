#ifndef RESERVA_H
#define RESERVA_H

typedef struct {
    char nome[50];
    int quarto;
    char entrada[11];
    char saida[11];
} Reserva;

typedef struct node {
    Reserva reserva;
    struct node *prox;
} Node;

#endif

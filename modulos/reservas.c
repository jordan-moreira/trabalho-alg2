#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"

Node *lista = NULL;

void adicionar_reserva(Reserva reserva) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->reserva = reserva;
    novo->prox = lista;
    lista = novo;

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen("arquivos/reservas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escrever a reserva no arquivo
    fprintf(arquivo, "%s;%d;%s;%s\n", reserva.nome, reserva.quarto, reserva.entrada, reserva.saida);

    // Fechar o arquivo
    fclose(arquivo);
}


void remover_reserva(char *nome) {
    Node *atual = lista;
    Node *anterior = NULL;

    // Procurar a reserva na lista
    while (atual != NULL) {
        if (strcmp(atual->reserva.nome, nome) == 0) {
            // Remover a reserva da lista
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);

            // Atualizar o arquivo de reservas
            FILE *arquivo = fopen("arquivos/reservas.txt", "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                return;
            }
            Node *atual_arquivo = lista;
            while (atual_arquivo != NULL) {
                fprintf(arquivo, "%s;%d;%s;%s\n", atual_arquivo->reserva.nome, atual_arquivo->reserva.quarto, atual_arquivo->reserva.entrada, atual_arquivo->reserva.saida);
                atual_arquivo = atual_arquivo->prox;
            }
            fclose(arquivo);

            printf("Reserva removida com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Reserva nao encontrada!\n");
}

void atualizar_reserva(char *nome, Reserva nova_reserva) {
    Node *atual = lista;

    // Procurar a reserva na lista
    while (atual != NULL) {
        if (strcmp(atual->reserva.nome, nome) == 0) {
            // Atualizar a reserva na lista
            atual->reserva = nova_reserva;

            // Atualizar o arquivo de reservas
            FILE *arquivo = fopen("arquivos/reservas.txt", "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                return;
            }
            Node *atual_arquivo = lista;
            while (atual_arquivo != NULL) {
                fprintf(arquivo, "%s;%d;%s;%s\n", atual_arquivo->reserva.nome, atual_arquivo->reserva.quarto, atual_arquivo->reserva.entrada, atual_arquivo->reserva.saida);
                atual_arquivo = atual_arquivo->prox;
            }
            fclose(arquivo);

            printf("Reserva atualizada com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Reserva nao encontrada!\n");
}

void listar_reservas() {
    // Abrir o arquivo de reservas para leitura
    FILE *arquivo = fopen("arquivos/reservas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Ler as reservas do arquivo e imprimir na tela
    char linha[100];
    printf("Reservas:\n");
    while (fgets(linha, 100, arquivo) != NULL) {
        char nome[50], entrada[11], saida[11];
        int quarto;
        sscanf(linha, "%[^;];%d;%[^;];%s", nome, &quarto, entrada, saida);
        printf("Nome: %s, Quarto: %d, Entrada: %s, Saida: %s\n", nome, quarto, entrada, saida);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void buscar_reserva(char *nome) {
    Node *atual = lista;

    // Procurar a reserva na lista
    while (atual != NULL) {
        if (strcmp(atual->reserva.nome, nome) == 0) {
            printf("Reserva encontrada:\n");
            printf("Nome: %s, Quarto: %d, Entrada: %s, Saida: %s\n", atual->reserva.nome, atual->reserva.quarto, atual->reserva.entrada, atual->reserva.saida);

            // Pedir as novas informacoes da reserva
            Reserva nova_reserva;
            printf("Digite o novo nome: ");
            scanf("%s", nova_reserva.nome);
            printf("Digite o novo quarto: ");
            scanf("%d", &nova_reserva.quarto);
            printf("Digite a nova data de entrada (DD/MM/AAAA): ");
            scanf("%s", nova_reserva.entrada);
            printf("Digite a nova data de saida (DD/MM/AAAA): ");
            scanf("%s", nova_reserva.saida);

            // Atualizar a reserva na lista
            atual->reserva = nova_reserva;

            // Atualizar o arquivo de reservas
            FILE *arquivo = fopen("arquivos/reservas.txt", "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                return;
            }
            Node *atual_arquivo = lista;
            while (atual_arquivo != NULL) {
                fprintf(arquivo, "%s;%d;%s;%s\n", atual_arquivo->reserva.nome, atual_arquivo->reserva.quarto, atual_arquivo->reserva.entrada, atual_arquivo->reserva.saida);
                atual_arquivo = atual_arquivo->prox;
            }
            fclose(arquivo);

            printf("Reserva atualizada com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Reserva nao encontrada!\n");
}
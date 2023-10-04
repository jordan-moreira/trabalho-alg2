#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "crudTxt.h"
#include "crudBin.h"
#include "reservas.h"
#include "transacoes.h"

// Define códigos de escape ANSI para cores de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"

void realizarCheckIn(char* nomeResponsavel, char* nomeArquivo, char codigoPermissao)
{
    if (codigoPermissao == 'N' || codigoPermissao == 'E') {
        printf(ANSI_RED "Permissão negada.\n" ANSI_RESET);
        return;
    }
    
    FILE* arquivoReservas;

    // Verificar a extensão do arquivo para determinar o tipo de arquivo
    char* extensao = strrchr(nomeArquivo, '.');
    if (extensao == NULL) {
        printf(ANSI_RED "Arquivo de reservas inválido.\n" ANSI_RESET);
        return;
    }
    if (strcmp(extensao, ".txt") == 0) {
        arquivoReservas = fopen(nomeArquivo, "r");
    } else if (strcmp(extensao, ".bin") == 0) {
        arquivoReservas = fopen(nomeArquivo, "rb");
    } else {
        printf(ANSI_RED "Tipo de arquivo de reservas inválido.\n" ANSI_RESET);
        return;
    }

    if (arquivoReservas == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
    }

    char linha[100];
    int encontrouReserva = 0;
    while (fgets(linha, 100, arquivoReservas) != NULL) 
    {
        char* token = strtok(linha, ",");
        if (strcmp(token, nomeResponsavel) == 0) 
        {
            encontrouReserva = 1;
            char opcao;
            printf(ANSI_GREEN "Reserva encontrada para o responsavel %s\n" ANSI_RESET, nomeResponsavel);
            printf("Deseja realizar o check-in? (S/N)\n");
            scanf("%c", &opcao);
            if (opcao == 'S' || opcao == 's') 
            {
                // Atualizar o arquivo de reservas para indicar que o check-in foi realizado
                FILE* arquivoTemp = fopen("reservas_temp.txt", "w");
                while (fgets(linha, 100, arquivoReservas) != NULL) 
                {
                    char* tokenTemp = strtok(linha, ",");
                    if (strcmp(tokenTemp, nomeResponsavel) == 0) {
                        // Atualizar o campo que indica se o check-in foi realizado
                        char* tokenTemp2 = strtok(NULL, ",");
                        fprintf(arquivoTemp, "%s,%s,%s,%s,%s\n", token, tokenTemp2, "S", strtok(NULL, ","), strtok(NULL, ","));
                    } else 
                    {
                        fprintf(arquivoTemp, "%s", linha);
                    }
                }
                fclose(arquivoReservas);
                fclose(arquivoTemp);
                remove(nomeArquivo);
                rename("reservas_temp.txt", nomeArquivo);
                printf(ANSI_GREEN "Check-in realizado com sucesso para o responsavel %s\n" ANSI_RESET, nomeResponsavel);
                //Ainda a implementar módulo de pagamento
                //...
            }
            break;
        }
    }
    if (!encontrouReserva) {
        printf("Reserva nao encontrada para o responsavel %s\n", nomeResponsavel);
        printf("Deseja gerenciar as reservas? (S/N)\n");
        char opcao;
        scanf("%c", &opcao);
        if (opcao == 'S' || opcao == 's') {
            gerenciarReservas(nomeArquivo, codigoPermissao);
        }
    }
}
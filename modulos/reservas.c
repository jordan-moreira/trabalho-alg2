#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "crudTxt.h"
#include "crudBin.h"
#include "reservas.h"

// Define códigos de escape ANSI para cores de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"

int operarReserva()
{
    int codigoMenu = 0;
    printf("Digite o código referente à operação a ser realizada:\n"); // codMenu para administrar operações do hotel.

    while (codigoMenu < 1 || codigoMenu > 4)
    {
        printf("1 -" ANSI_BOLD "Fazer reserva.\n" ANSI_RESET);
        printf("2 -" ANSI_BOLD "Atualizar informações de reserva.\n" ANSI_RESET);
        printf("3 -" ANSI_BOLD "Ler informações de reserva.\n" ANSI_RESET);
        printf("4 -" ANSI_BOLD "Cancelar reserva.\n" ANSI_RESET);
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu >= 1 && codigoMenu <= 4)
        {
            return codigoMenu;
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }
    }
}

void mostrarCorrespondentes(Acomodacao *dadosBusca, char tipoArquivo)
{
    int status;
    FILE *arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacao.txt", "r") : fopen("arquivos/acomodacao.bin", "rb");
    Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao));
    printf("\nAcomodações compatíveis:\n\n");
    while (1)
    {
        status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(0, arquivo, ptrAcomodacao) : lerAcomodacaoBin(0, arquivo, ptrAcomodacao);
        if (status == 1)
        {
            if (dadosBusca->codigo == ptrAcomodacao->codigo || strcmp(dadosBusca->categoria, ptrAcomodacao->categoria) || strcmp(dadosBusca->descricao, ptrAcomodacao->descricao) || strcmp(dadosBusca->facilidades, ptrAcomodacao->facilidades))
            {

                printf("%d {\n Categoria: %s,\n Descrição: %s,\n Facilidades: %s;}\n",
                       ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->descricao, ptrAcomodacao->facilidades);
            }
            continue;
        }
        else if (status == 0 && !feof(arquivo))
        {

            continue;
        }
        else
        {
            printf("Fim do arquivo alcançado.\n");
            fclose(arquivo);
            return;
        }
    }
}

void coletarDadosReserva(Reserva *ptrReserva) // Funcao para retornar um ponteiro de memoria onde estao os dados.

{
    printf("Digite o codigo da reserva: ");
    scanf("%d%*c",&ptrReserva->codigo);

    printf("Digite o codigo do hospede responsavel pela reserva: ");
    scanf("%d%*c", &ptrReserva->hospede);

    printf("Digite o codigo da acomodacao a ser reservada: ");
    scanf("%d%*c", &ptrReserva->acomodacao);

    printf("informe a data inicial da reserva: ");
    scanf("%10[^\n]%*c", &ptrReserva->dataInicial);

    printf("informe a data final da resesrva: ");
    scanf("%10[^\n]%*c", ptrReserva->dataFinal);

    printf("o check-in foi realizado? (S/N): ");
    scanf("%c%*c", &ptrReserva->checkIn);

    printf("o check-out foi realizado? (S/N): ");
    scanf("%c%*c", ptrReserva->checkOut);

    return;
}

void checarDatasDisponiveis(int codigoAcomodacao, char tipoArquivo, Reserva *ptrReserva, int codigoReserva)
{
    int status;
    FILE *arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reserva.txt", "r") : fopen("arquivos/reserva.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);

        return;
    }

    printf("Qualquer data disponível.\n");

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerReservaTxt(0, arquivo, ptrReserva) : lerReservaBin(0, arquivo, ptrReserva);
        if (status == 1)
        {
            if (ptrReserva->acomodacao == codigoAcomodacao && (codigoReserva == 0 || codigoReserva != ptrReserva->codigo))
            {
                printf("exceto %s a %s\n", ptrReserva->dataInicial, ptrReserva->dataFinal);
            }
            continue;
        }
        else if (status == 0 && !feof(arquivo))
        {
           
            continue;
        }
        else
        {
            printf("Fim do arquivo alcançado.\n");
            break;
        }
    }
    fclose(arquivo);
}

void gerenciarReserva(char tipoArquivo, char codigoPermissao)
{

    int operacao = operarReserva();
    FILE *arquivo;
    Reserva *ptrReserva;
    int status;

    switch (operacao)
    {
    case 1:
        Acomodacao *filtroReserva;
        int codigoAcomodacao;
        
        printf("digite os dados de filtragem para buscar uma acomodacao:\n");
        filtroReserva = coletarDadosAcomodacao(tipoArquivo);
        mostrarCorrespondentes(filtroReserva, tipoArquivo);
        free(filtroReserva);

        ptrReserva = malloc(sizeof(Reserva));
        if (ptrReserva == NULL)
        {
            printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
            return;
        }

        printf("Informe o código da Acomodação que você deseja reservar: ");
        scanf("%*c%d%*c", &codigoAcomodacao);

        checarDatasDisponiveis(codigoAcomodacao, tipoArquivo, ptrReserva, 0);

        coletarDadosReserva(ptrReserva);
        
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reserva.txt", "a") : fopen("arquivos/reserva.bin", "ab");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            free(ptrReserva);
            break;
        }

        (tipoArquivo == 'T') ? adicionarReservaTxt(ptrReserva, arquivo) : adicionarReservaBin(ptrReserva, arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);

        
        free(ptrReserva);
        
        fclose(arquivo);

        break;

    case 2:
        int codigoReserva = 0;
        printf("Digite o código único da reserva  que você deseja atualizar as datas: ");
        scanf("%d%*c", &codigoReserva);

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reserva.txt", "r") : fopen("arquivos/reserva.bin", "rb");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);

            break;
        }

        ptrReserva = malloc(sizeof(Reserva));

        while (1)
        {
            status = (tipoArquivo == 'T') ? lerReservaTxt(codigoReserva, arquivo, ptrReserva) : lerReservaBin(codigoReserva, arquivo, ptrReserva);

            if (status == 1)
            {
                codigoAcomodacao = ptrReserva->acomodacao;
                break;
            }
            else if (status == 0 && !feof(arquivo))
            {

                continue;
            }
            else
            {
                printf(ANSI_RED "Reserva não encontrado ou código incorreto.\n" ANSI_RESET);
                break;
            }
        }
        fclose(arquivo);

        checarDatasDisponiveis(codigoAcomodacao, tipoArquivo, ptrReserva, codigoReserva);

        printf("informe a data inicial da reserva: ");
        scanf("%10[^\n]%*c", &ptrReserva->dataInicial);

        printf("informe a data final da resesrva: ");
        scanf("%10[^\n]%*c", ptrReserva->dataFinal);

        status = (tipoArquivo == 'T') ? atualizarReservaTxt(codigoReserva, ptrReserva) : atualizarReservaBin(codigoReserva, ptrReserva);

        status == 1 ? printf(ANSI_GREEN "Datas de reserva atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar datas de reserva" ANSI_RESET);
        free(ptrReserva);
        break;

    case 3:

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reserva.txt", "r") : fopen("arquivos/reserva.bin", "rb");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrReserva = malloc(sizeof(Reserva));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos as reservas, digite 1. Se você deseja fazer uma leitura de uma reserva específica, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                status = (tipoArquivo == 'T') ? lerReservaTxt(0, arquivo, ptrReserva) : lerReservaBin(0, arquivo, ptrReserva);

                if (status == 1)
                {
                    printf("%d {\n Codigo do hospede responsavel: %d,\n Codigo da acomodacao reservada: %d,\n data inicial da reserva: %s,\n data final da reserva: %s;\n }\n", ptrReserva->codigo, ptrReserva->hospede, ptrReserva->acomodacao, ptrReserva->dataInicial, ptrReserva->dataFinal);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoReserva = 0;
            printf("Digite o código único da reserva que você deseja ler: ");
            scanf("%d%*c", &codigoReserva);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerReservaTxt(codigoReserva, arquivo, ptrReserva) : lerReservaBin(codigoReserva, arquivo, ptrReserva);

                if (status == 1)
                {
                    printf("%d {\n Codigo do hospede responsavel: %d,\n Codigo da acomodacao reservada: %d,\n data inicial da reserva: %s,\n data final da reserva: %s;\n }\n", ptrReserva->codigo, ptrReserva->hospede, ptrReserva->acomodacao, ptrReserva->dataInicial, ptrReserva->dataFinal);
                    break;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Reserva não encontrado ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }

        free(ptrReserva); // Libere a memória alocada para ptrReserva
        fclose(arquivo);
        break;

    case 4:
        codigoReserva = 0;
        printf("Digite o código único da reserva que você deseja deletar: ");
        scanf("%d%*c", &codigoReserva);
        status = (tipoArquivo == 'T') ? deletarReservaTxt(codigoReserva) : deletarReservaBin(codigoReserva);

        status == 1 ? printf(ANSI_GREEN "Registro de reserva deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de reserva" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

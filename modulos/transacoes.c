#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int diferencaDatas(char data1[], char data2[])
{
    struct tm tm1 = {0}, tm2 = {0};
    time_t time1, time2;

    strptime(data1, "%d/%m/%Y", &tm1);
    strptime(data2, "%d/%m/%Y", &tm2);

    time1 = mktime(&tm1);
    time2 = mktime(&tm2);

    return (int) difftime(time1, time2) / 86400;  
}

float buscarValorDiaria(int codigoAcomodacao, char tipoArquivo)
{
    FILE *arquivo;
    Acomodacao *ptrAcomodacao;
    Categoria *ptrCategoria;
    int status;

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacoes.txt", "r") : fopen("arquivos/acomodacoes.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return -1;
    }

    ptrAcomodacao = malloc(sizeof(Acomodacao)); 

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(codigoAcomodacao, arquivo, ptrAcomodacao) : lerAcomodacaoBin(codigoAcomodacao, arquivo, ptrAcomodacao);

        if (status == 1)
        {
            break;
        }
        else if (status == 0 && !feof(arquivo))
        {
            continue;
        }
        else
        {
            printf(ANSI_RED "Acomodação não encontrada ou código incorreto.\n" ANSI_RESET);
            return -1;
        }
    }
    fclose(arquivo);

    char Cateogira[50] = ptrAcomodacao->categoria;

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categorias.txt", "r") : fopen("arquivos/categorias.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return -1;
    }

    ptrCategoria = malloc(sizeof(Categoria));

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerCategoriaTxt(Cateogira, arquivo, ptrCategoria) : lerCategoriaBin(Cateogira, arquivo, ptrCategoria);

        if (status == 1)
        {
            break;
        }
        else if (status == 0 && !feof(arquivo))
        {
            continue;
        }
        else
        {
            printf(ANSI_RED "Categoria não encontrada ou código incorreto.\n" ANSI_RESET);
            return -1;
        }
    }

    float valorDiaria = ptrCategoria->valor;

    free(ptrAcomodacao);

    return valorDiaria;
}

void realizarCheckIn(char tipoArquivo, char codigoPermissao)
{
    if (codigoPermissao == 'N' || codigoPermissao == 'E')
    {
        printf(ANSI_RED "Acesso Negado!" ANSI_RESET);
        return;
    }
    
    FILE *arquivo;
    Reserva *ptrReserva;
    int status,
        codigoReserva = 0,
        codigoAcomodacao;

    printf("Digite o código único da reserva que você deseja realizar o check-in: ");
    scanf("%d%*c", &codigoReserva);

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reservas.txt", "r") : fopen("arquivos/reservas.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
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
            printf(ANSI_RED "Reserva não encontrada ou código incorreto.\n" ANSI_RESET);
            return;
        }
    }
    fclose(arquivo);

    ptrReserva->checkIn = 'S';

    status = (tipoArquivo == 'T') ? atualizarReservaTxt(codigoReserva, ptrReserva) : atualizarReservaBin(codigoReserva, ptrReserva);
    status == 1 ? printf(ANSI_GREEN "Check-in realizado com sucesso.\n" ANSI_RESET) : printf(ANSI_RED "Erro ao realizar check-in.\n" ANSI_RESET);

    printf("Deseja realizar o pagamento agora? (S/N): ");
    char opcao;
    scanf("%c%*c", &opcao);
    
    if (opcao == 'S' || opcao == 's')
    {
        int diferenca = diferencaDatas(ptrReserva->dataInicial, ptrReserva->dataFinal);
        float valorDiaria = buscarValorDiaria(codigoAcomodacao, tipoArquivo);
    
        if (valorDiaria != -1)
        {
            float valorTotal = diferenca * valorDiaria;
            printf("Valor total a ser pago: R$ %.2f\n", valorTotal);
        }
        else
        {
            printf(ANSI_RED "Erro ao calcular valor total.\n" ANSI_RESET);
        }
    }

    free(ptrReserva);
}

void realizarCheckOut(char tipoArquivo, char codigoPermissao)
{
    if (codigoPermissao == 'N' || codigoPermissao == 'E')
    {
        printf(ANSI_RED "Acesso Negado!" ANSI_RESET);
        return;
    }

    FILE *arquivo;
    Reserva *ptrReserva;
    int status,
        codigoReserva = 0,
        codigoAcomodacao;

    printf("Digite o código único da reserva que você deseja realizar o check-out: ");
    scanf("%d%*c", &codigoReserva);

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reservas.txt", "r") : fopen("arquivos/reservas.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
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
            printf(ANSI_RED "Reserva não encontrada ou código incorreto.\n" ANSI_RESET);
            return;
        }
    }
    fclose(arquivo);

    ptrReserva->checkOut = 'S';

    status = (tipoArquivo == 'T') ? atualizarReservaTxt(codigoReserva, ptrReserva) : atualizarReservaBin(codigoReserva, ptrReserva);
    status == 1 ? printf(ANSI_GREEN "Check-out realizado com sucesso.\n" ANSI_RESET) : printf(ANSI_RED "Erro ao realizar check-out.\n" ANSI_RESET);

    printf("Deseja realizar o pagamento agora? (S/N): ");
    char opcao;
    scanf("%c%*c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        int diferenca = diferencaDatas(ptrReserva->dataInicial, ptrReserva->dataFinal);
        float valorDiaria = buscarValorDiaria(codigoAcomodacao, tipoArquivo);
    
        if (valorDiaria != -1)
        {
            float valorTotal = diferenca * valorDiaria;
            printf("Valor total a ser pago: R$ %.2f\n", valorTotal);
        }
        else
        {
            printf(ANSI_RED "Erro ao calcular valor total.\n" ANSI_RESET);
        }
    }

    free(ptrReserva);
}

void registrarConsumivel(char tipoArquivo, char codigoPermissao)
{
    if (codigoPermissao == 'N' || codigoPermissao == 'E')
    {
        printf(ANSI_RED "Acesso Negado!" ANSI_RESET);
        return;
    }

    FILE *arquivo;
    Reserva *ptrReserva;
    int status,
        codigoReserva = 0;

    printf("Digite o código único da reserva do hóspede: ");
    scanf("%d%*c", &codigoReserva);

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/reservas.txt", "r") : fopen("arquivos/reservas.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
    }

    ptrReserva = malloc(sizeof(Reserva));

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerReservaTxt(codigoReserva, arquivo, ptrReserva) : lerReservaBin(codigoReserva, arquivo, ptrReserva);

        if (status == 1)
        {
            break;
        }
        else if (status == 0 && !feof(arquivo))
        {
            continue;
        }
        else
        {
            printf(ANSI_RED "Reserva não encontrada ou código incorreto.\n" ANSI_RESET);
            return;
        }
    }
    fclose(arquivo);

    int codigoConsumivel, quantidade;
    float valorVenda;
    FILE *arquivoConsumivel;
    Consumivel *ptrConsumivel;

    printf("Digite o código único do consumível a ser adicionado: ");
    scanf("%d%*c", &codigoConsumivel);

    arquivoConsumivel = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "r") : fopen("arquivos/consumivel.bin", "rb");
    if (arquivoConsumivel == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
    }

    ptrConsumivel = malloc(sizeof(Consumivel));

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerConsumivelTxt(codigoConsumivel, arquivoConsumivel, ptrConsumivel) : lerConsumivelBin(codigoConsumivel, arquivoConsumivel, ptrConsumivel);
    
        if (status == 1)
        {
            break;
        }
        else if (status == 0 && !feof(arquivoConsumivel))
        {
            continue;
        }
        else
        {
            printf(ANSI_RED "Consumível não encontrado ou código incorreto.\n" ANSI_RESET);
            return;
        }
    }
    fclose(arquivoConsumivel);
    
    printf("Digite a quantidade a ser adicionada: ");
    scanf("%d%*c", &quantidade);

    valorVenda = ptrConsumivel->precoVenda * quantidade;
    ptrReserva->valorTotal += valorVenda;

    status = (tipoArquivo == 'T') ? atualizarReservaTxt(codigoReserva, ptrReserva) : atualizarReservaBin(codigoReserva, ptrReserva);
    status == 1 ? printf(ANSI_GREEN "Consumível adicionado com sucesso.\n" ANSI_RESET) : printf(ANSI_RED "Erro ao adicionar consumível.\n" ANSI_RESET);
}
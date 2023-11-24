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

int converterString(char *data, struct tm *tm_info)
{
    if (sscanf(data, "%d/%d/%d", &tm_info->tm_mday, &tm_info->tm_mon, &tm_info->tm_year) != 3)
    {
        // A análise falhou
        return 0;
    }

    // Ajuste para o formato esperado (tm_mon é base 0, e tm_year é anos desde 1900)
    tm_info->tm_mon -= 1;
    tm_info->tm_year -= 1900;

    return 1; // Análise bem-sucedida
}

int diferencaDatas(char data1[], char data2[])
{
    struct tm tm1 = {0}, tm2 = {0};
    time_t time1, time2;

    converterString(data1, &tm1);
    converterString(data2, &tm2);

    time1 = mktime(&tm1);
    time2 = mktime(&tm2);

    return (int)difftime(time1, time2) / 86400; // se data1 for menor retorna um valor negativo se data2 for menor retorna um valor positivo
}

void coletarData(char dataString)
{
    // Obter o tempo atual
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    // Formatar a data como string no formato desejado (por exemplo, "DD/MM/AAAA")
    strftime(&dataString, 20 * sizeof(char), "%Y-%m-%d %H:%M:%S", infoTempo);
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

    char categoria;

    strcpy(&categoria, ptrAcomodacao->categoria);

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categorias.txt", "r") : fopen("arquivos/categorias.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return -1;
    }

    ptrCategoria = malloc(sizeof(Categoria));

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerCategoriaTxt(&categoria, arquivo, ptrCategoria) : lerCategoriaBin(&categoria, arquivo, ptrCategoria);

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

void lerRecebimentos()
{
    FILE *arquivo = fopen("arquivos/contasReceber.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    char linha[100];

    while (!feof(arquivo))
    {
        fgets(linha, sizeof(linha), arquivo);
        printf("%s", linha);
    }
    fclose(arquivo);
}

void atualizarRecebimentos(float valorTransacao, char *vencimento, char tipoTransacao)
{
    FILE *arquivoLeitura = fopen("arquivos/contasReceber.txt", "r"),
         *arquivoEscrita = fopen("arquivos/temp.txt", "w");
    float valorCaixa;
    char dataTransacao[20];
    float valorMovimentacao;
    char dataAtual;
    coletarData(dataAtual);
    while (!feof(arquivoLeitura))
    {
        if (fscanf(arquivoLeitura, "Caixa:%f", &valorCaixa))
        {
            tipoTransacao == '+' ? (valorCaixa += valorTransacao) : (valorCaixa -= valorTransacao);
            fprintf(arquivoEscrita, "Caixa:%f", valorCaixa);
        }
        else if (fscanf(arquivoLeitura, "%[^:]:%f;", &dataTransacao, &valorMovimentacao))
        {
            fprintf(arquivoEscrita, "%s:%f;", dataTransacao, valorMovimentacao);
        }
        else if (feof(arquivoLeitura) && tipoTransacao == '+')
        {
            fprintf(arquivoEscrita, "%s:%f;", dataAtual, valorTransacao);
        }
    }
    fclose(arquivoLeitura);
    fclose(arquivoEscrita);
    remove("arquivos/contasReceber.txt");
    rename("arquivos/temp.txt", "arquivos/contasReceber.txt");
}

void lerCaixa()
{
    FILE *arquivo = fopen("arquivos/caixa.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }

    char linha[100];

    while (!feof(arquivo))
    {
        fgets(linha, sizeof(linha), arquivo);
        printf("%s", linha);
    }
    fclose(arquivo);
}

void atualizarCaixa(float valorTransacao, char tipoTransacao)
{
    FILE *arquivoLeitura = fopen("arquivos/caixa.txt", "r"),
         *arquivoEscrita = fopen("arquivos/temp.txt", "w");
    float valorCaixa;
    char dataTransacao[20], tipoMovimentacao;
    float valorMovimentacao;
    char dataAtual;
    coletarData(dataAtual);
    while (!feof(arquivoLeitura))
    {
        if (fscanf(arquivoLeitura, "Caixa:%f", &valorCaixa))
        {
            tipoTransacao == '-' ? (valorCaixa -= valorTransacao) : (valorCaixa += valorTransacao);
            fprintf(arquivoEscrita, "Caixa:%f", valorCaixa);
        }
        else if (fscanf(arquivoLeitura, "%[^:]:%c %f;", &dataTransacao, &tipoMovimentacao, &valorMovimentacao))
        {
            fprintf(arquivoEscrita, "%s:%c %f;", dataTransacao, tipoMovimentacao, valorMovimentacao);
        }
        else if (feof(arquivoLeitura))
        {
            fprintf(arquivoEscrita, "%s:%c %f;", dataAtual, tipoTransacao, valorTransacao);
        }
    }
    fclose(arquivoLeitura);
    fclose(arquivoEscrita);
    remove("arquivos/caixa.txt");
    rename("arquivos/temp.txt", "arquivos/caixa.txt");
}

void gerirTransacoes(float valor, char tipoTransacao)
{

    int formaPagamento;

    printf("Selecione a forma de pagamento:\n1- dinheiro\n2- cartao de debito\n3- cartao de credito\n");
    scanf("%d%*c", &formaPagamento);

    if (formaPagamento == 1 || formaPagamento == 2)
    {

        atualizarCaixa(valor, '+');
    }
    else if (formaPagamento == 3)
    {

        char vencimento[11];
        printf("informe a data de vencimento do cartao(dd/mm/aaaa):");
        scanf("%s%*c", &vencimento);
        atualizarRecebimentos(valor, vencimento, '+');
    }
    else
    {
        printf("codigo invalido!!");
    }
}

void atualizarContas()
{
    FILE *arquivoLeitura = fopen("arquivos/contasReceber", "r"),
         *arquivoEscrita = fopen("arquivos/tempReceber.txt", "w");

    if (arquivoLeitura == NULL || arquivoEscrita == NULL)
    {
        printf("Erro ao abrir um dos arquivos");
        return;
    }

    float valorMovimentacao,
        valorSubtraido = 0;
    char dataTransacao,
        dataAtual;
    coletarData(dataAtual);
    while (!feof(arquivoLeitura))
    {
        if (fscanf(arquivoLeitura, "%[^:]:%f;", &dataTransacao, &valorMovimentacao))
        {
            if (!strcmp(&dataAtual, &dataTransacao))
            {
                atualizarCaixa(valorMovimentacao, '+');
                valorSubtraido += valorMovimentacao;
                continue;
            }
            else
            {
                fprintf(arquivoEscrita, "%s:%f;", dataTransacao, valorMovimentacao);
            }
        }
    }
    fclose(arquivoEscrita);
    fclose(arquivoLeitura);
    remove("arquivos/contasReceber.txt");
    rename("arquivos/tempReceber.txt", "arquivos/contasReceber.txt");

    atualizarRecebimentos(valorSubtraido, 0, '-');
}

void realizarCheckIn(char tipoArquivo)
{

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

    int diferenca = diferencaDatas(ptrReserva->dataInicial, ptrReserva->dataFinal);
    float valorDiaria = buscarValorDiaria(codigoAcomodacao, tipoArquivo);
    float valorTotal = diferenca * valorDiaria;

    if (opcao == 'S' || opcao == 's')
    {

        if (valorDiaria != -1)
        {

            printf("Valor total a ser pago: R$ %.2f\n", valorTotal);
            gerirTransacoes(valorTotal, '+');
            ptrReserva->valorTotal = 0;
        }
        else
        {
            printf(ANSI_RED "Erro ao calcular valor total.\n" ANSI_RESET);
        }
    }
    else if (opcao == 'N' || opcao == 'n')
    {
        ptrReserva->valorTotal = valorTotal;
    }

    free(ptrReserva);
}

void realizarCheckOut(char tipoArquivo)
{

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

    printf("Valor total a ser pago: R$ %.2f\n", ptrReserva->valorTotal);

    gerirTransacoes(ptrReserva->valorTotal, '+');

    free(ptrReserva);
}

void gerarNota(int quantProduto, float subTotal, int cliente, char *produto)
{
    // Obter o tempo atual
    time_t tempoAtual;
    time(&tempoAtual);
    struct tm *infoTempo = localtime(&tempoAtual);
    FILE *arquivo = fopen("nota.txt", "w");

    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não pode ser aberto!\n" ANSI_RESET);
        return;
    }

    fprintf(arquivo, "===========================================\n");
    fprintf(arquivo, "             Nota de Venda\n");
    fprintf(arquivo, "===========================================\n");
    fprintf(arquivo, "Data e Hora:%02d/%02d/%04d %02d:%02d:%02d\n",
            infoTempo->tm_mday, infoTempo->tm_mon + 1, infoTempo->tm_year + 1900,
            infoTempo->tm_hour, infoTempo->tm_min, infoTempo->tm_sec);
    fprintf(arquivo, "Cliente: %s\n\n", cliente);
    fprintf(arquivo, "-------------------------------------------\n");
    fprintf(arquivo, "  Produto            Quantidade    Subtotal\n");
    fprintf(arquivo, "-------------------------------------------\n");

    fprintf(arquivo, "  %-20s %-12d R$%-9.2f\n", produto, quantProduto, subTotal);

    fprintf(arquivo, "-------------------------------------------\n");
    fprintf(arquivo, "  Total da Compra:                  R$%-9.2f\n\n", subTotal);

    fprintf(arquivo, "-------------------------------------------\n");
    fprintf(arquivo, "          Assinatura do Cliente\n");

    fclose(arquivo);
}

void registrarVendaConsumivel(char tipoArquivo)
{

    int codigoConsumivel,
        quantidade,
        status;
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

    int formaPagamento;
    printf("Selecione a forma de pagamento:\n1- a vista\n2- a prazo\n");
    scanf("%d%*c", &formaPagamento);

    if (formaPagamento == 1)
    {

        gerirTransacoes(valorVenda, '+');

        ptrConsumivel->estoque -= quantidade;

        tipoArquivo == 'T' ? atualizarConsumivelTxt(codigoConsumivel, ptrConsumivel) : atualizarConsumivelBin(codigoConsumivel, ptrConsumivel);
        free(ptrConsumivel);
    }
    else if (formaPagamento == 2)
    {

        FILE *arquivo;
        Reserva *ptrReserva;

        int codigoReserva = 0;

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

        ptrReserva->valorTotal += valorVenda;

        status = (tipoArquivo == 'T') ? atualizarReservaTxt(codigoReserva, ptrReserva) : atualizarReservaBin(codigoReserva, ptrReserva);

        ptrConsumivel->estoque -= quantidade;

        tipoArquivo == 'T' ? atualizarConsumivelTxt(codigoConsumivel, ptrConsumivel) : atualizarConsumivelBin(codigoConsumivel, ptrConsumivel);

        gerarNota(quantidade, valorVenda, ptrReserva->hospede, ptrConsumivel->descricao);
        free(ptrConsumivel);
        free(ptrReserva);

        status == 1 ? printf(ANSI_GREEN "Consumível adicionado com sucesso.\n" ANSI_RESET) : printf(ANSI_RED "Erro ao adicionar consumível.\n" ANSI_RESET);
    }
    else
    {
        printf("codigo invalido");
    }
}

NotaFiscalEntrada *coletarNotaFiscal()
{

    NotaFiscalEntrada *notaFiscal = malloc(sizeof(NotaFiscalEntrada));

    printf("digite a razao social do fornecedor: ");
    scanf("%49[^\n]%*c", notaFiscal->fornecedor);
    printf("digite o CNPJ do fornecedor: ");
    scanf("%19[^\n]%*c", notaFiscal->cnpj);
    printf("digite o valor do frete: ");
    scanf("%f%*c", notaFiscal->frete);
    printf("digite o valor dos impostos: ");
    scanf("%f%*c", notaFiscal->imposto);
    printf("informe a quantidade de produtos a serem adicionados: ");
    scanf("%d%*c", notaFiscal->quantidadeProdutos);

    notaFiscal->produtos = malloc(notaFiscal->quantidadeProdutos * sizeof(Produto));
    for (int i = 0; i < notaFiscal->quantidadeProdutos; i++)
    {
        printf("digite a descricao do produto(Ex:bala, refrigerante, ...): ");
        scanf("%99[^\n]%*c", notaFiscal->produtos[i].descricao);
        printf("digite o preco de custo do produto: ");
        scanf("%f%*c", notaFiscal->produtos[i].precoCusto);
        printf("digite a quantidade de unidades desse produto: ");
        scanf("%f%*c", notaFiscal->produtos[i].quantidade);
        notaFiscal->quantidadeItens += notaFiscal->produtos[i].quantidade;
    }
    printf("informe o valor total da compra: ");
    scanf("%f%*c", notaFiscal->total);

    return notaFiscal;
}

void lerDespesas(char *data)
{
    FILE *arquivo = fopen("arquivos/contasPagar.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }
    char linha[100];
    char dataTransacao[20];
    int parcela;
    float valorMovimentacao;

    while (!feof(arquivo))
    {
        if (!strcmp(data, ""))
        {

            fgets(linha, sizeof(linha), arquivo);
            printf("%s", linha);
        }
        else if (fscanf(arquivo, "%[^:]:%dx%f;", &dataTransacao, &parcela, &valorMovimentacao) && !strcmp(data, dataTransacao))
        {
            printf("%s:%dx%f;", dataTransacao, parcela, valorMovimentacao);
        }
    }
    fclose(arquivo);
}

void atualizarDespesas(float valorTransacao, int parcelas, char *dataNota, int nParcela, char tipoTransacao)
{
    FILE *arquivoLeitura = fopen("arquivos/contasPagar.txt", "r"),
         *arquivoEscrita = fopen("arquivos/temp.txt", "w");
    float valorCaixa;
    char dataTransacao[20];
    int parcela;
    float valorMovimentacao;
    char dataAtual;
    coletarData(dataAtual);
    while (!feof(arquivoLeitura))
    {
        if (fscanf(arquivoLeitura, "Caixa:%f", &valorCaixa))
        {
            tipoTransacao == '+' ? (valorCaixa += valorTransacao) : (valorCaixa -= valorTransacao);
            fprintf(arquivoEscrita, "Caixa:%f", valorCaixa);
        }
        else if (fscanf(arquivoLeitura, "%[^:]:%dx%f;", &dataTransacao, &parcela, &valorMovimentacao))
        {
            if (!(!strcmp(dataTransacao, dataNota) && parcela == nParcela))
            {
                fprintf(arquivoEscrita, "%s:%dx%f;", dataTransacao, parcela, valorMovimentacao);
            }
        }
    }
    if (tipoTransacao == '+')
    {
        valorMovimentacao = valorTransacao / parcelas;
        for (int i = 0; i < parcelas; i++)
        {

            coletarData(dataAtual);
            fprintf(arquivoEscrita, "%s:%dx%f;", dataAtual, i + 1, valorMovimentacao);
        }
    }

    fclose(arquivoLeitura);
    fclose(arquivoEscrita);
    remove("arquivos/contasPagar.txt");
    rename("arquivos/temp.txt", "arquivos/contasPagar.txt");
}

int coletarValorParcela(char *data, int parcela)
{
    FILE *arquivo = fopen("arquivos/contasPagar.txt", "r");
    char dataTransacao[20];
    int parcelaTransacao;
    float valorMovimentacao;

    while (!feof(arquivo))
    {
        if (fscanf(arquivo, "%[^:]:%dx%f;", &dataTransacao, &parcelaTransacao, &valorMovimentacao))
        {
            if (strcmp(data, dataTransacao) && parcela == parcelaTransacao)
            {
                fclose(arquivo);
                return valorMovimentacao;
            }
        }
    }
}

void pagarContas()
{
    char dataNota;
    int parcela, valorNota;
    printf("informe a data e hora(AAAA-MM-DD HH:MM:SS) da nota quando foi registrada:");
    scanf("%s%*c", &dataNota);
    lerDespesas(&dataNota);

    printf("informe o numero da parcela que deseja pagar:");
    scanf("%d%*c", &parcela);

    valorNota = coletarValorParcela(&dataNota, parcela);
    atualizarCaixa(valorNota, '+');
    atualizarDespesas(valorNota, 0, &dataNota, parcela, '-');
}

void gerirCompras(NotaFiscalEntrada *nota)
{
    int formaPagamento;

    printf("Selecione a forma de pagamento:\n1- dinheiro\n2- a prazo\n");
    scanf("%d%*c", &formaPagamento);

    if (formaPagamento == 1)
    {

        atualizarCaixa(nota->total, '-');
        strcpy(nota->situacao, "paga");
    }
    else if (formaPagamento == 2)
    {
        float entrada, quantParcelas;

        printf("informe o valor de entrada:");
        scanf("%f%*c", &entrada);
        if (entrada == 0)
        {

            atualizarCaixa(nota->total, '-');
            nota->total -= entrada;
        }
        printf("informe a quantidade de parcelas:");
        scanf("%f%*c", &quantParcelas);

        atualizarDespesas(nota->total, quantParcelas, "", 0, '+');
    }
    else
    {
        printf("codigo invalido!!");
    }
}

void registrarNota(NotaFiscalEntrada *nota)
{
    FILE *arquivo = fopen("arquivo/notasCompras.txt", "a");
    char dataHoraAtual;
    coletarData(dataHoraAtual);
    fprintf(arquivo, "%s{\nsituacao:%s\nfornecedor:%s;\ncnpj:%s\nfrete:%f\nimposto:%f\nProdutos:{\n", dataHoraAtual, nota->situacao, nota->fornecedor, nota->cnpj, nota->frete, nota->imposto);

    for (int i = 0; i < nota->quantidadeProdutos; i++)
    {
        fprintf(arquivo, "%s:[preco custo:%f; quantidade:%d;]\n}\n", nota->produtos[i].descricao, nota->produtos[i].precoCusto, nota->produtos[i].quantidade);
    }
    fprintf(arquivo, "valor total:%f\n}\n\n", nota->total);

    fclose(arquivo);
}

void registrarCompraConsumivel(char tipoArquivo)
{
    NotaFiscalEntrada *notaFiscal = coletarNotaFiscal();
    FILE *arquivo;
    int status;
    float margemLucro,
        fretePorProduto = notaFiscal->frete / notaFiscal->quantidadeItens,
        impostoPorProduto = notaFiscal->imposto / notaFiscal->quantidadeItens;

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hotel.txt", "r") : fopen("arquivos/hotel.bin", "rb");

    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
    }

    Hotel *ptrHotel = malloc(sizeof(Hotel));
    status = (tipoArquivo == 'T') ? lerHotelTxt(arquivo, ptrHotel) : lerHotelBin(arquivo, ptrHotel);
    fclose(arquivo);

    if (status == 1)
    {
        margemLucro = ptrHotel->margemLucro;
        free(ptrHotel);
    }
    else if (status == 0)
    {
        printf(ANSI_RED "Hotel não encontrado ou erro de leitura.\n" ANSI_RESET);
    }

    // atualizacao do estoque dos consumiveis

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "r") : fopen("arquivos/consumivel.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return;
    }

    Consumivel *ptrConsumivel = malloc(sizeof(Consumivel));
    for (int i = 0; i < notaFiscal->quantidadeProdutos; i++)
    {

        while (1)
        {
            status = (tipoArquivo == 'T') ? lerConsumivelTxt(0, arquivo, ptrConsumivel) : lerConsumivelBin(0, arquivo, ptrConsumivel);
            if (status == 1)
            {
                if (!strcmp(ptrConsumivel->descricao, notaFiscal->produtos[i].descricao))
                {
                    ptrConsumivel->estoque += notaFiscal->produtos[i].quantidade;
                    ptrConsumivel->precoCusto = notaFiscal->produtos[i].precoCusto;
                    ptrConsumivel->precoVenda = notaFiscal->produtos[i].precoCusto * margemLucro + ptrConsumivel->precoCusto + fretePorProduto + impostoPorProduto;
                }
                else
                {

                    continue;
                }
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

            int codigoConsumivel = ptrConsumivel->codigo;

            status = (tipoArquivo == 'T') ? atualizarConsumivelTxt(codigoConsumivel, ptrConsumivel) : atualizarConsumivelBin(codigoConsumivel, ptrConsumivel);

            gerirCompras(notaFiscal);
            registrarNota(notaFiscal);

            status == 1 ? printf(ANSI_GREEN "Registro de consumivel atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de consumível" ANSI_RESET);
            break;
        }
    }
    free(ptrConsumivel);
}

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

    return (int)difftime(time1, time2) / 86400; // se data1 for menor retorna um valor negativo se data2 for menor retorna um valor positivo
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

    char categoria[50] = ptrAcomodacao->categoria;

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categorias.txt", "r") : fopen("arquivos/categorias.bin", "rb");
    if (arquivo == NULL)
    {
        printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
        return -1;
    }

    ptrCategoria = malloc(sizeof(Categoria));

    while (1)
    {
        status = (tipoArquivo == 'T') ? lerCategoriaTxt(categoria, arquivo, ptrCategoria) : lerCategoriaBin(categoria, arquivo, ptrCategoria);

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
        atualizarCaixa(valorVenda);
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
        free(ptrConsumivel);

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

//atualizacao do estoque dos consumiveis

    arquivo = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "r") : fopen("arquivos/consumivel.bin", "rb");
            if (arquivo == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
                break;
            }

            Consumivel *ptrConsumivel=malloc(sizeof(Consumivel));
    for(int i=0;i<notaFiscal->quantidadeProdutos;i++)
    {

    
while (1)
                {
                    status = (tipoArquivo == 'T') ? lerConsumivelTxt(0, arquivo, ptrConsumivel) : lerConsumivelBin(0, arquivo, ptrConsumivel);
                    if (status == 1)
                    {
                        if(!strcmp(ptrConsumivel->descricao,notaFiscal->produtos[i].descricao)){
                            ptrConsumivel->estoque+=notaFiscal->produtos[i].quantidade;
                            ptrConsumivel->precoCusto=notaFiscal->produtos[i].precoCusto;
                            ptrConsumivel->precoVenda=notaFiscal->produtos[i].precoCusto*margemLucro+ptrConsumivel->precoCusto+fretePorProduto+impostoPorProduto;
                        }else{

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

        status == 1 ? printf(ANSI_GREEN "Registro de consumivel atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de consumível" ANSI_RESET);
        break;
                }
}
        free(ptrConsumivel);

}

void gerirCaixa(char tipoArquivo)
{
}

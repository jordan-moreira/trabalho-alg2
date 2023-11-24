#ifndef TRANSACOES_H
#define TRANSACOES_H

#include <time.h>

struct tm;

typedef struct
{
    char descricao[100];
    float precoCusto;
    int quantidade;
} Produto;

typedef struct
{
    char fornecedor[50],
        cnpj[20];
    float frete,
        imposto,
        total;
    int quantidadeItens,
        quantidadeProdutos;

    Produto *produtos;
} NotaFiscalEntrada;

int coverterString(char *data, struct tm *tm_info);

int diferencaDatas(char data1[], char data2[]);

void coletarData(char dataString);

float buscarValorDiaria(int codigoAcomodacao, char tipoArquivo);

void lerRecebimentos();

void atualizarRecebimentos(float valorTransacao, char *vencimento, char tipoTransacao);

void lerCaixa();

void atualizarCaixa(float valorTransacao, char tipoTransacao);

void realizarCheckIn(char tipoArquivo);

void realizarCheckOut(char tipoArquivo);

void gerarNota(int quantProduto, float subTotal, int cliente, char *produto);

void registrarVendaConsumivel(char tipoArquivo);

NotaFiscalEntrada *coletarNotaFiscal();

void registrarCompraConsumivel(char tipoArquivo);

#endif
#ifndef TRANSACOES_H
#define TRANSACOES_H

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
    int quantidadeItens;

    Produto *produtos;
} NotaFiscalEntrada;

int diferencaDatas(char data1[], char data2[]);

float buscarValorDiaria(int codigoAcomodacao, char tipoArquivo);

void realizarCheckIn(char tipoArquivo);

void realizarCheckOut(char tipoArquivo);

void registrarVendaConsumivel(char tipoArquivo);

NotaFiscalEntrada *coletarNotaFiscal();

void registrarCompraConsumivel(char tipoArquivo);

void gerirCaixa(char tipoArquivo);

void gerirContasReceber(char tipoArquivo);

void gerirContasPagar(char tipoArquivo);

#endif
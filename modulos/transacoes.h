#ifndef TRANSACOES_H
#define TRANSACOES_H

int diferencaDatas(char data1[], char data2[]);

float buscarValorDiaria(int codigoAcomodacao, char tipoArquivo);

void realizarCheckIn(char tipoArquivo);

void realizarCheckOut(char tipoArquivo);

void registrarVendaConsumivel(char tipoArquivo);

void gerirCaixa(char tipoArquivo);

void gerirContasReceber(char tipoArquivo);

void gerirContasPagar(char tipoArquivo);

void registrarCompraConsumivel(char tipoArquivo);

#endif
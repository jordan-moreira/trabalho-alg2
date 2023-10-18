#ifndef TRANSACOES_H
#define TRANSACOES_H

void realizarCheckIn(char tipoArquivo, char codigoPermissao);
void realizarCheckOut(char tipoArquivo, char codigoPermissao);

int diferencaDatas(char data1[], char data2[]);
float buscarValorDiaria(int codigoAcomodacao, char tipoArquivo);

void registrarConsumivel(char tipoArquivo, char codigoPermissao);

#endif
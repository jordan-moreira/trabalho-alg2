#ifndef RESERVAS_H
#define RESERVAS_H

int operarReserva();

void mostrarCorrespondentes(Acomodacao *dadosBusca, char tipoArquivo);

void coletarDadosReserva(Reserva *ptrReserva);

void gerenciarReserva(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria);

void checarDatasDisponiveis(int codigoAcomodacao, char tipoArquivo, Reserva *ptrReserva, int codigoReserva, PtrMemoria *ptrMemoria);

#endif

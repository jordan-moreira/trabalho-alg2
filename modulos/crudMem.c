#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "crudMem.h"

// Capturar dados;
// Trabalhar com os dados;

// ------------Create---------

void criarHotelMem(Hotel *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->hotel = malloc(sizeof(Hotel));
    memcpy(ptrMemoria->hotel, estrutura, sizeof(Hotel));
}

void adicionarHospedeMem(Hospede *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamHospede++;
    int i = ptrMemoria->tamHospede - 1;
    ptrMemoria->hospede = realloc(ptrMemoria->hospede, ptrMemoria->tamHospede * sizeof(Hospede *));
    ptrMemoria->hospede[i] = malloc(sizeof(Hospede));

    memcpy(ptrMemoria->hospede[i], estrutura, sizeof(Hospede));
}

void adicionarCategoriaMem(Categoria *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamCategoria++;
    int i = ptrMemoria->tamCategoria - 1;
    ptrMemoria->categoria = realloc(ptrMemoria->categoria, ptrMemoria->tamCategoria * sizeof(Categoria *));
    ptrMemoria->categoria[i] = malloc(sizeof(Categoria));

    memcpy(ptrMemoria->categoria[i], estrutura, sizeof(Categoria));
}

void adicionarAcomodacaoMem(Acomodacao *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamAcomodacao++;
    int i = ptrMemoria->tamAcomodacao - 1;
    ptrMemoria->acomodacao = realloc(ptrMemoria->acomodacao, ptrMemoria->tamAcomodacao * sizeof(Acomodacao *));
    ptrMemoria->acomodacao[i] = malloc(sizeof(Acomodacao));

    memcpy(ptrMemoria->acomodacao[i], estrutura, sizeof(Acomodacao));
}

void adicionarConsumivelMem(Consumivel *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamConsumivel++;
    int i = ptrMemoria->tamConsumivel - 1;
    ptrMemoria->consumivel = realloc(ptrMemoria->consumivel, ptrMemoria->tamConsumivel * sizeof(Consumivel *));
    ptrMemoria->consumivel[i] = malloc(sizeof(Consumivel));

    memcpy(ptrMemoria->consumivel[i], estrutura, sizeof(Consumivel));
}

void adicionarFornecedorMem(Fornecedor *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamFornecedor++;
    int i = ptrMemoria->tamFornecedor - 1;
    ptrMemoria->fornecedor = realloc(ptrMemoria->fornecedor, ptrMemoria->tamFornecedor * sizeof(Fornecedor *));
    ptrMemoria->fornecedor[i] = malloc(sizeof(Fornecedor));

    memcpy(ptrMemoria->fornecedor[i], estrutura, sizeof(Fornecedor));
}

void adicionarOperadorMem(Operador *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamOperador++;
    int i = ptrMemoria->tamOperador - 1;
    ptrMemoria->operador = realloc(ptrMemoria->operador, ptrMemoria->tamOperador * sizeof(Operador *));
    ptrMemoria->operador[i] = malloc(sizeof(Operador));

    memcpy(ptrMemoria->operador[i], estrutura, sizeof(Operador));
}

void adicionarReservaMem(Reserva *estrutura, PtrMemoria *ptrMemoria)
{
    ptrMemoria->tamReserva++;
    int i = ptrMemoria->tamReserva - 1;
    ptrMemoria->reserva = realloc(ptrMemoria->reserva, ptrMemoria->tamReserva * sizeof(Reserva *));
    ptrMemoria->reserva[i] = malloc(sizeof(Reserva));

    memcpy(ptrMemoria->reserva[i], estrutura, sizeof(Reserva));
}

// ------------Read-----------

int lerHotelMem(Hotel *ptrHotel, PtrMemoria *ptrMemoria)
{
    memcpy(ptrHotel, ptrMemoria->hotel, sizeof(Hotel));
    return 1;
}

int lerHospedeMem(int codigo, Hospede *ptrHospede, Hospede *ptrMemHospede)
{
    memcpy(ptrHospede, ptrMemHospede, sizeof(Hospede));

    if (ptrHospede->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

int lerCategoriaMem(char *codigo, Categoria *ptrCategoria, Categoria *ptrMemCategoria)
{
    memcpy(ptrCategoria, ptrMemCategoria, sizeof(Categoria));
    if (!strcmp(ptrCategoria->codigo, codigo) || !strcmp(codigo, "0"))
    {
        return 1;
    }

    return 0;
}

int lerAcomodacaoMem(int codigo, Acomodacao *ptrAcomodacao, Acomodacao *ptrMemAcomodacao)
{

    memcpy(ptrAcomodacao, ptrMemAcomodacao, sizeof(Acomodacao));
    if (ptrAcomodacao->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

int lerConsumivelMem(int codigo, Consumivel *ptrConsumivel, Consumivel *ptrMemConsumivel)
{
    memcpy(ptrConsumivel, ptrMemConsumivel, sizeof(Consumivel));
    if (ptrConsumivel->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

int lerFornecedorMem(int codigo, Fornecedor *ptrFornecedor, Fornecedor *ptrMemFornecedor)
{
    memcpy(ptrFornecedor, ptrMemFornecedor, sizeof(Fornecedor));
    if (ptrFornecedor->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

int lerOperadorMem(int codigo, Operador *ptrOperador, Operador *ptrMemOperador)
{
    memcpy(ptrOperador, ptrMemOperador, sizeof(Operador));
    if (ptrOperador->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

int lerReservaMem(int codigo, Reserva *ptrReserva, Reserva *ptrMemReserva)
{
    memcpy(ptrReserva, ptrMemReserva, sizeof(Reserva));
    if (ptrReserva->codigo == codigo || codigo == 0)
    {

        return 1;
    }

    return 0;
}

// ------------Update---------

// Função para em memoria atualizar um registro de Hotel
int atualizarHotelMem(Hotel *novosDados, PtrMemoria *ptrMemoria)
{

    memcpy(ptrMemoria->hotel, novosDados, sizeof(Hotel));
    return 1; // Indica que a operação foi bem-sucedida
}

// Função para atualizar um registro de Hospede em memoria
int atualizarHospedeMem(int codigo, Hospede *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->hospede[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->hospede[i], novoDados, sizeof(Hospede));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de Categoria em memoria
int atualizarCategoriaMem(char *codigo, Categoria *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->categoria[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->categoria[i], novoDados, sizeof(Categoria));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de Acomodação em memoria
int atualizarAcomodacaoMem(int codigo, Acomodacao *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->acomodacao[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->acomodacao[i], novoDados, sizeof(Acomodacao));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de consumível em memoria
int atualizarConsumivelMem(int codigo, Consumivel *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->consumivel[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->consumivel[i], novoDados, sizeof(Consumivel));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de fornecedor em memoria
int atualizarFornecedorMem(int codigo, Fornecedor *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->fornecedor[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->fornecedor[i], novoDados, sizeof(Fornecedor));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de operador em memoria
int atualizarOperadorMem(int codigo, Operador *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->operador[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->operador[i], novoDados, sizeof(Operador));
            return 1;
        }
    }
    return 0;
}

// Função para atualizar um registro de reserva em memoria
int atualizarReservaMem(int codigo, Reserva *novoDados, PtrMemoria *ptrMemoria)
{
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->reserva[i]->codigo == codigo)
        {
            memcpy(ptrMemoria->reserva[i], novoDados, sizeof(Reserva));
            return 1;
        }
    }
    return 0;
}

//------------Delete---------

// Função para deletar todos os registros de Hotel
int deletarHotelMem(PtrMemoria *ptrMemoria)
{
    free(ptrMemoria->hotel);
    return 1;
}

// Função para deletar um hóspede por código
int deletarHospedeMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->hospede = malloc(0 * sizeof(Hospede *));
    ptrMemTemp->tamHospede = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamHospede; i++)
    {
        if (ptrMemoria->hospede[i]->codigo != codigo)
        {
            adicionarHospedeMem(ptrMemoria->hospede[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->hospede, ptrMemTemp->hospede, ptrMemTemp->tamHospede * sizeof(Hospede *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar uma categoria por código
int deletarCategoriaMem(char *codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->categoria = malloc(0 * sizeof(Categoria *));
    ptrMemTemp->tamCategoria = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamCategoria; i++)
    {
        if (ptrMemoria->categoria[i]->codigo != codigo)
        {
            adicionarCategoriaMem(ptrMemoria->categoria[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->categoria, ptrMemTemp->categoria, ptrMemTemp->tamCategoria * sizeof(Categoria *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar uma acomodação por código
int deletarAcomodacaoMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->acomodacao = malloc(0 * sizeof(Acomodacao *));
    ptrMemTemp->tamAcomodacao = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamAcomodacao; i++)
    {
        if (ptrMemoria->acomodacao[i]->codigo != codigo)
        {
            adicionarAcomodacaoMem(ptrMemoria->acomodacao[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->acomodacao, ptrMemTemp->acomodacao, ptrMemTemp->tamAcomodacao * sizeof(Acomodacao *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar um consumível por código
int deletarConsumivelMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->fornecedor = malloc(0 * sizeof(Fornecedor *));
    ptrMemTemp->tamFornecedor = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamFornecedor; i++)
    {
        if (ptrMemoria->fornecedor[i]->codigo != codigo)
        {
            adicionarFornecedorMem(ptrMemoria->fornecedor[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->fornecedor, ptrMemTemp->fornecedor, ptrMemTemp->tamConsumivel * sizeof(Consumivel *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar um fornecedor por código
int deletarFornecedorMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->fornecedor = malloc(0 * sizeof(Fornecedor *));
    ptrMemTemp->tamFornecedor = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamFornecedor; i++)
    {
        if (ptrMemoria->fornecedor[i]->codigo != codigo)
        {
            adicionarFornecedorMem(ptrMemoria->fornecedor[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->fornecedor, ptrMemTemp->fornecedor, ptrMemTemp->tamFornecedor * sizeof(Fornecedor *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar um operador por código
int deletarOperadorMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->operador = malloc(0 * sizeof(Operador *));
    ptrMemTemp->tamOperador = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamOperador; i++)
    {
        if (ptrMemoria->operador[i]->codigo != codigo)
        {
            adicionarOperadorMem(ptrMemoria->operador[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->operador, ptrMemTemp->operador, ptrMemTemp->tamOperador * sizeof(Operador *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para deletar ua reserva por código
int deletarReservaMem(int codigo, PtrMemoria *ptrMemoria)
{
    PtrMemoria *ptrMemTemp = malloc(sizeof(PtrMemoria));
    ptrMemTemp->reserva = malloc(0 * sizeof(Reserva *));
    ptrMemTemp->tamReserva = 0;

    int encontrado = 0;
    for (int i = 0; i < ptrMemoria->tamReserva; i++)
    {
        if (ptrMemoria->reserva[i]->codigo != codigo)
        {
            adicionarReservaMem(ptrMemoria->reserva[i], ptrMemTemp);
        }
        else
        {
            encontrado = 1;
        }
    }
    memcpy(ptrMemoria->reserva, ptrMemTemp->reserva, ptrMemTemp->tamReserva * sizeof(Reserva *));

    free(ptrMemTemp);
    if (encontrado)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
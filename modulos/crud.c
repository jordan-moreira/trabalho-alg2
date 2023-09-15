#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"
#include "crud.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

// ------------Create---------

void criarHotel(Hotel *estrutura)
{

    FILE *arquivo = fopen("arquivo/hotel.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "Nome:%s ;Razão Social:%s ;Inscrição Estadual:%s ;CNPJ:%s ;Endereço:%s ;Número de Celular:%s ;E-mail:%s ;Responsável:%s ;Número de Celular do Responsável:%s ;Horário de Check-In:%s ;Horário de Check-Out:%s ;", estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoEstadual, estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail, estrutura->responsavel, estrutura->celularResponsavel, estrutura->horarioCheckIn, estrutura->horarioCheckOut);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarHospede(Hospede *estrutura)
{

    FILE *arquivo = fopen("arquivo/hospede.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "%d{nome:%s ,endereco:%s ,cpf:%s ,celular:%s ,eMail:%s ,sexo:%s ,estadoCivil:%s ,dataNasc:%s ;}\n", estrutura->codigo, estrutura->nome, estrutura->endereco, estrutura->cpf, estrutura->celular, estrutura->eMail, estrutura->sexo, estrutura->estadoCivil, estrutura->dataNasc);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarCategoria(Categoria *estrutura)
{
    FILE *arquivo = fopen("arquivo/categoria.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{quantPessoas:%d, valor:%f, descricao:%s ;}\n", estrutura->codigo, estrutura->quantPessoas, estrutura->valor, estrutura->descricao);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarAcomodacao(Acomodacao *estrutura)
{
    FILE *arquivo = fopen("arquivo/acomodacao.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{categoria:%d, ocupada:%d, dataInicial:%d/%d/%d, dataFinal:%d/%d/%d, descricao:%s ,facilidades:%s ;}\n",
            estrutura->codigo, estrutura->categoria, estrutura->ocupada,
            estrutura->data.dataInicial[0], estrutura->data.dataInicial[1], estrutura->data.dataInicial[2],
            estrutura->data.dataFinal[0], estrutura->data.dataFinal[1], estrutura->data.dataFinal[2],
            estrutura->descricao, estrutura->facilidades);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarConsumivel(Consumivel *estrutura)
{
    FILE *arquivo = fopen("arquivo/consumivel.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%s , precoCusto:%f, precoVenda:%f ;}\n",
            estrutura->codigo, estrutura->estoque, estrutura->estoqueMin,
            estrutura->descricao, estrutura->precoCusto, estrutura->precoVenda);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarFornecedor(Fornecedor *estrutura)
{
    FILE *arquivo = fopen("arquivo/fornecedor.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{nome:%s , razaoSocial:%s , inscricaoSocial:%s , cnpj:%s , endereco:%s , celular:%s , eMail:%s ;}\n",
            estrutura->codigo, estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoSocial,
            estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarOperador(Operador *estrutura)
{
    FILE *arquivo = fopen("arquivo/operador.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%s ;}\n",
            estrutura->codigo, estrutura->nome, estrutura->usuario, estrutura->senha, estrutura->permissao);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

// ------------Read-----------

int lerHotel(FILE *arquivo, Hotel *ptrHotel)
{

    if (
        fscanf(arquivo, "Nome:%s ;Razão Social:%s ;Inscrição Estadual:%s ;CNPJ:%s ;Endereço:%s ;Número de Celular:%s ;E-mail:%s ;Responsável:%s ;Número de Celular do Responsável:%s ;Horário de Check-In:%s ;Horário de Check-Out:%s ;", ptrHotel->nome, ptrHotel->razaoSocial, ptrHotel->inscricaoEstadual, ptrHotel->cnpj, ptrHotel->endereco, ptrHotel->celular, ptrHotel->eMail, ptrHotel->responsavel, ptrHotel->celularResponsavel, ptrHotel->horarioCheckIn, ptrHotel->horarioCheckOut))
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int lerHospede(int codigo, FILE *arquivo, Hospede *ptrHospede)
{
    if (fscanf(arquivo, "%d{nome:%s ,endereco:%s ,cpf:%s ,celular:%s ,eMail:%s ,sexo:%s ,estadoCivil:%s ,dataNasc:%s ;}", &ptrHospede->codigo, ptrHospede->nome, ptrHospede->endereco, ptrHospede->cpf, ptrHospede->celular, ptrHospede->eMail, ptrHospede->sexo, ptrHospede->estadoCivil, ptrHospede->dataNasc) == 9)
    {
        if (ptrHospede->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerCategoria(int codigo, FILE *arquivo, Categoria *ptrCategoria)
{
    if (fscanf(arquivo, "%d{quantPessoas:%d, valor:%f, descricao:%s ;}", &ptrCategoria->codigo, &ptrCategoria->quantPessoas, &ptrCategoria->valor, ptrCategoria->descricao) == 4)
    {
        if (ptrCategoria->codigo == codigo || codigo == 0)
        {
            return 1;
        }
    }

    return 0;
}

int lerAcomodacao(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao)
{

    if (fscanf(arquivo, "%d{categoria:%d, ocupada:%d, dataInicial:%d/%d/%d, dataFinal:%d/%d/%d, descricao:%s ,facilidades:%s ;}", &ptrAcomodacao->codigo, &ptrAcomodacao->categoria, &ptrAcomodacao->ocupada, &ptrAcomodacao->data.dataInicial[0], &ptrAcomodacao->data.dataInicial[1], &ptrAcomodacao->data.dataInicial[2], &ptrAcomodacao->data.dataFinal[0], &ptrAcomodacao->data.dataFinal[1], &ptrAcomodacao->data.dataFinal[2], ptrAcomodacao->descricao, ptrAcomodacao->facilidades) == 11)
    {
        if (ptrAcomodacao->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerConsumivel(int codigo, FILE *arquivo, Consumivel *ptrConsumivel)
{
    if (fscanf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%s , precoCusto:%f, precoVenda:%f ;}", &ptrConsumivel->codigo, &ptrConsumivel->estoque, &ptrConsumivel->estoqueMin, ptrConsumivel->descricao, &ptrConsumivel->precoCusto, &ptrConsumivel->precoVenda) == 6)
    {
        if (ptrConsumivel->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerFornecedor(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor)
{
    if (fscanf(arquivo, "%d{nome:%s , razaoSocial:%s , inscricaoSocial:%s , cnpj:%s , endereco:%s , celular:%s , eMail:%s ;}", &ptrFornecedor->codigo, &ptrFornecedor->nome, &ptrFornecedor->razaoSocial, &ptrFornecedor->inscricaoSocial, &ptrFornecedor->cnpj, &ptrFornecedor->endereco, &ptrFornecedor->celular, &ptrFornecedor->eMail) == 8)
    {
        if (ptrFornecedor->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerOperador(int codigo, FILE *arquivo, Operador *ptrOperador)
{
    if (fscanf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%s ;}", &ptrOperador->codigo, &ptrOperador->nome, &ptrOperador->usuario, &ptrOperador->senha, &ptrOperador->permissao) == 5)
    {
        if (ptrOperador->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

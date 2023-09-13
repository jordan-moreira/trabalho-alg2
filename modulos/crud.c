#include <stdio.h>
#include "gestaoDados.h"
#include "crud.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

// ------------Create---------

void criarHotel(Hotel *estrutura)
{

    FILE *arquivo = fopen("hotel.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "Nome: %s\n", estrutura->nome);
    fprintf(arquivo, "Razão Social: %s\n", estrutura->razaoSocial);
    fprintf(arquivo, "Inscrição Estadual: %s\n", estrutura->inscricaoEstadual);
    fprintf(arquivo, "CNPJ: %s\n", estrutura->cnpj);
    fprintf(arquivo, "Endereço: %s\n", estrutura->endereco);
    fprintf(arquivo, "Número de Celular: %s\n", estrutura->celular);
    fprintf(arquivo, "E-mail: %s\n", estrutura->eMail);
    fprintf(arquivo, "Responsável: %s\n", estrutura->responsavel);
    fprintf(arquivo, "Número de Celular do Responsável: %s\n", estrutura->celularResponsavel);
    fprintf(arquivo, "Horário de Check-In: %s\n", estrutura->horarioCheckIn);
    fprintf(arquivo, "Horário de Check-Out: %s\n", estrutura->horarioCheckOut);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarHospede(Hospede *estrutura)
{

    FILE *arquivo = fopen("hospede.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "%d{nome:%s, endereco:%s, celular:%s, eMail:%s, sexo:%s, estadoCivil:%s, dataNasc:%s;}\n", estrutura->codigo, estrutura->nome, estrutura->endereco, estrutura->cpf, estrutura->celular, estrutura->eMail, estrutura->sexo, estrutura->estadoCivil, estrutura->dataNasc);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarCategoria(Categoria *estrutura)
{
    FILE *arquivo = fopen("categoria.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{quantPessoas:%d, descricao:%s, valor:%.2f}\n", estrutura->codigo, estrutura->quantPessoas, estrutura->descricao, estrutura->valor);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarAcomodacao(Acomodacao *estrutura)
{
    FILE *arquivo = fopen("acomodacao.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{categoria:%d, ocupada:%d, dataInicial:%d/%d/%d, dataFinal:%d/%d/%d, descricao:%s, facilidades:%s}\n",
            estrutura->codigo, estrutura->categoria, estrutura->ocupada,
            estrutura->data.dataInicial[0], estrutura->data.dataInicial[1], estrutura->data.dataInicial[2],
            estrutura->data.dataFinal[0], estrutura->data.dataFinal[1], estrutura->data.dataFinal[2],
            estrutura->descricao, estrutura->facilidades);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarConsumivel(Consumivel *estrutura)
{
    FILE *arquivo = fopen("consumivel.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%s, precoCusto:%.2f, precoVenda:%.2f}\n",
            estrutura->codigo, estrutura->estoque, estrutura->estoqueMin,
            estrutura->descricao, estrutura->precoCusto, estrutura->precoVenda);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarFornecedor(Fornecedor *estrutura)
{
    FILE *arquivo = fopen("fornecedor.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{nome:%s, razaoSocial:%s, inscrisaoSocial:%s, cnpj:%s, endereco:%s, celular:%s, eMail:%s}\n",
            estrutura->codigo, estrutura->nome, estrutura->razaoSocial, estrutura->inscrisaoSocial,
            estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

void adicionarOperador(Operador *estrutura)
{
    FILE *arquivo = fopen("operador.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
        return;
    }

    fprintf(arquivo, "%d{nome:%s, usuario:%s, senha:%s, permissao:%s}\n",
            estrutura->codigo, estrutura->nome, estrutura->usuario, estrutura->senha, estrutura->permissao);

    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

// ------------Read-----------

void lerCategoria(int codigo)
{
    Categoria estrutura;

    FILE *arquivo = fopen("categoria.txt", "rt");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser lido.\n");
    }

    while (fscanf(arquivo, "%d {quantPessoas:%d, descricao:%s[^;], valor:%.2f}", &estrutura.codigo, &estrutura.quantPessoas, &estrutura.descricao, &estrutura.valor) == 4)
    {
        fprintf(arquivo, "%d {quantPessoas:%d, descricao:%s, valor:%.2f}\n", estrutura.codigo, estrutura.quantPessoas, estrutura.descricao, estrutura.valor);
    }

    fclose(arquivo);
}

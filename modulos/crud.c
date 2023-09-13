#include <stdio.h>
#include "crud.h"
#include "gestaoDados.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

void criarHotel(Hotel *estrutura)
{

    FILE *arquivo = fopen("hotel.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "Nome: %s\n", estrutura.nome);
    fprintf(arquivo, "Razão Social: %s\n", estrutura.razaoSocial);
    fprintf(arquivo, "Inscrição Estadual: %s\n", estrutura.inscricaoEstadual);
    fprintf(arquivo, "CNPJ: %s\n", estrutura.cnpj);
    fprintf(arquivo, "Endereço: %s\n", estrutura.endereco);
    fprintf(arquivo, "Número de Celular: %s\n", estrutura.celular);
    fprintf(arquivo, "E-mail: %s\n", estrutura.eMail);
    fprintf(arquivo, "Responsável: %s\n", estrutura.responsavel);
    fprintf(arquivo, "Número de Celular do Responsável: %s\n", estrutura.celularResponsavel);
    fprintf(arquivo, "Horário de Check-In: %s\n", estrutura.horarioCheckIn);
    fprintf(arquivo, "Horário de Check-Out: %s\n", estrutura.horarioCheckOut);


    fclose(arquivo);

    printf("Registrado com sucesso!\n");
}

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

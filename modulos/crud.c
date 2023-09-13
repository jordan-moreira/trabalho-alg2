#include <stdio.h>
#include "crud.h"
#include "gestaoDados.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

void createElement(Categoria estrutura)
{
    // Cria um arquivo temporário para escrita
    FILE *arquivo = fopen("categoria.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não existe ou não pode ser aberto!\n");
    }

    fprintf(arquivo, "%d {quantPessoas:%d, descricao:%s, valor:%.2f}\n", estrutura.codigo, estrutura.quantPessoas, estrutura.descricao, estrutura.valor);

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

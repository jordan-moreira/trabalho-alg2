#include <stdio.h>
#include "crud.h"
#include "gestaoDados.h"
// capturar dados;
// trabalhar os dados;
// jogar no arquivo;

void createElement(Categoria estrutura)
{

    // Cria um arquivo temporario para escrita
    FILE *arquivo = fopen("categoria.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo nao existe ou nao pode ser aberto!");
    }

    fprintf(arquivo, "%d{quantPessoas :%d,descricao:%s,valor: %.2f}", estrutura.codigo, estrutura.quantPessoas, estrutura.descricao, estrutura.valor);

    fclose(arquivo);

    printf("Registrado com sucesso!");
}

void lerCategoria(int codigo)
{

    Categoria estrutura;

    FILE *arquivo = fopen("categoria.txt", "rt");

    if (arquivo == NULL)
    {
        printf("Arquivo nao existe ou nao pode ser lido");
    }

    while (fscanf(arquivo, "%d{quantPessoas :%d,descricao:%s[^;],valor: %.2f}", &estrutura.codigo, &estrutura.quantPessoas, &estrutura.valor) == 4)
    {

        fprintf(arquivo, "%d{quantPessoas :%d,descricao:%s,valor: %.2f}", estrutura.codigo, estrutura.quantPessoas, estrutura.descricao, estrutura.valor);
    }

    fclose(arquivo);
}

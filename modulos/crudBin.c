#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"
#include "crudBin.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

// ------------Create---------

void criarHotelBin(Hotel *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Hotel), 1, arquivo);
}

void adicionarHospedeBin(Hospede *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Hospede), 1, arquivo);
}

void adicionarCategoriaBin(Categoria *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Categoria), 1, arquivo);
}

void adicionarAcomodacaoBin(Acomodacao *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Acomodacao), 1, arquivo);
}

void adicionarConsumivelBin(Consumivel *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Consumivel), 1, arquivo);
}

void adicionarFornecedorBin(Fornecedor *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Fornecedor), 1, arquivo);
}

void adicionarOperadorBin(Operador *estrutura, FILE *arquivo)
{
    fwrite(estrutura, sizeof(Operador), 1, arquivo);
}

// ------------Read-----------

int lerHotelBin(FILE *arquivo, Hotel *ptrHotel)
{

    fread(ptrHotel, sizeof(Hotel), 1, arquivo);
}

int lerHospedeBin(int codigo, FILE *arquivo, Hospede *ptrHospede)
{
    if (fread(ptrHospede, sizeof(Hospede), 1, arquivo))
    {
        if (ptrHospede->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerCategoriaBin(int codigo, FILE *arquivo, Categoria *ptrCategoria)
{
    if (fread(ptrCategoria, sizeof(Categoria), 1, arquivo))
    {
        if (ptrCategoria->codigo == codigo || codigo == 0)
        {
            return 1;
        }
    }

    return 0;
}

int lerAcomodacaoBin(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao)
{

    if (fread(ptrAcomodacao, sizeof(Acomodacao), 1, arquivo))
    {
        if (ptrAcomodacao->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerConsumivelBin(int codigo, FILE *arquivo, Consumivel *ptrConsumivel)
{
    if (fread(ptrConsumivel, sizeof(Consumivel), 1, arquivo))
    {
        if (ptrConsumivel->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerFornecedorBin(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor)
{
    if (fread(ptrFornecedor, sizeof(Hospede), 1, arquivo))
    {
        if (ptrFornecedor->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerOperadorBin(int codigo, FILE *arquivo, Operador *ptrOperador)
{
    if (fread(ptrOperador, sizeof(Hospede), 1, arquivo))
    {
        if (ptrOperador->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

// ------------Update---------

// Função para atualizar um registro de Hospede
int atualizarHospedeBin(int codigo, Hospede *novoDados)
{
    FILE *arquivo = fopen("arquivo/hospede.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    while (1)
    {
        int resultadoLeitura = lerHospede(0, arquivo, novoDados);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (novoDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                fwrite(novoDados, sizeof(Hospede), 1, tempFile);
                encontrado = 1;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                fwrite(novoDados, sizeof(Hospede), 1, tempFile);
            }
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/hospede.txt");
    rename("arquivo/temp.txt", "arquivo/hospede.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de Categoria
int atualizarCategoriaBin(int codigo, Categoria *novoDados)
{
    FILE *arquivo = fopen("arquivo/categoria.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Categoria categoriaTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&categoriaTemp, sizeof(Categoria), 1, arquivo) == 1)
    {
        if (categoriaTemp.codigo == codigo)
        {
            // Se o código foi encontrado, atualize os dados com os novos dados
            memcpy(&categoriaTemp, novoDados, sizeof(Categoria));
            encontrado = 1;
        }
        fwrite(&categoriaTemp, sizeof(Categoria), 1, tempFile);
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/categoria.txt");
    rename("arquivo/temp.txt", "arquivo/categoria.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de Acomodação
int atualizarAcomodacaoBin(int codigo, Acomodacao *novoDados)
{
    FILE *arquivo = fopen("arquivo/acomodacao.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Acomodacao acomodacaoTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&acomodacaoTemp, sizeof(Acomodacao), 1, arquivo) == 1)
    {
        if (acomodacaoTemp.codigo == codigo)
        {
            // Se o código foi encontrado, atualize os dados com os novos dados
            memcpy(&acomodacaoTemp, novoDados, sizeof(Acomodacao));
            fwrite(&acomodacaoTemp, sizeof(Acomodacao), 1, tempFile);
            encontrado = 1;
        }
        else
        {
            // Se não for o código que estamos procurando, escreva o registro original no arquivo temporário
            fwrite(&acomodacaoTemp, sizeof(Acomodacao), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/acomodacao.txt");
    rename("arquivo/temp.txt", "arquivo/acomodacao.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de Hotel
int atualizarHotelBin(Hotel *novosDados)
{
    FILE *arquivo = fopen("arquivo/hotel.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    Hotel hotelTemp; // Estrutura temporária para armazenar os dados lidos

    memcpy(&hotelTemp, novosDados, sizeof(Hotel));
    fwrite(&hotelTemp, sizeof(Hotel), 1, tempFile);

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/hotel.txt");
    rename("arquivo/temp.txt", "arquivo/hotel.txt");

    printf("Registro atualizado com sucesso!\n");
    return 1; // Indica que a operação foi bem-sucedida
}

// Função para atualizar um registro de consumível
int atualizarConsumivelBin(int codigo, Consumivel *novosDados)
{
    FILE *arquivo = fopen("arquivo/consumivel.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Consumivel consumivelTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&consumivelTemp, sizeof(Consumivel), 1, arquivo) == 1)
    {
        if (consumivelTemp.codigo == codigo)
        {
            // Se o código foi encontrado, atualize os dados com os novos dados
            memcpy(&consumivelTemp, novosDados, sizeof(Consumivel));
            fwrite(&consumivelTemp, sizeof(Consumivel), 1, tempFile);
            encontrado = 1;
        }
        else
        {
            // Se não for o código que estamos procurando, escreva o registro original no arquivo temporário
            fwrite(&consumivelTemp, sizeof(Consumivel), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/consumivel.txt");
    rename("arquivo/temp.txt", "arquivo/consumivel.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de fornecedor
int atualizarFornecedorBin(int codigo, Fornecedor *novoDados)
{
    FILE *arquivo = fopen("arquivo/fornecedor.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Fornecedor fornecedorTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&fornecedorTemp, sizeof(Fornecedor), 1, arquivo) == 1)
    {
        if (fornecedorTemp.codigo == codigo)
        {
            // Se o código foi encontrado, atualize os dados com os novos dados
            memcpy(&fornecedorTemp, novoDados, sizeof(Fornecedor));
            fwrite(&fornecedorTemp, sizeof(Fornecedor), 1, tempFile);
            encontrado = 1;
        }
        else
        {
            // Se não for o código que estamos procurando, escreva o registro original no arquivo temporário
            fwrite(&fornecedorTemp, sizeof(Fornecedor), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/fornecedor.txt");
    rename("arquivo/temp.txt", "arquivo/fornecedor.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de operador
int atualizarOperadorBin(int codigo, Operador *novoDados)
{
    FILE *arquivo = fopen("arquivo/operador.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Operador operadorTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&operadorTemp, sizeof(Operador), 1, arquivo) == 1)
    {
        if (operadorTemp.codigo == codigo)
        {
            // Se o código foi encontrado, atualize os dados com os novos dados
            memcpy(&operadorTemp, novoDados, sizeof(Operador));
            fwrite(&operadorTemp, sizeof(Operador), 1, tempFile);
            encontrado = 1;
        }
        else
        {
            // Se não for o código que estamos procurando, escreva o registro original no arquivo temporário
            fwrite(&operadorTemp, sizeof(Operador), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/operador.txt");
    rename("arquivo/temp.txt", "arquivo/operador.txt");

    if (encontrado)
    {
        printf("Registro com código %d atualizado com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Registro com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

//------------Delete---------

// Função para deletar todos os registros de Hotel
int deletarHotelBin()
{
    FILE *arquivo = fopen("arquivo/hotel.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0; // Indica que a operação falhou
    }

    // Feche o arquivo imediatamente para excluí-lo
    fclose(arquivo);

    printf("Todos os registros de hotel foram excluídos com sucesso!\n");
    return 1; // Indica que a operação foi bem-sucedida
}

// Função para deletar um hóspede por código
int deletarHospedeBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/hospede.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Hospede hospedeTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&hospedeTemp, sizeof(Hospede), 1, arquivo) == 1)
    {
        if (hospedeTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&hospedeTemp, sizeof(Hospede), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitui o arquivo original pelo arquivo temporário
    remove("arquivo/hospede.txt");
    rename("arquivo/temp.txt", "arquivo/hospede.txt");

    if (encontrado)
    {
        printf("Hóspede com código %d excluída com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Hóspede com código %d não encontrada!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar uma categoria por código
int deletarCategoriaBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/categoria.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Categoria categoriaTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&categoriaTemp, sizeof(Categoria), 1, arquivo) == 1)
    {
        if (categoriaTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&categoriaTemp, sizeof(Categoria), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/categoria.txt");
    rename("arquivo/temp.txt", "arquivo/categoria.txt");

    if (encontrado)
    {
        printf("Categoria com código %d excluída com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Categoria com código %d não encontrada!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar uma acomodação por código
int deletarAcomodacaoBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/acomodacao.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Acomodacao acomodacaoTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&acomodacaoTemp, sizeof(Acomodacao), 1, arquivo) == 1)
    {
        if (acomodacaoTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&acomodacaoTemp, sizeof(Acomodacao), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/acomodacao.txt");
    rename("arquivo/temp.txt", "arquivo/acomodacao.txt");

    if (encontrado)
    {
        printf("Acomodação com código %d excluída com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Acomodação com código %d não encontrada!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um consumível por código
int deletarConsumivelBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/consumivel.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Consumivel consumivelTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&consumivelTemp, sizeof(Consumivel), 1, arquivo) == 1)
    {
        if (consumivelTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&consumivelTemp, sizeof(Consumivel), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/consumivel.txt");
    rename("arquivo/temp.txt", "arquivo/consumivel.txt");

    if (encontrado)
    {
        printf("Consumível com código %d excluído com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Consumível com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um fornecedor por código
int deletarFornecedorBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/fornecedor.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Fornecedor fornecedorTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&fornecedorTemp, sizeof(Fornecedor), 1, arquivo) == 1)
    {
        if (fornecedorTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&fornecedorTemp, sizeof(Fornecedor), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/fornecedor.txt");
    rename("arquivo/temp.txt", "arquivo/fornecedor.txt");

    if (encontrado)
    {
        printf("Fornecedor com código %d excluído com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Fornecedor com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um operador por código
int deletarOperadorBin(int codigo)
{
    FILE *arquivo = fopen("arquivo/operador.txt", "r+");
    FILE *tempFile = fopen("arquivo/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado

    Operador operadorTemp; // Estrutura temporária para armazenar os dados lidos

    while (fread(&operadorTemp, sizeof(Operador), 1, arquivo) == 1)
    {
        if (operadorTemp.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&operadorTemp, sizeof(Operador), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivo/operador.txt");
    rename("arquivo/temp.txt", "arquivo/operador.txt");

    if (encontrado)
    {
        printf("Operador com código %d excluído com sucesso!\n", codigo);
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        printf("Operador com código %d não encontrado!\n", codigo);
        return 0; // Indica que o código não foi encontrado
    }
}
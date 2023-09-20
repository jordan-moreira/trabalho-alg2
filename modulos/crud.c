#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"
#include "crud.h"

// Capturar dados;
// Trabalhar com os dados;
// Gravar no arquivo;

// ------------Create---------

void criarHotel(Hotel *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "Nome:%s ;Razão Social:%s ;Inscrição Estadual:%s ;CNPJ:%s ;Endereço:%s ;Número de Celular:%s ;E-mail:%s ;Responsável:%s ;Número de Celular do Responsável:%s ;Horário de Check-In:%s ;Horário de Check-Out:%s ;", estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoEstadual, estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail, estrutura->responsavel, estrutura->celularResponsavel, estrutura->horarioCheckIn, estrutura->horarioCheckOut);
}

void adicionarHospede(Hospede *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s ,endereco:%s ,cpf:%s ,celular:%s ,eMail:%s ,sexo:%s ,estadoCivil:%s ,dataNasc:%s ;}\n\n", estrutura->codigo, estrutura->nome, estrutura->endereco, estrutura->cpf, estrutura->celular, estrutura->eMail, estrutura->sexo, estrutura->estadoCivil, estrutura->dataNasc);
}

void adicionarCategoria(Categoria *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{quantPessoas:%d, valor:%f, descricao:%s ;}\n\n", estrutura->codigo, estrutura->quantPessoas, estrutura->valor, estrutura->descricao);
}

void adicionarAcomodacao(Acomodacao *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{categoria:%d, ocupada:%d, dataInicial:%d/%d/%d, dataFinal:%d/%d/%d, descricao:%s ,facilidades:%s ;}\n\n",
            estrutura->codigo, estrutura->categoria, estrutura->ocupada,
            estrutura->data.dataInicial[0], estrutura->data.dataInicial[1], estrutura->data.dataInicial[2],
            estrutura->data.dataFinal[0], estrutura->data.dataFinal[1], estrutura->data.dataFinal[2],
            estrutura->descricao, estrutura->facilidades);
}

void adicionarConsumivel(Consumivel *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%s , precoCusto:%f, precoVenda:%f ;}\n\n",
            estrutura->codigo, estrutura->estoque, estrutura->estoqueMin,
            estrutura->descricao, estrutura->precoCusto, estrutura->precoVenda);
}

void adicionarFornecedor(Fornecedor *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s , razaoSocial:%s , inscricaoSocial:%s , cnpj:%s , endereco:%s , celular:%s , eMail:%s ;}\n\n",
            estrutura->codigo, estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoSocial,
            estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail);
}

void adicionarOperador(Operador *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%s ;}\n\n",
            estrutura->codigo, estrutura->nome, estrutura->usuario, estrutura->senha, estrutura->permissao);
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

// ------------Update---------

// Função para atualizar um registro de Hospede
int atualizarHospede(int codigo, Hospede *novoDados)
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
int atualizarCategoria(int codigo, Categoria *novoDados)
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
int atualizarAcomodacao(int codigo, Acomodacao *novoDados)
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
int atualizarHotel(Hotel *novosDados)
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
int atualizarConsumivel(int codigo, Consumivel *novosDados)
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
int atualizarFornecedor(int codigo, Fornecedor *novoDados)
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
int atualizarOperador(int codigo, Operador *novoDados)
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
int deletarHotel()
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
int deletarHospede(int codigo)
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
int deletarCategoria(int codigo)
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
int deletarAcomodacao(int codigo)
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
int deletarConsumivel(int codigo)
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
int deletarFornecedor(int codigo)
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
int deletarOperador(int codigo)
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
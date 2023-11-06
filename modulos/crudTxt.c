#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "reservas.h"
#include "crudTxt.h"

// Gravar no arquivo;

// ------------Create---------

void criarHotelTxt(Hotel *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "Nome:%s; Razão Social:%s; Inscrição Estadual:%s; CNPJ:%s; Endereço:%s; Número de Celular:%s; E-mail:%s; Responsável:%s; Celular do Responsável:%s; Horário de Check-In:%s; Horário de Check-Out:%s;", estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoEstadual, estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail, estrutura->responsavel, estrutura->celularResponsavel, estrutura->horarioCheckIn, estrutura->horarioCheckOut);
}

void adicionarHospedeTxt(Hospede *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s, endereco:%s, cpf:%s, celular:%s, eMail:%s, sexo:%s, estadoCivil:%s, dataNasc:%s;}\n", estrutura->codigo, estrutura->nome, estrutura->endereco, estrutura->cpf, estrutura->celular, estrutura->eMail, estrutura->sexo, estrutura->estadoCivil, estrutura->dataNasc);
}

void adicionarCategoriaTxt(Categoria *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%s{quantPessoas:%d, valor:%f, descricao:%s;}\n", estrutura->codigo, estrutura->quantPessoas, estrutura->valor, estrutura->descricao);
}

void adicionarAcomodacaoTxt(Acomodacao *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{categoria:%s, descricao:%s, facilidades:%s;}\n",
            estrutura->codigo, estrutura->categoria,
            estrutura->descricao, estrutura->facilidades);
}

void adicionarConsumivelTxt(Consumivel *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%s, precoCusto:%f, precoVenda:%f;}\n",
            estrutura->codigo, estrutura->estoque, estrutura->estoqueMin,
            estrutura->descricao, estrutura->precoCusto, estrutura->precoVenda);
}

void adicionarFornecedorTxt(Fornecedor *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s, razaoSocial:%s, inscricaoSocial:%s, cnpj:%s, endereco:%s, celular:%s, eMail:%s;}\n",
            estrutura->codigo, estrutura->nome, estrutura->razaoSocial, estrutura->inscricaoSocial,
            estrutura->cnpj, estrutura->endereco, estrutura->celular, estrutura->eMail);
}

void adicionarOperadorTxt(Operador *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{nome:%s, usuario:%s, senha:%s, permissao:%c;}\n",
            estrutura->codigo, estrutura->nome, estrutura->usuario, estrutura->senha, estrutura->permissao);
}

void adicionarReservaTxt(Reserva *estrutura, FILE *arquivo)
{

    fprintf(arquivo, "%d{data inicial:%s, data final:%s, hospede:%d, acomodacao:%d, check-in:%c;}\n", estrutura->codigo, estrutura->dataInicial, estrutura->dataFinal, estrutura->hospede, estrutura->acomodacao);
}

// ------------Read-----------

int lerHotelTxt(FILE *arquivo, Hotel *ptrHotel)
{

    if (
        fscanf(arquivo, "Nome:%[^;]; Razão Social:%[^;]; Inscrição Estadual:%[^;]; CNPJ:%[^;]; Endereço:%[^;]; Número de Celular:%[^;]; E-mail:%[^;]; Responsável:%[^;]; Celular do Responsável:%[^;]; Horário de Check-In:%[^;]; Horário de Check-Out:%[^;]; ", ptrHotel->nome, ptrHotel->razaoSocial, ptrHotel->inscricaoEstadual, ptrHotel->cnpj, ptrHotel->endereco, ptrHotel->celular, ptrHotel->eMail, ptrHotel->responsavel, ptrHotel->celularResponsavel, ptrHotel->horarioCheckIn, ptrHotel->horarioCheckOut))
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int lerHospedeTxt(int codigo, FILE *arquivo, Hospede *ptrHospede)
{
    if (fscanf(arquivo, "%d{nome:%[^,], endereco:%[^,], cpf:%[^,], celular:%[^,], eMail:%[^,], sexo:%[^,], estadoCivil:%[^,], dataNasc:%[^;];}", &ptrHospede->codigo, ptrHospede->nome, ptrHospede->endereco, ptrHospede->cpf, ptrHospede->celular, ptrHospede->eMail, ptrHospede->sexo, ptrHospede->estadoCivil, ptrHospede->dataNasc) == 9)
    {

        if (ptrHospede->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }

    return 0;
}

int lerCategoriaTxt(char *codigo, FILE *arquivo, Categoria *ptrCategoria)
{
    if (fscanf(arquivo, " %[^{]{quantPessoas:%d, valor:%f, descricao:%[^;];}", ptrCategoria->codigo, &ptrCategoria->quantPessoas, &ptrCategoria->valor, ptrCategoria->descricao) == 4)
    {
        if (!strcmp(ptrCategoria->codigo, codigo) || !strcmp(codigo, "0"))
        {
            return 1;
        }
    }

    return 0;
}

int lerAcomodacaoTxt(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao)
{

    if (fscanf(arquivo, "%d{categoria:%[^,], descricao:%[^,], facilidades:%[^;];}", &ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->descricao, ptrAcomodacao->facilidades) == 4)
    {
        if (ptrAcomodacao->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerConsumivelTxt(int codigo, FILE *arquivo, Consumivel *ptrConsumivel)
{
    if (fscanf(arquivo, "%d{estoque:%d, estoqueMin:%d, descricao:%[^,], precoCusto:%f, precoVenda:%f;}", &ptrConsumivel->codigo, &ptrConsumivel->estoque, &ptrConsumivel->estoqueMin, ptrConsumivel->descricao, &ptrConsumivel->precoCusto, &ptrConsumivel->precoVenda) == 6)
    {
        if (ptrConsumivel->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerFornecedorTxt(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor)
{
    if (fscanf(arquivo, "%d{nome:%[^,], razaoSocial:%[^,], inscricaoSocial:%[^,], cnpj:%[^,], endereco:%[^,], celular:%[^,], eMail:%[^;];}", &ptrFornecedor->codigo, &ptrFornecedor->nome, &ptrFornecedor->razaoSocial, &ptrFornecedor->inscricaoSocial, &ptrFornecedor->cnpj, &ptrFornecedor->endereco, &ptrFornecedor->celular, &ptrFornecedor->eMail) == 8)
    {
        if (ptrFornecedor->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerOperadorTxt(int codigo, FILE *arquivo, Operador *ptrOperador)
{
    if (fscanf(arquivo, "%d{nome:%[^,], usuario:%[^,], senha:%[^,], permissao:%c;}", &ptrOperador->codigo, &ptrOperador->nome, &ptrOperador->usuario, &ptrOperador->senha, &ptrOperador->permissao) == 5)
    {

        if (ptrOperador->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

int lerReservaTxt(int codigo, FILE *arquivo, Reserva *ptrReserva)
{
    if (fscanf(arquivo, "%d{data inicial:%[^,], data final:%[^,], hospede:%d, acomodacao:%d, check-in:%c;}", &ptrReserva->codigo, &ptrReserva->dataInicial, &ptrReserva->dataFinal, &ptrReserva->hospede, &ptrReserva->acomodacao) == 5)
    {
        if (ptrReserva->codigo == codigo || codigo == 0)
        {

            return 1;
        }
    }
    return 0;
}

// ------------Update---------

// Função para atualizar um registro de Hotel
int atualizarHotelTxt(Hotel *novoDados)
{
    FILE *arquivo = fopen("arquivos/hotel.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    criarHotelTxt(novoDados, tempFile);

    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/hotel.txt");
    rename("arquivos/temp.txt", "arquivos/hotel.txt");
    return 1;
}

// Função para atualizar um registro de Hospede
int atualizarHospedeTxt(int codigo, Hospede *novoDados)
{
    FILE *arquivo = fopen("arquivos/hospede.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Hospede *antigosDados = malloc(sizeof(Hospede));

    while (1)
    {
        int resultadoLeitura = lerHospedeTxt(0, arquivo, antigosDados);

        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarHospedeTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarHospedeTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/hospede.txt");
        rename("arquivos/temp.txt", "arquivos/hospede.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de Categoria
int atualizarCategoriaTxt(char *codigo, Categoria *novoDados)
{
    FILE *arquivo = fopen("arquivos/categoria.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Categoria *antigosDados = malloc(sizeof(Categoria));

    while (1)
    {
        int resultadoLeitura = lerCategoriaTxt("0", arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (!strcmp(antigosDados->codigo, codigo))
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarCategoriaTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarCategoriaTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/categoria.txt");
        rename("arquivos/temp.txt", "arquivos/categoria.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de Acomodação
int atualizarAcomodacaoTxt(int codigo, Acomodacao *novoDados)
{
    FILE *arquivo = fopen("arquivos/acomodacao.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Acomodacao *antigosDados = malloc(sizeof(Acomodacao));

    while (1)
    {
        int resultadoLeitura = lerAcomodacaoTxt(0, arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarAcomodacaoTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarAcomodacaoTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/acomodacao.txt");
        rename("arquivos/temp.txt", "arquivos/acomodacao.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de consumível
int atualizarConsumivelTxt(int codigo, Consumivel *novoDados)
{
    FILE *arquivo = fopen("arquivos/consumivel.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Consumivel *antigosDados = malloc(sizeof(Consumivel));

    while (1)
    {
        int resultadoLeitura = lerConsumivelTxt(0, arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarConsumivelTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarConsumivelTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/consumivel.txt");
        rename("arquivos/temp.txt", "arquivos/consumivel.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de fornecedor
int atualizarFornecedorTxt(int codigo, Fornecedor *novoDados)
{
    FILE *arquivo = fopen("arquivos/fornecedor.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Fornecedor *antigosDados = malloc(sizeof(Fornecedor));

    while (1)
    {
        int resultadoLeitura = lerFornecedorTxt(0, arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarFornecedorTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarFornecedorTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/fornecedor.txt");
        rename("arquivos/temp.txt", "arquivos/fornecedor.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar um registro de operador
int atualizarOperadorTxt(int codigo, Operador *novoDados)
{
    FILE *arquivo = fopen("arquivos/operador.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Operador *antigosDados = malloc(sizeof(Operador));

    while (1)
    {
        int resultadoLeitura = lerOperadorTxt(0, arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarOperadorTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarOperadorTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/operador.txt");
        rename("arquivos/temp.txt", "arquivos/operador.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para atualizar a data de uma reserva
int atualizarReservaTxt(int codigo, Reserva *novoDados)
{
    FILE *arquivo = fopen("arquivos/reserva.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0; // Indica se o código foi encontrado
    Reserva *antigosDados = malloc(sizeof(Reserva));

    while (1)
    {
        int resultadoLeitura = lerReservaTxt(0, arquivo, antigosDados);
        if (resultadoLeitura == 1)
        {
            if (antigosDados->codigo == codigo)
            {
                // Se o código foi encontrado, atualize os dados com os novos dados
                adicionarReservaTxt(novoDados, tempFile);
                encontrado = 1;
                continue;
            }
            else
            {
                // Se não for o código que estamos procurando, escreva o registro original de volta no arquivo temporário
                adicionarReservaTxt(antigosDados, tempFile);
            }
        }
        else if (feof(arquivo))
        {
            break;
        }
    }
    free(antigosDados);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/reserva.txt");
        rename("arquivos/temp.txt", "arquivos/reserva.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

//------------Delete---------

// Função para deletar todos os registros de Hotel
int deletarHotelTxt()
{
    FILE *arquivo = fopen("arquivos/hotel.txt", "w"); // abrindo o arquivo ja existente no modo "w" os seus dados sao apagados

    if (arquivo == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    // Feche o arquivo
    fclose(arquivo);

    return 1; // Indica que a operação foi bem-sucedida
}

// Função para deletar um hóspede por código
int deletarHospedeTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/hospede.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {

        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                // Indica se o código foi encontrado
    Hospede *dadosOriginais = malloc(sizeof(Hospede)); // Estrutura temporária para armazenar os dados lidos

    while (1)
    {
        int resultadoLeitura = lerHospedeTxt(0, arquivo, dadosOriginais);

        if (resultadoLeitura == 1 && dadosOriginais->codigo == codigo)
        {

            // Se o código foi encontrado, nao o escreva no novo arquivo
            encontrado = 1;

            continue;
        }
        else if (resultadoLeitura == 1 && !feof(arquivo))
        {
            adicionarHospedeTxt(dadosOriginais, tempFile);
            continue;
        }
        else if (resultadoLeitura == 0 && !feof(arquivo))
        {

            continue;
        }
        else
        {
            break;
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/hospede.txt");
        rename("arquivos/temp.txt", "arquivos/hospede.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar uma categoria por código
int deletarCategoriaTxt(char *codigo)
{
    FILE *arquivo = fopen("arquivos/categoria.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {

        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                    // Indica se o código foi encontrado
    Categoria *dadosOriginais = malloc(sizeof(Categoria)); // Estrutura temporária para armazenar os dados lidos

    while (1)
    {
        int resultadoLeitura = lerCategoriaTxt("0", arquivo, dadosOriginais);

        if (resultadoLeitura == 1 && !strcmp(dadosOriginais->codigo, codigo))
        {

            // Se o código foi encontrado, nao o escreva no novo arquivo
            encontrado = 1;

            continue;
        }
        else if (resultadoLeitura == 1 && !feof(arquivo))
        {
            adicionarCategoriaTxt(dadosOriginais, tempFile);
            continue;
        }
        else if (resultadoLeitura == 0 && !feof(arquivo))
        {

            continue;
        }
        else
        {
            break;
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    if (encontrado)
    {
        // Substitua o arquivo original pelo arquivo temporário
        remove("arquivos/categoria.txt");
        rename("arquivos/temp.txt", "arquivos/categoria.txt");
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        remove("arquivos/temp.txt");
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar uma acomodação por código
int deletarAcomodacaoTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/acomodacao.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                      // Indica se o código foi encontrado
    Acomodacao *dadosOriginais = malloc(sizeof(Acomodacao)); // Estrutura temporária para armazenar os dados lidos
    while (1)
    {
        int resultadoLeitura = lerAcomodacaoTxt(0, arquivo, dadosOriginais);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (dadosOriginais->codigo == codigo)
            {
                // Se o código foi encontrado, nao o escreva no novo arquivo
                encontrado = 1;
            }
            else
            {
                adicionarAcomodacaoTxt(dadosOriginais, tempFile);
            }
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/acomodacao.txt");
    rename("arquivos/temp.txt", "arquivos/acomodacao.txt");

    if (encontrado)
    {
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um consumível por código
int deletarConsumivelTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/consumivel.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                      // Indica se o código foi encontrado
    Consumivel *dadosOriginais = malloc(sizeof(Consumivel)); // Estrutura temporária para armazenar os dados lidos
    while (1)
    {
        int resultadoLeitura = lerConsumivelTxt(0, arquivo, dadosOriginais);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (dadosOriginais->codigo == codigo)
            {
                // Se o código foi encontrado, nao o escreva no novo arquivo
                encontrado = 1;
            }
            else
            {
                adicionarConsumivelTxt(dadosOriginais, tempFile);
            }
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/consumivel.txt");
    rename("arquivos/temp.txt", "arquivos/consumivel.txt");

    if (encontrado)
    {
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um fornecedor por código
int deletarFornecedorTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/fornecedor.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                      // Indica se o código foi encontrado
    Fornecedor *dadosOriginais = malloc(sizeof(Fornecedor)); // Estrutura temporária para armazenar os dados lidos
    while (1)
    {
        int resultadoLeitura = lerFornecedorTxt(0, arquivo, dadosOriginais);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (dadosOriginais->codigo == codigo)
            {
                // Se o código foi encontrado, nao o escreva no novo arquivo
                encontrado = 1;
            }
            else
            {
                adicionarFornecedorTxt(dadosOriginais, tempFile);
            }
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/fornecedor.txt");
    rename("arquivos/temp.txt", "arquivos/fornecedor.txt");

    if (encontrado)
    {
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar um operador por código
int deletarOperadorTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/operador.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                  // Indica se o código foi encontrado
    Operador *dadosOriginais = malloc(sizeof(Operador)); // Estrutura temporária para armazenar os dados lidos
    while (1)
    {
        int resultadoLeitura = lerOperadorTxt(0, arquivo, dadosOriginais);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (dadosOriginais->codigo == codigo)
            {
                // Se o código foi encontrado, nao o escreva no novo arquivo
                encontrado = 1;
            }
            else
            {
                adicionarOperadorTxt(dadosOriginais, tempFile);
            }
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/operador.txt");
    rename("arquivos/temp.txt", "arquivos/operador.txt");

    if (encontrado)
    {
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        return 0; // Indica que o código não foi encontrado
    }
}

// Função para deletar uma reserva por código
int deletarReservaTxt(int codigo)
{
    FILE *arquivo = fopen("arquivos/reserva.txt", "r");
    FILE *tempFile = fopen("arquivos/temp.txt", "w");

    if (arquivo == NULL || tempFile == NULL)
    {
        return 0; // Indica que a operação falhou
    }

    int encontrado = 0;                                // Indica se o código foi encontrado
    Reserva *dadosOriginais = malloc(sizeof(Reserva)); // Estrutura temporária para armazenar os dados lidos
    while (1)
    {
        int resultadoLeitura = lerReservaTxt(0, arquivo, dadosOriginais);
        if (resultadoLeitura == 0)
        {
            // Fim do arquivo
            break;
        }

        if (resultadoLeitura == 1)
        {
            if (dadosOriginais->codigo == codigo)
            {
                // Se o código foi encontrado, nao o escreva no novo arquivo
                encontrado = 1;
            }
            else
            {
                adicionarReservaTxt(dadosOriginais, tempFile);
            }
        }
    }
    free(dadosOriginais);
    fclose(arquivo);
    fclose(tempFile);

    // Substitua o arquivo original pelo arquivo temporário
    remove("arquivos/reserva.txt");
    rename("arquivos/temp.txt", "arquivos/reserva.txt");

    if (encontrado)
    {
        return 1; // Indica que a operação foi bem-sucedida
    }
    else
    {
        return 0; // Indica que o código não foi encontrado
    }
}

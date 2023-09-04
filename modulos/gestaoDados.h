#ifndef GESTAODADOS_H
#define GESTAODADOS_H

// estrutura que inclui os dados referentes ao hotel
typedef struct
{
    char nome,
        razaoSocial,
        inscricaoEstadual,
        cnpj[19],
        endereco,
        celular[11],
        eMail,
        // dono ou gerente
        responsavel,
        celularResponsavel,
        horarioCheckIn,
        horarioCheckOut;

    float margemLucro;

} Hotel;

// estrutura que inclui os dados de hospedes
typedef struct
{
    int codigo;

    char nome,
        endereco,
        cpf[15],
        celular[11],
        eMail,
        sexo[1],
        estadoCivil[11],
        dataNasc[8];
} Hospede;

// estrutura que inclui os dados de categorizacao dos quartos
typedef struct
{
    int codigo,
        quantPessoas;

    char descricao;

    float valor;
} Categoria;

typedef struct
{
    char dataInicial[10],
         dataFinal[10];
         
}Reserva;

// estrutura que inclui os dados dos quartos
typedef struct
{
    int codigo,
        categoria, //pre cadastrada
        ocupada;

    Reserva reserva;

    char descricao,
        facilidades;

} Acomodacao;

// estrutura que inclui os dados dos produtos consumiveis pelos hospedes
typedef struct
{
    int codigo,
        estoque,
        estoqueMin;

    char descricao;

    float precoCusto,
        precoVenda;

} Consumivel;

// estrutura que inclui os dados dos fornecedores
typedef struct
{
    int codigo;

    char nome,
        razaoSocial,
        inscrisaoSocial,
        cnpj[19],
        endereco,
        celular[11],
        eMail;

} Fornecedor;

// estrutura que inclui os dados dos operadores do sistema
typedef struct
{
    int codigo;

    char nome,
        usuario,
        senha,
        permissao;
} Operador;

// funcao que executa a gestao de dados
void gerirCadastros(char tipo, char valor);

#endif
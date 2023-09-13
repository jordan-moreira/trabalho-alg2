#ifndef GESTAODADOS_H
#define GESTAODADOS_H

// estrutura que inclui os dados referentes ao hotel
typedef struct
{
    char nome[100],
        razaoSocial[100],
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

// estrutura que inclui os dados das datas inicias e finais de uma reserva no formato int data[3]={dia,mes,ano}
typedef struct
{
    int dataInicial[3],
        dataFinal[3];

} Reserva;

// estrutura que inclui os dados dos quartos
typedef struct
{
    int codigo,
        categoria, // armazena o codigo da categoria pre cadastrada
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

// funcao responsavel por gerenciar dados do hotel
void gerenciarHotel();

// funcao responsavel por gerenciar dados dos hospedes
void gerenciarHospedes();

// funcao responsavel por gerenciar dados dos quartos
void gerenciarQuartos();

// funcao responsavel por gerenciar dados das categorias dos quartos
void gerenciarCategorias();

// funcao responsavel por gerenciar dados dos consumiveis
void gerenciarConsumiveis();

// funcao responsavel por gerenciar dados dos fornecedores
void gerenciarFornecedores();

// funcao responsavel por gerenciar dados dos operadores
void gerenciarOperadores();

// funcao responsavel por coletar o tipo de operacao CRUD a ser realizada retornando-a
int selecionarOperacao(char *);

// funcao responsvel por coletar e armazenar os dados do hotel e retornar o ponteiro da memoria onde foi alocado a estrutura com os dados
Hotel *coletarDadosHotel();

#endif
#ifndef GESTAODADOS_H
#define GESTAODADOS_H

// estrutura que inclui os dados referentes ao hotel
typedef struct
{
    char nome[100],
        razaoSocial[100],
        inscricaoEstadual[15],
        cnpj[20],
        endereco[100],
        celular[12],
        eMail[100],
        // dono ou gerente
        responsavel[100],
        celularResponsavel[12],
        horarioCheckIn[6],  // Horário de check-in do hotel (formato HH:MM)
        horarioCheckOut[6]; // Horário de check-out do hotel (formato HH:MM)

    float margemLucro;

} Hotel;

// estrutura que inclui os dados de hospedes
typedef struct
{
    int codigo;

    char nome[100],
        endereco[100],
        cpf[15],
        celular[12],
        eMail[100],
        sexo[2], // Sexo do hóspede (M ou F)
        estadoCivil[20],
        dataNasc[11]; // Data de nascimento do hóspede (formato dd/mm/aaaa)
} Hospede;

// estrutura que inclui os dados de categorizacao dos quartos
typedef struct
{
    char codigo[50];
    int quantPessoas;

    char descricao[100];

    float valor;
} Categoria;

// estrutura que inclui os dados dos quartos
typedef struct
{
    int codigo;
    char categoria[50]; // armazena o codigo da categoria pre cadastrada

    char descricao[100],
        facilidades[100];

} Acomodacao;

// estrutura que inclui os dados dos produtos consumiveis pelos hospedes
typedef struct
{
    int codigo,
        estoque,
        estoqueMin;

    char descricao[100];

    float precoCusto,
        precoVenda;

} Consumivel;

// estrutura que inclui os dados dos fornecedores
typedef struct
{
    int codigo;

    char nome[100],
        razaoSocial[100],
        inscricaoSocial[20],
        cnpj[20],
        endereco[100],
        celular[12],
        eMail[100];

} Fornecedor;

// estrutura que inclui os dados dos operadores do sistema
typedef struct
{
    int codigo;

    char nome[100],
        usuario[50],
        senha[50],
        permissao;
} Operador;

// estrutura que inclui os dados das datas inicias e finais de uma reserva no formato char data="dd/mm/aaaa"
typedef struct
{
    int codigo,
        hospede,
        acomodacao;
    char dataInicial[11],
        dataFinal[11],
        checkIn;

} Reserva;

// estrutura responsavel por armazenar o ponteiro dos dados quando armazenados em memoria
typedef struct
{
    Hotel *hotel;
    Hospede **hospede;
    int tamHospede;
    Categoria **categoria;
    int tamCategoria;
    Acomodacao **acomodacao;
    int tamAcomodacao;
    Consumivel **consumivel;
    int tamConsumivel;
    Fornecedor **fornecedor;
    int tamFornecedor;
    Operador **operador;
    int tamOperador;
    Reserva **reserva;
    int tamReserva;
} PtrMemoria;

// -------------------FUNÇÕES-------------

// funcao responsavel por coletar o tipo de operacao CRUD a ser realizada retornando-a
int selecionarOperacao(char *tipoDoDado);

// funcao usada para alterar o tipo de armazenamento de .txt para .bin ou .bin para .txt
void converterArquivos(char tipoArquivo);

// funcao responsavel por gerenciar dados do hotel
void gerenciarHotel(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados dos hospedes
void gerenciarHospede(char tipoArquivo, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados das categorias dos quartos
void gerenciarCategoria(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados dos quartos
void gerenciarAcomodacao(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados dos consumiveis
void gerenciarConsumivel(char tipoArquivo, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados dos fornecedores
void gerenciarFornecedor(char tipoArquivo, PtrMemoria *ptrMemoria);

// funcao responsavel por gerenciar dados dos operadores
void gerenciarOperador(char tipoArquivo, PtrMemoria *ptrMemoria);

// funcao responsvel por coletar e armazenar em uma struct os dados do hotel e retornar o ponteiro da memoria onde a struct esta alocada
Hotel *coletarDadosHotel();

// funcao responsvel por coletar e armazenar em uma struct os dados de um hospede e retornar o ponteiro da memoria onde a struct esta alocada
Hospede *coletarDadosHospede();

// funcao responsvel por coletar e armazenar em uma struct os dados de uma categoria de acomodacao e retornar o ponteiro da memoria onde a struct esta alocada
Categoria *coletarDadosCategoria();

// funcao responsvel por coletar e armazenar em uma struct os dados de uma acomodacao e retornar o ponteiro da memoria onde a struct esta alocada
Acomodacao *coletarDadosAcomodacao(char tipoArquivo);

// funcao responsvel por coletar e armazenar em uma struct os dados de um consumivel e retornar o ponteiro da memoria onde a struct esta alocada
Consumivel *coletarDadosConsumivel();

// funcao responsvel por coletar e armazenar em uma struct os dados de um fornecedor e retornar o ponteiro da memoria onde a struct esta alocada
Fornecedor *coletarDadosFornecedor();

// funcao responsvel por coletar e armazenar em uma struct os dados de um operador e retornar o ponteiro da memoria onde a struct esta alocada
Operador *coletarDadosOperador();

#endif
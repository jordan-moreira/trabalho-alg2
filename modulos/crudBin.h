#ifndef CRUDBIN_H
#define CRUDBIN_H

// ------------Create---------

// Função responsavel pelo registro das informações do hotel em um arquivo .bin
void criarHotelBin(Hotel *estrutura, FILE *arquivo);

// Função responsavel pelo registro de um hospede em um arquivo .bin
void adicionarHospedeBin(Hospede *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma categoria em um arquivo .bin
void adicionarCategoriaBin(Categoria *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma acomodacao em um arquivo .bin
void adicionarAcomodacaoBin(Acomodacao *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um consumivel em um arquivo .bin
void adicionarConsumivelBin(Consumivel *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um fornecedor em um arquivo .bin
void adicionarFornecedorBin(Fornecedor *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um operador de sistema em um arquivo .bin
void adicionarOperadorBin(Operador *estrutura, FILE *arquivo);

// ------------Read-----------

// Função responsavel por ler os registros do hotel em um arquivo .bin
int lerHotelBin(FILE *arquivo, Hotel *ptrHotel);

// Função responsavel por ler os registros de hóspede em um arquivo .bin
int lerHospedeBin(int codigo, FILE *arquivo, Hospede *ptrHospede);
// Função responsavel por ler os registros de categoria em um arquivo .bin
int lerCategoriaBin(char *codigo, FILE *arquivo, Categoria *ptrCategoria);

// Função responsavel por ler os registros de acomodação em um arquivo .bin
int lerAcomodacaoBin(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao);
// Função responsavel por ler os registros de consumível em um arquivo .bin
int lerConsumivelBin(int codigo, FILE *arquivo, Consumivel *ptrConsumivel);
// Função responsavel por ler os registros de fornecedor em um arquivo .bin
int lerFornecedorBin(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor);
// Função responsavel por ler os registros de operador em um arquivo .bin
int lerOperadorBin(int codigo, FILE *arquivo, Operador *ptrOperador);

// ------------Updtate-----------

// Função responsável por atualizar os registros do hotel em um arquivo .bin
int atualizarHotelBin(Hotel *novosDados);

// Função responsável por atualizar os registros de hóspede em um arquivo .bin
int atualizarHospedeBin(int codigo, Hospede *novoDados);
// Função responsável por atualizar os registros de categoria em um arquivo .bin
int atualizarCategoriaBin(char *codigo, Categoria *novoDados);

// Função responsável por atualizar os registros de acomodação em um arquivo .bin
int atualizarAcomodacaoBin(int codigo, Acomodacao *novoDados);
// Função responsavel por atualizar os registros de consumível em um arquivo .bin
int atualizarConsumivelBin(int codigo, Consumivel *novoDados);
// Função responsavel por atualizar os registros de fornecedor em um arquivo .bin
int atualizarFornecedorBin(int codigo, Fornecedor *novoDados);
// Função responsavel por atualizar os registros de operador em um arquivo .bin
int atualizarOperadorBin(int codigo, Operador *novoDados);

// ------------Delete-----------

// Função responsável por deletar os registros do hotel em um arquivo .bin
int deletarHotelBin();

// Função responsável por deletar os registros de hóspede em um arquivo .bin
int deletarHospedeBin(int codigo);
// Função responsável por deletar os registros de categoria em um arquivo .bin
int deletarCategoriaBin(char *codigo);

// Função responsável por deletar os registros de acomodação em um arquivo .bin
int deletarAcomodacaoBin(int codigo);
// Função responsável por deletar os registros de consumível em um arquivo .bin
int deletarConsumivelBin(int codigo);
// Função responsável por deletar os registros de fornecedor em um arquivo .bin
int deletarFornecedorBin(int codigo);
// Função responsável por deletar os registros de operador em um arquivo .bin
int deletarOperadorBin(int codigo);

#endif
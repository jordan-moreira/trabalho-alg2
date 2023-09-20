#ifndef CRUD_H
#define CRUD_H

// ------------Create---------

// Função responsavel pelo registro das informações do hotel;
void criarHotel(Hotel *estrutura, FILE *arquivo);

// Função responsavel pelo registro de um hospede;
void adicionarHospede(Hospede *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma categoria
void adicionarCategoria(Categoria *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma acomodacao
void adicionarAcomodacao(Acomodacao *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um consumivel
void adicionarConsumivel(Consumivel *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um fornecedor
void adicionarFornecedor(Fornecedor *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um operador de sistema
void adicionarOperador(Operador *estrutura, FILE *arquivo);

// ------------Read-----------

// Função responsavel por ler os registros do hotel;
int lerHotel(FILE *arquivo, Hotel *ptrHotel);

// Função responsavel por ler os registros de hóspede;
int lerHospede(int codigo, FILE *arquivo, Hospede *ptrHospede);
// Função responsavel por ler os registros de categoria;
int lerCategoria(int codigo, FILE *arquivo, Categoria *ptrCategoria);

// Função responsavel por ler os registros de acomodação;
int lerAcomodacao(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao);
// Função responsavel por ler os registros de consumível;
int lerConsumivel(int codigo, FILE *arquivo, Consumivel *ptrConsumivel);
// Função responsavel por ler os registros de fornecedor;
int lerFornecedor(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor);
// Função responsavel por ler os registros de operador;
int lerOperador(int codigo, FILE *arquivo, Operador *ptrOperador);

// ------------Updtate-----------

// Função responsável por atualizar os registros do hotel;
int atualizarHotel(Hotel *novosDados);

// Função responsável por atualizar os registros de hóspede;
int atualizarHospede(int codigo, Hospede *novoDados);
// Função responsável por atualizar os registros de categoria;
int atualizarCategoria(int codigo, Categoria *novoDados);

// Função responsável por atualizar os registros de acomodação;
int atualizarAcomodacao(int codigo, Acomodacao *novoDados);
// Função responsavel por atualizar os registros de consumível;
int atualizarConsumivel(int codigo, Consumivel *novoDados);
// Função responsavel por atualizar os registros de fornecedor;
int atualizarFornecedor(int codigo, Fornecedor *novoDados);
// Função responsavel por atualizar os registros de operador;
int atualizarOperador(int codigo, Operador *novoDados);

// ------------Delete-----------

// Função responsável por deletar os registros do hotel;
int deletarHotel();

// Função responsável por deletar os registros de hóspede;
int deletarHospede(int codigo);
// Função responsável por deletar os registros de categoria;
int deletarCategoria(int codigo);

// Função responsável por deletar os registros de acomodação;
int deletarAcomodacao(int codigo);
// Função responsável por deletar os registros de consumível;
int deletarConsumivel(int codigo);
// Função responsável por deletar os registros de fornecedor;
int deletarFornecedor(int codigo);
// Função responsável por deletar os registros de operador;
int deletarOperador(int codigo);

#endif
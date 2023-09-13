#ifndef CRUD_H
#define CRUD_H

// ------------Create---------

// Função responsavel pelo registro das informações do hotel;
void criarHotel(Hotel *estrutura);

// Função responsavel pelo registro de um hospede;
void adicionarHospede(Hospede *estrutura);

// funcao responsavel pelo registro de uma categoria
void adicionarCategoria(Categoria *estrutura);

// funcao responsavel pelo registro de uma acomodacao
void adicionarAcomodacao(Acomodacao *estrutura);

// funcao responsavel pelo registro de um consumivel
void adicionarConsumivel(Consumivel *estrutura);

// funcao responsavel pelo registro de um fornecedor
void adicionarFornecedor(Fornecedor *estrutura);

// funcao responsavel pelo registro de um operador de sistema
void adicionarOperador(Operador *estrutura);

// ------------Read-----------

// Função criada para ler registros de categoria;
void lerCategoria(int codigo);

#endif
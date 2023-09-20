#ifndef CRUDTXT_H
#define CRUDTXT_H

// ------------Create---------

// Função responsavel pelo registro das informações do hotel em um arquivo .txt
void criarHotelTxt(Hotel *estrutura, FILE *arquivo);

// Função responsavel pelo registro de um hospede em um arquivo .txt
void adicionarHospedeTxt(Hospede *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma categoria em um arquivo .txt
void adicionarCategoriaTxt(Categoria *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de uma acomodacao em um arquivo .txt
void adicionarAcomodacaoTxt(Acomodacao *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um consumivel em um arquivo .txt
void adicionarConsumivelTxt(Consumivel *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um fornecedor em um arquivo .txt
void adicionarFornecedorTxt(Fornecedor *estrutura, FILE *arquivo);

// funcao responsavel pelo registro de um operador de sistema em um arquivo .txt
void adicionarOperadorTxt(Operador *estrutura, FILE *arquivo);

// ------------Read-----------

// Função responsavel por ler os registros do hotel em um arquivo .txt
int lerHotelTxt(FILE *arquivo, Hotel *ptrHotel);

// Função responsavel por ler os registros de hóspede em um arquivo .txt
int lerHospedeTxt(int codigo, FILE *arquivo, Hospede *ptrHospede);
// Função responsavel por ler os registros de categoria em um arquivo .txt
int lerCategoriaTxt(int codigo, FILE *arquivo, Categoria *ptrCategoria);

// Função responsavel por ler os registros de acomodação em um arquivo .txt
int lerAcomodacaoTxt(int codigo, FILE *arquivo, Acomodacao *ptrAcomodacao);
// Função responsavel por ler os registros de consumível em um arquivo .txt
int lerConsumivelTxt(int codigo, FILE *arquivo, Consumivel *ptrConsumivel);
// Função responsavel por ler os registros de fornecedor em um arquivo .txt
int lerFornecedorTxt(int codigo, FILE *arquivo, Fornecedor *ptrFornecedor);
// Função responsavel por ler os registros de operador em um arquivo .txt
int lerOperadorTxt(int codigo, FILE *arquivo, Operador *ptrOperador);

// ------------Updtate-----------

// Função responsável por atualizar os registros do hotel em um arquivo .txt
int atualizarHotelTxt(Hotel *novosDados);

// Função responsável por atualizar os registros de hóspede em um arquivo .txt
int atualizarHospedeTxt(int codigo, Hospede *novoDados);
// Função responsável por atualizar os registros de categoria em um arquivo .txt
int atualizarCategoriaTxt(int codigo, Categoria *novoDados);

// Função responsável por atualizar os registros de acomodação em um arquivo .txt
int atualizarAcomodacaoTxt(int codigo, Acomodacao *novoDados);
// Função responsavel por atualizar os registros de consumível em um arquivo .txt
int atualizarConsumivelTxt(int codigo, Consumivel *novoDados);
// Função responsavel por atualizar os registros de fornecedor em um arquivo .txt
int atualizarFornecedorTxt(int codigo, Fornecedor *novoDados);
// Função responsavel por atualizar os registros de operador em um arquivo .txt
int atualizarOperadorTxt(int codigo, Operador *novoDados);

// ------------Delete-----------

// Função responsável por deletar os registros do hotel em um arquivo .txt
int deletarHotelTxt();

// Função responsável por deletar os registros de hóspede em um arquivo .txt
int deletarHospedeTxt(int codigo);
// Função responsável por deletar os registros de categoria em um arquivo .txt
int deletarCategoriaTxt(int codigo);

// Função responsável por deletar os registros de acomodação em um arquivo .txt
int deletarAcomodacaoTxt(int codigo);
// Função responsável por deletar os registros de consumível em um arquivo .txt
int deletarConsumivelTxt(int codigo);
// Função responsável por deletar os registros de fornecedor em um arquivo .txt
int deletarFornecedorTxt(int codigo);
// Função responsável por deletar os registros de operador em um arquivo .txt
int deletarOperadorTxt(int codigo);

#endif
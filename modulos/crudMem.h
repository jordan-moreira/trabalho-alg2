#ifndef CRUDMEM_H
#define CRUDMEM_H

// ------------Create---------

// Função responsavel pelo registro das informações do hotel em memoria
void criarHotelMem(Hotel *estrutura, PtrMemoria *ptrMemoria);

// Função responsavel pelo registro de um hospede em memoria
void adicionarHospedeMem(Hospede *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de uma categoria em memoria
void adicionarCategoriaMem(Categoria *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de uma acomodacao em memoria
void adicionarAcomodacaoMem(Acomodacao *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de um consumivel em memoria
void adicionarConsumivelMem(Consumivel *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de um fornecedor em memoria
void adicionarFornecedorMem(Fornecedor *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de um operador de sistema em memoria
void adicionarOperadorMem(Operador *estrutura, PtrMemoria *ptrMemoria);

// funcao responsavel pelo registro de uma reserva de quarto em memoria
void adicionarReservaMem(Reserva *estrutura, PtrMemoria *ptrMemoria);

// ------------Read-----------

// Função responsavel por ler os registros do hotel em memoria
int lerHotelMem(Hotel *ptrHotel, PtrMemoria *ptrMemoria);

// Função responsavel por ler os registros de hóspede em memoria
int lerHospedeMem(int codigo, Hospede *ptrHospede, Hospede *ptrMemHospede);
// Função responsavel por ler os registros de categoria em memoriax
int lerCategoriaMem(char *codigo, Categoria *ptrCategoria, Categoria *ptrMemCategoria);

// Função responsavel por ler os registros de acomodação em memoria
int lerAcomodacaoMem(int codigo, Acomodacao *ptrAcomodacao, Acomodacao *ptrMemAcomodacao);
// Função responsavel por ler os registros de consumível em memoria
int lerConsumivelMem(int codigo, Consumivel *ptrConsumivel, Consumivel *ptrMemConsumivel);
// Função responsavel por ler os registros de fornecedor em memoria
int lerFornecedorMem(int codigo, Fornecedor *ptrFornecedor, Fornecedor *ptrMemFornecedor);
// Função responsavel por ler os registros de operador em memoria
int lerOperadorMem(int codigo, Operador *ptrOperador, Operador *ptrMemOperador);
// Função responsavel por ler as reservas em memoria
int lerReservaMem(int codigo, Reserva *ptrReserva, Reserva *ptrMemReserva);

// ------------Updtate-----------

// Função responsável por atualizar os registros do hotel em memoria
int atualizarHotelMem(Hotel *novosDados, PtrMemoria *ptrMemoria);

// Função responsável por atualizar os registros de hóspede em memoria
int atualizarHospedeMem(int codigo, Hospede *novoDados, PtrMemoria *ptrMemoria);
// Função responsável por atualizar os registros de categoria em memoria
int atualizarCategoriaMem(char *codigo, Categoria *novoDados, PtrMemoria *ptrMemoria);

// Função responsável por atualizar os registros de acomodação em memoria
int atualizarAcomodacaoMem(int codigo, Acomodacao *novoDados, PtrMemoria *ptrMemoria);
// Função responsavel por atualizar os registros de consumível em memoria
int atualizarConsumivelMem(int codigo, Consumivel *novoDados, PtrMemoria *ptrMemoria);
// Função responsavel por atualizar os registros de fornecedor em memoria
int atualizarFornecedorMem(int codigo, Fornecedor *novoDados, PtrMemoria *ptrMemoria);
// Função responsavel por atualizar os registros de operador em memoria
int atualizarOperadorMem(int codigo, Operador *novoDados, PtrMemoria *ptrMemoria);
// Função responsavel por atualizar os registros de reserva em memoria
int atualizarReservaMem(int codigo, Reserva *novoDados, PtrMemoria *ptrMemoria);

// ------------Delete-----------

// Função responsável por deletar os registros do hotel em memoria
int deletarHotelMem(PtrMemoria *ptrMemoria);

// Função responsável por deletar os registros de hóspede em memoria
int deletarHospedeMem(int codigo, PtrMemoria *ptrMemoria);
// Função responsável por deletar os registros de categoria em memoria
int deletarCategoriaMem(char *codigo, PtrMemoria *ptrMemoria);

// Função responsável por deletar os registros de acomodação em memoria
int deletarAcomodacaoMem(int codigo, PtrMemoria *ptrMemoria);
// Função responsável por deletar os registros de consumível em memoria
int deletarConsumivelMem(int codigo, PtrMemoria *ptrMemoria);
// Função responsável por deletar os registros de fornecedor em memoria
int deletarFornecedorMem(int codigo, PtrMemoria *ptrMemoria);
// Função responsável por deletar os registros de operador em memoria
int deletarOperadorMem(int codigo, PtrMemoria *ptrMemoria);
// Função responsável por deletar os registros de reserva em memoria
int deletarReservaMem(int codigo, PtrMemoria *ptrMemoria);

#endif
# implementacoes a serem feitas

corrigir o erro de acesso a memoria nas funcoes de leitura

## implementacoes de cadastro e gerenciamento de dados

- [X] criar um menu de selecao de operacao primaria q sera executado na inicializacao do sistema.
- [X] criar um menu para selecionar qual tipo de dado sera cadastrado quando essa opcao for selecionada no menu principal
- [X] criar as funcoes de gerenciamento de dados uma pra cada tipo de dado(hotel, hospede, categoria, ...)
- [X] criar uma funcao responsavel por coletar o tipo de operacao que o usuario pretende fazer com aquele tipo de dado
- [X] criar a funcao de coleta e armazenamento de informacao para cada tipo de dado(hotel, hospede, categoria, ...) Create(Crud)
- [X] criar a funcao de leitura de documento completo ou de item especifico de todos os tipos de dados Read(cRud)
- [ ] criar a funcao de pesquisa de item especifico para cada dado para o mesmo poder ser alterado Update(crUd)
- [ ] criar a funcao de delecao de item especifico para cada dado Delete(cruD)
- [ ] criar uma logica de niveis de acesso para diferentes tipos de operadores de sistema

## implementacoes de cancelamento e reserva de acomodacoes

- [ ] criar uma funcao responsavel por gerir as reservas das acomodacoes questionando se o usuario pretende reservar uma acomodacao ou cancelar uma reserva
- [ ] criar uma funcao que questione a forma de filtragem das acomodacoes ( por data, categoria de acomodação, quantidade de pessoas, tipo de facilidade, ou por uma combinação destes critérios) para a realizacao de uma reserva
- [ ] criar um funcao de busca para filtrar as acomodacoes q atendem os criterios exigidos armazene esses dados em memoria e retorne uma lista de ponteiros das acomodacoes compativeis
- [ ] criar uma funcao q receba a lista de ponteiros acima e mostre na tela as informacoes sobre os quartos
- [ ]criar uma funcao responsavel por receber um ponteiro de um quarto anteriormente reservado e atualizalo para um quarto vago

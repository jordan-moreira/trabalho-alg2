# implementacoes a serem feitas

- [x] criar uma funcao responsavel por clonar os arquivos no tipo de armazanemento selecionado(txt ou bin) para todas as 7 estruturas 
- [x] alterar o tipo das variaveis de Categoria.codigo e Acomodacao.categoria para q elas aceitem texto
- [ ] criar um menu de categorias disponiveis para serem selecionas na funcao coletarDadosAcomodacao (coo na funcao coletarDadosOperador na selecao de cargos)

## implementacoes de cadastro e gerenciamento de dados

- [X] criar um menu de selecao de operacao primaria q sera executado na inicializacao do sistema.
- [X] criar um menu para selecionar qual tipo de dado sera cadastrado quando essa opcao for selecionada no menu principal
- [X] criar as funcoes de gerenciamento de dados uma pra cada tipo de dado(hotel, hospede, categoria, ...)
- [X] criar uma funcao responsavel por coletar o tipo de operacao que o usuario pretende fazer com aquele tipo de dado
- [X] criar a funcao de coleta e armazenamento de informacao para cada tipo de dado(hotel, hospede, categoria, ...) Create(Crud)
- [X] criar a funcao de leitura de documento completo ou de item especifico de todos os tipos de dados Read(cRud)
- [X] criar a funcao de pesquisa de item especifico para cada dado para o mesmo poder ser alterado Update(crUd)
- [X] criar a funcao de delecao de item especifico para cada dado Delete(cruD)
- [x] criar uma logica de niveis de acesso para diferentes tipos de operadores de sistema:
gerente geral(acesso total): CRUD de todas as estruturas codigo:g

recepcionista(check-in check-out gerenciamento de hospedes: estrutura Hospede, Reserva e Acomodacao.ocupada ):Create de Hospedes, Read de todas exceto Fornecedor e Operador, Update de Hospede, Reserva, Acomodacao.ocupada, Consumivel.estoque(apenas para subtracao); Delete de Hospede. 
codigo de acesso: R

camareiro:Nenhum acesso 
codigo de acesso: N

garcon:nenhum acesso  
codigo de acesso: No estoque:Create para Consumiveis e Fornecedor;Read total exceto Hospede, Categoria, Reserva, Acomodacao e Operador; Atualizacao de Fornecedor e Consumivel; Delete de Fornecedor e Consuivel 
codigo de acesso: E

- [x] criar a funcao de login e relacionados a checagem do nivel de acesso permitido (luiz)


## implementacoes de cancelamento e reserva de acomodacoes

- [ ] criar uma funcao responsavel por gerir as reservas das acomodacoes questionando se o usuario pretende reservar uma acomodacao ou cancelar uma reserva

#### para fazer uma reserva
- [ ] criar uma funcao para coletar os dados de filtragem como na funcao coletarDadosAcomodacao
- [ ] criar um funcao para comparar os dados informados com os dados salvos no arquivo printar as estruturas compativeis e seus codigos de identificacao
- [ ] criar uma funcao para coletar o codigo da acomodacao a ser reservada e salvar a data da reserva (dataInicial e dataFinal)

#### para cancelar uma reserva
- [ ] criar uma funcao para coletar o codigo da acomodacao a ser cancelada e apagar a data da reserva (dataInicial e dataFinal)apenas atribuir "" para as datas
 

<h2>anotacoes ignore</h2>

criar um arquivo de config para armazenar tipo arquivo ou entao criar uma logica pra isso

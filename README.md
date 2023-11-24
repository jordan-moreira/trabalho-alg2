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

## implementacoes modulo de armazenamento
- [x] criar arquivo crud.mem onde estaram as funcao q armazenam os dados em memoria (para quando fechado o sistema os dados serem descartados)
- [x] criar logica de selecao para esse tipo de armazenamento tbm

## implementacoes de cancelamento e reserva de acomodacoes

- [x] criar uma funcao responsavel por gerir as reservas das acomodacoes questionando se o usuario pretende reservar uma acomodacao ou cancelar uma reserva

#### para fazer uma reserva
- [x] criar uma funcao para coletar os dados de filtragem como na funcao coletarDadosAcomodacao
- [x] criar um funcao para comparar os dados informados com os dados salvos no arquivo printar as estruturas compativeis e seus codigos de identificacao
- [x] criar uma funcao para coletar o codigo da acomodacao a ser reservada e salvar a data da reserva (dataInicial e dataFinal)

#### para cancelar uma reserva
- [x] criar uma funcao para coletar o codigo da acomodacao a ser cancelada e apagar a data da reserva (dataInicial e dataFinal)apenas atribuir "" para as datas
 
## implementacoes modulo de transacao

- [x] criar logica e funcao de check-in
- [x] criar logica e funcao de check-out
- [x] criar logica e funcao de saida de produtos
    - [x] criar uma logica  e funcao para questionar a forma de pagamento: a vista ou a prazo
    - [x] a vista: adicionar o valor da compra ao caixa e subtrair a quantidade de produtos do estoque
    - [x] a prazo: adicionar o valor da compra a conta do hospede e subtrair a quantidade de produtos do estoque
    - [x] gerar uma nota para o cliente assinar se a venda for a prazo
- [x] criar logica e funcao de entrada de produtos
    - [x] criar funcao responsavel por lancamento de notas fiscais de entrada 
    - [x] funcao responsvel por atualizar o estoque e preco de venda do produto em questao
        > checar calculo de preco venda no arquivo enunciado.pdf pagina 4
- [x] criar logica e funcao de gestao de caixa
    - [x] criar uma logica para saber a forma de pagamento: dinheiro ou cartao(credito/debito)
    - [x] funcao para adicionar o valo da venda no caixa se a venda for em dinheiro
    - [x] funcao para adicionar ao contas a receber o valor da venda e o dia do vencimento do cartao para registrar quando o hotel recebera o valor 
    - [x] criar logica e funcoes necessarias para consulta de lancamentos e retiradas feitas no caixa(como um extrato bancario)
- [x] criar logica e funcao de contas a receber
    > responsavel por lancar no caixa o valor das contas a receber relativas a venda por cartao(credito/debito) no dia de seus vencimentos e indicar no extrato o valor recebido e a data 

- [ ] funcao responsavel pelo pagamento de produtos se a vista debitar o valor do caixa e lancar no extrato se a prazo retirar o valor de entrada se houver e lancar o restante e parcelas no contas a pagar
- [ ] criar logica e funcao de contas a pagar
    - [ ] funcao de registro de notas pagas 
    - [ ] funcao de debito de valor pago no caixa do hotel



#### anotacoes
 
revisar a logica de permissao de acesso

sera necessario a criacao de um arquivo de caixa  ou config onde serao armazenados os dados sensiveis do hotel()

criar logica para sombreamento de dados na adicao de reservas

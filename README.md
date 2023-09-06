 # implementacoes a serem feitas

 
- [x] Adicionar um campo nas acomodacoes indicando se elas estao ocupadas ou n 

- [x] criar uma estrutura de calendario ou adicionar mais um campo nas acomodacoes indicando a data inicial e final que o quarto esta ocupado se caso o quarto estiver ocupado 

- [ ] criar um menu para selecionar o tipo de arquivo a ser trabalhado

- [ ] iniciar a implementacao do modulo de manuseio de arquivos (funcoes CRUD) tanto para arquivos .bin, e .txt

- [ ] criar arquivos de dados para configuracoes(onde serao armazenados os dados do hotel, acomodacoes e suas categorias, fonecedores e operadores do sistema), produtos, hospedes e reservas(onde sera armazenados tudo relacionado sobre os quartos reservados como horarios e o codigo dos quartos)

- [ ] criar uma funcao responsavel por fazer a estrutura basica dos registro que sera executada na inicializacao do sistema como mostrado abaixo:

```c
Hotel[

],
Acomodacao[

],
Categoria[

],
Fornecedor[

],
Operador[

]
```
- [ ] criar uma logica para captura dos dados de cada estrutura no arquivo main onde essas estruturas serao passadas por pontero para as devidas funcoes de registro

- [ ] para criacao das funcoes de registros: criar um menu para captura de dados de cada estrutura onde tera uma funcao de busca responsavel por procurar um padrao de registro:

```c
tipoDaEstrutura[

]
```

para armazenar os dados coletados:

```c
tipoDaEstrutura[
    123{
        quant:3423,
        descric:ola;
    },
]
```


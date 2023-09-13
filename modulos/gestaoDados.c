#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"
#include "crud.h"

int selecionarOperacao(char *tipoDoDado)
{
    int codigoMenu = 0;
    printf("Digite o código referente à operação a ser realizada:\n");

    while (codigoMenu < 1 || codigoMenu > 4)
    {
        printf("1 - Adicionar %s.\n 2 - Atualizar informações de %s.\n 3 - Ler informações de %s.\n 4 - Deletar %s.\n", tipoDoDado, tipoDoDado, tipoDoDado, tipoDoDado);
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu >= 1 && codigoMenu <= 4)
        {
            return codigoMenu;
        }
        else
        {
            printf("Opção inválida.\n");
        }
    }
}

void gerenciarHotel()
{
    char item[] = "hotel";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Hotel *ptr = coletarDadosHotel();
        criarHotel(ptr);
        break;

        // case 2:
        // atualizarHotel();
        // break;

        // case 3:
        // lerHotel();
        // break;

        // case 4:
        // deletarHotel();
        // break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarHospede()
{
    char item[] = "hospede";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Hospede *ptr = coletarDadosHospede();
        adicionarHospede(ptr);
        break;

    case 2:
        // atualizarHospede();
        break;

    case 3:
        // lerHospede();
        break;

    case 4:
        // deletarHospede();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarCategoria()
{
    char item[] = "categoria";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Categoria *ptr = coletarDadosCategoria();
        adicionarCategoria(ptr);
        break;

    case 2:
        // atualizarCategoria();
        break;

    case 3:
        // lerCategoria();
        break;

    case 4:
        // deletarCategoria();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarAcomodacao()
{
    char item[] = "acomodacao";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Acomodacao *ptr = coletarDadosAcomodacao();
        adicionarAcomodacao(ptr);
        break;

    case 2:
        // atualizarAcomodacao();
        break;

    case 3:
        // lerAcomodacao();
        break;

    case 4:
        // deletarAcomodacao();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarConsumivel()
{
    char item[] = "consumivel";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Consumivel *ptr = coletarDadosConsumivel();
        adicionarConsumivel(ptr);
        break;

    case 2:
        // atualizarConsumivel();
        break;

    case 3:
        // lerConsumivel();
        break;

    case 4:
        // deletarConsumivel();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarFornecedor()
{
    char item[] = "fornecedor";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Fornecedor *ptr = coletarDadosFornecedor();
        adicionarFornecedor(ptr);
        break;

    case 2:
        // atualizarFornecedor();
        break;

    case 3:
        // lerFornecedor();
        break;

    case 4:
        // deletarFornecedor();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarOperador()
{
    char item[] = "operador";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Operador *ptr = coletarDadosOperador();
        adicionarOperador(ptr);
        break;

    case 2:
        // atualizarOperador();
        break;

    case 3:
        // lerOperador();
        break;

    case 4:
        // deletarOperador();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

Hotel *coletarDadosHotel()
{
    Hotel *ptrHotel = malloc(sizeof(Hotel));

    if (ptrHotel == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o nome do hotel: ");
    scanf("%s", ptrHotel->nome);

    printf("\nDigite a razão social do hotel: ");
    scanf("%s", ptrHotel->razaoSocial);

    printf("\nDigite a inscrição estadual do hotel: ");
    scanf("%s", ptrHotel->inscricaoEstadual);

    printf("\nDigite o CNPJ do hotel: ");
    scanf("%s", ptrHotel->cnpj);

    printf("\nDigite o endereço do hotel: ");
    scanf("%s", ptrHotel->endereco);

    printf("\nDigite o número de celular do hotel: ");
    scanf("%s", ptrHotel->celular);

    printf("\nDigite o e-mail do hotel: ");
    scanf("%s", ptrHotel->eMail);

    printf("\nDigite o nome do responsável (ou gerente) pelo hotel: ");
    scanf("%s", ptrHotel->responsavel);

    printf("\nDigite o número de celular do responsável (ou gerente) pelo hotel: ");
    scanf("%s", ptrHotel->celularResponsavel);

    printf("\nDigite o horário de Check-in do hotel: ");
    scanf("%s", ptrHotel->horarioCheckIn);

    printf("\nDigite o horário de Check-out do hotel: ");
    scanf("%s", ptrHotel->horarioCheckOut);

    return ptrHotel;
}

Hospede *coletarDadosHospede()
{
    Hospede *ptrHospede = malloc(sizeof(Hospede));

    if (ptrHospede == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código do hóspede: ");
    scanf("%d", &ptrHospede->codigo);

    printf("Digite o nome do hóspede: ");
    scanf("%s", ptrHospede->nome);

    printf("Digite o endereço do hóspede: ");
    scanf("%s", ptrHospede->endereco);

    printf("Digite o CPF do hóspede: ");
    scanf("%s", ptrHospede->cpf);

    printf("Digite o número de celular do hóspede: ");
    scanf("%s", ptrHospede->celular);

    printf("Digite o e-mail do hóspede: ");
    scanf("%s", ptrHospede->eMail);

    printf("Digite o sexo do hóspede (M ou F): ");
    scanf("%s", ptrHospede->sexo);

    printf("Digite o estado civil do hóspede: ");
    scanf("%s", ptrHospede->estadoCivil);

    printf("Digite a data de nascimento do hóspede (formato dd/mm/aaaa): ");
    scanf("%s", ptrHospede->dataNasc);

    return ptrHospede;
}

Categoria *coletarDadosCategoria()
{
    Categoria *ptrCategoria = malloc(sizeof(Categoria));

    if (ptrCategoria == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código da categoria: ");
    scanf("%d", &ptrCategoria->codigo);

    printf("Digite a quantidade de pessoas da categoria: ");
    scanf("%d", &ptrCategoria->quantPessoas);

    printf("Digite a descrição da categoria: ");
    scanf("%s", ptrCategoria->descricao);

    printf("Digite o valor da categoria: ");
    scanf("%f", &ptrCategoria->valor);

    return ptrCategoria;
}

Acomodacao *coletarDadosAcomodacao()
{
    Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao));

    if (ptrAcomodacao == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código da acomodação: ");
    scanf("%d", &ptrAcomodacao->codigo);

    printf("Digite o código da categoria da acomodação: ");
    scanf("%d", &ptrAcomodacao->categoria);

    printf("Digite a descrição da acomodação: ");
    scanf("%s", ptrAcomodacao->descricao);

    printf("Digite as facilidades da acomodação: ");
    scanf("%s", ptrAcomodacao->facilidades);

    printf("Acomodação ocupada? (0 - Não, 1 - Sim): ");
    scanf("%d", &ptrAcomodacao->ocupada);

    printf("Digite a data inicial da reserva (dd mm aaaa): ");
    scanf("%d %d %d", &ptrAcomodacao->data.dataInicial[0], &ptrAcomodacao->data.dataInicial[1], &ptrAcomodacao->data.dataInicial[2]);

    printf("Digite a data final da reserva (dd mm aaaa): ");
    scanf("%d %d %d", &ptrAcomodacao->data.dataFinal[0], &ptrAcomodacao->data.dataFinal[1], &ptrAcomodacao->data.dataFinal[2]);

    return ptrAcomodacao;
}

Consumivel *coletarDadosConsumivel()
{
    Consumivel *ptrConsumivel = malloc(sizeof(Consumivel));

    if (ptrConsumivel == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código do consumível: ");
    scanf("%d", &ptrConsumivel->codigo);

    printf("Digite a descrição do consumível: ");
    scanf("%s", ptrConsumivel->descricao);

    printf("Digite o estoque do consumível: ");
    scanf("%d", &ptrConsumivel->estoque);

    printf("Digite o estoque mínimo do consumível: ");
    scanf("%d", &ptrConsumivel->estoqueMin);

    printf("Digite o preço de custo do consumível: ");
    scanf("%f", &ptrConsumivel->precoCusto);

    printf("Digite o preço de venda do consumível: ");
    scanf("%f", &ptrConsumivel->precoVenda);

    return ptrConsumivel;
}

Fornecedor *coletarDadosFornecedor()
{
    Fornecedor *ptrFornecedor = malloc(sizeof(Fornecedor));

    if (ptrFornecedor == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código do fornecedor: ");
    scanf("%d", &ptrFornecedor->codigo);

    printf("Digite o nome do fornecedor: ");
    scanf("%s", ptrFornecedor->nome);

    printf("Digite a razão social do fornecedor: ");
    scanf("%s", ptrFornecedor->razaoSocial);

    printf("Digite a inscrição social do fornecedor: ");
    scanf("%s", ptrFornecedor->inscrisaoSocial);

    printf("Digite o CNPJ do fornecedor: ");
    scanf("%s", ptrFornecedor->cnpj);

    printf("Digite o endereço do fornecedor: ");
    scanf("%s", ptrFornecedor->endereco);

    printf("Digite o número de celular do fornecedor: ");
    scanf("%s", ptrFornecedor->celular);

    printf("Digite o e-mail do fornecedor: ");
    scanf("%s", ptrFornecedor->eMail);

    return ptrFornecedor;
}

Operador *coletarDadosOperador()
{
    Operador *ptrOperador = malloc(sizeof(Operador));

    if (ptrOperador == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    printf("Digite o código do operador: ");
    scanf("%d", &ptrOperador->codigo);

    printf("Digite o nome do operador: ");
    scanf("%s", ptrOperador->nome);

    printf("Digite o nome de usuário do operador: ");
    scanf("%s", ptrOperador->usuario);

    printf("Digite a senha do operador: ");
    scanf("%s", ptrOperador->senha);

    printf("Digite a permissão do operador: ");
    scanf("%s", ptrOperador->permissao);

    return ptrOperador;
}

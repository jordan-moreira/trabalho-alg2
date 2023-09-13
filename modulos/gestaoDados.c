#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"

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
        coletarDadosHotel();
        // criarHotel();
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

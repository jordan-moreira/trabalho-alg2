#include <stdio.h>
#include "modulos/gestaoDados.h"

void menuCadastro()
{
    int codigoMenu;

    while (codigoMenu != 8)
    {

        printf("---MENU---\n 1- informacoes do hote.\n 2- informacoes dos hospedes.\n 3- informacoes dos quartos.\n 4- lista de categorias dos quartos.\n 5- tabela de consumiveis.\n 6- lista de fornecedores.\n 7- lista de operadores do sistema.\n 8- voltar a tela principal.\n\n Digite um codigo referente ao item que voce deseja gerenciar: \n");
        scanf("%d%*c", &codigoMenu);

        switch (codigoMenu)
        {

        case 1:
            gerenciarHotel();
            break;

            // case 2:
            // gerenciarHospedes();
            // break;

            // case 3:
            // gerenciarQuartos();
            // break;

            // case 4:
            // gerenciarCategorias();
            // break;

            // case 5:
            // gerenciarConsumiveis();
            // break;

            // case 6:
            // gerenciarFornecedores();
            // break;

            // case 7:
            // gerenciarOperadores();
            // break;

        case 8:
            printf("voltando para tela principal\n\n");
            break;

        default:
            printf("\nCodigo de menu informado invalido!\n\n");
            break;
        }
    }
}

int main()
{

    printf("Bem vindo ao sistema de gerenciamento de hoteis\n ");

    int codigoMenu = 0;

    while (codigoMenu != 7)
    {

        printf("---MENU---\n 1- Cadastrar e gerir dados armazenados.\n 2- Gerenciar reservas de quartos.\n 3- Gerir dados adimistrativos.\n 4- Relatorios de sistema.\n 5- Importar/Exportar dados.\n 6- Alterar configuracao de armazanamento.\n 7- Encerrar programa.\n\n Digite um codigo referente a operacao que voce deseja fazer: ");
        scanf("%d%*c", &codigoMenu);

        switch (codigoMenu)
        {
        case 1:
            menuCadastro();
            // gerirCadastros();
            break;

            // case 2:
            // gerirReservas();
            // break;

            // case 3:
            // gerirCaixa();
            // break;

            // case 4:
            // gerarRelatorios();
            // break;

            // case 5:
            // gerirDados();
            // break;

        case 6:
            printf("\nEscolha o tipo de armazenamento (txt ou binário):\n");
            printf("1- Texto (txt)\n");
            printf("2- Binário (bin)\n");

            int escolhaArmazenamento;
            scanf("%d", &escolhaArmazenamento);

            if (escolhaArmazenamento == 1)
            {
                // Seleciona o tipo de armazenamento para texto (txt)
                printf("\nArmazenamento configurado para texto (txt).\n");
            }
            else if (escolhaArmazenamento == 2)
            {
                // Seleciona o tipo de armazenamento para binário (bin)
                printf("\nArmazenamento configurado para binário (bin).\n");
            }
            else
            {
                printf("\nOpção inválida.\n");
            }
            break;

        case 7:
            printf("\nEncerrando programa...");
            break;

        default:
            printf("\nCodigo de menu informado invalido!\n\n");
            break;
        }
    }

    return 0;
}

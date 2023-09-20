#include <stdio.h>
#include <string.h>
#include "modulos/gestaoDados.h"

void menuCadastro(char tipoArquivo)
{
    int codigoMenu;

    while (codigoMenu != 8)
    {
        printf("--- MENU ---\n 1 - Informações do hotel.\n 2 - Informações dos hóspedes.\n 3 - Lista de categorias das acomodações.\n 4 - Informações das acomodações.\n 5 - Tabela de consumíveis.\n 6 - Lista de fornecedores.\n 7 - Lista de operadores do sistema.\n 8 - Voltar à tela principal.\n\nDigite um código referente ao item que você deseja gerenciar: ");
        scanf("%d%*c", &codigoMenu);

        switch (codigoMenu)
        {
        case 1:
            gerenciarHotel(tipoArquivo);
            break;

        case 2:
            gerenciarHospede(tipoArquivo);
            break;

        case 3:
            gerenciarCategoria(tipoArquivo);
            break;

        case 4:
            gerenciarAcomodacao(tipoArquivo);
            break;

        case 5:
            gerenciarConsumivel(tipoArquivo);
            break;

        case 6:
            gerenciarFornecedor(tipoArquivo);
            break;

        case 7:
            gerenciarOperador(tipoArquivo);
            break;

        case 8:
            printf("Voltando para a tela principal.\n\n");
            break;

        default:
            printf("\nCódigo de menu informado é inválido!\n\n");
            break;
        }
    }
}

int main()
{
    printf("Bem-vindo ao sistema de gerenciamento de hotéis.\n");

    int codigoMenu = 0;
    char tipoArquivo[3] = "txt";

    while (codigoMenu != 7)
    {
        printf("--- MENU ---\n 1 - Cadastrar e gerir dados armazenados.\n 2 - Gerenciar reservas de quartos.\n 3 - Gerir dados administrativos.\n 4 - Relatórios do sistema.\n 5 - Importar/Exportar dados.\n 6 - Alterar configuração de armazenamento.\n 7 - Encerrar o programa.\n\nDigite um código referente à operação que você deseja fazer: ");
        scanf(" %d%*c", &codigoMenu);

        switch (codigoMenu)
        {
        case 1:
            menuCadastro(tipoArquivo);
            break;

        case 6:
            printf("\nEscolha o tipo de armazenamento (txt ou binário):\n");
            printf("1 - Texto (txt)\n");
            printf("2 - Binário (bin)\n");

            int escolhaArmazenamento;
            scanf("%d", &escolhaArmazenamento);

            if (escolhaArmazenamento == 1)
            { // Seleciona o tipo de armazenamento para texto (txt)
                strcpy(tipoArquivo, "txt");
                printf("\nArmazenamento configurado para texto (txt).\n");
            }
            else if (escolhaArmazenamento == 2)
            {
                // Seleciona o tipo de armazenamento para binário (bin)
                strcpy(tipoArquivo, "bin");
                printf("\nArmazenamento configurado para binário (bin).\n");
            }
            else
            {
                printf("\nOpção inválida.\n");
            }
            break;

        case 7:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\nCódigo de menu informado é inválido!\n\n");
            break;
        }
    }

    return 0;
}

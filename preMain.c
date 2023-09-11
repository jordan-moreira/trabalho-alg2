#include <stdio.h>
#include "modulos/gestaoDados.h"

int main()
{
    int codigoMenu = 0;

    printf("Bem vindo ao sistema de gerenciamento de hoteis\n ");

    while (codigoMenu != 6)
    {

        printf("---MENU---\n 1- Cadastrar e gerir dados armazenados.\n 2- Gerenciar reservas de quartos.\n 3- Gerir dados adimistrativos.\n 4- Relatorios de sistema.\n 5- Importar/Exportar dados.\n 6- Alterar configuracao de armazanamento.\n 7- Encerrar programa.\n\n Digite um codigo referente a operacao que voce deseja fazer: ");
        scanf("%d%*c", &codigoMenu);

        switch (codigoMenu)
        {
        case 1:
            //gerirCadastros();
            //break;

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

            // case 6:
            // alterarArquivo();
            // break;

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

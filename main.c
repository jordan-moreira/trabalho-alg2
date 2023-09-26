#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulos/gestaoDados.h"

// Define códigos de escape ANSI para cores de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"

struct LoginSenha
{
    char login[50];
    char senha[50];
};

int fazerLogin(struct LoginSenha *operador, char *codigoPermissao)
{
    FILE *arquivo = fopen("arquivos/operador.txt", "r");
    Operador ptrOperador;
    while (1)
    {
        if (fscanf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%c ;}", &ptrOperador.codigo, &ptrOperador.nome, &ptrOperador.usuario, &ptrOperador.senha, &ptrOperador.permissao) == 5)
        {
            if (strcmp(ptrOperador.usuario, operador->login) == 0 && strcmp(ptrOperador.senha, operador->senha) == 0)
            {

                *codigoPermissao = ptrOperador.permissao;
                return 1;
            }
        }
        else if (feof(arquivo))
        {
            return 0;
        }
    }
}

void menuCadastro(char tipoArquivo, char codigoPermissao)
{
    int codigoMenu;

    printf(ANSI_BOLD ANSI_GREEN "Menu de Cadastro Selecionado (Tipo de Arquivo: %c)\n" ANSI_RESET, tipoArquivo);
    if (codigoPermissao == 'e') {
        printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
    } 
    else
    {
        while (codigoMenu != 4)
        {
            printf("--- MENU ---\n");
            printf(" 1 - " ANSI_BOLD "Informações dos hóspedes.\n" ANSI_RESET);
            printf(" 2 - " ANSI_BOLD "Lista de categorias das acomodações.\n" ANSI_RESET);
            printf(" 3 - " ANSI_BOLD "Informações das acomodações.\n" ANSI_RESET);
            printf(" 4 - " ANSI_BOLD "Voltar à tela principal.\n" ANSI_RESET);

            printf("\nDigite um código referente ao item que você deseja gerenciar: ");
            scanf("%d%*c", &codigoMenu);

            switch (codigoMenu)
            {

                case 1:
                gerenciarHospede(tipoArquivo);
                break;

                case 2:
                gerenciarCategoria(tipoArquivo, codigoPermissao);
                break;

                case 3:
                gerenciarAcomodacao(tipoArquivo, codigoPermissao);
                break;

                case 4:
                printf("Voltando para a tela principal.\n\n");
                break;

                default:
                printf("\nCódigo de menu informado é inválido!\n\n");
                break;
        }
    }
    } 
}


void menuAdm(char tipoArquivo, char codigoPermissao)
{
    printf(ANSI_BOLD ANSI_GREEN "Menu Administrativo Selecionado (Tipo de Arquivo: %c)\n" ANSI_RESET, tipoArquivo);
    if (codigoPermissao == 'e') {
        printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
    }
    else
    {
        int codigoMenu;
        printf("--- MENU ---\n");
        printf(" 1 - " ANSI_BOLD "Tabela de consumíveis.\n" ANSI_RESET);
        printf(" 2 - " ANSI_BOLD "Lista de fornecedores.\n" ANSI_RESET);
        printf(" 3 - " ANSI_BOLD "Lista de operadores do sistema.\n" ANSI_RESET);
        printf(" 4 - " ANSI_BOLD "Voltar à tela principal.\n" ANSI_RESET);
        printf(" 5 - " ANSI_BOLD "Informações sobre o Hotel.\n" ANSI_RESET);

        printf("\nDigite um código referente ao item que você deseja gerenciar: ");
        scanf("%d", &codigoMenu);

        if (codigoPermissao == 'e')
        {
            if (codigoMenu == 3)
            {
                printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
                return;
            }
        }
        else if (codigoPermissao == 'r')
        {

            if (codigoMenu != 4 && codigoMenu != 5)
            {
                printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
                return;
            }
        }
        while (codigoMenu != 4)
        {

            switch (codigoMenu)
            {
            case 1:
                gerenciarConsumivel(tipoArquivo);
                break;

            case 2:
                gerenciarFornecedor(tipoArquivo);
                break;

            case 3:
                gerenciarOperador(tipoArquivo);
                break;

            case 4:
                printf("Voltando à tela inicial\n\n");
                break;

            case 5:
                gerenciarHotel(tipoArquivo, codigoPermissao);
                break;

            default:
                printf("Código de menu informado inválido!!\n\n");
                break;
            }
        }
    }
}

int main()
{
    printf("|||||BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE HÓTEIS|||||\n");

    int codigoMenu = 0;
    char tipoArquivo = 'T',
         codigoPermissao = 'g';

    while (codigoMenu != 7)
    {
        printf("--- MENU ---\n");
        printf(" 1 - " ANSI_BOLD "Cadastrar e gerir dados armazenados.\n" ANSI_RESET);
        printf(" 2 - " ANSI_BOLD "Gerenciar reservas de quartos.\n" ANSI_RESET);
        printf(" 3 - " ANSI_BOLD "Gerir dados administrativos.\n" ANSI_RESET);
        printf(" 4 - " ANSI_BOLD "Relatórios do sistema.\n" ANSI_RESET);
        printf(" 5 - " ANSI_BOLD "Importar/Exportar dados.\n" ANSI_RESET);
        printf(" 6 - " ANSI_BOLD "Alterar configuração de armazenamento.\n" ANSI_RESET);
        printf(" 7 - " ANSI_BOLD "Encerrar o programa.\n" ANSI_RESET);
        printf(" 8 - " ANSI_BOLD "Fazer login.\n" ANSI_RESET);
        printf("\nDigite um código referente à operação que você deseja fazer: ");
        scanf(" %d%*c", &codigoMenu);

        if (codigoPermissao == 'e') {
            if (codigoMenu != 3 && codigoMenu != 7) {
                printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
                continue;
            }
        }

        switch (codigoMenu) {
            case 1:
                menuCadastro(tipoArquivo, codigoPermissao);
                break;

            case 3:
                menuAdm(tipoArquivo, codigoPermissao);
                break;

            case 6:
                printf("\nEscolha o tipo de armazenamento (txt ou binário):\n");
                printf("1 - Texto (txt)\n");
                printf("2 - Binário (bin)\n");

                int escolhaArmazenamento;
                scanf("%d", &escolhaArmazenamento);

                if (escolhaArmazenamento == 1) {
                    tipoArquivo = 'T';
                    printf("\nArmazenamento configurado para texto (txt).\n");
                } else if (escolhaArmazenamento == 2) {
                    tipoArquivo = 'B';
                    printf("\nArmazenamento configurado para binário (bin).\n");
                } else {
                    printf(ANSI_RED "\nOpção inválida.\n" ANSI_RESET);
                }
                break;

            case 7:
                printf("\nEncerrando o programa...\n");
                break;

            case 8:
                struct LoginSenha operador;

                printf("Digite o login: ");
                scanf("%s", operador.login);

                printf("Digite a senha: ");
                scanf("%s", operador.senha);

                int status = fazerLogin(&operador, &codigoPermissao);

                if (status == 1) {
                    printf(ANSI_GREEN "Logado com sucesso!\n" ANSI_RESET);
                } else {
                    printf(ANSI_RED "Erro de login!\n" ANSI_RESET);
                }
                printf("Código de permissão: %c\n", codigoPermissao);
                break;

            default:
                printf(ANSI_RED "\nCódigo de menu informado é inválido!\n\n" ANSI_RESET);
                break;
        }
    }

    return 0;
}

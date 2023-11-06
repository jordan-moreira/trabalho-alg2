#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulos/gestaoDados.h"
#include "modulos/reservas.h"

// Define códigos de escape ANSI para cores de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"
// Define struct de usuario e senha
struct LoginSenha
{
    char usuario[50];
    char senha[50];
};

int fazerLogin(struct LoginSenha *operador, char *codigoPermissao) // Logica criada para login de usuario.Usado while usado para looping no arquivo e ler por inteiro e
{
    FILE *arquivo = fopen("arquivos/operador.txt", "r");
    Operador ptrOperador;
    while (1)
    {
        if (fscanf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%c ;}", &ptrOperador.codigo, &ptrOperador.nome, &ptrOperador.usuario, &ptrOperador.senha, &ptrOperador.permissao) == 5)
        { // ifelse para checagem se usuario e senha estao cadastrados.
            if (strcmp(ptrOperador.usuario, operador->usuario) == 0 && strcmp(ptrOperador.senha, operador->senha) == 0)
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

void menuCadastro(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria)
{
    int codigoMenu;

    printf(ANSI_BOLD ANSI_GREEN "Menu de Cadastro Selecionado (Tipo de Arquivo: %c)\n" ANSI_RESET, tipoArquivo);
    if (codigoPermissao == 'e')
    {
        printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
    }
    else
    {
        while (codigoMenu != 4)
        {
            printf("--- MENU ---\n"); // Menu para lista e informacoes das acomodacoes.
            printf(" 1 - " ANSI_BOLD "Informações dos hóspedes.\n" ANSI_RESET);
            printf(" 2 - " ANSI_BOLD "Lista de categorias das acomodações.\n" ANSI_RESET);
            printf(" 3 - " ANSI_BOLD "Informações das acomodações.\n" ANSI_RESET);
            printf(" 4 - " ANSI_BOLD "Voltar à tela principal.\n" ANSI_RESET);

            printf("\nDigite um código referente ao item que você deseja gerenciar: ");
            scanf("%d%*c", &codigoMenu);

            switch (codigoMenu)
            {

            case 1:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->hospede == 0)
                    {
                        ptrMemoria->tamHospede = 0;
                        ptrMemoria->hospede = malloc(ptrMemoria->tamHospede * sizeof(Hospede *));
                    }
                    gerenciarHospede(tipoArquivo, ptrMemoria);
                }
                gerenciarHospede(tipoArquivo, 0); // Para receber informaçes de hospedes.
                break;

            case 2:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->categoria == 0)
                    {
                        ptrMemoria->tamCategoria = 0;
                        ptrMemoria->categoria = malloc(ptrMemoria->tamCategoria * sizeof(Categoria *));
                    }
                    gerenciarCategoria(tipoArquivo, codigoPermissao, ptrMemoria);
                }
                gerenciarCategoria(tipoArquivo, codigoPermissao, 0); // Lista das acomodacoes.
                break;

            case 3:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->acomodacao == 0)
                    {
                        ptrMemoria->tamAcomodacao = 0;
                        ptrMemoria->acomodacao = malloc(ptrMemoria->tamAcomodacao * sizeof(Acomodacao *));
                    }
                    gerenciarAcomodacao(tipoArquivo, codigoPermissao, ptrMemoria);
                }
                gerenciarAcomodacao(tipoArquivo, codigoPermissao, 0); // Informacoes sobre acomodacoes
                break;

            case 4:
                printf("Voltando para a tela principal.\n\n"); // Caso usuario deseje voltar ao menu de escolha.
                break;

            default:
                printf(ANSI_RED "\nCódigo de menu informado é inválido!\n\n" ANSI_RESET);
                break;
            }
        }
    }
}

void menuAdm(char tipoArquivo, char codigoPermissao, PtrMemoria *ptrMemoria)
{
    int codigoMenu;

    printf(ANSI_BOLD ANSI_GREEN "Menu Administrativo Selecionado (Tipo de Arquivo: %c)\n" ANSI_RESET, tipoArquivo);
    if (codigoPermissao == 'e')
    {
        printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
    }
    else
    {
        while (codigoMenu != 4)
        {
            // Menu para consumiveis,fornecedores, operadore e informações sobre o hotel.Usado ifelse para checar se usuario tem permissão e switch para a escolha das opções.
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

            switch (codigoMenu)
            {
            case 1:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->consumivel == 0)
                    {
                        ptrMemoria->tamConsumivel = 0;
                        ptrMemoria->consumivel = malloc(ptrMemoria->tamConsumivel * sizeof(Consumivel *));
                    }
                    gerenciarConsumivel(tipoArquivo, ptrMemoria);
                }
                gerenciarConsumivel(tipoArquivo, 0);
                break;

            case 2:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->fornecedor == 0)
                    {
                        ptrMemoria->tamFornecedor = 0;
                        ptrMemoria->fornecedor = malloc(ptrMemoria->tamFornecedor * sizeof(Fornecedor *));
                    }
                    gerenciarFornecedor(tipoArquivo, ptrMemoria);
                }
                gerenciarFornecedor(tipoArquivo, 0);
                break;

            case 3:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->operador == 0)
                    {
                        ptrMemoria->tamOperador = 0;
                        ptrMemoria->operador = malloc(ptrMemoria->tamOperador * sizeof(Operador *));
                    }
                    gerenciarOperador(tipoArquivo, ptrMemoria);
                }
                gerenciarOperador(tipoArquivo, 0);
                break;

            case 4:
                printf("Voltando à tela inicial\n\n");
                break;

            case 5:
                if (tipoArquivo == 'M')
                {
                    if (ptrMemoria->hotel == 0)
                    {
                        ptrMemoria->hotel = malloc(sizeof(Hotel));
                    }
                    gerenciarOperador(tipoArquivo, ptrMemoria);
                }
                gerenciarHotel(tipoArquivo, codigoPermissao, 0);
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
    // Criado menu para o ferenciamento do hotel usando while para percorrer as opçoes do usauario e casa o proprio nao tiver permissao para acessar
    //  alguma opção, printf com Acesso boqueado.
    printf("|||||BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE HÓTEIS|||||\n");

    int codigoMenu = 0,
        configSetada = 0;
    FILE *arquivo;
    PtrMemoria *ptrMemoria;
    char tipoArquivo,
        codigoPermissao;
    arquivo = fopen("arquivos/operador.txt", "r");
    if (arquivo != NULL)
    {
        tipoArquivo = 'T';
        codigoPermissao = 'n';
        configSetada = 1;
        fclose(arquivo);
    }
    arquivo = fopen("arquivos/operador.bin", "rb");
    if (arquivo != NULL && configSetada == 0)
    {
        tipoArquivo = 'B';
        codigoPermissao = 'n';
        configSetada = 1;
        fclose(arquivo);
    }
    else if (configSetada == 0)
    {
        tipoArquivo = 'T';
        codigoPermissao = 'g';
        configSetada = 1;
    }

    printf("%c", codigoPermissao);
    while (codigoMenu != 7)
    {
        printf("--- MENU ---\n");
        printf(" 1 - " ANSI_BOLD "Cadastrar e gerir dados armazenados.\n" ANSI_RESET);
        printf(" 2 - " ANSI_BOLD "Gerenciar reservas de quartos.\n" ANSI_RESET); // Ainda nao implementado no switch.
        printf(" 3 - " ANSI_BOLD "Gerir dados administrativos.\n" ANSI_RESET);
        printf(" 4 - " ANSI_BOLD "Relatórios do sistema.\n" ANSI_RESET);   // Ainda nao implementado no switch.
        printf(" 5 - " ANSI_BOLD "Importar/Exportar dados.\n" ANSI_RESET); // Ainda nao implementado no switch.
        printf(" 6 - " ANSI_BOLD "Alterar configuração de armazenamento.\n" ANSI_RESET);
        printf(" 7 - " ANSI_BOLD "Encerrar o programa.\n" ANSI_RESET);
        printf(" 8 - " ANSI_BOLD "Fazer login.\n" ANSI_RESET);
        printf("\nDigite um código referente à operação que você deseja fazer: ");
        scanf(" %d%*c", &codigoMenu);

        if (codigoPermissao == 'e')
        {
            if (codigoMenu != 3 && codigoMenu != 7)
            {
                printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
                continue;
            }
        }

        switch (codigoMenu)
        {
        case 1:
            menuCadastro(tipoArquivo, codigoPermissao, tipoArquivo == 'M' ? ptrMemoria : 0);
            break;

        case 2:
            if (codigoPermissao == 'e')
            {
                printf(ANSI_RED "Acesso negado !!!" ANSI_RESET);
                break;
            }
            else
            {
                gerenciarReserva(tipoArquivo, codigoPermissao, tipoArquivo == 'M' ? ptrMemoria : 0);
                break;
            }

        case 3:
            menuAdm(tipoArquivo, codigoPermissao, tipoArquivo == 'M' ? ptrMemoria : 0);
            break;

        case 6:
            // Logica para escolher o tipo de armazenamento do codigo em txt ou binario.
            printf("\nEscolha o tipo de armazenamento (txt ou binário):\n");
            printf("1 - Texto (txt)\n");
            printf("2 - Binário (bin)\n");
            printf("3 - Memoria (mem)\n");

            int escolhaArmazenamento;
            scanf("%d", &escolhaArmazenamento);

            if (escolhaArmazenamento == 1)
            {
                tipoArquivo = 'T';

                converterArquivos(tipoArquivo);
                printf("\nArmazenamento configurado para texto (txt).\n");
            }
            else if (escolhaArmazenamento == 2)
            {
                tipoArquivo = 'B';

                converterArquivos(tipoArquivo);
                printf("\nArmazenamento configurado para binário (bin).\n");
            }
            else if (escolhaArmazenamento == 3)
            {
                if (tipoArquivo != 'M')
                {
                    tipoArquivo = 'M';
                    ptrMemoria = malloc(sizeof(PtrMemoria));
                    memset(&ptrMemoria, 0, sizeof(PtrMemoria));
                }
            }
            else
            {
                printf(ANSI_RED "\nOpção inválida.\n" ANSI_RESET);
            }
            break;

        case 7:
            printf("\nEncerrando o programa...\n");
            break;

        case 8:
            // Criado logica para fazer login de usuarios cadastrados.
            struct LoginSenha operador;

            printf("Digite o usuario: ");
            scanf("%s", operador.usuario);

            printf("Digite a senha: ");
            scanf("%s", operador.senha);

            int status = fazerLogin(&operador, &codigoPermissao);

            if (status == 1)
            {
                printf(ANSI_GREEN "Logado com sucesso!\n" ANSI_RESET);
            }
            else
            {
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "crudTxt.h"
#include "crudBin.h"
// Funcoes criadas para serem implementadas no codigo.

// Define códigos de escape ANSI para cores de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"

int selecionarOperacao(char *tipoDoDado)
{
    int codigoMenu = 0;
    printf("Digite o código referente à operação a ser realizada:\n"); // codMenu para administrar operações do hotel.

    while (codigoMenu < 1 || codigoMenu > 4)
    {
        printf("1 -" ANSI_BOLD "Adicionar %s.\n" ANSI_RESET, tipoDoDado);
        printf("2 -" ANSI_BOLD "Atualizar informações de %s.\n" ANSI_RESET, tipoDoDado);
        printf("3 -" ANSI_BOLD "Ler informações de %s.\n" ANSI_RESET, tipoDoDado);
        printf("4 -" ANSI_BOLD "Deletar %s.\n" ANSI_RESET, tipoDoDado);
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu >= 1 && codigoMenu <= 4)
        {
            return codigoMenu;
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }
    }
}

Hotel *coletarDadosHotel() // Funcao para retornar um ponteiro de memoria onde estao os dados.
{
    Hotel *ptrHotel = malloc(sizeof(Hotel)); // Memoria alocada para salvar dados coletados.

    if (ptrHotel == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    //  printf e scanf para adicionar e salvar e coletar dados do hotem em memoria.
    printf("Digite o nome do hotel: ");
    scanf("%99[^\n]%*c", ptrHotel->nome);

    printf("\nDigite a razão social do hotel: ");
    scanf("%99[^\n]%*c", ptrHotel->razaoSocial);

    printf("\nDigite a inscrição estadual do hotel: ");
    scanf("%14[^\n]%*c", ptrHotel->inscricaoEstadual);

    printf("\nDigite o CNPJ do hotel: ");
    scanf("%s%*c", ptrHotel->cnpj);

    printf("\nDigite o endereço do hotel: ");
    scanf("%99[^\n]%*c", ptrHotel->endereco);

    printf("\nDigite o número de celular do hotel: ");
    scanf("%s%*c", ptrHotel->celular);

    printf("\nDigite o e-mail do hotel: ");
    scanf("%s%*c", ptrHotel->eMail);

    printf("\nDigite o nome do responsável (ou gerente) pelo hotel: ");
    scanf("%99[^\n]%*c", ptrHotel->responsavel);

    printf("\nDigite o número de celular do responsável (ou gerente) pelo hotel: ");
    scanf("%s%*c", ptrHotel->celularResponsavel);

    printf("\nDigite o horário de Check-in do hotel: ");
    scanf("%s%*c", ptrHotel->horarioCheckIn);

    printf("\nDigite o horário de Check-out do hotel: ");
    scanf("%s%*c", ptrHotel->horarioCheckOut);

    return ptrHotel;
}

Hospede *coletarDadosHospede() // Funcao para retornar um ponteiro de memoria onde estao os dados.
{
    Hospede *ptrHospede = malloc(sizeof(Hospede)); // Memoria criada para salvar dados coletados.

    if (ptrHospede == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    // Criado printf e scanf para coletar e armazenar dados de hospedes.
    printf("Digite o código do hóspede: ");
    scanf("%d%*c", &ptrHospede->codigo);

    printf("Digite o nome do hóspede: ");
    scanf("%99[^\n]%*c", ptrHospede->nome);

    printf("Digite o endereço do hóspede: ");
    scanf("%99[^\n]%*c", ptrHospede->endereco);

    printf("Digite o CPF do hóspede: ");
    scanf("%s%*c", ptrHospede->cpf);

    printf("Digite o número de celular do hóspede: ");
    scanf("%s%*c", ptrHospede->celular);

    printf("Digite o e-mail do hóspede: ");
    scanf("%s%*c", ptrHospede->eMail);

    printf("Digite o sexo do hóspede (M ou F): ");
    scanf("%s%*c", ptrHospede->sexo);

    printf("Digite o estado civil do hóspede: ");
    scanf("%s%*c", ptrHospede->estadoCivil);

    printf("Digite a data de nascimento do hóspede (formato dd/mm/aaaa): ");
    scanf("%s%*c", ptrHospede->dataNasc);

    return ptrHospede;
}

Categoria *coletarDadosCategoria() // Funcao para retornar um ponteiro de memoria onde estao os dados.

{
    Categoria *ptrCategoria = malloc(sizeof(Categoria)); // Memoria criada para salvar dados coletados.

    if (ptrCategoria == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    //  Logica criada para hospede decidir qual categoria lhe-convem.
    printf("Digite o código da categoria(luxo,dormitório,...): ");
    scanf("%s%*c", ptrCategoria->codigo);

    printf("Digite a quantidade de pessoas da categoria: ");
    scanf("%d%*c", &ptrCategoria->quantPessoas);

    printf("Digite a descrição da categoria: ");
    scanf("%[^\n]%*c", ptrCategoria->descricao);

    printf("Digite o valor da categoria: ");
    scanf("%f%*c", &ptrCategoria->valor);

    return ptrCategoria;
}

Acomodacao *coletarDadosAcomodacao(char tipoArquivo) // Funcao para retornar um ponteiro de memoria onde estao os dados.

{
    Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao)); // Memoria criada para salvar dados coletados.

    if (ptrAcomodacao == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    // Criado logica para informar acmodacoes fornecidas pelo hotel e com  facilidades. Tambem a possivel data de entrada do hospede e saida(dataInicial e dataFinal).

    printf("Digite o código da acomodação: ");
    scanf("%d%*c", &ptrAcomodacao->codigo);

    printf("informe a descrição da acomodação: ");
    scanf("%99[^\n]%*c", &ptrAcomodacao->descricao);

    printf("informe a categoria da acomodação: ");
    scanf("%49[^\n]%*c", ptrAcomodacao->categoria);

    printf("Digite as facilidades da acomodação: ");
    scanf("%99[^\n]%*c", ptrAcomodacao->facilidades);

    return ptrAcomodacao;
}

Consumivel *coletarDadosConsumivel() // Funcao para retornar um ponteiro de memoria onde estao os dados.
{
    Consumivel *ptrConsumivel = malloc(sizeof(Consumivel)); // Memoria criada para salvar dados coletados.

    if (ptrConsumivel == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    // Logica para coleta de dados de consumiveis e informar preço e tamanho do estoque de tal produto.
    printf("Digite o código do consumível: ");
    scanf("%d%*c", &ptrConsumivel->codigo);

    printf("Digite a descrição do consumível: ");
    scanf("%99[^\n]%*c", ptrConsumivel->descricao);

    printf("Digite a quantidade de unidades em estoque: ");
    scanf("%d%*c", &ptrConsumivel->estoque);

    printf("Digite o estoque mínimo do consumível: ");
    scanf("%d%*c", &ptrConsumivel->estoqueMin);

    printf("Digite o preço de custo do consumível: ");
    scanf("%f%*c", &ptrConsumivel->precoCusto);

    printf("Digite o preço de venda do consumível: ");
    scanf("%f%*c", &ptrConsumivel->precoVenda);

    return ptrConsumivel;
}

Fornecedor *coletarDadosFornecedor() // Funcao para retornar um ponteiro de memoria onde estao os dados.
{
    Fornecedor *ptrFornecedor = malloc(sizeof(Fornecedor)); // Memoria criada para salvar dados coletados.

    if (ptrFornecedor == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    // Logica para coleta de dados de fornecedores.
    printf("Digite o código do fornecedor: ");
    scanf("%d%*c", &ptrFornecedor->codigo);

    printf("Digite o nome do fornecedor: ");
    scanf("%99[^\n]%*c", ptrFornecedor->nome);

    printf("Digite a razão social do fornecedor: ");
    scanf("%99[^\n]%*c", ptrFornecedor->razaoSocial);

    printf("Digite a inscrição social do fornecedor: ");
    scanf("%19[^\n]%*c", ptrFornecedor->inscricaoSocial);

    printf("Digite o CNPJ do fornecedor: ");
    scanf("%s%*c", ptrFornecedor->cnpj);

    printf("Digite o endereço do fornecedor: ");
    scanf("%99[^\n]%*c", ptrFornecedor->endereco);

    printf("Digite o número de celular do fornecedor: ");
    scanf("%s%*c", ptrFornecedor->celular);

    printf("Digite o e-mail do fornecedor: ");
    scanf("%s%*c", ptrFornecedor->eMail);

    return ptrFornecedor;
}

Operador *coletarDadosOperador() // Funcao para retornar um ponteiro de memoria onde estao os dados.
{
    Operador *ptrOperador = malloc(sizeof(Operador)); // Memoria criada para salvar dados coletados.

    if (ptrOperador == NULL)
    {
        printf(ANSI_RED "Erro na alocação de memória.\n" ANSI_RESET);
        return NULL;
    }
    // Logica criada para adicionar operadores ao sistema.
    printf("Digite o código do operador: ");
    scanf("%d%*c", &ptrOperador->codigo);

    printf("Digite o nome do operador: ");
    scanf("%99[^\n]%*c", ptrOperador->nome);

    printf("Digite o nome de usuário do operador: ");
    scanf("%s%*c", ptrOperador->usuario);

    printf("Digite a senha do operador: ");
    scanf("%s%*c", ptrOperador->senha);

    while (ptrOperador->permissao != 'g' && ptrOperador->permissao != 'r' && ptrOperador->permissao != 'e') // Logica para coletar o cargo do operador de sistema.
    {
        printf("||||| Menu de Cargos |||||\ng-Gernte geral.\nr-Recepcionista.\ne-Gerente de estoque\n");

        printf("Digite a permissão do operador: ");
        scanf(" %c%*c", &ptrOperador->permissao);
    }
    return ptrOperador;
}

void gerenciarHotel(char tipoArquivo, char codigoPermissao) // Logica criada para que se usuario não tiver acesso, seja barrado.
{
    char item[] = "hotel";
    int operacao = selecionarOperacao(item);
    int status;
    FILE *arquivo;
    Hotel *ptrHotel;

    if (codigoPermissao == 'r' || codigoPermissao == 'e')
    {
        if (operacao != 3)
        {
            printf(ANSI_RED "Acesso bloqueado!!!\n" ANSI_RESET);
            return;
        }
    }
    switch (operacao)
    {
    case 1:
        ptrHotel = coletarDadosHotel();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hotel.txt", "a") : fopen("arquivos/hotel.bin", "ab");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }
        (tipoArquivo == 'T') ? criarHotelTxt(ptrHotel, arquivo) : criarHotelBin(ptrHotel, arquivo);

        free(ptrHotel);
        fclose(arquivo);
        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        ptrHotel = coletarDadosHotel();
        status = (tipoArquivo == 'T') ? atualizarHotelTxt(ptrHotel) : atualizarHotelBin(ptrHotel);
        status == 1 ? printf(ANSI_GREEN "Registros de hotel atualizados com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registros de hotel" ANSI_RESET);
        free(ptrHotel);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hotel.txt", "r") : fopen("arquivos/hotel.bin", "rb");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }

        ptrHotel = malloc(sizeof(Hotel));
        status = (tipoArquivo == 'T') ? lerHotelTxt(arquivo, ptrHotel) : lerHotelBin(arquivo, ptrHotel);

        if (status == 1)
        {
            printf("\n Nome do Hotel: %s,\n Razão Social: %s,\n Inscrição Estadual: %s,\n CNPJ: %s,\n Endereço: %s,\n Número de Celular: %s,\n E-mail: %s,\n Nome do Responsável: %s,\n Número de Celular do Responsável: %s,\n Horário de Check-in: %s,\n Horário de Check-out: %s;\n}\n",
                   ptrHotel->nome, ptrHotel->razaoSocial, ptrHotel->inscricaoEstadual, ptrHotel->cnpj, ptrHotel->endereco, ptrHotel->celular, ptrHotel->eMail, ptrHotel->responsavel, ptrHotel->celularResponsavel, ptrHotel->horarioCheckIn, ptrHotel->horarioCheckOut);
        }
        else if (status == 0)
        {
            printf(ANSI_RED "Hotel não encontrado ou erro de leitura.\n" ANSI_RESET);
        }

        free(ptrHotel);
        fclose(arquivo);

        break;

    case 4:
        status = (tipoArquivo == 'T') ? deletarHotelTxt() : deletarHotelBin();
        status == 1 ? printf("registros de hotel deletados com sucesso") : printf("erro ao deletar registros de hotel");
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarHospede(char tipoArquivo)
{
    char item[] = "hospede";
    int operacao = selecionarOperacao(item);
    int status;
    int codigoHospede;
    FILE *arquivo;
    Hospede *ptrHospede;

    switch (operacao)
    {
    case 1:
        ptrHospede = coletarDadosHospede();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hospede.txt", "a") : fopen("arquivos/hospede.bin", "ab");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }

        (tipoArquivo == 'T') ? adicionarHospedeTxt(ptrHospede, arquivo) : adicionarHospedeBin(ptrHospede, arquivo);
        free(ptrHospede);
        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        codigoHospede = 0;
        ptrHospede = coletarDadosHospede();
        printf("Digite o código único do hospede que você deseja atualizar: ");
        scanf("%d%*c", &codigoHospede);
        status = (tipoArquivo == 'T') ? atualizarHospedeTxt(codigoHospede, ptrHospede) : atualizarHospedeBin(codigoHospede, ptrHospede);

        status == 1 ? printf(ANSI_GREEN "Registro de hospede atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de hospede" ANSI_RESET);
        free(ptrHospede);
        break;

    case 3:

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hospede.txt", "r") : fopen("arquivos/hospede.bin", "rb");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrHospede = malloc(sizeof(Hospede));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os hóspedes, digite 1. Se você deseja fazer uma leitura de um hóspede específico, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                status = (tipoArquivo == 'T') ? lerHospedeTxt(0, arquivo, ptrHospede) : lerHospedeBin(0, arquivo, ptrHospede);

                if (status == 1)
                {
                    printf("%d {\n Nome: %s,\n Endereço: %s,\n CPF: %s,\n Celular: %s,\n E-mail: %s,\n Sexo: %s,\n Estado Civil: %s,\n Data de Nascimento: %s;\n}\n",
                           ptrHospede->codigo, ptrHospede->nome, ptrHospede->endereco, ptrHospede->cpf, ptrHospede->celular, ptrHospede->eMail, ptrHospede->sexo, ptrHospede->estadoCivil, ptrHospede->dataNasc);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {
                    printf("a");

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoHospede = 0;
            printf("Digite o código único do hóspede que você deseja ler: ");
            scanf("%d%*c", &codigoHospede);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerHospedeTxt(codigoHospede, arquivo, ptrHospede) : lerHospedeBin(codigoHospede, arquivo, ptrHospede);

                if (status == 1)
                {
                    printf("%d {\n Nome: %s,\n Endereço: %s,\n CPF: %s,\n Celular: %s,\n E-mail: %s,\n Sexo: %s,\n Estado Civil: %s,\n Data de Nascimento: %s;\n}\n",
                           ptrHospede->codigo, ptrHospede->nome, ptrHospede->endereco, ptrHospede->cpf, ptrHospede->celular, ptrHospede->eMail, ptrHospede->sexo, ptrHospede->estadoCivil, ptrHospede->dataNasc);
                    break;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Hospede não encontrado ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }

        free(ptrHospede); // Libere a memória alocada para ptrHospede
        fclose(arquivo);
        break;

    case 4:
        codigoHospede = 0;
        printf("Digite o código único do hospede que você deseja deletar: ");
        scanf("%d%*c", &codigoHospede);
        status = (tipoArquivo == 'T') ? deletarHospedeTxt(codigoHospede) : deletarHospedeBin(codigoHospede);

        status == 1 ? printf(ANSI_GREEN "Registro de hospede deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de hóspede" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void gerenciarCategoria(char tipoArquivo, char codigoPermissao)
{
    char item[] = "categoria";
    int operacao = selecionarOperacao(item);
    int status;
    char codigoCategoria[50];
    FILE *arquivo;
    Categoria *ptrCategoria;
    if (codigoPermissao == 'r')
    {
        if (operacao != 3)
        {
            printf(ANSI_RED "Acesso negado !!!" ANSI_RESET);
            return;
        }
    }
    switch (operacao)
    {
    case 1:
        ptrCategoria = coletarDadosCategoria();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categoria.txt", "a") : fopen("arquivos/categoria.bin", "ab");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }

        (tipoArquivo == 'T') ? adicionarCategoriaTxt(ptrCategoria, arquivo) : adicionarCategoriaBin(ptrCategoria, arquivo);
        free(ptrCategoria);
        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        strcpy(codigoCategoria, "0");
        ptrCategoria = coletarDadosCategoria();
        printf("Digite o código único da categoria que você deseja atualizar: ");
        scanf("%s%*c", &codigoCategoria);
        status = (tipoArquivo == 'T') ? atualizarCategoriaTxt(codigoCategoria, ptrCategoria) : atualizarCategoriaBin(codigoCategoria, ptrCategoria);

        status == 1 ? printf(ANSI_GREEN "Registro de categoria atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de categoria" ANSI_RESET);
        free(ptrCategoria);
        break;

    case 3:

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categoria.txt", "r") : fopen("arquivos/categoria.bin", "rb");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrCategoria = malloc(sizeof(Categoria));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todas as categorias, digite 1. Se você deseja fazer uma leitura de uma categoria específica, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerCategoriaTxt("0", arquivo, ptrCategoria) : lerCategoriaBin("0", arquivo, ptrCategoria);
                if (status == 1)
                {

                    printf("%s {\n Quantidade de Pessoas: %d,\n Descrição: %s,\n Valor: %.2f;\n}\n", ptrCategoria->codigo, ptrCategoria->quantPessoas, ptrCategoria->descricao, ptrCategoria->valor);

                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            strcpy(codigoCategoria, "0");
            printf("Digite o código único da categoria que você deseja ler: ");
            scanf("%s%*c", &codigoCategoria);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerCategoriaTxt(codigoCategoria, arquivo, ptrCategoria) : lerCategoriaBin(codigoCategoria, arquivo, ptrCategoria);
                if (status == 1)
                {

                    printf("%s {\n Quantidade de Pessoas: %d,\n Descrição: %s,\n Valor: %.2f;\n}\n", ptrCategoria->codigo, ptrCategoria->quantPessoas, ptrCategoria->descricao, ptrCategoria->valor);

                    break;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Categoria não encontrada ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }

        free(ptrCategoria);
        fclose(arquivo);
        break;

    case 4:
        strcpy(codigoCategoria, "0");
        printf("Digite o código único do categoria que você deseja deletar: ");
        scanf("%s%*c", &codigoCategoria);
        status = (tipoArquivo == 'T') ? deletarCategoriaTxt(codigoCategoria) : deletarCategoriaBin(codigoCategoria);

        status == 1 ? printf(ANSI_GREEN "Registro de categoria deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de categoria" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void gerenciarAcomodacao(char tipoArquivo, char codigoPermissao)
{
    char item[] = "acomodacao";
    int operacao = selecionarOperacao(item);
    int status;
    int codigoAcomodacao;
    FILE *arquivo;
    Acomodacao *ptrAcomodacao;

    if (codigoPermissao == 'r')
    {
        if (operacao != 3)
        {
            printf(ANSI_RED "Acesso negado !!!" ANSI_RESET);
            return;
        }
    }

    switch (operacao)
    {
    case 1:
        ptrAcomodacao = coletarDadosAcomodacao(tipoArquivo);

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacao.txt", "a") : fopen("arquivos/acomodacao.bin", "ab");

        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }

        (tipoArquivo == 'T') ? adicionarAcomodacaoTxt(ptrAcomodacao, arquivo) : adicionarAcomodacaoBin(ptrAcomodacao, arquivo);
        free(ptrAcomodacao);

        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        codigoAcomodacao = 0;
        ptrAcomodacao = coletarDadosAcomodacao(tipoArquivo);
        printf("Digite o código único do acomodacao que você deseja atualizar: ");
        scanf("%d%*c", &codigoAcomodacao);
        status = (tipoArquivo == 'T') ? atualizarAcomodacaoTxt(codigoAcomodacao, ptrAcomodacao) : atualizarAcomodacaoBin(codigoAcomodacao, ptrAcomodacao);

        status == 1 ? printf(ANSI_GREEN "Registro de acomodacao atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de acomodação" ANSI_RESET);
        free(ptrAcomodacao);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacao.txt", "r") : fopen("arquivos/acomodacao.bin", "rb");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrAcomodacao = malloc(sizeof(Acomodacao));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todas as acomodações, digite" ANSI_BOLD "1." ANSI_RESET "Se você deseja fazer uma leitura de uma acomodação específica, digite" ANSI_BOLD "2" ANSI_RESET ": ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(0, arquivo, ptrAcomodacao) : lerAcomodacaoBin(0, arquivo, ptrAcomodacao);
                if (status == 1)
                {
                    printf("%d {\n Categoria: %s,\n Descrição: %s,\n Facilidades: %s;}\n",
                           ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->descricao, ptrAcomodacao->facilidades);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoAcomodacao = 0;
            printf("Digite o código único da acomodação que você deseja ler: ");
            scanf("%d%*c", &codigoAcomodacao);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(codigoAcomodacao, arquivo, ptrAcomodacao) : lerAcomodacaoBin(codigoAcomodacao, arquivo, ptrAcomodacao);
                if (status == 1)
                {
                    printf("%d {\n Categoria: %s,\n Descrição: %s,\n Facilidades: %s;}\n",
                           ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->descricao, ptrAcomodacao->facilidades);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Acomodação não encontrada ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }

        free(ptrAcomodacao);
        fclose(arquivo);
        break;

    case 4:
        codigoAcomodacao = 0;
        printf("Digite o código único do acomodacao que você deseja deletar: ");
        scanf("%d%*c", &codigoAcomodacao);
        status = (tipoArquivo == 'T') ? deletarAcomodacaoTxt(codigoAcomodacao) : deletarAcomodacaoBin(codigoAcomodacao);

        status == 1 ? printf(ANSI_GREEN "Registro de acomodacao deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de acomodação" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void gerenciarConsumivel(char tipoArquivo)
{
    char item[] = "consumivel";
    int operacao = selecionarOperacao(item);

    int status;
    int codigoConsumivel;
    FILE *arquivo;
    Consumivel *ptrConsumivel;
    switch (operacao)
    {
    case 1:
        ptrConsumivel = coletarDadosConsumivel();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "a") : fopen("arquivos/consumivel.bin", "ab");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }
        (tipoArquivo == 'T') ? adicionarConsumivelTxt(ptrConsumivel, arquivo) : adicionarConsumivelBin(ptrConsumivel, arquivo);
        free(ptrConsumivel);
        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        codigoConsumivel = 0;
        ptrConsumivel = coletarDadosConsumivel();
        printf("Digite o código único do consumivel que você deseja atualizar: ");
        scanf("%d%*c", &codigoConsumivel);
        status = (tipoArquivo == 'T') ? atualizarConsumivelTxt(codigoConsumivel, ptrConsumivel) : atualizarConsumivelBin(codigoConsumivel, ptrConsumivel);

        status == 1 ? printf(ANSI_GREEN "Registro de consumivel atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de consumível" ANSI_RESET);
        free(ptrConsumivel);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "r") : fopen("arquivos/consumivel.bin", "rb");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrConsumivel = malloc(sizeof(Consumivel));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os produtos, digite" ANSI_BOLD "1." ANSI_RESET "Se você deseja fazer uma leitura de um produto específico, digite" ANSI_BOLD "2" ANSI_RESET ": ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                status = (tipoArquivo == 'T') ? lerConsumivelTxt(0, arquivo, ptrConsumivel) : lerConsumivelBin(0, arquivo, ptrConsumivel);
                if (status == 1)
                {
                    printf("%d {\n Estoque: %d,\n Estoque Mínimo: %d,\n Descrição: %s,\n Preço de Custo: %.2f,\n Preço de Venda: %.2f;}\n",
                           ptrConsumivel->codigo, ptrConsumivel->estoque, ptrConsumivel->estoqueMin, ptrConsumivel->descricao, ptrConsumivel->precoCusto, ptrConsumivel->precoVenda);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoConsumivel = 0;
            printf("Digite o código único do produto consumível que você deseja ler: ");
            scanf("%d%*c", &codigoConsumivel);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerConsumivelTxt(codigoConsumivel, arquivo, ptrConsumivel) : lerConsumivelBin(codigoConsumivel, arquivo, ptrConsumivel);
                if (status == 1)
                {
                    printf("%d {\n Estoque: %d,\n Estoque Mínimo: %d,\n Descrição: %s,\n Preço de Custo: %.2f,\n Preço de Venda: %.2f;}\n",
                           ptrConsumivel->codigo, ptrConsumivel->estoque, ptrConsumivel->estoqueMin, ptrConsumivel->descricao, ptrConsumivel->precoCusto, ptrConsumivel->precoVenda);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Produto consumível não encontrado ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }
        free(ptrConsumivel);
        fclose(arquivo);
        break;

    case 4:
        codigoConsumivel = 0;
        printf("Digite o código único do consumivel que você deseja deletar: ");
        scanf("%d%*c", &codigoConsumivel);
        status = (tipoArquivo == 'T') ? deletarConsumivelTxt(codigoConsumivel) : deletarConsumivelBin(codigoConsumivel);

        status == 1 ? printf(ANSI_GREEN "Registro de consumivel deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de consumivel" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void gerenciarFornecedor(char tipoArquivo)
{
    char item[] = "fornecedor";
    int operacao = selecionarOperacao(item);

    int status;
    int codigoFornecedor;
    FILE *arquivo;
    Fornecedor *ptrFornecedor;
    switch (operacao)
    {
    case 1:
        ptrFornecedor = coletarDadosFornecedor();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/fornecedor.txt", "a") : fopen("arquivos/fornecedor.bin", "ab");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            break;
        }

        (tipoArquivo == 'T') ? adicionarFornecedorTxt(ptrFornecedor, arquivo) : adicionarFornecedorBin(ptrFornecedor, arquivo);
        free(ptrFornecedor);
        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        codigoFornecedor = 0;
        ptrFornecedor = coletarDadosFornecedor();
        printf("Digite o código único do fornecedor que você deseja atualizar: ");
        scanf("%d%*c", &codigoFornecedor);
        status = (tipoArquivo == 'T') ? atualizarFornecedorTxt(codigoFornecedor, ptrFornecedor) : atualizarFornecedorBin(codigoFornecedor, ptrFornecedor);

        status == 1 ? printf(ANSI_GREEN "Registro de fornecedor atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de fornecedor" ANSI_RESET);
        free(ptrFornecedor);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/fornecedor.txt", "r") : fopen("arquivos/fornecedor.bin", "rb");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrFornecedor = malloc(sizeof(Fornecedor));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os fornecedores, digite" ANSI_BOLD "1." ANSI_RESET "se você deseja fazer uma leitura de um fornecedor específico, digite" ANSI_BOLD "2" ANSI_RESET ": ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                status = (tipoArquivo == 'T') ? lerFornecedorTxt(0, arquivo, ptrFornecedor) : lerFornecedorBin(0, arquivo, ptrFornecedor);
                if (status == 1)
                {
                    printf("%d {\n Nome: %s,\n Razão Social: %s,\n Inscrição Social: %s,\n CNPJ: %s,\n Endereço: %s,\n Celular: %s,\n E-mail: %s;}\n",
                           ptrFornecedor->codigo, ptrFornecedor->nome, ptrFornecedor->razaoSocial, ptrFornecedor->inscricaoSocial, ptrFornecedor->cnpj, ptrFornecedor->endereco, ptrFornecedor->celular, ptrFornecedor->eMail);

                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoFornecedor = 0;
            printf("Digite o código único do fornecedor que você deseja ler: ");
            scanf("%d%*c", &codigoFornecedor);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerFornecedorTxt(codigoFornecedor, arquivo, ptrFornecedor) : lerFornecedorBin(codigoFornecedor, arquivo, ptrFornecedor);
                if (status == 1)
                {
                    printf("%d {\n Nome: %s,\n Razão Social: %s,\n Inscrição Social: %s,\n CNPJ: %s,\n Endereço: %s,\n Celular: %s,\n E-mail: %s;}\n",
                           ptrFornecedor->codigo, ptrFornecedor->nome, ptrFornecedor->razaoSocial, ptrFornecedor->inscricaoSocial, ptrFornecedor->cnpj, ptrFornecedor->endereco, ptrFornecedor->celular, ptrFornecedor->eMail);

                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Fornecedor não encontrado ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }
        free(ptrFornecedor); // Libere a memória alocada para ptrFornecedor
        fclose(arquivo);

        break;

    case 4:
        codigoFornecedor = 0;
        printf("Digite o código único do fornecedor que você deseja deletar: ");
        scanf("%d%*c", &codigoFornecedor);
        status = (tipoArquivo == 'T') ? deletarFornecedorTxt(codigoFornecedor) : deletarFornecedorBin(codigoFornecedor);

        status == 1 ? printf(ANSI_GREEN "Registro de fornecedor deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de fornecedor" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void gerenciarOperador(char tipoArquivo)
{
    char item[] = "operador";
    int operacao = selecionarOperacao(item);

    int status;
    int codigoOperador;
    FILE *arquivo;
    Operador *ptrOperador;
    switch (operacao)
    {
    case 1:
        ptrOperador = coletarDadosOperador();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/operador.txt", "a") : fopen("arquivos/operador.bin", "ab");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
            return;
        }

        (tipoArquivo == 'T') ? adicionarOperadorTxt(ptrOperador, arquivo) : adicionarOperadorBin(ptrOperador, arquivo);
        free(ptrOperador);
        fclose(arquivo);

        printf(ANSI_GREEN "Registrado com sucesso!\n" ANSI_RESET);
        break;

    case 2:
        codigoOperador = 0;
        ptrOperador = coletarDadosOperador();
        printf("Digite o código único do operador que você deseja atualizar: ");
        scanf("%d%*c", &codigoOperador);
        status = (tipoArquivo == 'T') ? atualizarOperadorTxt(codigoOperador, ptrOperador) : atualizarOperadorBin(codigoOperador, ptrOperador);

        status == 1 ? printf(ANSI_GREEN "Registro de operador atualizado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao atualizar registro de operador" ANSI_RESET);
        free(ptrOperador);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/operador.txt", "r") : fopen("arquivos/operador.bin", "rb");
        if (arquivo == NULL)
        {
            printf(ANSI_RED "Arquivo não existe ou não pode ser lido.\n" ANSI_RESET);
            break;
        }
        ptrOperador = malloc(sizeof(Operador));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os operadores, digite" ANSI_BOLD "1." ANSI_RESET "Se você deseja fazer uma leitura de um operador específico, digite" ANSI_BOLD "2" ANSI_RESET ": ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                status = (tipoArquivo == 'T') ? lerOperadorTxt(0, arquivo, ptrOperador) : lerOperadorBin(0, arquivo, ptrOperador);
                if (status)
                {
                    printf("%d {\n Nome: %s,\n Usuário: %s,\n Senha: %s,\n Permissão: %c;}\n",
                           ptrOperador->codigo, ptrOperador->nome, ptrOperador->usuario, ptrOperador->senha, ptrOperador->permissao);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Fim do arquivo alcançado.\n");
                    break;
                }
            }
        }
        else if (codigoMenu == 2)
        {
            codigoOperador = 0;
            printf("Digite o código único do operador que você deseja ler: ");
            scanf("%d%*c", &codigoOperador);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerOperadorTxt(codigoOperador, arquivo, ptrOperador) : lerOperadorBin(codigoOperador, arquivo, ptrOperador);

                if (status)
                {
                    printf("%d {\n Nome: %s,\n Usuário: %s,\n Senha: %s,\n Permissão: %c;}\n",
                           ptrOperador->codigo, ptrOperador->nome, ptrOperador->usuario, ptrOperador->senha, ptrOperador->permissao);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf(ANSI_RED "Operador não encontrado ou código incorreto.\n" ANSI_RESET);
                    break;
                }
            }
        }
        else
        {
            printf(ANSI_RED "Opção inválida.\n" ANSI_RESET);
        }
        free(ptrOperador);
        fclose(arquivo);
        break;

    case 4:
        codigoOperador = 0;
        printf("Digite o código único do operador que você deseja deletar: ");
        scanf("%d%*c", &codigoOperador);
        status = (tipoArquivo == 'T') ? deletarOperadorTxt(codigoOperador) : deletarOperadorBin(codigoOperador);

        status == 1 ? printf(ANSI_GREEN "Registro de operador deletado com sucesso" ANSI_RESET) : printf(ANSI_RED "Erro ao deletar registro de operador" ANSI_RESET);
        break;

    default:
        printf(ANSI_RED "Erro desconhecido.\n" ANSI_RESET);
        break;
    }
}

void converterArquivos(char tipoArquivo)
{
    FILE *arquivoLeitura,
        *arquivoEscrita;
    int status;
    if (tipoArquivo == 'T')
    {

        {
            Hotel *ptrHotel = malloc(sizeof(Hotel));
            arquivoLeitura = fopen("arquivos/hotel.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrHotel);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/hotel.txt", "w");
                if (arquivoLeitura == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHotel);
                }
                else
                {

                    lerHotelBin(arquivoLeitura, ptrHotel);
                    criarHotelTxt(ptrHotel, arquivoEscrita);

                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHotel);
                    remove("arquivos/hotel.bin");
                }
            }
        }

        {
            Hospede *ptrHospede = malloc(sizeof(Hospede));
            arquivoLeitura = fopen("arquivos/hospede.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrHospede);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/hospede.txt", "w");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHospede);
                }
                else
                {

                    while (1)
                    {

                        status = lerHospedeBin(0, arquivoLeitura, ptrHospede);
                        if (status)
                        {
                            adicionarHospedeTxt(ptrHospede, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHospede);
                    remove("arquivos/hospede.bin");
                }
            }
        }

        {
            Categoria *ptrCategoria = malloc(sizeof(Categoria));
            arquivoLeitura = fopen("arquivos/categoria.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrCategoria);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/categoria.txt", "w");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrCategoria);
                }
                else
                {
                    while (1)
                    {

                        status = lerCategoriaTxt("0", arquivoLeitura, ptrCategoria);
                        if (status)
                        {
                            adicionarCategoriaTxt(ptrCategoria, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {

                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    remove("arquivos/categoria.bin");
                    free(ptrCategoria);
                }
            }
        }

        {
            Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao));
            arquivoLeitura = fopen("arquivos/acomodacao.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrAcomodacao);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/acomodacao.txt", "w");

                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrAcomodacao);
                }
                else
                {
                    while (1)
                    {
                        status = lerAcomodacaoBin(0, arquivoLeitura, ptrAcomodacao);
                        if (status)
                        {
                            adicionarAcomodacaoTxt(ptrAcomodacao, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrAcomodacao);
                    remove("arquivos/acomodacao.bin");
                }
            }
        }

        {
            Consumivel *ptrConsumivel = malloc(sizeof(Consumivel));
            arquivoLeitura = fopen("arquivos/consumivel.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrConsumivel);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/consumivel.txt", "w");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrConsumivel);
                }
                else
                {
                    while (1)
                    {

                        status = lerConsumivelBin(0, arquivoLeitura, ptrConsumivel);
                        if (status)
                        {
                            adicionarConsumivelTxt(ptrConsumivel, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrConsumivel);
                    remove("arquivos/consumivel.bin");
                }
            }
        }

        {
            Fornecedor *ptrFornecedor = malloc(sizeof(Fornecedor));
            arquivoLeitura = fopen("arquivos/fornecedor.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrFornecedor);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/fornecedor.txt", "w");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrFornecedor);
                }
                else
                {
                    while (1)
                    {

                        status = lerFornecedorBin(0, arquivoLeitura, ptrFornecedor);
                        if (status)
                        {
                            adicionarFornecedorTxt(ptrFornecedor, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrFornecedor);
                    remove("arquivos/fornecedor.bin");
                }
            }
        }

        {
            Operador *ptrOperador = malloc(sizeof(Operador));
            arquivoLeitura = fopen("arquivos/operador.bin", "rb");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrOperador);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/operador.txt", "w");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrOperador);
                }
                else
                {
                    while (1)
                    {

                        status = lerOperadorBin(0, arquivoLeitura, ptrOperador);
                        if (status)
                        {
                            adicionarOperadorTxt(ptrOperador, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrOperador);
                    remove("arquivos/operador.bin");
                }
            }
        }
    }
    else if (tipoArquivo == 'B')
    {

        {
            Hotel *ptrHotel = malloc(sizeof(Hotel));
            arquivoLeitura = fopen("arquivos/hotel.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrHotel);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/hotel.bin", "wb");
                if (arquivoLeitura == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHotel);
                }
                else
                {

                    lerHotelTxt(arquivoLeitura, ptrHotel);
                    criarHotelBin(ptrHotel, arquivoEscrita);

                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHotel);
                    remove("arquivos/hotel.txt");
                }
            }
        }

        {
            Hospede *ptrHospede = malloc(sizeof(Hospede));
            arquivoLeitura = fopen("arquivos/hospede.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrHospede);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/hospede.bin", "wb");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHospede);
                }
                else
                {

                    while (1)
                    {

                        status = lerHospedeTxt(0, arquivoLeitura, ptrHospede);
                        if (status)
                        {
                            adicionarHospedeBin(ptrHospede, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrHospede);
                    remove("arquivos/hospede.txt");
                }
            }
        }

        {
            Categoria *ptrCategoria = malloc(sizeof(Categoria));
            arquivoLeitura = fopen("arquivos/categoria.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrCategoria);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/categoria.bin", "wb");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrCategoria);
                }
                else
                {
                    while (1)
                    {

                        status = lerCategoriaTxt("0", arquivoLeitura, ptrCategoria);
                        if (status)
                        {
                            adicionarCategoriaBin(ptrCategoria, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {

                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    remove("arquivos/categoria.txt");
                    free(ptrCategoria);
                }
            }
        }

        {
            Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao));
            arquivoLeitura = fopen("arquivos/acomodacao.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrAcomodacao);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/acomodacao.bin", "wb");

                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrAcomodacao);
                }
                else
                {
                    while (1)
                    {
                        status = lerAcomodacaoTxt(0, arquivoLeitura, ptrAcomodacao);
                        if (status)
                        {
                            adicionarAcomodacaoBin(ptrAcomodacao, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrAcomodacao);
                    remove("arquivos/acomodacao.txt");
                }
            }
        }

        {
            Consumivel *ptrConsumivel = malloc(sizeof(Consumivel));
            arquivoLeitura = fopen("arquivos/consumivel.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrConsumivel);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/consumivel.bin", "wb");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrConsumivel);
                }
                else
                {
                    while (1)
                    {

                        status = lerConsumivelTxt(0, arquivoLeitura, ptrConsumivel);
                        if (status)
                        {
                            adicionarConsumivelBin(ptrConsumivel, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrConsumivel);
                    remove("arquivos/consumivel.txt");
                }
            }
        }

        {
            Fornecedor *ptrFornecedor = malloc(sizeof(Fornecedor));
            arquivoLeitura = fopen("arquivos/fornecedor.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrFornecedor);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/fornecedor.bin", "wb");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrFornecedor);
                }
                else
                {
                    while (1)
                    {

                        status = lerFornecedorTxt(0, arquivoLeitura, ptrFornecedor);
                        if (status)
                        {
                            adicionarFornecedorBin(ptrFornecedor, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrFornecedor);
                    remove("arquivos/fornecedor.txt");
                }
            }
        }

        {
            Operador *ptrOperador = malloc(sizeof(Operador));
            arquivoLeitura = fopen("arquivos/operador.txt", "r");
            if (arquivoLeitura == NULL)
            {
                printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                fclose(arquivoLeitura);
                free(ptrOperador);
            }
            else
            {
                arquivoEscrita = fopen("arquivos/operador.bin", "wb");
                if (arquivoEscrita == NULL)
                {
                    printf(ANSI_RED "Arquivo não existe ou não pode ser aberto!\n" ANSI_RESET);
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrOperador);
                }
                else
                {
                    while (1)
                    {

                        status = lerOperadorTxt(0, arquivoLeitura, ptrOperador);
                        if (status)
                        {
                            adicionarOperadorBin(ptrOperador, arquivoEscrita);
                            continue;
                        }
                        else if (feof(arquivoLeitura))
                        {
                            break;
                        }
                    }
                    fclose(arquivoLeitura);
                    fclose(arquivoEscrita);
                    free(ptrOperador);
                    remove("arquivos/operador.txt");
                }
            }
        }
    }
}

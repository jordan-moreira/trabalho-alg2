#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestaoDados.h"
#include "crudTxt.h"
#include "crudBin.h"

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
    scanf("%s", ptrFornecedor->inscricaoSocial);

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

void gerenciarHotel(char tipoArquivo)
{
    char item[] = "hotel";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Hotel *ptr = coletarDadosHotel();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hotel.txt", "a") : fopen("arquivo/hotel.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }
        strcmp(tipoArquivo, "txt") == 0 ? criarHotelTxt(ptr, arquivo) : criarHotelBin(ptr, arquivo);

        free(ptr);
        fclose(arquivo);
        printf("Registrado com sucesso!\n");
        break;

        // case 2:
        // atualizarHotel();
        // break;

    case 3:
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hotel.bin", "rb") : fopen("arquivo/hotel.txt", "r");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }

        Hotel *ptrHotel = malloc(sizeof(Hotel));
        int status = strcmp(tipoArquivo, "txt") == 0 ? lerHotelTxt(arquivo, ptrHotel) : lerHotelBin(arquivo, ptrHotel);

        if (status == 1)
        {
            printf("\n Nome do Hotel: %s,\n Razão Social: %s,\n Inscrição Estadual: %s,\n CNPJ: %s,\n Endereço: %s,\n Número de Celular: %s,\n E-mail: %s,\n Nome do Responsável: %s,\n Número de Celular do Responsável: %s,\n Horário de Check-in: %s,\n Horário de Check-out: %s;\n}\n",
                   ptrHotel->nome, ptrHotel->razaoSocial, ptrHotel->inscricaoEstadual, ptrHotel->cnpj, ptrHotel->endereco, ptrHotel->celular, ptrHotel->eMail, ptrHotel->responsavel, ptrHotel->celularResponsavel, ptrHotel->horarioCheckIn, ptrHotel->horarioCheckOut);
        }
        else if (status == 0)
        {
            printf("Hotel não encontrado ou erro de leitura.\n");
        }

        free(ptrHotel);
        fclose(arquivo);

        break;

        // case 4:
        // deletarHotel();
        // break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarHospede(char tipoArquivo)
{
    char item[] = "hospede";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Hospede *ptr = coletarDadosHospede();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hospede.txt", "a") : fopen("arquivo/hospede.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        strcmp(tipoArquivo, "txt") == 0 ? adicionarHospedeTxt(ptr, arquivo) : adicionarHospedeTxtBin(ptr, arquivo);
        free(ptr);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarHospede();
        break;

    case 3:

        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hospede.txt", "a") : fopen("arquivo/hospede.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Hospede *ptrHospede = malloc(sizeof(Hospede));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os hóspedes, digite 1. Se você deseja fazer uma leitura de um hóspede específico, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerHospedeTxt(0, arquivo, ptrHospede) : lerHospedeBin(0, arquivo, ptrHospede);

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
            int codigoHospede = 0;
            printf("Digite o código único do hóspede que você deseja ler: ");
            scanf("%d%*c", &codigoHospede);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerHospedeTxt(codigoHospede, arquivo, ptrHospede) : lerHospedeBin(codigoHospede, arquivo, ptrHospede);

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
                    printf("Hospede não encontrado ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }

        free(ptrHospede); // Libere a memória alocada para ptrHospede
        fclose(arquivo);
        break;

    case 4:
        // deletarHospede();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarCategoria(char tipoArquivo)
{
    char item[] = "categoria";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Categoria *ptr = coletarDadosCategoria();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hospede.txt", "a") : fopen("arquivo/hospede.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        strcmp(tipoArquivo, "txt") == 0 ? adicionarCategoriaTxt(ptr, arquivo) : adicionarCategoriaBin(ptr, arquivo);
        free(ptr);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarCategoria();
        break;

    case 3:

        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/hospede.txt", "a") : fopen("arquivo/hospede.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Categoria *ptrCategoria = malloc(sizeof(Categoria));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todas as categorias, digite 1. Se você deseja fazer uma leitura de uma categoria específica, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerCategoriaTxt(0, arquivo, ptrCategoria) : lerCategoriaBin(0, arquivo, ptrCategoria);
                if (status == 1)
                {

                    printf("%d {\n Quantidade de Pessoas: %d,\n Descrição: %s,\n Valor: %.2f;\n}\n", ptrCategoria->codigo, ptrCategoria->quantPessoas, ptrCategoria->descricao, ptrCategoria->valor);

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
            int codigoCategoria = 0;
            printf("Digite o código único da categoria que você deseja ler: ");
            scanf("%d%*c", &codigoCategoria);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerCategoriaTxt(codigoCategoria, arquivo, ptrCategoria) : lerCategoriaBin(codigoCategoria, arquivo, ptrCategoria);
                if (status == 1)
                {

                    printf("%d {\n Quantidade de Pessoas: %d,\n Descrição: %s,\n Valor: %.2f;\n}\n", ptrCategoria->codigo, ptrCategoria->quantPessoas, ptrCategoria->descricao, ptrCategoria->valor);

                    break;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Categoria não encontrada ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }

        free(ptrCategoria);
        fclose(arquivo);
        break;

    case 4:
        // deletarCategoria();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarAcomodacao(char tipoArquivo)
{
    char item[] = "acomodacao";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Acomodacao *ptr = coletarDadosAcomodacao();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/acomodacao.txt", "a") : fopen("arquivo/acomodacao.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        strcmp(tipoArquivo, "txt") == 0 ? adicionarAcomodacaoTxt(ptr, arquivo) : adicionarAcomodacaoBin(ptr, arquivo);
        free(ptr);

        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarAcomodacao();
        break;

    case 3:
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/acomodacao.txt", "a") : fopen("arquivo/acomodacao.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Acomodacao *ptrAcomodacao = malloc(sizeof(Acomodacao));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todas as acomodações, digite 1. Se você deseja fazer uma leitura de uma acomodação específica, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerAcomodacaoTxt(0, arquivo, ptrAcomodacao) : lerAcomodacaoBin(0, arquivo, ptrAcomodacao);
                if (status == 1)
                {
                    printf("%d {\n Categoria: %d,\n Ocupada: %d,\n Data Inicial: %d/%d/%d,\n Data Final: %d/%d/%d,\n Descrição: %s,\n Facilidades: %s;}\n",
                           ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->ocupada, ptrAcomodacao->data.dataInicial[0], ptrAcomodacao->data.dataInicial[1], ptrAcomodacao->data.dataInicial[2], ptrAcomodacao->data.dataFinal[0], ptrAcomodacao->data.dataFinal[1], ptrAcomodacao->data.dataFinal[2], ptrAcomodacao->descricao, ptrAcomodacao->facilidades);
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
            int codigoAcomodacao = 0;
            printf("Digite o código único da acomodação que você deseja ler: ");
            scanf("%d%*c", &codigoAcomodacao);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerAcomodacaoTxt(codigoAcomodacao, arquivo, ptrAcomodacao) : lerAcomodacaoBin(codigoAcomodacao, arquivo, ptrAcomodacao);
                if (status == 1)
                {
                    printf("%d {\n Categoria: %d,\n Ocupada: %d,\n Data Inicial: %d/%d/%d,\n Data Final: %d/%d/%d,\n Descrição: %s,\n Facilidades: %s;}\n",
                           ptrAcomodacao->codigo, ptrAcomodacao->categoria, ptrAcomodacao->ocupada, ptrAcomodacao->data.dataInicial[0], ptrAcomodacao->data.dataInicial[1], ptrAcomodacao->data.dataInicial[2], ptrAcomodacao->data.dataFinal[0], ptrAcomodacao->data.dataFinal[1], ptrAcomodacao->data.dataFinal[2], ptrAcomodacao->descricao, ptrAcomodacao->facilidades);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Acomodação não encontrada ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }

        free(ptrAcomodacao);
        fclose(arquivo);
        break;

    case 4:
        // deletarAcomodacao();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarConsumivel(char tipoArquivo)
{
    char item[] = "consumivel";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Consumivel *ptr = coletarDadosConsumivel();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/consumivel.txt", "a") : fopen("arquivo/consumivel.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }
        strcmp(tipoArquivo, "txt") == 0 ? adicionarConsumivelTxt(ptr, arquivo) : adicionarConsumivelBin(ptr, arquivo);
        free(ptr);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarConsumivel();
        break;

    case 3:
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/consumivel.txt", "a") : fopen("arquivo/consumivel.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Consumivel *ptrConsumivel = malloc(sizeof(Consumivel));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os produtos, digite 1. Se você deseja fazer uma leitura de um produto específico, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerConsumivelTxt(0, arquivo, ptrConsumivel) : lerConsumivelBin(0, arquivo, ptrConsumivel);
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
            int codigoConsumivel = 0;
            printf("Digite o código único do produto consumível que você deseja ler: ");
            scanf("%d%*c", &codigoConsumivel);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerConsumivelTxt(codigoConsumivel, arquivo, ptrConsumivel) : lerConsumivelBin(codigoConsumivel, arquivo, ptrConsumivel);
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
                    printf("Produto consumível não encontrado ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }
        free(ptrConsumivel);
        fclose(arquivo);
        break;

    case 4:
        // deletarConsumivel();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarFornecedor(char tipoArquivo)
{
    char item[] = "fornecedor";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Fornecedor *ptr = coletarDadosFornecedor();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/fornecedor.txt", "a") : fopen("arquivo/fornecedor.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        strcmp(tipoArquivo, "txt") == 0 ? adicionarFornecedorTxt(ptr, arquivo) : adicionarFornecedorBin(ptr, arquivo);
        free(ptr);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarFornecedor();
        break;

    case 3:
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/fornecedor.txt", "a") : fopen("arquivo/fornecedor.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Fornecedor *ptrFornecedor = malloc(sizeof(Fornecedor));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os fornecedores, digite 1. Se você deseja fazer uma leitura de um fornecedor específico, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerFornecedorTxt(0, arquivo, ptrFornecedor) : lerFornecedorBin(0, arquivo, ptrFornecedor);
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
            int codigoFornecedor = 0;
            printf("Digite o código único do fornecedor que você deseja ler: ");
            scanf("%d%*c", &codigoFornecedor);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerFornecedorTxt(codigoFornecedor, arquivo, ptrFornecedor) : lerFornecedorBin(codigoFornecedor, arquivo, ptrFornecedor);
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
                    printf("Fornecedor não encontrado ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }
        free(ptrFornecedor); // Libere a memória alocada para ptrFornecedor
        fclose(arquivo);

        break;

    case 4:
        // deletarFornecedor();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

void gerenciarOperador(char tipoArquivo)
{
    char item[] = "operador";
    int operacao = selecionarOperacao(item);

    switch (operacao)
    {
    case 1:
        Operador *ptr = coletarDadosOperador();
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/operador.txt", "a") : fopen("arquivo/operador.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            return;
        }

        strcmp(tipoArquivo, "txt") == 0 ? adicionarOperadorTxt(ptr, arquivo) : adicionarOperadorBin(ptr, arquivo);
        free(ptr);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        // atualizarOperador();
        break;

    case 3:
        FILE *arquivo;

        arquivo = strcmp(tipoArquivo, "txt") == 0 ? fopen("arquivo/operador.txt", "a") : fopen("arquivo/operador.bin", "ab");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        Operador *ptrOperador = malloc(sizeof(Operador));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os operadores, digite 1. Se você deseja fazer uma leitura de um operador específico, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {
            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerOperadorTxt(0, arquivo, ptrOperador) : lerOperadorBin(0, arquivo, ptrOperador);
                if (status)
                {
                    printf("%d {\n Nome: %s,\n Usuário: %s,\n Senha: %s,\n Permissão: %s;}\n",
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
            int codigoOperador = 0;
            printf("Digite o código único do operador que você deseja ler: ");
            scanf("%d%*c", &codigoOperador);

            while (1)
            {
                int status = strcmp(tipoArquivo, "txt") == 0 ? lerOperadorTxt(codigoOperador, arquivo, ptrOperador) : lerOperadorBin(codigoOperador, arquivo, ptrOperador);

                if (status)
                {
                    printf("%d {\n Nome: %s,\n Usuário: %s,\n Senha: %s,\n Permissão: %s;}\n",
                           ptrOperador->codigo, ptrOperador->nome, ptrOperador->usuario, ptrOperador->senha, ptrOperador->permissao);
                    continue;
                }
                else if (status == 0 && !feof(arquivo))
                {

                    continue;
                }
                else
                {
                    printf("Operador não encontrado ou código incorreto.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }
        free(ptrOperador);
        fclose(arquivo);
        break;

    case 4:
        // deletarOperador();
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

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
0
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
    scanf(" %c", &ptrOperador->permissao);

    return ptrOperador;
}

void gerenciarHotel(char tipoArquivo)
{
    char item[] = "hotel";
    int operacao = selecionarOperacao(item);
    int status;
    FILE *arquivo;
    Hotel *ptrHotel;

    switch (operacao)
    {
    case 1:
        ptrHotel = coletarDadosHotel();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hotel.txt", "a") : fopen("arquivos/hotel.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }
        (tipoArquivo == 'T') ? criarHotelTxt(ptrHotel, arquivo) : criarHotelBin(ptrHotel, arquivo);

        free(ptrHotel);
        fclose(arquivo);
        printf("Registrado com sucesso!\n");
        break;

    case 2:
        ptrHotel = coletarDadosHotel();
        status = (tipoArquivo == 'T') ? atualizarHotelTxt(ptrHotel) : atualizarHotelBin(ptrHotel);
        status == 1 ? printf("registros de hotel atualizados com sucesso") : printf("erro ao atualizar registros de hotel");
        free(ptrHotel);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hotel.txt", "r") : fopen("arquivos/hotel.bin", "rb");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
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
            printf("Hotel não encontrado ou erro de leitura.\n");
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
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        (tipoArquivo == 'T') ? adicionarHospedeTxt(ptrHospede, arquivo) : adicionarHospedeBin(ptrHospede, arquivo);
        free(ptrHospede);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoHospede = 0;
        ptrHospede = coletarDadosHospede();
        printf("Digite o código único do hospede que você deseja atualizar: ");
        scanf("%d%*c", &codigoHospede);
        status = (tipoArquivo == 'T') ? atualizarHospedeTxt(codigoHospede, ptrHospede) : atualizarHospedeBin(codigoHospede, ptrHospede);

        status == 1 ? printf("registro de hospede atualizado com sucesso") : printf("erro ao atualizar registro de hospede");
        free(ptrHospede);
        break;

    case 3:

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/hospede.txt", "r") : fopen("arquivos/hospede.bin", "rb");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
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
        codigoHospede = 0;
        printf("Digite o código único do hospede que você deseja deletar: ");
        scanf("%d%*c", &codigoHospede);
        status = (tipoArquivo == 'T') ? deletarHospedeTxt(codigoHospede) : deletarHospedeBin(codigoHospede);

        status == 1 ? printf("registro de hospede deletado com sucesso") : printf("erro ao deletar registro de hospede");
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
    int status;
    int codigoCategoria;
    FILE *arquivo;
    Categoria *ptrCategoria;
    switch (operacao)
    {
    case 1:
        ptrCategoria = coletarDadosCategoria();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categoria.txt", "a") : fopen("arquivos/categoria.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        (tipoArquivo == 'T') ? adicionarCategoriaTxt(ptrCategoria, arquivo) : adicionarCategoriaBin(ptrCategoria, arquivo);
        free(ptrCategoria);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoCategoria = 0;
        ptrCategoria = coletarDadosCategoria();
        printf("Digite o código único da categoria que você deseja atualizar: ");
        scanf("%d%*c", &codigoCategoria);
        status = (tipoArquivo == 'T') ? atualizarCategoriaTxt(codigoCategoria, ptrCategoria) : atualizarCategoriaBin(codigoCategoria, ptrCategoria);

        status == 1 ? printf("registro de categoria atualizado com sucesso") : printf("erro ao atualizar registro de categoria");
        free(ptrCategoria);
        break;

    case 3:

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/categoria.txt", "r") : fopen("arquivos/categoria.bin", "rb");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
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
                status = (tipoArquivo == 'T') ? lerCategoriaTxt(0, arquivo, ptrCategoria) : lerCategoriaBin(0, arquivo, ptrCategoria);
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
            codigoCategoria = 0;
            printf("Digite o código único da categoria que você deseja ler: ");
            scanf("%d%*c", &codigoCategoria);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerCategoriaTxt(codigoCategoria, arquivo, ptrCategoria) : lerCategoriaBin(codigoCategoria, arquivo, ptrCategoria);
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
        codigoCategoria = 0;
        printf("Digite o código único do categoria que você deseja deletar: ");
        scanf("%d%*c", &codigoCategoria);
        status = (tipoArquivo == 'T') ? deletarCategoriaTxt(codigoCategoria) : deletarCategoriaBin(codigoCategoria);

        status == 1 ? printf("registro de categoria deletado com sucesso") : printf("erro ao deletar registro de categoria");
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
    int status;
    int codigoAcomodacao;
    FILE *arquivo;
    Acomodacao *ptrAcomodacao;

    switch (operacao)
    {
    case 1:
        ptrAcomodacao = coletarDadosAcomodacao();

        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacao.txt", "a") : fopen("arquivos/acomodacao.bin", "ab");

        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        (tipoArquivo == 'T') ? adicionarAcomodacaoTxt(ptrAcomodacao, arquivo) : adicionarAcomodacaoBin(ptrAcomodacao, arquivo);
        free(ptrAcomodacao);

        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoAcomodacao = 0;
        ptrAcomodacao = coletarDadosAcomodacao();
        printf("Digite o código único do acomodacao que você deseja atualizar: ");
        scanf("%d%*c", &codigoAcomodacao);
        status = (tipoArquivo == 'T') ? atualizarAcomodacaoTxt(codigoAcomodacao, ptrAcomodacao) : atualizarAcomodacaoBin(codigoAcomodacao, ptrAcomodacao);

        status == 1 ? printf("registro de acomodacao atualizado com sucesso") : printf("erro ao atualizar registro de acomodacao");
        free(ptrAcomodacao);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/acomodacao.txt", "r") : fopen("arquivos/acomodacao.bin", "rb");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        ptrAcomodacao = malloc(sizeof(Acomodacao));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todas as acomodações, digite 1. Se você deseja fazer uma leitura de uma acomodação específica, digite 2: ");
        scanf("%d%*c", &codigoMenu);

        if (codigoMenu == 1)
        {

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(0, arquivo, ptrAcomodacao) : lerAcomodacaoBin(0, arquivo, ptrAcomodacao);
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
            codigoAcomodacao = 0;
            printf("Digite o código único da acomodação que você deseja ler: ");
            scanf("%d%*c", &codigoAcomodacao);

            while (1)
            {
                status = (tipoArquivo == 'T') ? lerAcomodacaoTxt(codigoAcomodacao, arquivo, ptrAcomodacao) : lerAcomodacaoBin(codigoAcomodacao, arquivo, ptrAcomodacao);
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
        codigoAcomodacao = 0;
        printf("Digite o código único do acomodacao que você deseja deletar: ");
        scanf("%d%*c", &codigoAcomodacao);
        status = (tipoArquivo == 'T') ? deletarAcomodacaoTxt(codigoAcomodacao) : deletarAcomodacaoBin(codigoAcomodacao);

        status == 1 ? printf("registro de acomodacao deletado com sucesso") : printf("erro ao deletar registro de acomodacao");
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
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }
        (tipoArquivo == 'T') ? adicionarConsumivelTxt(ptrConsumivel, arquivo) : adicionarConsumivelBin(ptrConsumivel, arquivo);
        free(ptrConsumivel);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoConsumivel = 0;
        ptrConsumivel = coletarDadosConsumivel();
        printf("Digite o código único do consumivel que você deseja atualizar: ");
        scanf("%d%*c", &codigoConsumivel);
        status = (tipoArquivo == 'T') ? atualizarConsumivelTxt(codigoConsumivel, ptrConsumivel) : atualizarConsumivelBin(codigoConsumivel, ptrConsumivel);

        status == 1 ? printf("registro de consumivel atualizado com sucesso") : printf("erro ao atualizar registro de consumivel");
        free(ptrConsumivel);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/consumivel.txt", "r") : fopen("arquivos/consumivel.bin", "rb");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        ptrConsumivel = malloc(sizeof(Consumivel));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os produtos, digite 1. Se você deseja fazer uma leitura de um produto específico, digite 2: ");
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
        codigoConsumivel = 0;
        printf("Digite o código único do consumivel que você deseja deletar: ");
        scanf("%d%*c", &codigoConsumivel);
        status = (tipoArquivo == 'T') ? deletarConsumivelTxt(codigoConsumivel) : deletarConsumivelBin(codigoConsumivel);

        status == 1 ? printf("registro de consumivel deletado com sucesso") : printf("erro ao deletar registro de consumivel");
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
            printf("Arquivo não existe ou não pode ser aberto!\n");
            break;
        }

        (tipoArquivo == 'T') ? adicionarFornecedorTxt(ptrFornecedor, arquivo) : adicionarFornecedorBin(ptrFornecedor, arquivo);
        free(ptrFornecedor);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoFornecedor = 0;
        ptrFornecedor = coletarDadosFornecedor();
        printf("Digite o código único do fornecedor que você deseja atualizar: ");
        scanf("%d%*c", &codigoFornecedor);
        status = (tipoArquivo == 'T') ? atualizarFornecedorTxt(codigoFornecedor, ptrFornecedor) : atualizarFornecedorBin(codigoFornecedor, ptrFornecedor);

        status == 1 ? printf("registro de fornecedor atualizado com sucesso") : printf("erro ao atualizar registro de fornecedor");
        free(ptrFornecedor);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/fornecedor.txt", "r") : fopen("arquivos/fornecedor.bin", "rb");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        ptrFornecedor = malloc(sizeof(Fornecedor));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os fornecedores, digite 1. Se você deseja fazer uma leitura de um fornecedor específico, digite 2: ");
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
        codigoFornecedor = 0;
        printf("Digite o código único do fornecedor que você deseja deletar: ");
        scanf("%d%*c", &codigoFornecedor);
        status = (tipoArquivo == 'T') ? deletarFornecedorTxt(codigoFornecedor) : deletarFornecedorBin(codigoFornecedor);

        status == 1 ? printf("registro de fornecedor deletado com sucesso") : printf("erro ao deletar registro de fornecedor");
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
            printf("Arquivo não existe ou não pode ser aberto!\n");
            return;
        }

        (tipoArquivo == 'T') ? adicionarOperadorTxt(ptrOperador, arquivo) : adicionarOperadorBin(ptrOperador, arquivo);
        free(ptrOperador);
        fclose(arquivo);

        printf("Registrado com sucesso!\n");
        break;

    case 2:
        codigoOperador = 0;
        ptrOperador = coletarDadosOperador();
        printf("Digite o código único do operador que você deseja atualizar: ");
        scanf("%d%*c", &codigoOperador);
        status = (tipoArquivo == 'T') ? atualizarOperadorTxt(codigoOperador, ptrOperador) : atualizarOperadorBin(codigoOperador, ptrOperador);

        status == 1 ? printf("registro de operador atualizado com sucesso") : printf("erro ao atualizar registro de operador");
        free(ptrOperador);
        break;

    case 3:
        arquivo = (tipoArquivo == 'T') ? fopen("arquivos/operador.txt", "r") : fopen("arquivos/operador.bin", "rb");
        if (arquivo == NULL)
        {
            printf("Arquivo não existe ou não pode ser lido.\n");
            break;
        }
        ptrOperador = malloc(sizeof(Operador));

        int codigoMenu = 0;

        printf("Se você deseja fazer uma leitura de todos os operadores, digite 1. Se você deseja fazer uma leitura de um operador específico, digite 2: ");
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
        codigoOperador = 0;
        printf("Digite o código único do operador que você deseja deletar: ");
        scanf("%d%*c", &codigoOperador);
        status = (tipoArquivo == 'T') ? deletarOperadorTxt(codigoOperador) : deletarOperadorBin(codigoOperador);

        status == 1 ? printf("registro de operador deletado com sucesso") : printf("erro ao deletar registro de operador");
        break;

    default:
        printf("Erro desconhecido.\n");
        break;
    }
}

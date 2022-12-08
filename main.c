/**********************************************************
 *  SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 *  Unidade Curricular: Lógica de programação
 *  Situação de aprendizagem
 *  Professor: Lucas Antunes
 *  Alunos: Douglas Melere Tibola Junior
 *  Luzerna, 26/05/2022
 **********************************************************/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "estoque.h"
#include "loja.h"

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_ESTOQUE 100
#define MAX_CARRINHO 100
#define MAX_LOJAS 100

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Estoque estoques[MAX_ESTOQUE];
Loja lojas[MAX_LOJAS];

int i_clientes = 0; // Variável de índice do vetor.
int i_produtos = 0;
int i_lojas = 0;
int i_carrinhos = 0;
int i_estoque = 0;

//----------------------------------------------------------
//


void opcao1()
{

     printf("========================================================================================================================\n\n");
        printf("\t\t  \t                              CLIENTES\n\n");
        printf("========================================================================================================================\n\n\n");

    printf("Escolha uma das opções abaixo:\n\n"
           "  [1] - Adicionar cliente\n"
           "  [2] - Listar clientes\n"
           "  [3] - Buscar clientes\n"
           "  [ESC] - Voltar ao menu inicial\n");

            printf("\n\n\n\t-Opção:");

    switch (getch())
    {

    case '1':
        clientes[i_clientes++] = cadastraCliente();
        break;

    case '2':
        for (int n = 0; n < i_clientes; n++)
        {
            imprimeCliente(clientes[n]);
        }
        break;

    case '3':

        system("cls");

        for (int n = 0; n < i_clientes; n++)
        {
            procurarCliente(clientes, i_clientes);
            break;
        }
        break;

        break;

    case 27:
        return;

    default:
        printf("Opção inválida!\n");
    }

}

void opcao2()
{

     printf("========================================================================================================================\n\n");
        printf("\t\t  \t                              PRODUTO\n\n");
        printf("========================================================================================================================\n\n\n");

    printf("Escolha uma das opções abaixo:\n\n"
           "  [1] - Adicionar produto\n"
           "  [2] - Listar produtos\n"
           "  [ESC] - Voltar ao menu inical\n");

            printf("\n\n\n\t-Opção:");

    switch (getch())
    {
    case '1':
        produtos[i_produtos++] = cadastraProduto();
        break;

    case '2':
        for (int n = 0; n < i_produtos; n++)
        {
            ordenaProduto(produtos, i_produtos);
            imprimeProduto(produtos[n]);
        }
        break;

    case 27:
        return;

    default:
        printf("Opção inválida!\n");
    }

}

void opcao3()
{

     printf("========================================================================================================================\n\n");
        printf("\t\t  \t                              ESTOQUE\n\n");
        printf("========================================================================================================================\n\n\n");

    printf("Escolha uma das opções abaixo:\n\n"
           "  [1] - Adicionar Estoque\n"
           "  [2] - Listar Estoque\n"
           "  [ESC] - Voltar ao menu inical\n");

            printf("\n\n\n\t-Opção:");

    switch (getch())
    {
    case '1':
        estoques[i_estoque++] = cadastraEstoque();
        break;

    case '2':
        for (int n = 0; n < i_estoque; n++)
        {
            imprimeEstoque(estoques[n]);
        }
        break;

    case 27:
        return;
    }

}


    void opcao4() {
    
     printf("========================================================================================================================\n\n");
        printf("\t\t  \t                              LOJAS\n\n");
        printf("========================================================================================================================\n\n\n");

            printf("\n\n\n\tOpção:");

    printf("Escolha uma das opções abaixo:\n\n"
           "  [1] - Adicionar loja\n"
           "  [2] - Listar lojas\n"
           "  [ESC] - Voltar ao menu inicial\n");

            printf("\n\n\n\t-Opção:");

    switch (getch())
    {
    case '1':
        lojas[i_lojas++] = cadastraLoja();
        break;

    case '2':
        for (int n = 0; n < i_lojas; n++)
        {
            imprimeLoja(lojas[n]);
        }
        break;

    case 27:
        return;

    default:
        printf("Opção inválida!\n");
    }

}


int main()
{
    SetConsoleOutputCP((UINT)65001);

    i_clientes = carregarClientesTXT(clientes);
    i_produtos = carregarProdutosTXT(produtos);
    i_estoque = carregarEstoquesTXT(estoques);
    i_lojas = carregarLojasTXT(lojas);

    while (1)
    {
        system("cls");

        printf("========================================================================================================================\n\n");
        printf("\t\t  \t                              MENU\n\n");
        printf("========================================================================================================================\n\n\n");
        
        printf("  [1] - Cliente\n"
               "  [2] - Produto\n"
               "  [3] - Estoque\n"
               "  [4] - Lojas\n"
               "  [ESC] - Sair\n\n\n");

               printf("\t-Opção:");

        switch (getch())
        {
        case '1':

            system("cls");
            opcao1();
            break;

        case '2':
            system("cls");
            opcao2();
            break;

        case '3':

            system("cls");
            opcao3();
            break;

        case '4':

            system("cls");
            opcao4();
            break;

        case 27:

            salvarClienteTXT(clientes, i_clientes);
            salvarEstoqueTXT(estoques, i_estoque);
            salvarProdutoTXT(produtos, i_produtos);
            salvarLojaTXT(lojas, i_lojas);

            return (0);

        default:
            printf("Opção inválida!\n");
        }

        printf("\n\n\n\n");
        system("pause");
    }
}

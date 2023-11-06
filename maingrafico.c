#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "modulos/gestaoDados.h"

struct LoginSenha
{
    char usuario[50];
    char senha[50];
    GtkWidget *usuarioEntry;
    GtkWidget *senhaEntry;
};

int fazerLogin(struct LoginSenha *operador, char *codigoPermissao)
{
    FILE *arquivo = fopen("arquivos/operador.txt", "r");
    struct {
        int codigo;
        char nome[50];
        char usuario[50];
        char senha[50];
        char permissao;
    } ptrOperador;

    while (1)
    {
        if (fscanf(arquivo, "%d{nome:%s , usuario:%s , senha:%s , permissao:%c ;}", &ptrOperador.codigo, &ptrOperador.nome, &ptrOperador.usuario, &ptrOperador.senha, &ptrOperador.permissao) == 5)
        {
            if (strcmp(ptrOperador.usuario, operador->usuario) == 0 && strcmp(ptrOperador.senha, operador->senha) == 0)
            {
                *codigoPermissao = ptrOperador.permissao;
                fclose(arquivo);
                return 1;
            }
        }
        else if (feof(arquivo))
        {
            fclose(arquivo);
            return 0;
        }
    }
}

static void on_button_clicked(GtkWidget *widget, gpointer data)
{
    struct LoginSenha *login = (struct LoginSenha *)data;
    char codigoPermissao;

    const gchar *username = gtk_entry_get_text(GTK_ENTRY(login->usuarioEntry));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(login->senhaEntry));

    strcpy(login->usuario, username);
    strcpy(login->senha, password);

    int resultado = fazerLogin(login, &codigoPermissao);

    if (resultado == 1)
    {
        // Login bem-sucedido, faça o que for necessário aqui
        g_print("Login bem-sucedido. Permissao: %c\n", codigoPermissao);
    }
    else
    {
        // Login falhou, exiba uma mensagem de erro
        g_print("Login falhou\n");
    }
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Login");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    struct LoginSenha login;
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *labelUsuario = gtk_label_new("Usuário:");
    login.usuarioEntry = gtk_entry_new();
    GtkWidget *labelSenha = gtk_label_new("Senha:");
    login.senhaEntry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(login.senhaEntry), FALSE);

    GtkWidget *button = gtk_button_new_with_label("Entrar");

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), &login);

    gtk_grid_attach(GTK_GRID(grid), labelUsuario, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), login.usuarioEntry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), labelSenha, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), login.senhaEntry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);
if (resultado == 1)
{
    // Login bem-sucedido, exiba o menu
    GtkWidget *menuWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(menuWindow), "Menu");
    gtk_container_set_border_width(GTK_CONTAINER(menuWindow), 10);
    gtk_widget_set_size_request(menuWindow, 300, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(menuWindow), grid);

    GtkWidget *button1 = gtk_button_new_with_label("Cadastrar e gerir dados armazenados");
    GtkWidget *button2 = gtk_button_new_with_label("Gerenciar reservas de quartos");
    GtkWidget *button3 = gtk_button_new_with_label("Gerir dados administrativos");
    GtkWidget *button4 = gtk_button_new_with_label("Relatórios do sistema");
    GtkWidget *button5 = gtk_button_new_with_label("Importar/Exportar dados");
    GtkWidget *button6 = gtk_button_new_with_label("Alterar configuração de armazenamento");
    GtkWidget *button7 = gtk_button_new_with_label("Encerrar o programa");
    GtkWidget *button8 = gtk_button_new_with_label("Fazer login");

    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button4, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button5, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button6, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button7, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button8, 0, 7, 1, 1);

    gtk_widget_show_all(menuWindow);
}

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

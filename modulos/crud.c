#include <stdio.h>
#include "crud.h"
//capturar dados;
//trabalhar os dados;
//jogar no arquivo;

void createElement(Categoria estrutura){
    
   
    //Cria um arquivo temporario para escrita
    FILE *arquivo = fopen("categoria.txt","a");
    
    fprintf(arquivo,"%d{quantPessoas :%d,descricao:%s,valor: %.2f}",estrutura.quantPessoas,estrutura.descricao,estrutura.valor);
    
    fclose(arquivo);
    
    printf("Registrado com sucesso!");   
}
void readCategoria (Categoria estrutura){
    
    FILE *arquivo = fopen("categoria.txt","a");
        
    
    
    
    
    
    
    
    fclose(arquivo);
}
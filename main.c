/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ruben
 *
 * Created on 14 de Maio de 2018, 16:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "guitarras.h"


int guitarras(pgui guitarra){
    int opcao;
   
    
    do{
        printf("\n\n 1 - Adicionar Guitarra");
        printf("\n 2 - Historico de alugueres");
        printf("\n 3 - Listar Guitarras");
        printf("\n 4 - Listar Guitarras Alugadas");
        printf("\n 5 - Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: adicionaGuitarra(guitarra);   break;
            case 2: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 3: listarGuitarras(guitarra);   break;
            case 4: puts("COLOCAR CHAMADA A FUNCAO");   break;		  
        }
    }while(opcao!=5);
    return guitarra;
}

void clientes(){
    int opcao;
    do{
        printf("\n\n 1 - Adicionar Cliente");
        printf("\n 2 - Remover cliente");
        printf("\n 3 - Estado do Cliente");
        printf("\n 4 - Clientes Ativos");
        printf("\n 5 - Clientes Banidos");
        printf("\n 6 - Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 2: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 3: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 4: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 5: puts("COLOCAR CHAMADA A FUNCAO");   break;
        }
    }while(opcao!=6);
}

void alugueres(){
        int opcao;
    do{
        printf("\n\n 1 - Criar Aluguer");
        printf("\n 2 - Concluir Aluguer");
        printf("\n 3 - Listar de Alugueres");
        printf("\n 4 - Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 2: puts("COLOCAR CHAMADA A FUNCAO");   break;
            case 3: puts("COLOCAR CHAMADA A FUNCAO");   break;		  
        }
    }while(opcao!=4);
    return;
}

int main(int argc, char** argv) {
   pgui guitarra = NULL;
   
   guitarra = converte(guitarra);
     
    int opcao;
    
    do{
        printf("\n\n1 - Guitarras\n");
        printf("2 - Clientes\n");
        printf("3 - Alugueres\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
                switch(opcao){
                    case 1:
                        guitarras(guitarra);   
                        break;
                    case 2:
                        clientes();   
                        break;
                    case 3:
                        alugueres();   
                        break;
   		}
	}while(opcao!=4);
        
        desconverte(guitarra);
        free(guitarra);
       
    return 0;
}

pgui adicionaGuitarra(pgui guitarra){
    int tam = guitarra[0].numGuitarras;
    tam = tam + 1; // Tamanho do novo array
    guitarra=realloc(guitarra, tam * sizeof(pgui));
    tam = tam - 1; // Posiçao do endereço    
    
        printf("\nID: \n");
        scanf("%d", &guitarra[tam].ID);
        printf("Preco p/Dia: \n");
        scanf("%d", &guitarra[tam].precoDia);
        printf("Valor: \n");
        scanf("%d", &guitarra[tam].valor);
        printf("Estado: \n");
        scanf("%d", &guitarra[tam].estado);
        printf("Nome: \n");
        scanf(" %[^\n]", &guitarra[tam].nome);
   
        guitarra[0].numGuitarras = tam+1;
}


pgui converte(pgui guitarra){  
    FILE *fin;
    int numGuitarras = 1,i;
    char ch;
    
   fin=fopen("Guitarras.txt", "r");
    if(fin==NULL){
        printf("Erro ao abrir o ficheiro texto Guitarras.txt para leitura.\n");
        return guitarra;
    }
       
   while(!feof(fin)) //ler ficheiro ate ao fim e contar n linhas
    {
      ch = fgetc(fin);
      if(ch == '\n')
      {
        numGuitarras++;
      }
    }
   
   printf("%d linhas\n",numGuitarras);
   
    fseek(fin, 0, SEEK_SET);//ponteiro volta ao inicio
    guitarra = malloc(numGuitarras * sizeof(pgui));
   
   
     for(i=0;i<numGuitarras;i++){
     fscanf(fin, "%d %d %d %d %[^\n]", &guitarra[i].ID, &guitarra[i].precoDia, &guitarra[i].valor, &guitarra[i].estado, &guitarra[i].nome);  
     guitarra[i].numGuitarras = numGuitarras;
     }
    
   fclose(fin);
   
    return guitarra;
}

void desconverte(pgui guitarra){
    int numGuitarras,i;
     FILE *fout;
    
    fout=fopen("Guitarras.txt", "w");
        if(fout==NULL){
         printf("Erro ao abrir o ficheiro texto para escrita.\n");
        return ;
    } 
    
    numGuitarras = guitarra[0].numGuitarras;
     
       for(i=0;i<numGuitarras;i++){
     fprintf(fout, "%d %d %d %d %s\n", guitarra[i].ID, guitarra[i].precoDia, guitarra[i].valor, guitarra[i].estado, guitarra[i].nome);  
     }
        
      
        fclose(fout);
        return;
}

 

void listarGuitarras(pgui guitarra){
    
    int i;
    
        
   for(i=0;i<guitarra[0].numGuitarras;i++){
         printf("%d %d %d %d %s\n", guitarra[i].ID, guitarra[i].precoDia, guitarra[i].valor, guitarra[i].estado, guitarra[i].nome);
    }
    

        
 }
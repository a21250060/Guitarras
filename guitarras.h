/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   guitarras.h
 * Author: ruben
 *
 * Created on 14 de Maio de 2018, 17:44
 */

#ifndef GUITARRAS_H
#define GUITARRAS_H

#ifdef __cplusplus
extern "C" {
#endif
// Estrutura para armazenar informacao sobre uma guitarra  
#define MAX 500
typedef struct guitarra gui, *pgui;
struct guitarra{
    int ID;
    int precoDia;
    int valor;
    int estado;
    char nome[MAX];
    int numGuitarras;
};

pgui adicionaGuitarra(pgui guitarra);
void listarGuitarras(pgui guitarra);
pgui converte(pgui guitarra);  
void desconverte(pgui guitarra);

#ifdef __cplusplus
}
#endif

#endif /* GUITARRAS_H */


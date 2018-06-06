/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clientes.h
 * Author: ruben
 *
 * Created on 4 de Junho de 2018, 18:32
 */

#ifndef CLIENTES_H
#define CLIENTES_H
#define MAX 500

typedef struct cliente cli, *pcli;
struct cliente{
    int NIF;
    int NAlugueres;
    char nome[MAX];
    pcli next;
};


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CLIENTES_H */


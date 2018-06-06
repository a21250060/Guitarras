/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aluguer.h
 * Author: ruben
 *
 * Created on 6 de Junho de 2018, 17:07
 */

#ifndef ALUGUER_H
#define ALUGUER_H
#define MAX 500

typedef struct aluguer alug, *palug;
struct aluguer{
    int ID;
    int estado;
    char nome[MAX];
    palug next;
};


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ALUGUER_H */


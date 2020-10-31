#ifndef COD_H
#define COD_H
#include "arch.h"

void codif(string name, int method, int n);
string txt2bin(string texto);
string particion(string binario, int n);
string cod2txt(string part);
void texto2bin_in_char(char *arreglo, char *arreglo2, unsigned long long tam);
void codificar_char(char *arreglo2, char *arreglo3, unsigned long long n, unsigned long long m);
string cod2txt(string cod);
void descodificar_char(char *arreglo2, char *arreglo3, unsigned long long n, unsigned long long tam);
void charbinario2text(char *arreglo2, char *arreglo3, unsigned long long tam);
void codichar(string name);
void charbinario2text2(char *arreglo, char *arreglo3, unsigned long long tam);

#endif // COD_H

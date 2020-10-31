#ifndef CAJERO_H
#define CAJERO_H
#include <arch.h>

void verif_doc(string text, string document);
void guardar_reg(string name, long long cc, int clave, long long cash);
void consulta_saldo(string name, long long cc, int clave);
void mod_dinero(string name, long long cc, int clave, int a);
void leer_registros(string name);
bool verifi_doc2(string name);
#endif // CAJERO_H

#include "arch.h"

void escr_txt(string name, string data)
{
    fstream k(name,fstream::out);
    k<<data;
    //k.write(data.c_str(),data.length());
    k.close();
}
string leer_txt(string name)
{
    long long int tam;
    string data="";
    fstream k(name,fstream::in | fstream::ate );
    if(k.is_open()) {
        tam = k.tellg();
        k.seekg(0);
        for (long long int i=0;i<tam;i++) data.push_back(k.get());
    }
    else cout << "No existe." << endl;
    k.close();
    return data;
}

#include "deco.h"
#include "cod.h"

void decod(string name, int method, int n, int ej)
{
    string texto,encrip,decodificado,binar;
    encrip=leer_txt(name);
    binar=txt2binar(encrip);
    decodificado=parti(binar,n);
    texto=bin2txt(decodificado);
    if (ej==1) {
        cout << "El archivo en binario es:" << endl;
        cout << binar << endl;
        cout << "El archivo decodificado es: " << endl;
        cout << decodificado << endl;
        cout << "El archivo de texto es: " << endl;
        cout << texto << endl;
        cout << endl;
        cout << "Revisar el archivo 'Decodificado.txt'." << endl;
        cout << "Revisar el archivo 'Caracteres_finales.txt'." << endl;
        cout << endl;
    }
    escr_txt("Decodificado.txt",decodificado);
    escr_txt("Caracteres_finales.txt",texto);
}
string txt2binar(string carac)
{
    {
        string binario="";
        for (unsigned long long int i=0;i<carac.length();i++) {
            for (int j=0;j<8;j++) binario.push_back(char((((carac[i]<<j)&(0x80))/128)+48));
        }
        return binario;
    }
}
string parti(string codific, int n)
{
    string partido="",decodificado="";
    int c=0, cero=0, uno=0;
    for (unsigned long long int i=0,k=0;i<codific.length();i++) {
        partido.push_back(codific[i]);
        if ((k+1)*n-1==i) {
            if (k==0) {
                for (cero=0,uno=0,c=0;c<n;c++) {
                    if (partido[c]=='1') decodificado.push_back('0'),cero++;
                    else decodificado.push_back('1'),uno++;
                }
            }
            if (k>0) {
                if (cero==uno) {
                    for (cero=0,uno=0,c=0;c<n;c++) {
                        if (partido[c]=='1') decodificado.push_back('0'),cero++;
                        else decodificado.push_back('1'),uno++;
                    }
                }
                else if (cero>uno) {
                    for (cero=0,uno=0,c=1;c<=n;c++) {
                        if (c%2==0) {
                            if (partido[c-1]=='1') decodificado.push_back('0'),cero++;
                            else decodificado.push_back('1'),uno++;
                        }
                        else {
                            if (partido[c-1]=='1') decodificado.push_back('1'),uno++;
                            else decodificado.push_back('0'),cero++;
                        }
                    }
                }

                else if (cero<uno) {
                    for (cero=0,uno=0,c=1;c<=n;c++) {
                        if (c%3==0) {
                            if (partido[c-1]=='1') decodificado.push_back('0'),cero++;
                            else decodificado.push_back('1'),uno++;
                        }
                        else {
                            if (partido[c-1]=='1') decodificado.push_back('1'),uno++;
                            else decodificado.push_back('0'),cero++;
                        }
                    }
                }
            }
            partido.clear();
            k++;
        }
    }
    int no=partido.length();
    if (cero==uno) {
        for (cero=0,uno=0,c=0;c<no;c++) {
            if (partido[c]=='1') decodificado.push_back('0');
            else decodificado.push_back('1');
        }
    }
    else if (cero>uno) {
        for (cero=0,uno=0,c=1;c<=no;c++) {
            if (c%2==0) {
                if (partido[c-1]=='1') decodificado.push_back('0');
                else decodificado.push_back('1');
            }
            else decodificado.push_back(partido[c-1]);
        }
    }
    else if (cero<uno) {
        for (cero=0,uno=0,c=1;c<=no;c++) {
            if (c%3==0) {
                if (partido[c-1]=='1') decodificado.push_back('0');
                else decodificado.push_back('1');
            }
            else decodificado.push_back(partido[c-1]);
        }
    }
    return decodificado;
}

string bin2txt(string deco)
{
    string partido,n_text="";
    int sum=0,num=0,pot=0,c=0;
    for (unsigned long long int i=0,k=0;i<deco.length();i++) {
        partido.push_back(deco[i]);
        if ((k+1)*8-1==i) {
            for (num=0,sum=0,pot=7,c=0;c<8;c++,pot--) {
                num=(int(partido[c])-48)*(pow(2,pot));
                sum+=num;
            }
            n_text.push_back(char(sum));
            partido.clear();
            k++;
        }
    }
    return n_text;
}


void decochar(string name){
    string file;
    //cout <<"Ingrese nombre con extension del archivo a decodificar: ";
    //cin >> name;
    unsigned long long tam;
    file=leer_txt(name);
    tam=file.length();
    char *arreglo = new char [tam];
    char *arreglo2 = new char [tam*8];
    char *arreglo3 = new char [tam*8];

    for(unsigned long long i=0;i<tam;i++){
        arreglo[i]=file[i];
    }
    texto2bin_in_char(arreglo, arreglo2, tam); cout<<endl;
    //cout<< "Ingrese la semilla: ";
    int n;  //cin >>n;
    n=4;
    cout<<endl;
    descodificar_char(arreglo2, arreglo3, n, tam); cout<<endl;
    charbinario2text2(arreglo, arreglo3, tam); cout<<endl;
    //cout<<"Ingrese nombre y extension para guardar el archivo: "; cin>>name;
    name="sudo.txt";
    cout<<endl;
    //cout<<"Archivo correctamente guardado!!"<<endl;
    cout<<endl;
    ofstream guardar2;
    guardar2.open(name, ios::out);
    guardar2 << arreglo;
    guardar2.close();

    delete [] arreglo;
    delete [] arreglo2;
    delete [] arreglo3;
}

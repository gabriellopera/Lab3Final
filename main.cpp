#include "cod.h"
#include "deco.h"
#include "cajero.h"

int main()
{
    int elec=0;
    while (true) {
        cout<<endl;
        cout<<"Bienvenido!"<<endl;
        cout << "1. Codificar y decodificar archivos" << endl;
        cout << "2. Cajero" << endl; cout<<endl;
        cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
        switch (elec) {
        case 1:{
            cout<<"Desea trabajar con el metodo 1 o 2?: ";
            cin >> elec; cout<<endl;
            switch (elec) {
            case 1:{
                    cout<<"1. Si desea codificar";
                    cout<<endl;
                    cout<<"2. Si desea decodificar"<<endl; cout<<endl;
                    cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
                    switch (elec) {
                    case 1:{
                        string nombre="M1S6.dat", tex, nom_cod;
                        //cout << "Ingrese nombre del archivo con (.dat): "; cin >> nombre;
                        int metodo, n;
                        cout << "Ingrese el metodo de codificacion deseado y la semilla n: " << endl;
                        cin >> metodo >> n;
                        codif(nombre,metodo,n);
                        cout << endl;
                        }
                        break;

                    case 2:{
                        int metodo, n;
                        string arch_cod="Encriptado.txt";
                        //cout << "Ingrese nombre del archivo a decodificar: "; cin >> arch_cod;
                        cout << "Ingrese el metodo de decodificacion deseado y la semilla n: " << endl;
                        cin >> metodo >> n;
                        decod(arch_cod,metodo,n, elec);
                        }
                        break;
                    }
              }break;
            case 2:{
                cout<<"1. Si desea codificar";
                cout<<endl;
                cout<<"2. Si desea decodificar"<<endl; cout<<endl;
                cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
                switch (elec) {

                case 1:{
                    string name, file;
                    cout <<"Ingrese nombre con extension del archivo a codificar: ";
                    cin >> name; cout<<endl;
                    unsigned long long tam;
                    file=leer_txt(name);
                    tam=file.length();
                    char *arreglo = new char [tam];
                    char *arreglo2 = new char [tam*8];
                    char *arreglo3 = new char [tam*8];

                    for(unsigned long long i=0;i<tam;i++){   arreglo[i]=file[i];}

                    texto2bin_in_char(arreglo, arreglo2, tam);cout<<endl;
                    cout<< "Ingrese la semilla: ";
                    int n;  cin >>n; cout<<endl;
                    codificar_char(arreglo2, arreglo3, n, tam); cout<<endl;
                    charbinario2text(arreglo, arreglo3, tam);
                    cout<<"Ingrese nombre y extension para guardar el archivo: "; cin >> name; cout<<endl;
                    ofstream guardar;
                    guardar.open(name, ios::binary);
                    guardar << arreglo;
                    guardar.close();

                    delete [] arreglo;
                    delete [] arreglo2;
                    delete [] arreglo3;

                    break;
                }

                case 2:{
                    string name, file;
                    cout <<"Ingrese nombre con extension del archivo a decodificar: ";
                    cin >> name;
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
                    cout<< "Ingrese la semilla: ";
                    int n;  cin >>n; cout<<endl;
                    descodificar_char(arreglo2, arreglo3, n, tam); cout<<endl;
                    charbinario2text(arreglo, arreglo3, tam); cout<<endl;
                    cout<<"Ingrese nombre y extension para guardar el archivo: "; cin>>name; cout<<endl;
                    cout<<"Archivo correctamente guardado!!"<<endl; cout<<endl;
                    ofstream guardar2;
                    guardar2.open(name, ios::out);
                    guardar2 << arreglo;
                    guardar2.close();

                    delete [] arreglo;
                    delete [] arreglo2;
                    delete [] arreglo3;
                    }
                    break;


                }

            }


            }
            }
            break;

            case 2:{
                cout << "Bienvenido al cajero" << endl;
                int n=4,metodo=0,a=0,opcion=0;
                string encrip="Encriptado.txt",todo_doc,doc;
                decod(encrip,metodo,n,elec);
                todo_doc="sudo.txt";
                while (true) {
                cout << "1. Administrador" << endl;
                cout << "2. Usuario de sistema" << endl;
                cout << "Ingrese el rol a emplear: "; cin >> a; cout << endl;

                    switch (a) {
                    case 1:{
                        //cout << "Ingrese documento de identificacion: "; cin >> doc;
                        //verif_doc(todo_doc,doc);
                        if(verifi_doc2("sudo.txt")==true){
                        cout << endl; cout << "Bienvenido!" << endl; cout << endl;
                        cout << "1. Guardar Registro" << endl;
                        cout << "2. Leer Registros" << endl;
                        cout << endl;
                        cout << "Ingrese una opcion: "; cin >> opcion;
                        switch (opcion) {

                        case 1:{
                            string name="sudo.txt"; long long cc, cash; int clave;
                            cout<<"Ingrese nuevo documento de identificacion: "; cin>>cc;
                            cout<<"Ingrese nueva clave: "; cin>>clave;
                            cout<<"Ingrese el dinero: "; cin>> cash; cout << endl;
                            guardar_reg(name, cc, clave, cash);
                            cout<<"Registro exitoso!";cout << endl;

                        }break;
                        case 2:{
                            string name="sudo.txt";
                            leer_registros(name); cout<<endl;
                            break;

                        }

                        }
                        }
                        else{cout << endl; cout<<"Documento o clave incorrecta"<<endl; cout << endl; break;}

                    }
                    break;

                    case 2:{
                        cout << endl;
                        cout << "1. Consultar saldo" << endl;
                        cout << "2. Retirar dinero" << endl;
                        cout << "Ingrese una opcion: "; cin >> opcion; cout << endl;
                        switch (opcion) {

                        case 1:{
                            //string name="sudo.dat";
                            long long cc; int clave, a;
                            //decochar(name);
                            string name="sudo.txt";
                            cout<<"El Costo de esta transaccion es de $1000. ¿Desea continuar?"<<endl;
                            cout<<"1. Si"<<endl;
                            cout<<"2. No"<<endl; cout<<endl;
                            cout<<"Ingrese opcion: "; cin >> a; cout<<endl;
                            if(a==1){
                                cout<<"Ingrese documento de identificacion : "; cin>>cc;
                                cout<<"Ingrese clave: "; cin>>clave; cout << endl;
                                mod_dinero(name, cc, clave, 2);
                                //consulta_saldo(name, cc, clave); cout << endl;
                                cout<<"¡Hasta la proxima!"<<endl; cout << endl;
                            }
                            else{cout<<"¡Hasta la proxima!"<<endl; cout << endl;}
                        //codichar("sudo.txt");
                        break;
                        }

                        case 2:{
                            string name="sudo.txt"; long long cc; int clave;
                            cout<<"Ingrese documento de identificacion : "; cin>>cc;
                            cout<<"Ingrese clave: "; cin>>clave; cout << endl;
                            mod_dinero(name, cc, clave, 1); cout<<endl;
                            cout<<"¡Hasta la proxima!"<<endl; cout << endl;
                            break;


                        }

                        }
                    }
                    break;

                    default:{
                        cout << "Debe ingresar 1 o 2" << endl;
                    }
                    }
                }
            }
        break;

        default:{
            cout << "Ingrese 1 o 2:";
        }
        }
    }
}


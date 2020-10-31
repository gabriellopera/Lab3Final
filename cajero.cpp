#include "cajero.h"

void verif_doc(string text, string document)
{
    bool act=true,cl=false;
    while (act==true) {
        string partido="",clave;
        bool ban=false;
        for (unsigned long long int i=0, cop_i=0;i<text.length() && ban==false;i++) {
            if (text[i]==' ' || text[i]=='\n') {
                partido.clear();
            }
            else {
                partido.push_back(text[i]);
                if (partido.length()==10) {
                    if (partido==document) {
                        i+=2;
                        cop_i=i;
                        while (cl==false) {
                            cout << "Ingrese su clave: "; cin >> clave;
                            for (partido="";text[i]!=' ';i++) {
                                partido.push_back(text[i]);
                            }
                            if (partido==clave) {
                                cout << "Clave correcta." << endl;
                                cl=true;
                            }
                            else {
                                cout << "Clave incorrecta." << endl;
                                i=cop_i;
                            }
                        }
                        ban=true;
                    }
                    partido.clear();
                }
            }
        }
        if (ban==false) {
            cout << "Documento no encontrado." << endl;
            cout << "Ingrese nuevamente su documento: "; cin >> document;
        }
        else {
            act=false;
        }
    }

}



void guardar_reg(string name, long long cc, int clave, long long cash){
    ofstream guardar;
    guardar.open(name, ios::app);
    guardar<< cc << " " << clave << " " << cash <<endl;
    guardar.close();
}

void consulta_saldo(string name, long long cc, int clave){
    long long ced, cash;
    int pass; bool encontrado = false;
    ifstream leer;
    leer.open(name, ios::in);
    leer>>ced;
    while(!leer.eof()){
        leer>>pass;
        if(ced==cc && pass==clave){
            encontrado = true;
            leer>> cash;
            cout <<"Su saldo actual es: "<<cash<<endl;
        }
        leer>> cash;
        leer>>ced;
    }
    if(!encontrado){
        cout<<"Cedula o contrasenia incorrecta"<<endl;
    }
    leer.close();
}


void mod_dinero(string name, long long cc, int clave, int a){

    ifstream leer; ofstream temp;
    long long ced, cash, cash2;
    int pass; bool encontrado = false;
    leer.open(name);
    temp.open("temp.txt");
    leer>>ced;
    if(a==1){
        while(!leer.eof()){
            leer>>pass;
            leer>>cash;
            if(ced==cc && pass==clave){
                encontrado=true;
                cout<<"Ingrese el monto que desea retirar: "; cin>> cash2; cout<<endl;
                if(cash2>cash){cout<<"Saldo insuficiente"<<endl; temp.close(); leer.close(); break;}
                temp<< ced << " " << pass << " " << (cash-cash2)<<endl;
                cout<<"Retiro de forma exitosa!"<<endl; cout <<endl;
                cout<<"Costo transaccion: "<<"$0"<<endl;
                cout<<"Monto retirado: "<<"$"<<cash2<<endl;
                cout<<"Nuevo saldo: "<<"$"<<(cash-cash2)<<endl;
            }
            else{temp<< ced << " " << pass << " " << cash<<endl;
            }
            leer>>ced;
        }
        if(!encontrado){cout<<"Cedula o contrasenia incorrecta"<<endl;}
    }
    else if(a==2){
        while(!leer.eof()){
            leer>>pass;
            leer>>cash;
            if(ced==cc && pass==clave){
                encontrado=true;
                cash2=1000;
                if(cash2>cash){cout<<"Saldo insuficiente"<<endl;  temp.close(); leer.close(); break;}
                temp<< ced << " " << pass << " " << (cash-cash2)<<endl;
                cout<<"Su saldo actual es: "<< "$" <<(cash-cash2)<<endl;
            }
            else{temp<< ced << " " << pass << " " << cash<<endl;
            }
            leer>>ced;
        }
        if(!encontrado){cout<<"Cedula o contrasenia incorrecta"<<endl;}

    }

    leer.close();
    temp.close();
    remove("sudo.txt");
    rename("temp.txt","sudo.txt");
}


void leer_registros(string name){
    long long ced, cash;
    int pass; bool encontrado = false;
    ifstream leer;
    leer.open(name);
    leer>>ced;
    while (!leer.eof()) {
        leer>>pass;
        leer>> cash;
        cout<<"Cedula: "<< ced<<endl;
        cout<<"Clave: "<< pass<<endl;
        cout<<"Saldo: $"<< cash<<endl;
        cout<<endl;
        leer>>ced;
    }
}


bool verifi_doc2(string name){
    long long cc; int clave;
    cout<<"Ingrese documento de identificacion: "; cin>>cc;
    cout<<"Ingrese clave: "; cin>>clave;
    long long ced, cash;
    int pass; bool encontrado = false;
    ifstream leer;
    leer.open(name, ios::in);
    leer>>ced;
    while(!leer.eof()){
        leer>>pass;
        leer>> cash;
        if(ced==cc && pass==clave){
            encontrado = true;
        }
        leer>>ced;
    }
    leer.close();

    return encontrado;
}














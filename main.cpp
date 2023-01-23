#include <iostream>
#include <fstream>

#define FILE_NAME "auto.csv"

using namespace std;

struct s_auto
{
    string categoria, marca, modello, colore, lun, mar, mer, gio, ven, sab, dom;
};

int conta_record();
void c_a_auto(s_auto *ptr_vet_auto);
void carica_vet(s_auto *ptr_vet_auto);
void leggi();
void riempi_con_vet(s_auto *ptr_vet_auto, int k);

void menu()
{
    s_auto vet_auto[2000];
    s_auto *ptr_vet_auto=vet_auto;

    int scelta;
    do{
        cout<<endl<<"-=====- MENU -=====-"<<endl
        <<"1 - Cerca e affitta auto"<<endl
        <<"2 - Stampa file"<<endl
        <<"3 - Uscita"
        <<endl<<">>";
        cin>>scelta;

        switch(scelta)
        {
            case 1:
                c_a_auto(ptr_vet_auto);
                break;
            case 2:
                leggi();
                break;
            case 3:
                cout<<"\nPROGRAMMA TERMINATO";
        }
    }while(scelta!=3);
}

int main()
{
    menu();
    return 0;
}

void c_a_auto(s_auto *ptr_vet_auto)
{
    int n_righe=conta_record(), i=0, trov[n_righe];
    carica_vet(ptr_vet_auto);

    string key;
    do
    {
        cout<<"\nQuale categoria di auto vuoi affittare? (utilitaria / lusso / sportiva / furgone)\n>> ";
        cin>>key;
        for(int j=0; j<n_righe; j++)
        {
            if(key==(ptr_vet_auto+j)->categoria)
            {
                trov[i]=j;
                i++;
            }
        }
    }while(i==0);


    cout<<"\nLa categoria "<<key<<" mette a disposizione : \n";
    for(int j=0; j<i; j++)
    {
        cout<<endl<<j+1<<")";
        cout<<(ptr_vet_auto+trov[j])->marca;
        cout<<(ptr_vet_auto+trov[j])->modello<<", colore";
        cout<<(ptr_vet_auto+trov[j])->colore;
        cout<<"\n\tDISPONIBILITA` : ";
        if((ptr_vet_auto+trov[j])->lun==" L")
            cout<<"Lunedi`(1) ";
        if((ptr_vet_auto+trov[j])->mar==" L")
            cout<<"Martedi`(2) ";
        if((ptr_vet_auto+trov[j])->mer==" L")
            cout<<"Mercoledi`(3) ";
        if((ptr_vet_auto+trov[j])->gio==" L")
            cout<<"Giovedi`(4) ";
        if((ptr_vet_auto+trov[j])->ven==" L")
            cout<<"Venerdi`(5) ";
        if((ptr_vet_auto+trov[j])->sab==" L")
            cout<<"Sabato(6) ";
        if((ptr_vet_auto+trov[j])->dom==" L")
            cout<<"Domenica(7)";
        cout<<endl;
    }

    int k1,k2;
    cout<<"\n\tInserisci numero DELL'AUTO che si desidera affittare\n\t>> ";
    cin>>k1;
    cout<<"\n\tInserisci numero DEI GIORNI che si desidera affittare [uscita(8)]\n";
    do
    {
        cout<<"\t>> ";
        cin>>k2;
        switch (k2)
        {
            case 1:
                (ptr_vet_auto+trov[k1-1])->lun=" A";
                break;
            case 2:
                (ptr_vet_auto+trov[k1-1])->mar=" A";
                break;
            case 3:
                (ptr_vet_auto+trov[k1-1])->mer=" A";
                break;
            case 4:
                (ptr_vet_auto+trov[k1-1])->gio=" A";
                break;
            case 5:
                (ptr_vet_auto+trov[k1-1])->ven=" A";
                break;
            case 6:
                (ptr_vet_auto+trov[k1-1])->sab=" A";
                break;
            case 7:
                (ptr_vet_auto+trov[k1-1])->dom=" A";
                break;
            case 8:
                break;
            default:
                cout<<"SCELTA SBAGLIATA\n";
                break;
        }
    }while(k2!=8);
    riempi_con_vet(ptr_vet_auto, n_righe);
}

int conta_record()
{
    int i=0;
    string appoggio;

    fstream fin;
    fin.open(FILE_NAME,ios::in);

    while(getline(fin,appoggio))
        (i++);

    fin.close();
    return i;
}

void carica_vet(s_auto *ptr_vet_auto)
{
    ifstream fin(FILE_NAME);

    string appoggio;

    int j=0;

    while(!fin.eof())
    {
        getline(fin,(ptr_vet_auto+j)->categoria,',');
        getline(fin,(ptr_vet_auto+j)->marca,',');
        getline(fin,(ptr_vet_auto+j)->modello,',');
        getline(fin,(ptr_vet_auto+j)->colore,',');
        getline(fin,(ptr_vet_auto+j)->lun,',');
        getline(fin,(ptr_vet_auto+j)->mar,',');
        getline(fin,(ptr_vet_auto+j)->mer,',');
        getline(fin,(ptr_vet_auto+j)->gio,',');
        getline(fin,(ptr_vet_auto+j)->ven,',');
        getline(fin,(ptr_vet_auto+j)->sab,',');
        getline(fin,(ptr_vet_auto+j)->dom);

        j++;
    }

    fin.close();
}

void riempi_con_vet(s_auto *ptr_vet_auto, int k)
{
    ofstream fout(FILE_NAME);

    for(int i=0;i<k-1;i++)
        fout<<(ptr_vet_auto+i)->categoria
        <<','<<(ptr_vet_auto+i)->marca
        <<','<<(ptr_vet_auto+i)->modello
        <<','<<(ptr_vet_auto+i)->colore
        <<','<<(ptr_vet_auto+i)->lun
        <<','<<(ptr_vet_auto+i)->mar
        <<','<<(ptr_vet_auto+i)->mer
        <<','<<(ptr_vet_auto+i)->gio
        <<','<<(ptr_vet_auto+i)->ven
        <<','<<(ptr_vet_auto+i)->sab
        <<','<<(ptr_vet_auto+i)->dom<<endl;

    fout<<(ptr_vet_auto+k-1)->categoria
    <<','<<(ptr_vet_auto+k-1)->marca
    <<','<<(ptr_vet_auto+k-1)->modello
    <<','<<(ptr_vet_auto+k-1)->colore
    <<','<<(ptr_vet_auto+k-1)->lun
    <<','<<(ptr_vet_auto+k-1)->mar
    <<','<<(ptr_vet_auto+k-1)->mer
    <<','<<(ptr_vet_auto+k-1)->gio
    <<','<<(ptr_vet_auto+k-1)->ven
    <<','<<(ptr_vet_auto+k-1)->sab
    <<','<<(ptr_vet_auto+k-1)->dom;

    fout.close();
}

void leggi()
{
    ifstream fin(FILE_NAME);

    string appoggio;
    cout<<endl;

    while(!fin.eof())
    {
        getline(fin,appoggio);
        cout<<appoggio<<endl;
    }

    fin.close();
}

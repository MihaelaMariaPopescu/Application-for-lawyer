#include <iostream>
#include <vector>
using namespace std;

class Avocat
{
    int COD;
    string NUME;
    int NR_PROCESE;
    int *VECTOR_PROCESE;
public:
    //default constructor
    Avocat()=default;

    //constructor initializare
    Avocat(int cod, string nume,int nr, int *vector_procese)
    {
        COD=cod;
        NUME=nume;
        NR_PROCESE=nr;
        VECTOR_PROCESE=vector_procese;
    }

    //constructor copiere
    Avocat(const Avocat &av)
    {
        COD=av.COD;
        NUME=av.NUME;
        NR_PROCESE=av.NR_PROCESE;
        VECTOR_PROCESE=av.VECTOR_PROCESE;
    }

    //destructor
    virtual ~Avocat()
    {
        delete VECTOR_PROCESE;
    }

//setteri si getteri
    void setcod(int cod)
    {
        COD=cod;
    }

    void setnume(string nume)
    {
        NUME=nume;
    }

    void setnr(int nr)
    {
        NR_PROCESE=nr;
    }

    void setprocese(int *vector_procese)
    {
        VECTOR_PROCESE=vector_procese;
    }

    int getcod()
    {
        return COD;
    }

    string getnume()
    {
        return NUME;
    }

    int getnr()
    {
        return NR_PROCESE;
    }

    int getprocese()
    {
        return *VECTOR_PROCESE;
    }

    void afisare(std::ostream& out) const
    {
        out<<NUME;
        out<<COD;
        out<<NR_PROCESE;
        for (int i=0; i<NR_PROCESE; i++)
            out<<VECTOR_PROCESE[i];

    }

    friend istream &operator >>(istream &in, Avocat &a)
    {
        in>>a.COD;
        in>>a.NUME;
        in>>a.NR_PROCESE;
        for (int i=0; i<a.NR_PROCESE; i++)
            in>>a.VECTOR_PROCESE[i];
        return in;
    }

    friend ostream &operator << (ostream &out, Avocat &a)
    {
        a.afisare(out);
        return out;
    }

     Avocat &operator=(const Avocat &av)
    {
        this->COD=av.COD;
        this->NUME=av.NUME;
        this->NR_PROCESE=av.NR_PROCESE;
        this->VECTOR_PROCESE=av.VECTOR_PROCESE;

    }
};


void vect(vector <Avocat>& newvect)
{
    int n,cod,nr,vp[1000];
    string nume;
    cout<<"Cati avocati doriti sa avem? ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cout<<"Introduceti codul avocatului: "<<endl;
        cin>>cod;
        cout<<"Introduceti numele avocatului: "<<endl;
        cin>>nume;
        cout<<"Introduceti numarul de procese al avocatului: "<<endl;
        cin>>nr;
        cout<<"Introduceti vectorul de procese al avocatului: "<<endl;
        for(int j=0; j<nr; j++)
            cin>>vp[j];

        Avocat newavocat(cod,nume,nr,vp);
        newvect.push_back(newavocat);
    }
    cout<<"Vector creat cu succes!"<<endl;
}

void sortare(vector <Avocat>&newvect)
{
    int ok=0,size=newvect.size();
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
        {
            if(newvect[i].getnr()>newvect[j].getnr())
                swap(newvect[i],newvect[j]), ok=1;
        }
}

void printVector( vector<Avocat>& newvect)
{
    int size=newvect.size();

    for( int i=0; i<size; i++)
    {
        cout<<"Cod avocat: "<<newvect[i].getcod()<<endl;
        cout<<"Nume avocat: "<<newvect[i].getnume()<<endl;
        cout<<"Nr procese: "<<newvect[i].getnr()<<endl;
    }
    cout<<"press any letter to exit program"<<endl;
}




class Avocat_Oficiu: public Avocat
{
    string NUME_CLIENT;
    int DURATA;
    static int nrclienti;
public:

    //default constr
    Avocat_Oficiu()=default;

    //constructor initializare
    Avocat_Oficiu(int cod, string nume,int nr, int *vector_procese,string nume_client,int durata)
    :Avocat(cod,nume,nr,vector_procese)

    {
        NUME_CLIENT=nume_client;
        DURATA=durata;
        clienti();
    }

    //constructor copiere
    Avocat_Oficiu(const Avocat_Oficiu &av)
    {
        NUME_CLIENT=av.NUME_CLIENT;
        DURATA=av.DURATA;
    }

    //destructor
    virtual ~Avocat_Oficiu()
    {
        NUME_CLIENT=' ';
        DURATA=0;
    };

    //setteri si getteri

    void setnumeclient(string nume)
    {
        NUME_CLIENT=nume;
    }

    void setdurata(int durata)
    {
        DURATA=durata;
    }

    string getnumeclient()
    {
        return NUME_CLIENT;
    }

    int getdurata()
    {
        return DURATA;
    }

    void printare(std::ostream& out) const
    {
        out<<NUME_CLIENT;
        out<<DURATA;


    }

    friend istream &operator>>(istream &in, Avocat_Oficiu &a)
    {
        in>>a.NUME_CLIENT;
        in>>a.DURATA;
        return in;
    }
    friend ostream &operator<<(ostream &out, Avocat_Oficiu &a)
    {
        a.printare(out);
        return out;

    }

     Avocat_Oficiu &operator=(const Avocat_Oficiu &av)
    {
        this->NUME_CLIENT=av.NUME_CLIENT;
        this->DURATA=av.DURATA;
    }

    bool operator>(const Avocat_Oficiu &a)
    {
        if(DURATA>a.DURATA)
            return 1;
        else return 0;
    }

    bool operator<(const Avocat_Oficiu &a)
    {
        if(DURATA<a.DURATA)
            return 1;
        else return 0;
    }

    static void clienti(){
        nrclienti++;
    }

     static int getnrclienti(){
    return nrclienti;
    }

};

int Avocat_Oficiu::nrclienti=0;


void vectoroficiu(vector<Avocat_Oficiu>&vo)
{
    int cod,nr,vp[1000];
    int durata;
    string name,nume;

    cout<<"Introduceti numarul de avocati din oficiu: "<<endl;
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cout<<"Introduceti codul avocatului: "<<endl;
        cin>>cod;
        cout<<"Introduceti numele avocatului: "<<endl;
        cin>>nume;
        cout<<"Introduceti numarul de procese al avocatului: "<<endl;
        cin>>nr;
        cout<<"Introduceti vectorul de procese al avocatului: "<<endl;
        for(int j=0; j<nr; j++)
            cin>>vp[j];

        cout<<"Introduceti numele clientului: "<<endl;
        cin>>name;
        cout<<"Introduceti timpul petrecut cu clientul: "<<endl;
        cin>>durata;

        Avocat_Oficiu newav(cod,nume,nr,vp,name,durata);
        vo.push_back(newav);
        cout<<"Numarul de clienti este: "<<Avocat_Oficiu::getnrclienti()<<endl;
    }
    cout<<"Vector creat cu succes!"<<endl;
}
void tmax(vector <Avocat_Oficiu> &vo)
{
    int k=0,maxi=0;
    int size=vo.size();
    for( int i=0; i<size; i++)
    {
        if(vo[i].getdurata()>maxi)
            {maxi=vo[i].getdurata();
            k=i;}
    }


    string nume=vo[k].getnumeclient();
    cout<<"Avocatul care a petrecut timpul maxim cu un client este: ";
    cout<< nume;
    cout<<endl;
    cout<<"press any letter to exit program"<<endl;
}


int main()
{

    cout<<"Sortare dupa nr procese sau timpul maxim petrecut cu un client? S/T"<<endl;
    char operatie;
    vector <Avocat> vector_avocati;
    vector <Avocat_Oficiu>va_oficiu;

    while(cin>>operatie)
{
    if(operatie=='S')
    {
         vect(vector_avocati);
    sortare(vector_avocati);
    printVector(vector_avocati);

    }
    else
        if(operatie=='T')
    {
        vectoroficiu(va_oficiu);
    tmax(va_oficiu);
    }
    else
    {
        break;
    }
}


    return 0;
}

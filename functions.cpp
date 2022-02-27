#include "functions.h"

void ivedimas(vector<student> &A, int i)
{
    cout << "Iveskite studento varda: "; cin >> A[i].vardas;
    cout << "Iveskite studento pavarde: "; cin >> A[i].pavarde;
}

void pazymiai(vector<student> &A, int i)
{
    int temp;
    while(temp!=-1)
    {
    paznd:
        cout << "Iveskite " << A[i].sk+1 <<  " -a(-i) pazymi (arba -1 jei norite stabdyti ivedima): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto paznd; }
        if(!((temp>=-1)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto paznd;}
        if(temp==-1) break;
            else{
                A[i].nd.push_back(temp);
                A[i].sk++;
                A[i].sum+=temp;
            }
    }
    egzp:
        cout << "Veskite egzamino iverti (nuo 0 iki 10): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto egzp; }
        if(!((temp>=0)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto egzp;}
        else A[i].egz=temp;
}

void generuoti(vector<student> &A, int i)
{
    int kiek;
    int temp;
Genopt:
    cout << "Kiek pazymiu sugeneruoti mokiniui? (Nuo 0 iki 500): ";
    cin >> kiek;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Genopt; }
    if(!((kiek>=0)&&(kiek<=500))) {cout << "Reiksme turi buti tarp 0 ir 500\n"; goto Genopt;}
    srand((unsigned) time(NULL));
    A[i].sk=kiek;
    cout << "Sugeneruoti pazymiai:\n";
    for(int j=0; j<kiek; j++)
    {
        temp=rand()%11;
        A[i].nd.push_back(temp);
        A[i].sum+=temp;
        cout << temp << " ";
    }
    cout << endl;
    temp=rand()%11;
    A[i].egz=temp;
}

void rastiMediana(vector<student> &A, int i)
{
    sort(A[i].nd.begin(), A[i].nd.end());
    if(A[i].sk%2!=0)
    {
        A[i].med=(double)A[i].nd[A[i].sk/2];
    }
    else A[i].med=(double)(A[i].nd[(A[i].sk-1)/2] + A[i].nd[A[i].sk/2])/2.0;
}

void rastiVidurki(vector<student> &A, int i)
{
    A[i].vid=(double)A[i].sum/(double)A[i].sk;
}

void header()
{
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << setw(5) << left << "Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
}

void spausdinimas(vector<student> &A, int i)
{
    A[i].galV=0.4*A[i].vid+0.6*A[i].egz;
    A[i].galM=0.4*A[i].med+0.6*A[i].egz;
    cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].galV << setw(5) << left << A[i].galM << endl;
}

void rikiavimas(vector<student> &A, int &num)
{
    for(int i=0; i<num-1; i++)
        for(int j=i+1; j<num; j++)
        if(A[i].pavarde> A[j].pavarde)
            std::swap(A[i], A[j]);
}

void skaitymas (vector<student> &A, int &num, std::ifstream& in)
{
    int j=0, egz=0;
    string temp, eil, vardas, pavarde;
    while(std::getline(in, eil))
    {
        A.push_back(student());
        std::istringstream line(eil);
        line >> vardas >> pavarde;
        A[num].vardas=vardas;
        A[num].pavarde=pavarde;
        num++;

        while(line >> temp)
        {
            int paz = std::stoi(temp);
            if(paz>=0 && paz<=10)
            {
                A[j].nd.push_back(paz);
                A[j].sum+=paz;
                A[j].sk++;
            }
        }
    line.end;
    A[j].egz=A[j].nd[A[j].sk-1];
    A[j].nd[A[j].sk-1]=0;
    A[j].sum-=A[j].egz;
    A[j].sk--;
    j++;
    }
}
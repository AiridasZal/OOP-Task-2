#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::left;
using std::fixed;
using std::setw;
using std::setprecision;
using std::vector;

struct student
{
    string vardas="", pavarde="";
    vector<int> nd;
    int egz=0;
    double med=0;
    double vid=0;
    int sum=0;
    int sk=0;
    double galV=0;
    double galM=0;
};

void ivedimas(vector<student> &A, int i);
void pazymiai(vector<student> &A, int i);
void rastiMediana(vector<student> &A, int i);
void rastiVidurki(vector<student> &A, int i);

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

int main()
{
    vector<student> A;
    int num=0;
    int inp, gen;
Ivestis:
    cout << "Ivesti duomenis ranka (0) ar skaityti is failo (1): ";
    cin >> inp;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Ivestis; }
    if(inp==0)
    {
        A.push_back(student());
        ivedimas(A, num);
        Generavimas:
        cout << "Pazymius ivesti ranka - (0). Pazymius generuoti atsitiktinai - (1): ";
        cin >> gen;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Generavimas; }
        if(gen==0)
        {
            pazymiai(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(gen==1)
        {
//            generuoti(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(!((gen>=0)&&(gen<=1))) goto Generavimas;
        num++;

    }
    if(inp==1)
    {

    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

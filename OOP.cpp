#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct node
{
    string vardas="", pavarde="";
    int paz[500] = {0}, egz=0, pazsk=0;
    double rezult=0;
    node* next;
};

void duom(node *&t)
{
    int temp=1;
    int choice;
    cout << "Iveskite varda: ";
    cin >> t->vardas;
    cout << "Iveskite pavarde: ";
    cin >> t->pavarde;
    Rand:
    cout << "Ar mokinio balus generuoti atsitiktinai? (0 - Ne, 1 - Taip): ";
    cin >> choice;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Rand; }
    if(choice==0)
    {
        while(temp!=-1) {
        PAZ1:
        cout << "Iveskite " << t->pazsk+1 << " -a(-i) pazymi (arba -1 jei norite stabdyti ivedima): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto PAZ1; }
        if(!((temp>=-1)&&(temp<=10))) goto PAZ1;
        if(temp==-1) break;
            else{
                t->paz[t->pazsk]=temp;
                t->pazsk++;
            }
        }
        PAZ2:
        cout << "Veskite egzamino iverti (nuo 0 iki 10): ";
        cin >> t->egz;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto PAZ2; }
        if(!((t->egz>=0)&&(t->egz<=10))) {cout << "Reiksme turi buti tarp 0 ir 10" << endl; goto PAZ2;}

    }
    if(choice==1)
    {
        Gen:
        cout << "Kiek pazymiu sugeneruoti mokiniui? (Nuo 0 iki 500): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Gen; }
        if(!((temp>=0)&&(temp<=500))) goto Gen;
        for(int i=0; i<temp; i++)
            t->paz[i]=rand()%11;
        t->egz=rand()%11;
    }
    else if(!(choice>=0&&choice<=1)) goto Rand;
}

void input(node *&root)
{
    if (root)
    {
        node *t = root;
        while (t->next) t = t->next;
        t->next = new node;
        t = t->next;
        duom(t);
        t->next = NULL;
    }
    else
    {
        root = new node;
        duom(root);
        root->next = NULL;
    }
}

void vidurkis(node *&root)
{
    double temp=0;
    node *t=root;
    while(t!=NULL)
    {
        temp=0;
        for(int i=0; i<t->pazsk; i++) temp+=t->paz[i];
        if(t->pazsk!=0)
        t->rezult=0.4*(temp/t->pazsk)+0.6*t->egz;
        else t->rezult=0.6*t->egz;
        t=t->next;
    }
}

void median(node *&root)
{
    double temp=0;
    node *t=root;
    while(t!=NULL)
    {
        temp=0;
        std::sort(t->paz, t->paz+t->pazsk);
        if (t->pazsk % 2 != 0)
            temp=(double)t->paz[t->pazsk/2];
        else temp=(double)(t->paz[(t->pazsk-1)/2]+t->paz[t->pazsk/2])/2.0;
        t->rezult=0.4*temp+0.6*t->egz;
        t=t->next;
    }
}

void output(node *root, int choice)
{
    cout << std::setw(20) << std::left << "Vardas" << std::setw(20) << std::left << "Pavarde";
    if(choice==0) cout << std::setw(5) << std::left << "Galutinis (Vid.)" << endl;
    if(choice==1) cout << std::setw(5) << std::left << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    while(root!=NULL)
    {
        cout << std::setw(20) << std::left << root->vardas << std::setw(20) << std::left << root->pavarde << std::setw(5) << std::left << std::fixed << std::setprecision(2) << root->rezult << endl;
        root=root->next;
    }
}

int main()
{
    node* root = NULL;
    int choice;
    int asmuo;
    input(root);
PRIDEJIMAS:
        cout << "Jei norite prideti dar viena asmeni iveskite 1. Jei norite testi, iveskite 0: ";
        cin >> asmuo;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto PRIDEJIMAS; }
        if(asmuo==1) { input(root); goto PRIDEJIMAS; }
OUTPUT:
    cout << "Galutini bala apaskaiciuoti naudojant namu darbu vidurki ar mediana? (Atitinkamai 0 arba 1): ";
    cin >> choice;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto OUTPUT; }
    if(choice == 0) vidurkis(root);
    if(choice == 1) median(root);
    if(!((choice>=0)&&(choice<=1))) goto OUTPUT;
    output(root, choice);
    delete[] root;
    system("pause");
    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct node
{
    string vardas="", pavarde="";
    std::vector<int> paz;
    int egz=0;
    double rezult=0;
    bool gen=0;
    node* next;
};

void duom(node *&t)
{
    int temp=1;
    srand((unsigned) time(NULL));
    cout << "Iveskite varda: ";
    cin >> t->vardas;
    cout << "Iveskite pavarde: ";
    cin >> t->pavarde;
    t->paz.reserve(500);
    Rand:
    cout << "Ar mokinio balus generuoti atsitiktinai? (0 - Ne, 1 - Taip): ";
    cin >> t->gen;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Rand; }
    if(!t->gen) {
    while(temp!=-1)
    {
            PAZ1:
            cout << "Iveskite " << t->paz.size()+1 << " -a(-i) pazymi (nuo 0 iki 10). Iveskite -1, jei norite stabdyti ivedima: ";
            cin >> temp;
            if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto PAZ1; }
            if(temp==-1) break;
            if(!((temp>=-1)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10" << endl; goto PAZ1;}
            else{
                t->paz.push_back(temp);
        }
    }
    PAZ2:
    cout << "Veskite egzamino iverti (nuo 0 iki 10): ";
    cin >> t->egz;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto PAZ2; }
    if(!((t->egz>=0)&&(t->egz<=10))) {cout << "Reiksme turi buti tarp 0 ir 10" << endl; goto PAZ2;}
    t->paz.shrink_to_fit();
    }
    else if(t->gen)
    {
        Gen:
        cout << "Kiek pazymiu sugeneruoti mokiniui? (Nuo 0 iki 500): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Gen; }
        if(!((temp>=0)&&(temp<=500))) goto Gen;
        t->paz.resize(temp);
        for(int i=0; i<t->paz.size(); i++)
            t->paz.at(i)=rand()%11;
        t->egz=rand()%11;
    }
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
        for(const auto &el : t->paz) temp+=el;
        if(t->paz.size()!=0)
        t->rezult=0.4*(temp/t->paz.size())+0.6*t->egz;
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
        std::sort(t->paz.begin(), t->paz.end());
        if (t->paz.size() % 2 != 0)
            temp=(double)t->paz[t->paz.size()/2];
        else temp=(double)(t->paz[(t->paz.size()-1)/2]+t->paz[t->paz.size()/2])/2.0;
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
    cout << "Galutini bala apaskaiciuoti naudojant namu darbu vidurki ar mediana? (0 - Vidurki, 1 - Mediana): ";
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

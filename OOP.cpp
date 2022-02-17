#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

struct node
{
    string vardas="", pavarde="";
    int paz[3]= {0}, egz=0;
    double rezult=0;
    node* next;
};

void input(node *&root, int n)
{
    if (root)
    {
        node *t = root;
        while (t->next) t = t->next;
        t->next = new node;
        t = t->next;
        cout << "Iveskite varda: ";
        cin >> t->vardas;
        cout << "Iveskite pavarde: ";
        cin >> t->pavarde;
        for(int i=0; i<n; i++)
        {
            cout << "Iveskite " << i+1 << " -a(-i) pazymi: ";
            cin >> t->paz[i];
        }
        cout << "Veskite egzamino iverti: ";
        cin >> t->egz;
        t->next = NULL;
    }
    else
    {
        root = new node;
        cout << "Iveskite varda: ";
        cin >> root->vardas;
        cout << "Iveskite pavarde: ";
        cin >> root->pavarde;
        for(int i=0; i<n; i++)
        {
            cout << "Iveskite " << i+1 << " -a(-i) pazymi: ";
            cin >> root->paz[i];
        }
        cout << "Veskite egzamino iverti: ";
        cin >> root->egz;
        root->next = NULL;
    }
}

void vidurkis(node *&root, int n)
{
    double temp=0;
    node *t=root;
    while(t!=NULL)
    {
        temp=0;
        for(int i=0; i<n; i++) temp+=t->paz[i];
        t->rezult=0.4*(temp/n)+0.6*t->egz;
        t=t->next;
    }
}

void median(node *&root, int n)
{
    double temp=0;
    node *t=root;
    while(t!=NULL)
    {
        temp=0;
        std::sort(t->paz, t->paz+n);
        if (n % 2 != 0)
            temp=(double)t->paz[n/2];
        else temp=(double)(t->paz[(n-1)/2]+t->paz[n/2])/2.0;
        t->rezult=0.4*temp+0.6*t->egz;
        cout << "TEST: " << t->rezult << std::endl;
        t=t->next;
    }
}

void output(node *root, int choice)
{
    cout << std::setw(20) << std::left << "Vardas" << std::setw(20) << std::left << "Pavarde";
    if(choice==0) cout << std::setw(5) << std::left << "Galutinis (Vid.)" << std::endl;
    if(choice==1) cout << std::setw(5) << std::left << "Galutinis (Med.)" << std::endl;
    cout << "----------------------------------------------------------------------------" << std::endl;
    while(root!=NULL)
    {
        cout << std::setw(20) << std::left << root->vardas << std::setw(20) << std::left << root->pavarde << std::setw(5) << std::left << std::fixed << std::setprecision(2) << root->rezult << std::endl;
        root=root->next;
    }
}

int main()
{
    node* root = NULL;
    int num;
    int choice;
    int n=3;
    cout << "Kiek asmenu skaiciuosit? ";
    cin >> num;
    for(int i=0; i<num; i++) input(root, n);
OUTPUT:
    cout << "Galutini bala apaskaiciuoti naudojant namu darbu vidurki ar mediana? (Atitinkamai 0 arba 1): ";
    cin >> choice;
    if(choice == 0) vidurkis(root, n);
    if(choice == 1) median(root, n);
    if(!((choice>=0)&&(choice<=1)))
    {
        goto OUTPUT;
    }
    output(root, choice);
    delete[] root;
    system("pause");
    return 0;
}

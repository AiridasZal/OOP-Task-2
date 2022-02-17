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
    int paz[50]= {0}, egz=0, pazsk=0;
    double rezult=0;
    node* next;
};

void duom(node *&t)
{
    int temp=1;
    cout << "Iveskite varda: ";
    cin >> t->vardas;
    cout << "Iveskite pavarde: ";
    cin >> t->pavarde;
    while(temp!=0)
    {
        cout << "Iveskite " << t->pazsk+1 << " -a(-i) pazymi (arba 0 jei norite stabdyti ivedima): ";
        cin >> temp;
        if(temp==0) break;
        else{
            t->paz[t->pazsk]=temp;
            t->pazsk++;
        }
    }
    cout << "Veskite egzamino iverti: ";
    cin >> t->egz;
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
    int choice;
    int asmuo;
    input(root);
    do{
        cout << "Jei norite prideti dar viena asmeni iveskite 1, ivedus kita skaiciu pereinama prie balo skaiciavimo: ";
        cin >> asmuo;
        if(asmuo==1) input (root);
        else cin.ignore();
    } while(asmuo==1);
OUTPUT:
    cout << "Galutini bala apaskaiciuoti naudojant namu darbu vidurki ar mediana? (Atitinkamai 0 arba 1): ";
    cin >> choice;
    if(choice == 0) vidurkis(root);
    if(choice == 1) median(root);
    if(!((choice>=0)&&(choice<=1)))
    {
        goto OUTPUT;
    }
    output(root, choice);
    delete[] root;
    system("pause");
    return 0;
}

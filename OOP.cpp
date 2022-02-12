#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

struct node{
    string vardas="", pavarde="";
    int paz[3]={0}, egz=0;
    double rezult=0;
    node* next;
};

void input(node *&root) {
    int n=3;
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

void galutinis(node *&root) {
    double temp=0;
    node *t=root;
    while(t!=NULL) {
        temp=0;
        for(int i=0; i<3; i++) temp+=t->paz[i];
        t->rezult=0.4*(temp/3)+0.6*t->egz;
        t=t->next;
    }
}

void output(node *root)
{
    cout << std::setw(20) << std::left << "Vardas" << std::setw(20) << std::left << "Pavarde" << std::setw(5) << std::left << "Galutinis (Vid.)" << std::endl;
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
    cout << "Kiek asmenu skaiciuosit? ";
    cin >> num;
    for(int i=0; i<num; i++)
    input(root);
    galutinis(root);
    output(root);
    delete[] root;
//    system("pause");
    return 0;
}

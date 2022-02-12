#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

struct data{
    string vardas="", pavarde="";
    int paz[3]={0}, egz=0;
};

void input(data &temp)
{
    int n=3;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    for(int i=0; i<n; i++)
    {
        cout << "Iveskite " << i+1 << " -a(-i) pazymi: ";
        cin >> temp.paz[i];
    }
    cout << "Veskite egzamino iverti: "; cin >> temp.egz;
}

int main()
{
    data A;
    input(A);
    system("pause");
}

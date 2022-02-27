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

int main()
{
    vector<student> A;
    int num=0;
    int inp;
Ivestis:
    cout << "Ivesti duomenis ranka (0) ar skaityti is failo (1): ";
    cin >> inp;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Ivestis; }
    if(inp==0)
    {

    }
    if(inp==1)
    {

    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

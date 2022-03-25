#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <fstream>
#include <chrono>
#include <sstream>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::left;
using std::fixed;
using std::setw;
using std::setprecision;
using std::vector;
using std::list;
using std::deque;
using std::sort;

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
void generuoti(vector<student> &A, int i);
template<typename Container>
void galutinisBalas(Container &A, int kiek)
{
    for(auto &v : A)
    {
        sort(v.nd.begin(), v.nd.end());
        if(v.sk%2!=0)
        {
            v.med=(double)v.nd[v.sk/2];
        }
        else v.med=(double)(v.nd[(v.sk-1)/2] + v.nd[v.sk/2])/2.0;
        v.galM=0.4*v.med+0.6*v.egz;

        if(v.sum==0) for(int j=0; j<kiek-1; j++) v.sum+=v.nd[j];
        v.vid=(double)v.sum/(double)v.sk;
        v.galV=0.4*v.vid+0.6*v.egz;
    }
}
template<typename Container>
void spausdinimas(Container &A, string file)
{
    std::ofstream out(file);
    std::stringstream buffer;
    buffer << "---------------------------------------------------------------------------------" << endl;
    buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << setw(5) << left << "Galutinis (Med.)" << endl;
    buffer << "---------------------------------------------------------------------------------" << endl;
    for(const auto &v : A)
    {
    buffer << setw(20) << left << v.vardas << setw(20) << left << v.pavarde << setw(25) << left << fixed << setprecision(2) << v.galV << setw(5) << left << v.galM << endl;
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}
void rikiavimas(vector<student> &A, int &num);
void skaitymas(vector<student> &A, int &num, std::ifstream& in);
void filegen(int i, int num, int kiek);
void GradeNumber(int &kiek);
template<typename Container>
void readgen(Container &A, int i, int num, int kiek)
{
    string ifname[5]={"studentai1000.txt", "studentai10000.txt", "studentai100000.txt",  "studentai1000000.txt", "studentai10000000.txt"};
    int temp;
    std::ifstream in(ifname[i]);
    student duom;
    while(!in.eof())
    {
        in >> duom.vardas >> duom.pavarde;
        duom.nd.reserve(kiek-1);
        for(int j=0; j<kiek-1; j++)
        {
            in >> temp;
            duom.nd.push_back(temp);
            duom.sum+=temp;
        }
        in >> duom.egz;
        duom.sk=kiek;
        A.push_back(duom);
        duom.sum=0;
        duom.nd.clear();
    }
    in.close();
}
template<typename Container>
void rusiavimas(Container &A, Container &silpni, Container &kieti)
{
    for(const auto &v : A)
    {
        if(v.galV < 5)
        {
            silpni.push_back(v);
        }
        else kieti.push_back(v);
    }
}

#endif

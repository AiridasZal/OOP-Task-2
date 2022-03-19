#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
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
void galutinisBalas(vector<student> &A, int kiek);
void spausdinimas(vector<student> &A, string file);
void rikiavimas(vector<student> &A, int &num);
void skaitymas (vector<student> &A, int &num, std::ifstream& in);
void filegen(int i, int num, int kiek);
void GradeNumber(int &kiek);
void readgen(vector<student> &A, int i, int num, int kiek);
void rusiavimas(vector<student> &A, vector<student> &silpni, vector<student> &kieti);

#endif

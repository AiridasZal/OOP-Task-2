#pragma once
#include "studentas.h"

void DuomenuIvedimas(vector <Studentas> &A, int &num);
void galutinisBalas(vector<Studentas> &A);
void spausdinimas(vector<Studentas> &A, string file);
void rikiavimas(vector<Studentas> &A, int &num);
void skaitymas(vector<Studentas> &A, int &num, std::ifstream& in);
void filegen(int i, int num, int kiek);
void GradeNumber(int &kiek);
void readgen(vector<Studentas> &A, int i, int num, int kiek);
template<typename Container>
void rusiavimas(Container &A, Container &kieti)
{
    for(const auto x: A)
    {
        if(x.getFAverage()>=5.00)
        {
            kieti.push_back(x);
        }
    }
    A.erase(remove_if(A.begin(), A.end(), [](Studentas x){return x.getFAverage()>=5.00;}), A.end());
}

// Testavimo funkcijos

double GalutinisV(double vid, double egz);
bool Islaikyta(double balas);
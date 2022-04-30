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
    std::remove_copy_if(A.begin(), A.end(), std::back_inserter(kieti), [](const Studentas &v){return v.getFAverage() >= 5;});
}
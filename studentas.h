#pragma once
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

class Studentas{
private:
  string vardas;
  string pavarde;
  double egz;
  vector<double> nd;
  double med;
  double vid;
  double galV;
  double galM;
public:
  Studentas();
  Studentas(const Studentas&);
  ~Studentas();
  void setName(string);
  void setLastName(string);
  void setHW(vector <double>);
  void setExam(double);
  string getName() const;
  string getLastName() const;
  double getExam() const;
  double getFMedian() const;
  double getFAverage() const;
  void Galutinis();

  Studentas& operator=(const Studentas& other);
  bool operator==(const Studentas& other);
  bool operator!=(const Studentas& other);
};
#pragma once
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
using std::sort;

class zmogus{
protected:
  string vardas;
  string pavarde;
public:
  zmogus();
  zmogus(string, string);
  ~zmogus();
  virtual void setName(string)=0;
  virtual void setLastName(string)=0;
  string getName() const;
  string getLastName() const;
};

class Studentas: public zmogus{
private:
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
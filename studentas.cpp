#include "studentas.h"

Studentas::Studentas(){
	string vardas="";
	string pavarde="";
	double egz = 0.0;
	double vid = 0.0;
	double med = 0.0;
	double galM = 0.0;
	double galV = 0.0;
}

Studentas::~Studentas(){

}

void Studentas::setName(string v) {
	vardas = v;
}

void Studentas::setLastName(string pav) {
	pavarde = pav;
}

void Studentas::setHW(vector <double> ndpaz) {
	nd = ndpaz;
}

void Studentas::setExam(double egzpaz) {
	egz = egzpaz;
}

string Studentas::getName() const {
	return vardas;
}

string Studentas::getLastName() const {
	return pavarde;
}

double Studentas::getFAverage() const {
	return galV;
}

double Studentas::getFMedian() const {
	return galM;
}

void Studentas::Galutinis() {

	sort(nd.begin(),nd.end());
	int sk = nd.size();

    if(sk%2!=0)
    {
        med=(double)nd.at(sk/2);
    }
    else med=(double)(nd.at((sk-1)/2) + nd.at(sk/2))/2.0;
    galM=0.4*med+0.6*egz;

	for(int i=0; i<nd.size(); i++){
		vid+=nd.at(i);
	}
	vid=vid/nd.size();
	galV=0.4*vid+0.6*egz;
}
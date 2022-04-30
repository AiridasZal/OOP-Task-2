#include "functions.h"

void DuomenuIvedimas(vector<Studentas> &A, int &num)
{
    string vardas, pavarde;
    int egz, sk;
    vector<double> ndpaz;
    Studentas duom;
    int choice, gen, kiek, temp;
    Kiekis:
    cout << "Kiek bus mokiniu?" << endl;
    cin >> choice;
    num=choice;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Kiekis; }
    if(!((choice>=0)&&(choice<=150))) goto Kiekis;

    for(int i=0; i<choice; i++)
    {
        cout << "Iveskite studento varda:\n";
        cin >> vardas;
        duom.setName(vardas);
        cout << "Iveskite studento pavarde:\n";
        cin >> pavarde;
        duom.setLastName(pavarde);
        Generacija:
        cout << "Pazymius norite suvesti ranka ar sugeneruoti atsitiktinai (0 - ranka, 1 - atsitiktinai)\n";
        cin >> gen;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Generacija; }
        if(!((gen>=0)&&(gen<=1))) goto Generacija;

        if(choice==0)
        {
            sk=1;
            while(temp!=-1)
            {
            paznd:
                cout << "Iveskite " << sk <<  " -a(-i) pazymi (arba -1 jei norite stabdyti ivedima): ";
                cin >> temp;
                if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto paznd; }
                if(!((temp>=-1)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto paznd;}
                if(temp==-1) break;
                    else{
                        ndpaz.push_back(temp);
                        sk++;
                    }
            }
            duom.setHW(ndpaz);
            ndpaz.clear();
            egzp:
                cout << "Veskite egzamino iverti (nuo 0 iki 10): ";
                cin >> temp;
                if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto egzp; }
                if(!((temp>=0)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto egzp;}
                else duom.setExam(temp);
        }

        if(choice==1)
        {
            Genopt:
                cout << "Kiek pazymiu sugeneruoti mokiniui? (Nuo 0 iki 500): ";
                cin >> kiek;
                if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Genopt; }
                if(!((kiek>=0)&&(kiek<=500))) {cout << "Reiksme turi buti tarp 0 ir 500\n"; goto Genopt;}
                srand((unsigned) time(NULL));
                cout << "Sugeneruoti pazymiai:\n";
                for(int j=0; j<kiek; j++)
                {
                    temp=rand()%11;
                    ndpaz.push_back(temp);
                    cout << temp << " ";
                }
                cout << endl;
                temp=rand()%11;
                duom.setExam(temp);
        }
        duom.setHW(ndpaz);
        A.push_back(duom);
        ndpaz.clear();
        
    }
    
}

void spausdinimas(vector<Studentas> &A, string file)
{
    std::ofstream out(file);
    std::stringstream buffer;
    buffer << "---------------------------------------------------------------------------------" << endl;
    buffer << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << setw(5) << left << "Galutinis (Med.)" << endl;
    buffer << "---------------------------------------------------------------------------------" << endl;
    for(const auto &v : A)
    {
    buffer << setw(20) << left << v.getName() << setw(20) << left << v.getLastName() << setw(25) << left << fixed << setprecision(2) << v.getFAverage() << setw(5) << left << v.getFMedian() << endl;
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}

void rikiavimas(vector<Studentas> &A, int &num)
{
    for(int i=0; i<num-1; i++)
        for(int j=i+1; j<num; j++)
        if(A[i].getLastName()> A[j].getLastName())
            std::swap(A[i], A[j]);
}

void skaitymas(vector<Studentas> &A, int &num, std::ifstream& in)
{
    string stulp, vardas, pavarde;
    int kiek, temp, egzpaz;
    vector<double> ndpaz;
    Studentas duom;
    
    in >> stulp >> stulp >> stulp;
    while(stulp[0]=='N')
    {
        kiek++;
        in >> stulp;
    }

    while(!in.eof())
    {
        in >> vardas >> pavarde;
        duom.setName(vardas);
        duom.setLastName(pavarde);

        for(int i=0; i<kiek; i++)
        {
            in >> temp;
        }
        ndpaz.push_back(temp);
        in >> egzpaz;
        duom.setExam(egzpaz);
        duom.setHW(ndpaz);
        A.push_back(duom);
        ndpaz.clear();
    }
    in.close();
}

void filegen(int i, int num, int kiek)
{
    string ofname[5]={"studentai1000.txt", "studentai10000.txt", "studentai100000.txt",  "studentai1000000.txt", "studentai10000000.txt"};

    int temp;

    std::ofstream out(ofname[i]);
    std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution <int> dist(1, 10);

    std::stringstream buffer;

    for(int k=0; k<num; k++)
    {
        buffer << "Vardas" << k+1 << " " << "Pavarde" << k+1;

        for(int j=0; j<kiek; j++)
        {
            temp=dist(mt);
            buffer << " " << temp;
        }
        buffer << endl;
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}

void GradeNumber(int &kiek)
{
    std::ifstream fr("studentai1000.txt");
    try
    {
        if(!fr.good())
        {
        throw "Failas nerastas...";
        }
    }
    catch (const char* msg)
    {
        cout << msg <<endl;
    }
    string temp;
    int sk;
    fr >> temp >> temp;
    while(fr >> sk)
    {
        kiek++;
    }
    fr.clear();
    fr.seekg(0, fr.beg);
    fr.close();
}

void readgen(vector<Studentas> &A, int i, int num, int kiek)
{
    string ifname[5]={"studentai1000.txt", "studentai10000.txt", "studentai100000.txt",  "studentai1000000.txt", "studentai10000000.txt"};
    int temp;
    std::ifstream in(ifname[i]);
    Studentas duom;
    string vardas, pavarde;
    int egzpaz;
    vector<double> ndpaz;
    while(!in.eof())
    {
        in >> vardas >> pavarde;
        duom.setName(vardas);
        duom.setLastName(pavarde);
        for(int j=0; j<kiek-1; j++)
        {
            in >> temp;
            ndpaz.push_back(temp);
        }
        in >> egzpaz;
        duom.setExam(egzpaz);
        duom.setHW(ndpaz);
        A.push_back(duom);
        ndpaz.clear();
    }
    in.close();
}

void galutinisBalas(vector<Studentas> &A)
{
	for(auto &v : A) {
		v.Galutinis();
	}
}
#include "functions.h"

void ivedimas(vector<student> &A, int i)
{
    cout << "Iveskite studento varda: "; cin >> A[i].vardas;
    cout << "Iveskite studento pavarde: "; cin >> A[i].pavarde;
}

void pazymiai(vector<student> &A, int i)
{
    int temp;
    while(temp!=-1)
    {
    paznd:
        cout << "Iveskite " << A[i].sk+1 <<  " -a(-i) pazymi (arba -1 jei norite stabdyti ivedima): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto paznd; }
        if(!((temp>=-1)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto paznd;}
        if(temp==-1) break;
            else{
                A[i].nd.push_back(temp);
                A[i].sk++;
                A[i].sum+=temp;
            }
    }
    egzp:
        cout << "Veskite egzamino iverti (nuo 0 iki 10): ";
        cin >> temp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto egzp; }
        if(!((temp>=0)&&(temp<=10))) {cout << "Reiksme turi buti tarp 0 ir 10\n"; goto egzp;}
        else A[i].egz=temp;
}

void generuoti(vector<student> &A, int i)
{
    int kiek;
    int temp;
Genopt:
    cout << "Kiek pazymiu sugeneruoti mokiniui? (Nuo 0 iki 500): ";
    cin >> kiek;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Genopt; }
    if(!((kiek>=0)&&(kiek<=500))) {cout << "Reiksme turi buti tarp 0 ir 500\n"; goto Genopt;}
    srand((unsigned) time(NULL));
    A[i].sk=kiek;
    cout << "Sugeneruoti pazymiai:\n";
    for(int j=0; j<kiek; j++)
    {
        temp=rand()%11;
        A[i].nd.push_back(temp);
        A[i].sum+=temp;
        cout << temp << " ";
    }
    cout << endl;
    temp=rand()%11;
    A[i].egz=temp;
}

void galutinisBalas(vector<student> &A, int kiek)
{
    for(auto &v : A)
    {
        long int i = &v - &A[0];
        sort(A.at(i).nd.begin(), A.at(i).nd.end());
        if(A.at(i).sk%2!=0)
        {
            A.at(i).med=(double)A.at(i).nd[A.at(i).sk/2];
        }
        else A.at(i).med=(double)(A.at(i).nd[(A.at(i).sk-1)/2] + A.at(i).nd[A.at(i).sk/2])/2.0;
        A.at(i).galM=0.4*A.at(i).med+0.6*A.at(i).egz;

        if(A.at(i).sum==0) for(int j=0; j<kiek-1; j++) A.at(i).sum+=A.at(i).nd[j];
        A.at(i).vid=(double)A.at(i).sum/(double)A.at(i).sk;
        A.at(i).galV=0.4*A.at(i).vid+0.6*A.at(i).egz;
    }
}

void spausdinimas(vector<student> &A, string file)
{
    std::ofstream out(file);
    out << "---------------------------------------------------------------------------------" << endl;
    out << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << setw(5) << left << "Galutinis (Med.)" << endl;
    out << "---------------------------------------------------------------------------------" << endl;
    for(auto &v : A)
    {
    long int i = &v - &A[0];
    out << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].galV << setw(5) << left << A[i].galM << endl;
    }
    out.close();
}

void rikiavimas(vector<student> &A, int &num)
{
    for(int i=0; i<num-1; i++)
        for(int j=i+1; j<num; j++)
        if(A[i].pavarde> A[j].pavarde)
            std::swap(A[i], A[j]);
}

void skaitymas (vector<student> &A, int &num, std::ifstream& in)
{
    int egz=0;
    string temp, eil, vardas, pavarde;
    while(std::getline(in, eil))
    {
        A.push_back(student());
        std::istringstream line(eil);
        line >> vardas >> pavarde;
        A[num].vardas=vardas;
        A[num].pavarde=pavarde;
        while(line >> temp)
        {
            int paz = std::stoi(temp);
            if(paz>=0 && paz<=10)
            {
                A[num].nd.push_back(paz);
                A[num].sum+=paz;
                A[num].sk++;
            }
        }
    line.end;
    A[num].egz=A[num].nd[A[num].sk-1];
    A[num].nd[A[num].sk-1]=0;
    A[num].sum-=A[num].egz;
    A[num].sk--;
    num++;
    }
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

void readgen(vector<student> &A, int i, int num, int kiek)
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

void rusiavimas(vector<student> &A, vector<student> &silpni, vector<student> &kieti)
{
    for(auto &v : A)
    {
        long int i = &v - &A[0];
        if(A.at(i).galV < 5)
        {
            silpni.push_back(A.at(i));
        }
        else kieti.push_back(A.at(i));
    }
}
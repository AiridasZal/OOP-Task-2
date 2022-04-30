#include "functions.h"

int main()
{
    vector<Studentas> A, kieti;

    int num=0;
    int inp, gen,asmuo;
Ivestis:
    cout << "Ivesti duomenis ranka (0) ar skaityti is failo (1): ";
    cin >> inp;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Ivestis; }
    if(inp==0)
    {
        DuomenuIvedimas(A, num);
        galutinisBalas(A);
        rikiavimas(A, num);
        spausdinimas(A, "Rezultatai.txt");
    }

    if(inp==1)
    {
        Genskai:
        cout << "Skaityti duomenis is 'kursiokai.txt' (0) ar generuoti naujus failus (1): ";
        cin >> inp;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Genskai; }
        if(!((inp>=0)&&(inp<=1))) {cout << "Negalima reiksme, bandykite dar karta\n"; goto Genskai;}
        if(inp==0)
        {
            num=0;
            std::ifstream in("kursiokai.txt");
            try
            {
                if(!in.good())
                {
                throw "Failas nerastas...";
                }
            }
            catch (const char* msg)
            {
                cout <<msg<<endl;
            }
            in.ignore(1024, '\n');
            skaitymas(A, num, in);
            galutinisBalas(A);
            rikiavimas(A, num);
            spausdinimas(A, "Rezultatai.txt");
            in.close();
        }
        if(inp==1)
        {
            int num=100;
            int kiek=0;
            Filec:
            cout << "Ar norite sugeneruoti naujus failus (0) ar atlikti programos su failais spartos testavima (1)?\n";
            cin >> inp;
            if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Filec; }
            if(!((inp>=0)&&(inp<=1))) goto Filec;
            if(inp==0)
            {
                Pazkiek:
                cout << "Po kiek pazymiu sugeneruoti kiekvienam studentui (2-16): ";
                cin >> kiek;
                if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Pazkiek;}
                if(!((kiek>=2)&&(kiek<=16))) {cout << "Ivesta reiksme neatitinka intervalo nuo 2 iki 16...\n"; goto Pazkiek;}
                for(int i=0; i<5; i++)
                {
                    num*=10;
                    auto start = std::chrono::high_resolution_clock::now();
                    filegen(i, num, kiek);
                    auto stop = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo generavimas uztruko: " << duration.count() << " sekundziu" << endl;
                }
                cout << endl;
                goto speed;
            }
            if(inp==1)
            {
                speed:
                if(!((kiek>=2)&&(kiek<=16))) GradeNumber(kiek);
                num=100;
                for(int i=0; i<5; i++)
                {
                    num*=10;
                    //Vektoriai

                    auto start = std::chrono::high_resolution_clock::now();
                    auto fullstart = start;
                    readgen(A, i, num, kiek);
                    auto stop = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskaitymas su vektoriumi uztruko: " << duration.count() << " sekundziu" << endl;
                    galutinisBalas(A);
                    sort(A.begin(), A.end(), [](Studentas& s1, Studentas& s2) -> bool {if(s1.getFAverage() == s2.getFAverage()) return s1.getLastName() < s2.getLastName(); else return s1.getFAverage() < s2.getFAverage();});
                    start = std::chrono::high_resolution_clock::now();
                    rusiavimas(A, kieti);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    auto fulldur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-fullstart);
                    cout << i+1 << " -ojo failo isrusiavimas uztruko: " << duration.count() << " sekundziu" << endl;
                    cout << i+1 << " -ojo failo nuskaitymas ir rusiavimas su vektoriais uztruko: " << fulldur.count() << " sekundziu" << endl;
                    spausdinimas(A, "NuskriaustiV" + std::to_string(num) + ".txt");
                    spausdinimas(kieti, "KietiV" + std::to_string(num) + ".txt");
                    A.clear();
                    kieti.clear();
                    cout << endl;

                    system("pause");
                }
            }
        }
    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

#include "functions.h"

int main()
{
    vector<student> A;
    int num=0;
    int inp, gen,asmuo;
Ivestis:
    cout << "Ivesti duomenis ranka (0) ar skaityti is failo (1): ";
    cin >> inp;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Ivestis; }
    if(inp==0)
    {
        Generavimas:
        A.push_back(student());
        ivedimas(A, num);
        cout << "Pazymius ivesti ranka - (0). Pazymius generuoti atsitiktinai - (1): ";
        cin >> gen;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Generavimas; }
        if(gen==0)
        {
            pazymiai(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(gen==1)
        {
            generuoti(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(!((gen>=0)&&(gen<=1))) goto Generavimas;
        num++;
        Pridejimas:
        cout << "Jei norite prideti dar viena asmeni iveskite 1. Jei norite testi, iveskite 0: ";
        cin >> asmuo;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Pridejimas; }
        if(asmuo==1) goto Generavimas;
        if(!((asmuo>=0)&&(asmuo<=1))) goto Pridejimas;
    }
    for(int i=0; i<num; i++)
    {
        if(i==0) header();
        rikiavimas(A, num);
        spausdinimas(A, i);
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
            for (int i=0; i<num; i++)
            {
                rastiMediana(A, i);
                rastiVidurki(A, i);
                if (i==0)
                    header();
    //            rikiavimas(A, num);
                spausdinimas (A, i);
            }
            in.close();
        }
        if(inp==1)
        {
            int num=100;
            int kiek=0;
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
                start = std::chrono::high_resolution_clock::now();
                readgen(A, i, num, kiek);
                stop = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                cout << i+1 << " -ojo failo nuskaitymas uztruko: " << duration.count() << " sekundziu" << endl;
                cout << endl;
                A.clear();
            }
        }
    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

#include "functions.h"

int main()
{
    vector<student> A, silpni, kieti;
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
        }
        if(gen==1)
        {
            generuoti(A, num);
        }

        if(!((gen>=0)&&(gen<=1))) goto Generavimas;
        num++;
        Pridejimas:
        cout << "Jei norite prideti dar viena asmeni iveskite 1. Jei norite testi, iveskite 0: ";
        cin >> asmuo;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Pridejimas; }
        if(asmuo==1) goto Generavimas;
        if(!((asmuo>=0)&&(asmuo<=1))) goto Pridejimas;
        galutinisBalas(A, num);
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
            galutinisBalas(A, num);
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
                    auto start = std::chrono::high_resolution_clock::now();
                    auto fulltime=start;
                    readgen(A, i, num, kiek);
                    auto stop = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskaitymas uztruko: " << duration.count() << " sekundziu" << endl;
                    galutinisBalas(A, kiek);
                    std::sort(A.begin(), A.end(), [](student& s1, student& s2) -> bool {if(s1.galV == s2.galV) return s1.pavarde < s2.pavarde; else return s1.galV < s2.galV;});
                    start = std::chrono::high_resolution_clock::now();
                    rusiavimas(A, silpni, kieti);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo isrusiavimas uztruko: " << duration.count() << " sekundziu" << endl;
                    A.clear();

                    start = std::chrono::high_resolution_clock::now();
                    auto file2 = start;
                    spausdinimas(silpni, "Nuskriausti"+ std::to_string(num) + ".txt");
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskriaustuju isvedimas i nauja faila uztruko: " << duration.count() << " sekundziu" << endl;

                    start = std::chrono::high_resolution_clock::now();
                    spausdinimas(kieti, "Kieti"+ std::to_string(num) + ".txt");
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    auto file2dur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-file2);
                    auto fulldur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-fulltime);
                    cout << i+1 << " -ojo failo kietiaku isvedimas i nauja faila uztruko: " << duration.count() << " sekundziu" << endl;
                    cout << i+1 << " -ojo failo isvedimas i 2 naujus failus uztruko: " << file2dur.count() << " sekundziu" << endl << endl;
                    cout << i+1 << " -ojo failo testas uztruko: " << fulldur.count() << " sekundziu" << endl;
                    system("pause");
                    cout << endl;
                    
                    silpni.clear();
                    kieti.clear();
                }
            }
            
        }
    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

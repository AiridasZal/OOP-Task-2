#include "functions.h"

int main()
{
    vector<student> A, silpni, kieti;
    list<student> StudList, silpniList, kietiList;
    deque<student> StudDeq, silpniDeq, kietiDeq;

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
                    //Vektoriai

                    auto start = std::chrono::high_resolution_clock::now();
                    auto fullstart = start;
                    readgen(A, i, num, kiek);
                    auto stop = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskaitymas su vektoriumi uztruko: " << duration.count() << " sekundziu" << endl;
                    galutinisBalas(A, kiek);
                    sort(A.begin(), A.end(), [](student& s1, student& s2) -> bool {if(s1.galV == s2.galV) return s1.pavarde < s2.pavarde; else return s1.galV < s2.galV;});
                    start = std::chrono::high_resolution_clock::now();
                    //rusiavimas(A, silpni, kieti);
                    rusiavimas2(A, kieti);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    auto fulldur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-fullstart);
                    cout << i+1 << " -ojo failo isrusiavimas uztruko: " << duration.count() << " sekundziu" << endl;
                    cout << i+1 << " -ojo failo nuskaitymas ir rusiavimas su vektoriais uztruko: " << fulldur.count() << " sekundziu" << endl;
                    //spausdinimas(silpni, "NuskriaustiV" + std::to_string(num) + ".txt");
                    spausdinimas(A, "NuskriaustiV" + std::to_string(num) + ".txt");
                    spausdinimas(kieti, "KietiV" + std::to_string(num) + ".txt");
                    A.clear();
                    silpni.clear();
                    kieti.clear();
                    cout << endl;

                    //List

                    start = std::chrono::high_resolution_clock::now();
                    fullstart = start;
                    readgen(StudList, i, num, kiek);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskaitymas su List'u uztruko: " << duration.count() << " sekundziu" << endl;
                    galutinisBalas(StudList, kiek);
                    StudList.sort([](const student& s1, const student& s2) -> bool {if(s1.galV == s2.galV) return s1.pavarde < s2.pavarde; else return s1.galV < s2.galV;});
                    start = std::chrono::high_resolution_clock::now();
                    //rusiavimas(StudList, silpniList, kietiList);
                    rusiavimas3(StudList, kietiList);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    fulldur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-fullstart);
                    cout << i+1 << " -ojo failo isrusiavimas uztruko: " << duration.count() << " sekundziu" << endl;
                    cout << i+1 << " -ojo failo nuskaitymas ir rusiavimas su List uztruko: " << fulldur.count() << " sekundziu" << endl;
                    //spausdinimas(silpniList, "NuskriaustiL"+ std::to_string(num) + ".txt");
                    spausdinimas(StudList, "NuskriaustiL" + std::to_string(num) + ".txt");
                    spausdinimas(kietiList, "KietiL"+ std::to_string(num) + ".txt");
                    StudList.clear();
                    silpniList.clear();
                    kietiList.clear();
                    cout << endl;

                    //Deque

                    start = std::chrono::high_resolution_clock::now();
                    fullstart = start;
                    readgen(StudDeq, i, num, kiek);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    cout << i+1 << " -ojo failo nuskaitymas su Deque'u uztruko: " << duration.count() << " sekundziu" << endl;
                    galutinisBalas(StudDeq, kiek);
                    sort(StudDeq.begin(), StudDeq.end(), [](student& s1, student& s2) -> bool {if(s1.galV == s2.galV) return s1.pavarde < s2.pavarde; else return s1.galV < s2.galV;});
                    start = std::chrono::high_resolution_clock::now();
                    //rusiavimas(StudDeq, silpniDeq, kietiDeq);
                    rusiavimas2(StudDeq, kietiDeq);
                    stop = std::chrono::high_resolution_clock::now();
                    duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);
                    fulldur = std::chrono::duration_cast<std::chrono::duration<double>>(stop-fullstart);
                    cout << i+1 << " -ojo failo isrusiavimas uztruko: " << duration.count() << " sekundziu" << endl;
                    cout << i+1 << " -ojo failo nuskaitymas ir rusiavimas su Deque uztruko: " << fulldur.count() << " sekundziu" << endl;
                    //spausdinimas(silpniDeq, "NuskriaustiD"+ std::to_string(num) + ".txt");
                    spausdinimas(StudDeq, "NuskriaustiD" + std::to_string(num) + ".txt");
                    spausdinimas(kietiDeq, "KietiD"+ std::to_string(num) + ".txt");
                    StudDeq.clear();
                    silpniDeq.clear();
                    kietiDeq.clear();
                    cout << endl;

                    system("pause");
                }
            }
        }
    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}

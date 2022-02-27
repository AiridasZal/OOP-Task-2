# OOP Program
## V0.1 Galimybės:
1. Programa nuskaito vartotojo įvedamus duomenis (struktūros elementus):
 
>*Mokinio vardą, pavardę, namų darbų ir egzamino rezultatus.*

2. Vartotojo įvesti duomenys talpinami į *linked list*.
3. Programa apskaičiuoja kiekvieno mokinio galutinį balą naudojant formulę:


>**_Galutinis_ = 0.4 * _vidurkis_ + 0.6 * _egzaminas_** 

arba 

>**_Galutinis_ = 0.4 * _mediana_ + 0.6 * _egzaminas_**

4. Mokinių kiekis ir įvedamų pažymių skaičius yra dinamiškas dydis.
5. Galimybė atsitiktinai generuoti mokinio namų darbų ir egzamino balus.

## V0.1.1 Papildymas:
1. Programa papildyta atsitiktinių pažymių generavimu masyvų implementacijoje.
2. Pataisytas klaidingų įvedimų numatymas.

## V0.2 Atnaujinimai:
1. Atsisakyta tiesinio sąrašo (angl. linked list) naudojimo, pilnai realizuotas struktūrų vektoriuose naudojimas.
2. Pridėta galimybė įvesti duomenis iš failo.
3. Rezultatai rūšiuojami pagal pavardę.

## V0.3 Atnaujinimai:
1. Funkcijų antraštės perkeltos į failą **functions.h**, o pačios funkcijos į **functions.cpp**.
2. Implementuotas išimčių valdymas (angl. Exception Handling), kai programa neranda failo "kursiokai.txt".

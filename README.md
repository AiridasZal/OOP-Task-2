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

## V0.4 Atnaujinimai:

1. Implementuotas automatinis failų generavimas nuo 1000 iki 10000000 eilučių failams su pasirenkamu studentų namų darbų skaičiumi.
2. Implementuotas sugeneruotų failų nuskaitymas ir išrūšiavimas į atskirus failus pagal galutinį pažymį. (Studentai, kurių galutinis balas < 5.0 keliauja į Nuskriausti*.txt, o kurių galutinis balas >= 5.0 į Kieti*.txt)
3. Implementuotas funkcijų veikimo laiko apskaičiavimas.

**Programos veikimo greičio (spartos) analizė**:

|    Vector    |    1000   |   10000   |  100000  |  1000000 | 10000000 |
|:------------:|:---------:|:---------:|:--------:|:--------:|----------|
|  Generavimas | 0.0019833 | 0.0140222 | 0.117207 | 1.37604  | 13.5376  |
|  Nuskaitymas | 0.0026898 | 0.024597  | 0.292046 | 2.44176  | 24.6615  |
| Išrūšiavimas | 0.0006733 | 0.0055393 | 0.056203 | 0.543265 | 5.8276   |
|    Išvedimas | 0.0047154 | 0.0265922 | 0.266584 | 2.33913  | 24.2102  |
|      Bendras | 0.0118902 | 0.0706046 | 0.771332 | 6.94353  | 71.6242  |
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
|  Generavimas | 0.0027923 | 0.0132638 | 0.125297 | 1.45284  | 13.9109  |
|  Nuskaitymas | 0.0028097 | 0.0238191 | 0.221508 | 2.5862   | 26.4137  |
| Išrūšiavimas | 0.0005547 | 0.0049201 | 0.046118 | 0.524698 | 5.53947  |
|    Išvedimas | 0.0215616 | 0.151341  | 1.36776  | 8.06367  | 76.1348  |
|      Bendras | 0.0294116 | 0.198143  | 1.74948  | 12.5405  | 122.721  |
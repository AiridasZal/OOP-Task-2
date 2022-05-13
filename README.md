# Studentų pasiekimų rezultatų skaičiuoklė

## Programos įdiegimas UNIX kompiuteryje

- `git clone https://github.com/AiridasZal/OOP-Task-1`
- `cd OOP-Task-1`
- `make main`
- `./main`

## V2.0 Atnaujinimai
1. Sukurta keletas Unit Testų, naudojant Catch2 framework'ą.

## V1.5 Atnaujinimai
1. Sukurta Base klasė (zmogus) ir Derived klasė (Studentas).
2. Base klasėje aprašyta (zmogus) vardas ir pavardė, pasiekiama tik iš išvestinių klasių.

## V1.2.1 Atnaujinimai

1. Atsisakyta std::remove_copy_if rūšiavimo dėl netinkamo veikimo. (Kopijavo, tačiau nešalino)

## V1.2 Atnaujinimai

1. ***Rule of Three*** įgyvendinimas.
2. Papildomų operatorių (palyginimo ir kopijavimo) pridėjimas.

## V1.1 Atnaujinimai

1. Atsisakyta lėtesnių mokinių skirstymo strategijų.
2. Struktūra pakeista į klasę.
3. Kodas pritaikytas klasei.

Struktūros ir klasės spartos analizė

| Dydis\Konteineris | Structure | Class   |
|-------------------|-----------|---------|
| 100000            | 0.322111  | 0.47478 |
| 1000000           | 3.45288   | 5.22309 |

Klasės spartos analizės naudojant skirtingus optimizavimo flag'us

| Dydis\Konteineris | -O1      | -O2      | -O3      |
|-------------------|----------|----------|----------|
| 100000            | 0.297189 | 0.285169 | 0.279394 |
| 1000000           | 3.18945  | 3.17024  | 3.18166  |

## V1.0 Atnaujinimai

1. Įgyvendintas patobulintas mokinių skaidymas.

**Mokinių skirstymo greičio (spartos) analizė su 3 skirtingais konteineriais ir 2 skirtingomis strategijomis**

| Container\Size |    1000   |   10000   |   100000  |  1000000 | 10000000 |
|---------------:|:---------:|:---------:|:---------:|:--------:|:--------:|
|  Vector 1 str. | 0.0002082 | 0.00157   | 0.0165726 | 0.206244 | 2.18961  |
|  Vector 2 str. | 0.0001094 | 0.0005674 | 0.0112997 | 0.141784 | 1.4222   |
|    List 1 str. | 0.000182  | 0.0014088 | 0.0226309 | 0.245209 | 2.76143  |
|    List 2 str. | 0.0000759 | 0.0005899 | 0.0116755 | 0.136401 | 1.44716  |
|   Deque 1 str. | 0.0001017 | 0.0012263 | 0.016823  | 0.183298 | 2.10436  |
|   Deque 2 str. | 0.0000675 | 0.0006402 | 0.010271  | 0.121397 | 1.44716  |


**Programos RAM panaudojimas išreikštas % visų RAM (16 GB) atliekant skaičiavimus su 10M failais**

| Container\Strategy | Strategy #1 | Strategy #2 |
|-------------------:|:-----------:|-------------|
|             Vector |     31.8    |      25     |
|               List |      32     |     23.5    |
|              Deque |      28     |     19.5    |

**Mokinių skaidymo funkcijos spartinimo bandymas pritaikant algoritmą std::remove_copy_if**

| Size\Method | Strategy #2 | #2 + remove_copy_if |
|------------:|:-----------:|---------------------|
|        1000 | 0.0001292   | 0.0000613           |
|       10000 | 0.0006771   | 0.0007114           |
|      100000 | 0.0113217   | 0.0086322           |
|     1000000 | 0.140314    | 0.0896481           |
|    10000000 | 1.6041      | 1.05716             |

## V0.5 Atnaujinimai

1. Implementuoti skaičiavimai su dviem papildomais STL konteineriais: List ir Deque.
2. Atlikta spartos analizė siekiant išanalizuoti skirtingų tipų konteinerių pranašumus.

Kompiuterio specifikacijos: Intel Core i7-6700HQ CPU @ 2.60GHz, 16 GB RAM, SSD 970 EVO Plus
**Programos veikimo greičio (spartos) analizė su 3 skirtingais konteineriais**:

|      Container\Size |    1000   |   10000   |   100000  |  1000000 | 10000000 |
|--------------------:|:---------:|:---------:|:---------:|:--------:|:--------:|
|  Vector Nuskaitymas | 0.0018455 | 0.0206329 | 0.178534  | 1.88479  | 20.1084  |
|    List Nuskaitymas | 0.0018228 | 0.0193562 | 0.192703  | 1.96293  | 20.3813  |
|   Deque Nuskaitymas | 0.0032357 | 0.021522  | 0.179479  | 1.9222   | 20.6482  |
| Vector Išrūšiavimas | 0.0002252 | 0.0024307 | 0.0208422 | 0.227679 | 2.52166  |
|   List Išrūšiavimas | 0.000596  | 0.0045538 | 0.0293545 | 0.310627 | 3.51064  |
|  Deque Išrūšiavimas | 0.0001436 | 0.0014275 | 0.0210595 | 0.212368 | 2.76909  |
|      Vector Bendrai | 0.0047167 | 0.0287869 | 0.246535  | 2.62027  | 28.9934  |
|        List Bendrai | 0.0029372 | 0.0288093 | 0.278628  | 3.02584  | 36.698   |
|       Deque Bendrai | 0.0043097 | 0.0290568 | 0.262061  | 2.79244  | 31.6902  |

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

## V0.3 Atnaujinimai:
1. Funkcijų antraštės perkeltos į failą **functions.h**, o pačios funkcijos į **functions.cpp**.
2. Implementuotas išimčių valdymas (angl. Exception Handling), kai programa neranda failo "kursiokai.txt".

## V0.2 Atnaujinimai:
1. Atsisakyta tiesinio sąrašo (angl. linked list) naudojimo, pilnai realizuotas struktūrų vektoriuose naudojimas.
2. Pridėta galimybė įvesti duomenis iš failo.
3. Rezultatai rūšiuojami pagal pavardę.

## V0.1.1 Papildymas:
1. Programa papildyta atsitiktinių pažymių generavimu masyvų implementacijoje.
2. Pataisytas klaidingų įvedimų numatymas.

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

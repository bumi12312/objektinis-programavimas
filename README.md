<img width="2863" height="2268" alt="image" src="https://github.com/user-attachments/assets/d7a543e6-547b-4ea5-b976-782456b10c15" /># Studentų galutinio balo skaičiavimas (v0.3)

## Testavimo sistema
- CPU: CPU Intel(R) Core(TM) Ultra 7 258V
- RAM: 32 GB
- Diskas: SSD (NVMe)
- Kompiliatorius: GNU GCC, Release režimas

## Matavimo metodika
Laikas matuojamas su `std::chrono`. Kiekvienas testas paleistas 3 kartus, lentelėse pateiktas vidurkis (sekundėmis).
Matuojami žingsniai: nuskaitymas iš failo, dalijimas į dvi grupes (`< 5.0` ir `>= 5.0`), rūšiavimas pagal galutinį balą, išvedimas į du failus.

## Failų kūrimo laikas

Įrašų skaičius	Laikas (s)
1 000	0.0019453
10 000	0.0033588
100 000	0.0287056
1 000 000	0.304699
10 000 000	3.38117

## std::vector

<img width="1302" height="348" alt="image" src="https://github.com/user-attachments/assets/a053b752-e1e0-4a3b-bf0b-619242a33039" />

## std::list

<img width="1298" height="346" alt="image" src="https://github.com/user-attachments/assets/8cf81986-d0f6-4223-ba61-c6698dfbdc5f" />

## std::vector adresai

<img width="1172" height="282" alt="image" src="https://github.com/user-attachments/assets/56e5c0e9-30fa-49ca-abad-1b3195911998" />

## std::list adresai

<img width="1170" height="296" alt="image" src="https://github.com/user-attachments/assets/8dea0bb5-656d-4e66-995d-ac004e1673d4" />

## Išvados

- **Bendra sparta.** `std::vector` yra greitesnis. Su 1 000 000 ir 10 000 000 įrašų `std::list` visą ciklą atlieka maždaug **1,5 karto lėčiau** (1,43 s prieš 2,15 s ir 18,15 s prieš 27,41 s). Mažiems failams (1 000 – 10 000) skirtumas nedaro reikšmingos įtakos, o išskirtinis `list` išvedimo laikas su 1 000 įrašų (0,0167 s) greičiausiai yra matavimo paklaida.
- **Rūšiavimas yra pagrindinis skirtumas.** `list` rūšiavimas 3,8 karto lėtesnis su 1 mln. ir **5,1 karto lėtesnis** su 10 mln. įrašų. Su `list` rūšiavimas užima 42 % viso laiko, o su `vector` tik 13 %. Priežastis: `vector` elementai guli atmintyje vienas po kito (žr. adresus žemiau), todėl gerai išnaudojama procesoriaus talpykla. `list` mazgai išmėtyti, todėl kiekvienas elementas gali sukelti talpyklos nepataikymą. Be to, augant duomenų kiekiui skirtumas didėja (`vector` rūšiavimas 1 mln. → 10 mln. užtruko 14 kartų ilgiau, o `list` – 19 kartų).
- **Nuskaitymas iš failo** abiem konteineriams beveik vienodas (10 mln. įrašų: 8,00 s ir 7,91 s). Didžiausią laiko dalį užima eilučių skaidymas (`istringstream`), todėl konteinerio pasirinkimas čia beveik nieko nekeičia. `vector` su 10 mln. įrašų buvo net šiek tiek lėtesnis tik dėl papildomų atminties perskyrimų.
- **Išvedimas į failus** su 1 mln. įrašų `list` buvo 1,4 karto lėtesnis, bet su 10 mln. skirtumo nebeliko (6,94 s ir 7,17 s). Čia laiką lemia diskas ir formatavimas (`setw`, `ofstream`), o ne einimas per konteinerį. Su `vector` 10 mln. įrašų išvedimas ir nuskaitymas kartu užėmė 84 % laiko.
- **Dalijimas į dvi grupes** užima nedidelę dalį laiko (~3–4 %). Su 1 mln. įrašų `list` buvo šiek tiek greitesnis (0,076 s prieš 0,081 s), o su 10 mln. – lėtesnis (0,92 s prieš 0,70 s). Taigi `list` pranašumo čia nepastebėjome, nes studentai perkeliami į naujus konteinerius, o ne šalinami iš pradinio.
- **Atmintis.** Visi testai (iki 10 mln. įrašų) sėkmingai pavyko abiem konteineriams (32 GB RAM). Teoriškai `list` kiekvienam elementui papildomai naudoja dvi rodykles ir atskirą atminties alokaciją, todėl su dideliais duomenimis jis užimtų daugiau vietos (šioje užduotyje atminties sunaudojimas nematuotas).
- **Adresai atmintyje.** `vector` elementų adresai eina iš eilės ir skiriasi po 104 baitus (`0x…cd10`, `0x…cd78`, `0x…cde0`), tai yra `sizeof(studentas)`. `list` mazgai nėra vienas šalia kito: antras mazgas yra toli nuo pirmo ir trečio (`0x…3b510`, `0x…58570`, `0x…3b590`), be to kiekvienas mazgas didesnis nei pats objektas, nes saugo rodykles.
- **Bendra išvada.** Šiai užduočiai (įrašų nuskaitymas, rūšiavimas, perėjimas per visus elementus) geresnis pasirinkimas yra `std::vector`. `std::list` verta rinktis, kai dažnai reikia įterpti ar šalinti elementus sąrašo viduryje be perkėlimo, o šioje užduotyje to nedaroma.

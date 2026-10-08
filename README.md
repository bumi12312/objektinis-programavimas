# objektinis-programavimas

## Failų generavimas

Failus sugeneravo gana greitai, o laikas didėjo proporcingai kiekiui. Pavyzdžiui, jei faile įrašų 10 kartų daugiau, tai ir generavimo laikas apie 10 kartų ilgesnis.

| Įrašų | Generavimo laikas (s) |
|------:|----------------------:|
| 1 000 | 0.002604 |
| 10 000 | 0.0051326 |
| 100 000 | 0.0323453 |
| 1 000 000 | 0.32815 |
| 10 000 000 | 3.1352 |

## Programos veikimo analizė

Nuskaitymas užtrunka ilgiausiai, antroje vietoje – rūšiavimas. Bendras programos veiksmingumas palyginus yra visai geras. Nuskaitymo standartinis nuokrypis didžiausias (~6 s).

### Vidurkiai (3 bandymai)

| Įrašų | Nuskaitymas | Dalinimas | Rūšiavimas | Išvedimas | Viso (s) |
|------:|------------:|----------:|-----------:|----------:|---------:|
| 1 000 | 0.0017 | 0.0002 | 0.0003 | 0.0031 | 0.0052 |
| 10 000 | 0.0120 | 0.0018 | 0.0036 | 0.0083 | 0.0256 |
| 100 000 | 0.1149 | 0.0147 | 0.0456 | 0.0588 | 0.2340 |
| 1 000 000 | 1.1487 | 0.1738 | 0.6943 | 0.6596 | 2.6763 |
| 10 000 000 | 16.9607 | 1.7464 | 9.0395 | 7.1748 | 34.9213 |

### Atskiri bandymai

<details>
<summary>Bandymas #1</summary>

| Įrašų | Nuskaitymas | Dalinimas | Rūšiavimas | Išvedimas | Viso (s) |
|------:|------------:|----------:|-----------:|----------:|---------:|
| 1 000 | 0.0014 | 0.0002 | 0.0003 | 0.0028 | 0.0047 |
| 10 000 | 0.0122 | 0.0019 | 0.0042 | 0.0079 | 0.0261 |
| 100 000 | 0.1183 | 0.0136 | 0.0445 | 0.0609 | 0.2373 |
| 1 000 000 | 1.1275 | 0.1536 | 0.6309 | 0.5427 | 2.4547 |
| 10 000 000 | 14.1497 | 1.9861 | 8.2115 | 8.6248 | 32.9721 |

</details>

<details>
<summary>Bandymas #2</summary>

| Įrašų | Nuskaitymas | Dalinimas | Rūšiavimas | Išvedimas | Viso (s) |
|------:|------------:|----------:|-----------:|----------:|---------:|
| 1 000 | 0.0015 | 0.0002 | 0.0003 | 0.0037 | 0.0056 |
| 10 000 | 0.0120 | 0.0017 | 0.0032 | 0.0078 | 0.0246 |
| 100 000 | 0.1144 | 0.0172 | 0.0445 | 0.0582 | 0.2344 |
| 1 000 000 | 1.1487 | 0.2121 | 0.5650 | 0.5440 | 2.4699 |
| 10 000 000 | 16.5991 | 1.5668 | 11.6841 | 7.3494 | 37.1994 |

</details>

<details>
<summary>Bandymas #3</summary>

| Įrašų | Nuskaitymas | Dalinimas | Rūšiavimas | Išvedimas | Viso (s) |
|------:|------------:|----------:|-----------:|----------:|---------:|
| 1 000 | 0.0021 | 0.0003 | 0.0003 | 0.0027 | 0.0054 |
| 10 000 | 0.0117 | 0.0017 | 0.0033 | 0.0093 | 0.0260 |
| 100 000 | 0.1120 | 0.0132 | 0.0479 | 0.0572 | 0.2303 |
| 1 000 000 | 1.1698 | 0.1556 | 0.8869 | 0.8921 | 3.1044 |
| 10 000 000 | 20.1332 | 1.6862 | 7.2230 | 5.5501 | 34.5925 |

</details>

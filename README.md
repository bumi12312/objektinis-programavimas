# objektinis-programavimas

Failus sugeneravo gana greitai ir didėjo priklausomai nuo kiekio. Pavyzdžiui jeigu faile įrašų 10 kartų daugiau,
tai ir generavimo laikas 10 kartų ilgesnis.

Sukurtas failas su 1000 irasu per 0.002604 s.
Sukurtas failas su 10000 irasu per 0.0051326 s.
Sukurtas failas su 100000 irasu per 0.0323453 s.
Sukurtas failas su 1000000 irasu per 0.32815 s.
Sukurtas failas su 10000000 irasu per 3.1352 s.

Nuskaitymas užtrunka ilgiausiai, o antroj vietoj rūšiavimas. Bendras programos veiksmingumas palyginus visai greitas.
Nuskaitymo standartinis nuokrypis didžiausias ~6 sek.

#vidurkiai

Irasu       Nuskaitymas   Dalinimas     Rusiavimas    Isvedimas     Viso (s)
--------------------------------------------------------------------------------
1000        0.0017        0.0002        0.0003        0.0031        0.0052
10000       0.0120        0.0018        0.0036        0.0083        0.0256
100000      0.1149        0.0147        0.0456        0.0588        0.2340
1000000     1.1487        0.1738        0.6943        0.6596        2.6763
10000000    16.9607       1.7464        9.0395        7.1748        34.9213

#1

Irasu       Nuskaitymas   Dalinimas     Rusiavimas    Isvedimas     Viso (s)
--------------------------------------------------------------------------------
1000        0.0014        0.0002        0.0003        0.0028        0.0047
10000       0.0122        0.0019        0.0042        0.0079        0.0261
100000      0.1183        0.0136        0.0445        0.0609        0.2373
1000000     1.1275        0.1536        0.6309        0.5427        2.4547
10000000    14.1497       1.9861        8.2115        8.6248        32.9721

#2

Irasu       Nuskaitymas   Dalinimas     Rusiavimas    Isvedimas     Viso (s)
--------------------------------------------------------------------------------
1000        0.0015        0.0002        0.0003        0.0037        0.0056
10000       0.0120        0.0017        0.0032        0.0078        0.0246
100000      0.1144        0.0172        0.0445        0.0582        0.2344
1000000     1.1487        0.2121        0.5650        0.5440        2.4699
10000000    16.5991       1.5668        11.6841       7.3494        37.1994

#3

Irasu       Nuskaitymas   Dalinimas     Rusiavimas    Isvedimas     Viso (s)
--------------------------------------------------------------------------------
1000        0.0021        0.0003        0.0003        0.0027        0.0054
10000       0.0117        0.0017        0.0033        0.0093        0.0260
100000      0.1120        0.0132        0.0479        0.0572        0.2303
1000000     1.1698        0.1556        0.8869        0.8921        3.1044
10000000    20.1332       1.6862        7.2230        5.5501        34.5925

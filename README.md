# 1-oji užduotis (C++)

Programa skirta studentų galutiniams balams apskaičiuoti pagal namų darbų (vidurkį arba medianą) ir egzamino rezultatus, duomenims surūšiuoti, suskirstyti į dvi kategorijas (`< 5.0` ir `>= 5.0`) bei `std::vector` ir `std::list` konteinerių ir skirstymo strategijų spartai tirti.

---

## Diegimo ir paleidimo instrukcija

1. **Atsisiųskite projektą:** atsisiųskite `.zip` archyvą iš GitHub ir išarchyvuokite jį į pasirinktą aplanką.
2. **Įsitikinkite, kad įdiegtas CMake:** terminale patikrinkite versiją komanda `cmake --version`. Jei neįdiegtas, atsisiųskite iš [cmake.org/download](https://cmake.org/download/) (Windows) arba įdiekite per terminalą (`brew install cmake` macOS, `sudo apt-get install cmake` Linux).
3. **Sukurkite `build` aplanką ir atidarykite jį terminale:** aplanke **"Kodo failai"** įvykdykite:
   ```bash
   mkdir build && cd build
   ```
4. **Sukonfigūruokite projektą:** terminale įveskite:
   ```bash
   cmake ..
   ```
   *(Jei Windows sistemoje naudojate MinGW, įveskite: `cmake -G "MinGW Makefiles" ..`)*
5. **Sukompiliuokite programą:** terminale įveskite:
   ```bash
   cmake --build . --config Release
   ```
   *(Arba `make` / `mingw32-make`, priklausomai nuo naudojamo kompiliatoriaus.)*
6. **Paleiskite programą:** `build` (arba `build\Release`) aplanke atsiras vykdomasis failas `studentai.exe` (Linux/macOS – `studentai`). Paleiskite jį paspaudę dukart arba terminale:
   ```bash
   .\studentai.exe          # Windows (MinGW)
   .\Release\studentai.exe  # Windows (MSVC)
   ./studentai              # Linux / macOS
   ```
   
## Pagrindinės programos funkcijos

* **Duomenų įvestis ir generavimas:** rankinis duomenų įvedimas, atsitiktinis studentų generavimas, duomenų nuskaitymas iš failo bei 5 testinių failų (`1 000` – `10 000 000` įrašų) generavimas.
* **Galutinio balo skaičiavimas:** naudojama formulė {Galutinis} = 0.4*{ND} + 0.6*{Egzaminas} (pasirenkant ND vidurkį arba medianą).
* **Kategorizavimas ir rūšiavimas:** studentų skirstymas į dvi grupes (`< 5.0` ir `>= 5.0`), rūšiavimas pagal vardą, pavardę arba galutinį balą bei išvedimas į ekraną ar atskirus failus.
* **Konteinerių ir atminties tyrimas:** `std::vector` ir `std::list` operacijų laiko palyginimas (3 bandymų vidurkis), objektų adresų atmintyje stebėjimas bei 3 skirstymo strategijų efektyvumo analizė.

---

## Versijų istorija (Releases)

* **v0.1** – Pradinė programos versija: rankinis duomenų įvedimas, atsitiktinis pažymių generavimas, galutinio balo skaičiavimas pagal vidurkį ir medianą, rezultatų išvedimas terminale.
* **v0.2** – Sukurtas studentų failų generatorius. Be to pridėta funkcija kuri suskaido studentus į dvi grupes, pirma - kurių galutinis pažymys >=5, antra - kurių galutinis pažymys <5. Taip pat pridėtas rikiavimas. Programos kodas išskaidytas į modulinius `.h` ir `.cpp` failus.
* **v0.3** – Patobulinta programos v0.2 versija ir atlikta studentų rūšiavimo bei duomenų suvedimo spartos analizė.

---

# Spartos analizė

Testavimo sistema:
- CPU: CPU Intel(R) Core(TM) Ultra 7 258V
- RAM: 32 GB
- Diskas: SSD (NVMe)
- Kompiliatorius: GNU GCC, Release režimas

## Failų generavimas

<img width="734" height="155" alt="image" src="https://github.com/user-attachments/assets/3b520f6d-243c-42fd-b445-d0c116619978" />

## Failų testavimas (vector tipo konteineriai):

1000 įrašų:

<img width="975" height="126" alt="image" src="https://github.com/user-attachments/assets/c76440d1-4094-4513-a449-7139a2fc214f" />

10000 įrašų:

<img width="975" height="124" alt="image" src="https://github.com/user-attachments/assets/59f31542-dd6a-412f-9803-f6ef03c3fafc" />

100000 įrašų:

<img width="975" height="129" alt="image" src="https://github.com/user-attachments/assets/f2db36b8-77e8-4789-ab99-2c884cbcc155" />

1000000 įrašų:

<img width="975" height="120" alt="image" src="https://github.com/user-attachments/assets/ef6f9117-c669-40f1-8875-dfdd40f01d9f" />

10000000 įrašų:

<img width="975" height="118" alt="image" src="https://github.com/user-attachments/assets/0ca02b6f-3509-4cef-88a6-0ab5bdcece52" />

## Failų testavimas (list tipo konteineriai):

1000 įrašų:

<img width="975" height="128" alt="image" src="https://github.com/user-attachments/assets/2a7f0620-a9af-4bad-99cc-6261c3e7b4f1" />

10000 įrašų:

<img width="975" height="126" alt="image" src="https://github.com/user-attachments/assets/4b78a4bd-6c96-4343-a3e7-dc7a6eb3488d" />

100000 įrašų:

<img width="975" height="124" alt="image" src="https://github.com/user-attachments/assets/969dbfc9-8415-42ae-bddd-53a40a764a8d" />

1000000 įrašų:

<img width="975" height="123" alt="image" src="https://github.com/user-attachments/assets/ac2a6df7-3d72-4a6d-b585-be46863e916d" />

10000000 įrašų:

<img width="975" height="119" alt="image" src="https://github.com/user-attachments/assets/d421db65-c79c-4226-9fd0-19359895d4a8" />

## Konteinerių palyginimas (`std::vector` vs `std::list`):

### 1 000 įrašų:

| Operacija | Vector (s) | List (s) |
| :--- | :---: | :---: |
| Nuskaitymas | 0.00138 | 0.00133 |
| Dalinimas | 0.00011 | 0.00010 |
| Rūšiavimas | 0.00013 | 0.00008 |
| Išvedimas (kietiakiai) | 0.00216 | 0.01531 |
| Išvedimas (vargšiukai) | 0.00168 | 0.00997 |
| **Viso** | **0.00546** | **0.02680** |

### 10 000 įrašų:

| Operacija | Vector (s) | List (s) |
| :--- | :---: | :---: |
| Nuskaitymas | 0.01053 | 0.00936 |
| Dalinimas | 0.00111 | 0.00092 |
| Rūšiavimas | 0.00113 | 0.00156 |
| Išvedimas (kietiakiai) | 0.00538 | 0.00679 |
| Išvedimas (vargšiukai) | 0.00374 | 0.00478 |
| **Viso** | **0.02188** | **0.02341** |

### 100 000 įrašų:

| Operacija | Vector (s) | List (s) |
| :--- | :---: | :---: |
| Nuskaitymas | 0.07710 | 0.09679 |
| Dalinimas | 0.00778 | 0.01036 |
| Rūšiavimas | 0.01357 | 0.05062 |
| Išvedimas (kietiakiai) | 0.03220 | 0.05698 |
| Išvedimas (vargšiukai) | 0.02281 | 0.04014 |
| **Viso** | **0.15346** | **0.25489** |

### 1 000 000 įrašų:

| Operacija | Vector (s) | List (s) |
| :--- | :---: | :---: |
| Nuskaitymas | 0.67681 | 1.05186 |
| Dalinimas | 0.07455 | 0.10406 |
| Rūšiavimas | 0.16367 | 1.11279 |
| Išvedimas (kietiakiai) | 0.31037 | 0.60290 |
| Išvedimas (vargšiukai) | 0.21414 | 0.40782 |
| **Viso** | **1.43954** | **3.27943** |

### 10 000 000 įrašų:

| Operacija | Vector (s) | List (s) |
| :--- | :---: | :---: |
| Nuskaitymas | 9.03028 | 10.21016 |
| Dalinimas | 0.61413 | 1.05008 |
| Rūšiavimas | 2.52699 | 10.72600 |
| Išvedimas (kietiakiai) | 4.07423 | 5.24164 |
| Išvedimas (vargšiukai) | 3.09844 | 3.96007 |
| **Viso** | **19.34406** | **31.18795** |

## Strategijų testavimas

1 strategija: Bendro konteinerio skaidymas i du naujus konteinerius (vargsiukai ir kietiakiai):

<img width="864" height="270" alt="image" src="https://github.com/user-attachments/assets/d91b87dd-2361-40be-a00f-469ab323623b" />

2 strategija: Skaidymas panaudojant viena nauja konteineri (vargsiukai) ir trynima is bendro:

<img width="866" height="272" alt="image" src="https://github.com/user-attachments/assets/9a774b4a-ffe5-4cfd-9489-922966e69b04" />

3 strategija: Optimizuotas skaidymas (vector: partition + move, list: splice):

<img width="872" height="278" alt="image" src="https://github.com/user-attachments/assets/f645c165-73c2-4465-b0ae-0c75c9e8db5e" />

# Išvados

1. **`std::vector` ir `std::list` spartos palyginimas:**
   * Didėjant įrašų skaičiui (`100 000` – `10 000 000`), `std::vector` yra ženkliai spartesnis už `std::list` visose operacijose.
   * Didžiausias skirtumas išryškėja **rūšiavimo** etape: surūšiuoti `1 000 000` įrašų su `std::vector` užtruko `0,16 s`, o su `std::list` – `1,11 s` (~6,8 karto lėčiau);
2. **Duomenų kiekio įtaka:**
   * Mažuose failuose (`1 000` – `10 000` įrašų) abiejų konteinerių apdorojimo laikas skiriasi tik tūkstantosiomis sekundės dalimis (`0,02188 s` vs `0,02341 s` ties `10 000` įrašų), o galutinį rezultatą labiau veikia disko įvesties/išvesties (I/O) svyravimai nei paties konteinerio struktūra. Realus duomenų struktūros pranašumas pasimato tik nuo `100 000` ir daugiau įrašų.

3. **Studentų skirstymo strategijų efektyvumas:**
   * **1 strategija** (skaidymas į du naujus konteinerius) veikia tiesiniu $O(n)$ laiku ir yra greita, tačiau reikalauja dvigubai daugiau operatyviosios atminties, nes vienu metu atmintyje laikomas ir pradinis konteineris, ir abi išskaidytos jo kopijos.
   * **2 strategija** (vienas naujas konteineris + trynimas iš bendro) su mažais failais dirba pakankamai greitai, tačiau didėjant įrašų skaičiui `std::vector` vykdymo laikas pradeda drastiškai ilgėti.
   * **3 strategija** (optimizuotas skaidymas naudojant `std::partition` + perkėlimą vektoriui ir `std::list::splice` sąrašui) yra greičiausia ir efektyviausia – ji išlaiko tiesinį $O(n)$ veikimo laiką ir nešvaisto papildomos atminties duomenų kopijavimui.


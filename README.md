
## Dokumentacija

Projekto dokumentacija buvo sukurta naudojant `Doxygen` įrankį. Ji apima:

- HTML versiją naršymui per naršyklę (`docs/index.html`)
- PDF versiją, sugeneruotą per LaTeX (naudojantis Overleaf) – `docs/manual.pdf`

Dokumentacijoje aprašyti visi klasės metodai, jų paskirtis bei naudojimo pavyzdžiai.

## Vienetų testavimas

Testavimas atliktas naudojant `Catch2` testų biblioteką. Sukurti testai tikrina šiuos metodus:

- `getAverage()` – tikrinamas pažymių vidurkio apskaičiavimas
- `getFinalMark()` – vertinama, ar grąžinama teisinga galutinio pažymio reikšmė
- `operator<()` – testuojama, ar veikia studentų palyginimas
- `operator==()` – testuojama, ar veikia studentų lygybės tikrinimas
- `getName()` / `getSurname()` – testuojamas duomenų grąžinimas

Testai parašyti taip, kad padėtų užtikrinti programos funkcionalumo teisingumą.

## Naudojimosi instrukcija

Norint paleisti projektą, rekomenduojama naudoti `cmake`:

```bash
cmake -B build
cmake --build build

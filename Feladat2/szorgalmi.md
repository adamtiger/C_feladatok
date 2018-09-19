# Ered? ellenállás számítása

Ebben a feladatban egy olyan program megvalósítása lenne a cél, ami képes ered? ellenállást számolni
egy áramkörben lev? ellenállásokra. A program a szabványos bemeneten megkap egy új ellenállást és azt, hogy az 
párhuzamosan vagy sorosan van e kapcsolva az eddig már felépített rendszerhez. Ezt követ?en kiszámolja az 
aktuális ered? ellenállást. A felhasználó megfelel? módon tudja jelezni, hogy most már végzett. Ekkor az
eredményt kiírja a képerny?re. Fontos a hibakezelés. legyen továbbá lehetséges reset-elni (el?lr?l kezdeni), illetve
egyet visszalépni, de sorozatos visszalépés nem lehet.

Alább a részletek következnek.

Bemenet:
* ellenállás soros kapcsolásakor ez legyen a bemenet a képerny?n: R 0
* ellenállás párhuzamos kapcsolásakor: R 1
* ha kész van: NA -3
* reset: NA -2
* egyet visszalépni (utolsó ellenállás levétele): NA -1
R az új bekötend? ellenállás értéke, míg utána szóközzel elválasztva, hogy soros (0) vagy párhuzamos (1) bekötés jön. NA azt jelenti, nem számít az értéke.

Hibakezelés:
* nem pozitív ellenállás esetén: írja ki, hogy az ellenállás negatív. A program ezután kínálja fel újra
az ellenállás csatolás lehetoségét.
* nem létezo kapcsolási mód esetén: írja, ki hogy érvénytelen bekötési mód. A program ezután kínálja fel újra
az ellenállás csatolás lehetoségét.

Példa a bemenet használatra:

![kapcsolas](ellenallas.png)

**Teszt:**

Bemenetek: (10 0) (8 0) (3 1) (20 0) (4.8 1) (3.9 0) (4.1 0)
Elvárt kimenet: 11.9582

*Feltöltend?:* csak a forráskód egy .c kiterjesztés? fájlban, feltöltés a moodle-ben a 3. labor szorgalmi feladatához <br/>
*Beadási határid?:* 2018.09.26, labor kezdetéig

# Mátrixok szorzása

Ebben a feladatban két mátrix szorzását megvalósító függvény implementálása a cél. 

1.	Készíts struktúrát, aminek 3 tagja van: magassága, szélessége a mátrixnak, egy tömb a matrix elemeivel. Feltesszük, 
hogy a mátrixnak legfeljebb **1000** eleme lehet. A tömb sorfolytonosan tárolja a mátrix értékeit.
2.	Készíts egy mátrixot kiíró függvényt. A függvény soronként írja ki a mátrixot. 
3.	Készíts egy függvényt, ami paraméterül vesz két mátrix struktúrát, amiket szorozni szeretnénk. A függvény adja vissza a mátrix 
szorzás eredményét egy mátrix struktúrában.

Sorfolytonosság pontosabb leírása:

|1 3| <br/>
|2 0|   -- > 1 3 2 0 5 4 <br/>
|5 4| <br/>

Tehát a baloldali 2D-s mátrix a job oldalon látható 1D-ós vektorban lesz tárolva. 

*Feltöltendő:* csak a forráskód egy .c kiterjesztésű fájlban, feltöltés a moodle-ben a 4b. labor szorgalmi feladatához <br/>
*Beadási határidő:* 2018.10.10, labor kezdetéig

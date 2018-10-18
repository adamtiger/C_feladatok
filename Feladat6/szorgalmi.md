# Halmaz

Ebben a feladatban halmazokról lesz szó. A halmaz most azt jelenti, hogy egész számokat tárol rendezetten egy tömbben (növekvő sorrendben), és minden elem csak egyszer fordul elő.
A halmaz a következő kompenesekből álljon: <br/>

**S1**: Struktúra (Set néven), ami egy tömbben képes tárolni akárhány elemet. Illetve eltárolja, hogy aktuálisan hány elem van a tömbben.
<br/> **F1**: Függvény, ami létrehoz egy üres halmazt.
<br/> **F2**: Függvény, ami inicializálja a halmazt. A halmaz alapállapotban 0 elemű.
<br/> **F3**: Függvény, ami mélymásolatot készít egy struktúráról. Ez azt jelenti, hogy a struktúrában levő elemeket új memória területre fogja másolni. Így szemben a sima értékadással (ez esetben shallow copy) szemben, ha módosítjuk az egyik struktúra elemeit, az nem lesz hatással a másik struktúra elemeire. 
<br/> **F4**: Függvény, ami új elemet ad a halmazhoz. Ha van már ilyen elem a halmazban, akkor nem adja hozzá, ha nincs akkor igen. Az új halmazban szintén legyenek rendezettek az elemek.
<br/> **F5**: Függvény, ami egy tömb összes elemét hozzáadja a halmazhoz.
<br/> **F6**: Függvény, ami megnézi, hogy egy adott elem szerepel e a halmazban.
<br/> **F7**: Függvény, ami ellenőrzi, hogy két halmaz egyezik e. (hossz és elemek)
<br/> **F8**: Függvény, ami két struktúra unióját adja vissza egy új struktúrában.
<br/> **F9**: Függvény, ami két halmaz különbségét veszi.
<br/> **F10**: Fügvény, ami két halmaz metszetét adja vissza.
<br/> **F11**: Függvény, ami kiírja egy halmaz elemeit.
<br/> **S2**: Struktúra (Pairs), ami szám párokat tárol.
<br/> **F12**: Függvény, ami két halmaz Descartes-szorzatát adja vissza egy Pairs struktúrában.

A megoldás teszteléséhez a **test.c** fájl nyújt segítséget, ami egyben súgó, hogy milyen függvényeket kellene implementálni. A test.c fájl a futtatás során ellenőrzi a függvények működését, így kiderül a megoldásodban van e hiba. 

A függvények deklarációi kerüljenek egy külön headerbe, míg a definíciók egy hozzátartozó forrás fájlba. Erre lehet példát látni az előző szorglamiban. (Az is elfogadható, ha minden egy .c forrásfájlba kerül és nincs header. Viszont az előbbi megoldás áttekinthetőbb és a következő félév első laborján már szerepelni fog.)

A függvények implementálása során **nem** a hatékonyság a cél. Tehát nyugodtan fel lehet használni a már implementált függvényeket. Ennek megfelelő használatával a legtöbb függvény elég egyszerűvé válik.

*Feltöltendő*: a halmaz header-je és a hozzátartozó .c forrásfájl (vagy egy megfelelően kiegészített test.c fájl), feltöltés a moodle-ben a 6. labor szorgalmi feladatához 
<br/> *Beadási határidő*: 2018.10.24, labor kezdetéig

# Galton tábla

A [Galton tábla](https://en.wikipedia.org/wiki/Bean_machine) egy olyan függőleges tábla, amin az ábrán látható elrendezés szerint helyezkednek el szögek. A háromszög csúcsánál belép egy gyönyg. Ezt követően véletlenszerűen balra vagy jobbra esik tovább. A következő szögnél szintén véletlenszerűen balra vagy jobbra halad tovább. Minden szögnél az oda érkező golyóknak átlagosan a fele megy balra, illetve a másik fele jobbra.

![galton](galton.png)

A legutolsó szögsor után a gyöngyök egy fachba esnek. Ahogy egyre több gyöngy halad át a táblán az egyes fachokban eltérő számú gyolyó lesz. 

A feladat, hogy szimuláljuk le, mennyi gyöngy lesz az egyes fachokban, ha a táblán áthaladó golyók száma 500000 illetve 20 sor szög van. Ábrázoljuk, hogy milyen alakú a gyönyök által kirajzolt eloszlás. Minden sor egy fachot reprezentál, jelölje * a gyöngyöket, de a csillagok száma legyen: 
80 * gyöngyök_száma_a_fachban / összes_golyó .

Végül hasonlítsd ezt össze egy normál eloszlással, úgy hogy kirajzolod a normál eloszlást. 
Szintén a sorok az x tengely. Itt legyen k a fach indexe. Ekkor a használandó képlet:

![gauss](gauss.png)

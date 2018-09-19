# Ered? ellen�ll�s sz�m�t�sa

Ebben a feladatban egy olyan program megval�s�t�sa lenne a c�l, ami k�pes ered? ellen�ll�st sz�molni
egy �ramk�rben lev? ellen�ll�sokra. A program a szabv�nyos bemeneten megkap egy �j ellen�ll�st �s azt, hogy az 
p�rhuzamosan vagy sorosan van e kapcsolva az eddig m�r fel�p�tett rendszerhez. Ezt k�vet?en kisz�molja az 
aktu�lis ered? ellen�ll�st. A felhaszn�l� megfelel? m�don tudja jelezni, hogy most m�r v�gzett. Ekkor az
eredm�nyt ki�rja a k�perny?re. Fontos a hibakezel�s. legyen tov�bb� lehets�ges reset-elni (el?lr?l kezdeni), illetve
egyet visszal�pni, de sorozatos visszal�p�s nem lehet.

Al�bb a r�szletek k�vetkeznek.

Bemenet:
* ellen�ll�s soros kapcsol�sakor ez legyen a bemenet a k�perny?n: R 0
* ellen�ll�s p�rhuzamos kapcsol�sakor: R 1
* ha k�sz van: NA -3
* reset: NA -2
* egyet visszal�pni (utols� ellen�ll�s lev�tele): NA -1
R az �j bek�tend? ellen�ll�s �rt�ke, m�g ut�na sz�k�zzel elv�lasztva, hogy soros (0) vagy p�rhuzamos (1) bek�t�s j�n. NA azt jelenti, nem sz�m�t az �rt�ke.

Hibakezel�s:
* nem pozit�v ellen�ll�s eset�n: �rja ki, hogy az ellen�ll�s negat�v. A program ezut�n k�n�lja fel �jra
az ellen�ll�s csatol�s lehetos�g�t.
* nem l�tezo kapcsol�si m�d eset�n: �rja, ki hogy �rv�nytelen bek�t�si m�d. A program ezut�n k�n�lja fel �jra
az ellen�ll�s csatol�s lehetos�g�t.

P�lda a bemenet haszn�latra:

![kapcsolas](ellenallas.png)

**Teszt:**

Bemenetek: (10 0) (8 0) (3 1) (20 0) (4.8 1) (3.9 0) (4.1 0)
Elv�rt kimenet: 11.9582

*Felt�ltend?:* csak a forr�sk�d egy .c kiterjeszt�s? f�jlban, felt�lt�s a moodle-ben a 3. labor szorgalmi feladat�hoz <br/>
*Bead�si hat�rid?:* 2018.09.26, labor kezdet�ig

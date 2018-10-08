some hints around the food-database
===================================

Gliederung
----------

- Frühstück
- Mittagessen
- Abendessen
- Snacks


Inhalt
------

- Name, z.B. Skyr(Lidl)
- Kalorien
- Eiweiss
- Kohlenhydrate
- Fett
- Icon, wird in der gui angezeigt
- Kommentar, der wird zur foodnote in der gui


Example for food-db
-------------------

 # name, footnote, icon-name, group, calories, eiweiss, fett, kohlenhydrate
 Brötchen, Körner vom Lild, koernerbroetchen.png, frühstück, 111, E22, K33, F44
 Schnitzel, Metzger xyz, schnitzel.png, Frühstück:Mittag:Abend, 222, E55, K66, F77
 Rührei, 4 Eier, ruehrei.png, Frühstück:Abend, 333, E88, K99, F01

Zur besseren Erkennung wird vor dem Makro-Wirkstoffen jeweils ein Grossbuchstabe hinzugefügt.

	K -> Kohlenhydrate
	E -> Eiweiss
	F -> Fett

# Vehicle-2D-C-
vehicle 2D using QT Creator 

Programmierung eines 2D-Fahrzeugspiels „Zielfahrt“
Bei diesem Praktikumsteil brauchen sie uns nur am Ende (aller spätestens am 12.1.18) ihre Lösung zu
schicken. Geben sie dabei ihre Gruppenmitglieder an.
C++P3 Anforderung 1: Dokumentation
a) Jede Datei muss eine kurze, im Team einheitliche Dokumentation enthalten mit mindestens:
Projektname, Dateiname, Autor, Version, sowie ein bis zwei Sätze zum jeweiligen Zweck des Moduls.
Das gilt sowohl für die Header-, als für die .cpp-Dateien. (Auf die Dokumentation der einzelnen
Funktionen sein hier verzichtet.)
b) Oben in jeder Datei muss eine Änderungshistorie gepflegt werden. Nicht für jede Kleinigkeit, aber
zumindest für größere Arbeiten. Pro Änderung sind dabei immer folgende Daten einzutragen:
1.) Wann wurde geändert? (Datum)
2.) Von wem wurde geändert (ggf. mehrere, aber nicht immer alle!!)
3.) Was würde geändert? Beispiel:
// 2016-05-31; AL; Zustandsautomat um Logik für UP und DOWN erweitert.
// 2016-06-01; AL; Logik für Zust. UP korrigiert, weil bei Eingabe ‘e‘ fehlerhaft.
Sinnvoll ist auch die Angabe: Warum wurde etwas geändert – das ist aber hier keine Muss.
C++P3 Anforderung 2: Umbau auf Klassen


Programmieren sie das Fahrzeug (Vehicle) und den Zustandsautomaten jeweils als eigene Klasse
(auch wenn beim Zustandsautomaten nicht viel dazu gehört).


a) 

Programmieren sie dann eine Klasse „SmVehicle“, die ein Zustands-Objekt und sein FahrzeugObjekt zusammen bringt. In dieser Klasse soll fast nichts enthalten sein, außer zweier Zeiger: Eines
zum zugehörigen Fahrzeug und eines zum zugehörigen Automaten. Im Konstruktor von SmVehicle
kümmern sie sich darum, dass Platz für die Objekte auf dem Heap reserviert wird. (Alternativ ist ihnen
offen gestellt, das Vehicle und Statemachine direkt in SmVehicle als Komponente einzubauen, statt
über Zeiger).


b) 

Legen sie das SmVehicle-Objekt dann nicht mehr Dateilokal, sondern in der main.cpp an. Das zieht
einige Veränderungen nach sich und es kann leicht undurchschaubare Probleme geben – nutzen sie die
Praktikumsstunden zur Unterstützung. Nicht vergessen: Damit auch in main die Klasse SmVehicle
bekannt ist, verschieben sie die class SmVehicle{….}; in “smvehicle.h“ und includen diese.
Die Klasse SmVehicle wird später übrigens auch die Brücke zum GUI schlagen. Sie sollten aber am
besten – zum Testen ihrer Umstellung – auch ihr Projekt mit der alten Konsolenausgabe noch einmal
lauffähig bekommen!

c) 

Damit im Zustandsautomaten beim richtigen Fahrzeug der Beschleunigungsbefehl aufgerufen wird,
muss jedes Zustandsautomaten-Objekt „sein Fahrzeug“ kennen (auch wenn bei C++P3 weiterhin nur
ein Fahrzeug gefordert ist). Sie können dies elegant lösen, indem sie im Automaten ein Zeiger auf
„sein Fahrzeug“ anlegen. Tipp: Diesen Zeiger können sie z.B. im Konstruktor des Zustandsautomaten
entgegennehmen und setzen.
class Statemachine{…
 int state;
 Vehicle * myVehPtr; ……
Wenn der Zeiger richtig gesetzt ist, erreichen sie immer das richtige aktuelle/eigene Fahrzeug:
myVehPtr->engineAccel();
Tipp: Beim Umstellen auf eine Klasse ersparen sie sich Ärger, wenn sie für die Definition der
Zustände kein #define oder const int nutzen, sondern eine enumeration. 

d) Zur Vorbereitung der „Schnittstelle“ von SmVehicle zur GUI müssen sie in SmVehicle folgende
Member-Funktionen programmieren:


double getCppVehicleX( void); //liefert Real-Teil der Position
double getCppVehicleY( void); //liefert Imag-Teil der Position
void reactOnDriverInput(char driverInput);//…bald:QString statt char
//…soll via dem Statemachine “Subobjekt” dort processEvent aufrufen
void runSimulatePhysics( void);
//… soll via dem Vehicle “Subobjekt” dort die Simulation aufrufen
Wie der Umbau mit GUI dann genau geschehen kann, erfahren sie in einem HandsOn-Training.
Tipp: Lassen sie für den Anfang in den Klassen alles auf public.
C++P3 Anforderung 3: Rechnen mit Komplexen für Up und Down
a) Verwenden Sie nun komplexen Zahlen für s, v, a und F_akt eines Fahrzeugs. Sie können
dazu selbst eine struct Komplex anlegen (besser keine Klasse! Siehe auch die Übungsaufgabe
dazu auf OLAT) oder sie nutzen die Klasse complex aus der Standard-Bibliothek. Das
Anlegen und Initialisieren einer Hilfsvariable würde z.B: so aussehen:
complex<double> myTmpComlex1= complex<double> ( 0. , 0. );
Das können sie z.B. nutzen, um F_akt zum Gas geben zu setzen:
myVeh.F_akt= complex<double>( myVeh.F_max,0.); //Kraft nach rechts (Realteil)
(Also myVeh.F_max weiterhin als double aber myVeh.F_akt als complex<double>.)
Die „get-Funktion“ für den real- bzw. imag-Anteil sehen sie hier:
cout << myTmpComlex1.real() << “, “ << myTmpComlex1.imag();
Umwandeln in einen c++string geht z.B. so: to_string(myTmpComlex1.real())
Setzen des Realteils auf 77.0 geht so: myTmpComlex1.real( 77.0);
Sie können den Umstieg schrittweise machen, und zunächst den Imag.-Teil immer auf 0
stehen lassen. Nutzen Sie in simulate aber unbedingt komplexe Rechenfunktionen bzw.
Operationen, statt jeweils einzeln auf Real- und Imag.-Anteil zu rechnen! Das soll etwa so
aussehen: s= s + v … und nicht so: s.real= s.real +…; s.imag= s.imag + ….;
Das Programm muss sich danach genauso verhalten wie zuvor ohne die komplexen Zahlen.
 
 
 
b) Legen Sie nun neben engineAccel() und engineDecel() weitere Funktionen engineUp() und
engineDown() an, die den Imag.teil der Kraft setzen. (Stellen sie sich einen Raketenantrieb
vor, der den aktuellen Schub in eine der vier Himmelrichtungen ausstoßen kann. Wenn das
Fahrzeug beispielsweise gerade mit konstanter Geschwindigkeit nach rechts fährt und jetzt
Kraftschübe nach oben bekommt, dann biegt es (immer mehr) nach rechts oben ab.)
Erweitern Sie auch den Zustandsautomaten um zwei Zustände UP und DOWN. In diese
Zustände soll bei Eingabe von z.B. ‚u‘ bzw. ‚d‘ gewechselt werden.
Lassen Sie sich am besten immer die akt. Werte von s, v und a auf der Konsole ausgeben
(jeweils Real. und Imag.) und prüfen Simulations-Schritt-für-Schritt die Berechnungen (z.B.
mit einem Breakpoint in simulatePhysics). Sie sollten jetzt das Fahrzeug in der Ebene lenken
können – auch wenn die Graphik dazu noch fehlt. 

C++P3 Anforderung 4: GUI mit Zielfahrt


a) Binden sie die UI an ihre Fahrzeugsimulation an – sobald das HandsOnTraining dazu
stattgefunden hat. Außerdem sollte der Klassenumbau zuvor erledigt sein. Die Zielfahrt
können sie dann schon eindimensional vorbereiten. Ganz einfach: Sobald das Fahrzeug soll
eine bestimmte X-Koordinate erreicht hat, ist das Spiel gewonnen. Überlegen sie sich, wie das
„gerechnet“ werden kann. (Diese Berechnung werden wir zur Vereinfachung in QML
(~JavaScript) programmieren – Hilfe dazu bitte im Praktikum erfragen.)


b) Sobald der Umbau auf komplexe Zahlen vom Kommilitonen verfügbar und getestet ist,
bauen sie das Spiel um, auf eine Zielposition in der Ebene. Alles weiter, z.B. mehrere Ziele
anzufahren, sei ihnen überlassen. Sobald das Ziel erreicht ist, soll dem Zustandsautomaten ein
‘e‘ (für Ende) übermittelt werden; bei der GUI-Version soll dadurch aber nicht das Programm
beendet werden (z.B. via exit()), sondern nur in den Zustand ENG_OFF verzweigt werden.


Ghid de Utilizare

Acest program determină numărul minim de operații necesare pentru a transforma un fragment de cod, astfel încât să respecte o regulă sintactică predefinită.

Opțiuni de Testare

Programul oferă patru metode de testare:

Exemplu predefinit:

Șirul regulă: func(myFunction)
Fragment de cod: fnuc(myFuncion)
Programul va afișa rezultatul 3, reprezentând numărul minim de operații necesare pentru a transforma fragmentul de cod în șirul regulă:
Inversarea lui "n" cu "u"
Adăugarea literei "t"
Adăugarea caracterului ")"

Generare aleatorie:

Utilizatorul specifică lungimea dorită pentru șirul regulă și fragmentul de cod.
Programul generează aleatoriu ambele șiruri și afișează rezultatul, împreună cu numărul minim de operații necesare pentru transformare.
Generare aleatorie cu similaritate:

Utilizatorul specifică lungimea șirului regulă.
Programul generează aleatoriu șirul regulă.
Apoi, programul generează un fragment de cod similar cu șirul regulă, dar cu mici diferențe intenționate.
Se afișează numărul minim de operații necesare pentru a transforma fragmentul de cod în șirul regulă valid.
Cum să rulezi programul

Compilează codul sursă (de exemplu, folosind GCC).
Execută fișierul executabil generat.
Alege metoda de testare dorită și urmează instrucțiunile afișate.

Note

Programul utilizează programare dinamică pentru a găsi soluția optimă.
Operațiile permise sunt: înlocuirea, ștergerea, inserarea și inversarea a două caractere adiacente.
Fiecare operație are un cost unitar.
Pentru detalii suplimentare despre implementare, consultați codul sursă și comentariile aferente.

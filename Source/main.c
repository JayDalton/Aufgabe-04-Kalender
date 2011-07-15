/*###############################################################################
  Kodierung: UTF-8 ohne BOM
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>

#include "eingaben.h"
#include "kalender.h"

#include "eingaben.c"
#include "kalender.c"

//###############################################################################
/**
  Das Programm dient der tabellarischen Darstellung einer Monatsansicht für einen
  durch Monat und Jahr zu bestimmenden Zeitpunkt basierend auf dem Gregorjanischen 
  Kalender.

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{

  do {

    system("clear");
    printf("\n\tK a l e n d e r\n\n");
    printf("Das Programm gibt nach Eingabe eines Datum (Monat + Jahr)\nden Kalender des Monates aus.\n\n");

    int monat = erfasse_ganzzahl("Bitte den Monat eingeben", 1, 12);
    int jahr = erfasse_ganzzahl("Bitte das Jahr eingeben", 1583, 1000000);

    int laenge = ermittle_monat_laenge(monat, jahr);
    int anzahl = ermittle_anzahl_tage(monat, jahr);
    int anfang = ermittle_monat_begin(anzahl);

    zeichne_monat_titel(monat, jahr);
    zeichne_monat_kopf();
    zeichne_monat_linie();
    zeichne_monat_ansicht(anfang, laenge);
    zeichne_monat_linie();

  } while (erfasse_antwort("Noch einmal? (j/n)"));

  printf("\n\n\tAuf Wiedersehen!\n\n");

}

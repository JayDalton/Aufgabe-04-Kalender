//###############################################################################
/** 
  Ermittelt die Anzahl der Tage seit der Zeitrechnung (1583) mittels uebergebener
  Angaben für Monat und Jahr.
  
  @param  monat Ganzzahl Entsprechung des Monates
  @param  jahr  Ganzzahl Entsprechung des Jahres

  @return Anzahl der Tage
**/
//###############################################################################
int ermittle_anzahl_tage(unsigned int monat, unsigned int jahr)
{
  int resultat = 0;

  for (unsigned int anfang = 1583; anfang < jahr; anfang++)
  {
    resultat += ermittle_schaltjahr(anfang) ? 366 : 365;
  }

  for (unsigned int index = 1; monat > 1 && index < monat; index++)
  {
    resultat += ermittle_monat_laenge(index, jahr);
  }

  return resultat;
}

//###############################################################################
/** 
  Liefert die Anzahl der Tage des uebergebenen Monat und Jahres.
  
  @param  monat Ganzzahl Entsprechung des Monates
  @param  jahr  Ganzzahl Entsprechung des Jahres

  @return Anzahl der Tage
**/
//###############################################################################
int ermittle_monat_laenge(unsigned int monat, unsigned int jahr)
{
  int laenge = 0;
  switch (monat)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      laenge = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      laenge = 30;
      break;
    case 2:
      laenge = ermittle_schaltjahr(jahr) ? 29 : 28;
      break;
    default:
      laenge = 0;
      break;
  }
  return laenge;
}

//###############################################################################
/** 
  Ermittelt für das uebergebene Jahr ob dieses ein Schaltjahr ist.
  
  @param  jahr  Ganzzahl Entsprechung des Jahres

  @return Wahr (1) oder Falsch (0)
**/
//###############################################################################
int ermittle_schaltjahr(int jahr)
{
  return (jahr % 4 == 0 && ((jahr % 100 != 0) || (jahr % 400 == 0)));
}

//###############################################################################
/** 
  Ermittelt den Begin des Monates (Wochentag) im Kalender (Tabelle) mittels der 
  uebergebenen Anzahl Tage
  
  @param  anzahl  Ganzzahl Entsprechung Anzahl Tage im Monat

  @return Wahr (1) oder Falsch (0)
**/
//###############################################################################
int ermittle_monat_begin(int anzahl)
{
  return ((anzahl % 7) + 5) % 7;
}

//###############################################################################
/** 
  Schreibt die Titelzeile des Kalender mittels der uebergebenen Angaben für Monat
  und Jahr
  
  @param  monat Minimum des definierten Wertebereiches
  @param  jahr  Beschriftung der Eingabeaufforderung  
**/
//###############################################################################
void zeichne_monat_titel(unsigned int monat, unsigned int jahr)
{
  char liste[12][10] = {
    "Januar", "Februar", "März", "April", "Mai", "Juni", 
    "Juli", "August", "September", "Oktober", "November", "Dezember"
  };

  printf("\n\n\t%s %i\n", liste[--monat], jahr);
}

//###############################################################################
/** 
  Schreibt die Kopfzeile des Kalender und beschriftet die Spalten mit den Tages-
  bezeichnungen.
**/
//###############################################################################
void zeichne_monat_kopf(void)
{
  char liste[7][3] = {"Mo", "Di", "Mi", "Do", "Fr", "Sa", "So"};

  printf("\n\t");

  for(int i = 0; i < 7; i++)
  {
    printf("%s        ", liste[i]);
  }
}

//###############################################################################
/** 
  Schreibt eine horizontale Linie in den Kalender.
**/
//###############################################################################
void zeichne_monat_linie(void)
{
  printf("\n\t");
  for (int i = 0; i < 7 * 10 - 8; i++)
  {
    printf("=");
  }
}

//###############################################################################
/** 
  Schreibt den Kalender als Tabelle mittels der uebergebenen Werte für Anfang und
  Länge des Monates.

  @param  anfang  Ganzzahl Entsprechung Begin des Monat
  @param  laenge  Ganzzahl Entsprechung Länge des Monat
**/
//###############################################################################
void zeichne_monat_ansicht(int anfang, int laenge)
{
  int tag = 0;

  while (tag < laenge)
  {
    printf("\n\t");
    for (int zeile = 0 ; zeile < 7; zeile++)
    {
      if (tag == 0 && zeile < anfang) {

        printf("          ");

      } else if (tag == 0 && zeile == anfang) {

        printf("%02d        ", ++tag);

      } else if (tag > 0 && tag < laenge) {

        printf("%02d        ", ++tag);

      } else {

        printf("          ");

      }
    }
  }
}





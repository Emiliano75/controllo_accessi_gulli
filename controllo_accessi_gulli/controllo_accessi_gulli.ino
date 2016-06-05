/*
 *********************Arduino Source File Header**************************
__file_name__ = controllo_accessi_gulli.ino
__description__="Modulo per la prova delle funzionalità dei sensori sonar
e la liberria NewPing "
__author__ = "Stefano Baldacci"
__copyright__ = "Informazioni di Copyright"
__license__ = "GPL"
__email__ = "stefano.baldacci@gmail.com"
__STATUS__ = "Development[]";"Test[X]";"Production[]";
__branch__= test_SM (SHA1)
__History__: (repeat the following line as many times as applicable)
    __version__ = "0.1 original"
***************************************************************************
*/

//#include "Arduino.h" // libreria per compatibilita con PlatformIO. Vedi www.platformio.org
#include <NewPing.h> // libreria per gestione moduli Sonar HC-SR04

//****************** global variables definition ******************
// Collegamenti moduli Sonar
#define EXT_SONAR_TRIG_PIN 3
#define EXT_SONAR_ECHO_PIN  4
#define INT_SONAR_TRIG_PIN 5
#define INT_SONAR_ECHO_PIN 6
#define MAX_SONAR_DISTANCE 50.0f  //[cm]
#define SPEED_OF_SOUND 33.0f    //[cm/ms]


//codifica dello stato delle barriere sonar
#define SB_EXT_X B00000010 //barriera esterna attraversata
#define SB_INT_X B00000001 //barriera interna attraversata
#define SB_NONE  B00000000 // barriere libere

// LED per eventi Ingresso e uscita
#define LED_SB_INT 7
#define LED_SB_EXT 8

//****************** global variables definition ******************
byte sonarBarries=B00000000; // così composta -> [0 0 0 0 0 0 extSonar intSonar ]

unsigned long TTV_timer=0; // timer per attraversamento barriera

// oggetti NewPing per la gestione dei moduli sonar
NewPing ext_Sonar(EXT_SONAR_TRIG_PIN,EXT_SONAR_ECHO_PIN,MAX_SONAR_DISTANCE);
NewPing int_Sonar(INT_SONAR_TRIG_PIN,INT_SONAR_ECHO_PIN,MAX_SONAR_DISTANCE);



void setup()
{
Serial.begin(115200);

}

void loop()
{
  bool BX=false;
//sonarBarries=_t_ReadSonars();
delay(10);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
Serial.print("Ping: ");
Serial.println(ext_Sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
BX=IsEXTBarrierCrossed();

if (BX) {
 Serial.println("!!! BARRIERA ATTRAVERSATA !!!");
 delay(1000);
}

// Funzioni di prova moduli sonar e chiamata funzioni del m modulo sonar_barrier.ino

}

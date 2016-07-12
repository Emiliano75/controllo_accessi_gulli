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
// libreria per gestione moduli Sonar HC-SR04

//****************** global variables definition ******************
// Collegamenti switch per simulazione Ingressi e Uscite
#define SW_INGRESSO 3
#define SW_USCITA 4

// LED per eventi Ingresso e uscita
#define LED_SB_INT 7
#define LED_SB_EXT 8
//LED per Errore Comunicazione
#define LED_COMM_ERR 9


int contaIngressi=0;
int contaUscite=0;
int txRetryIN=0;
int txRetryOUT=0;
String rxBuffer="   ";
String msg="";

void setup()
{
Serial.begin(115200);
Serial.setTimeout(10);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(SW_INGRESSO, INPUT_PULLUP);
pinMode(SW_USCITA, INPUT_PULLUP);
//tone(10, 200, 500);
}

void loop()
{

  digitalWrite(LED_SB_INT,LOW);
  digitalWrite(LED_SB_EXT,LOW);

  // INGRESSO
if (digitalRead(SW_INGRESSO)==LOW) {
  while(digitalRead(SW_INGRESSO)==LOW);
  contaIngressi++;
  txRetryIN++;
}


// USCITA
if (digitalRead(SW_USCITA)==LOW) {
    while(digitalRead(SW_USCITA)==LOW);
  contaUscite++;
  txRetryOUT++;
}


TxCounters("IN ", &(txRetryIN));
TxCounters("OUT ", &(txRetryOUT));
    //tone(11, 200, 100);

delay(100);

}

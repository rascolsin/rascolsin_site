/**************************************************************************************************
Nom ......... : serial_interrupt.ino
Role ........ : Fait clignoter une led dans le loop tant que msg est différent de "vu#", sinon etteint
                la led.
                Déclenche une interruption lorsque un événement arrive sur le serial, stocke le
                message reçu dans msg. Le message doit être terminé par '#'.
Auteur ...... : J.Serrand
Mail ........ : joris.serrand@rascol.net
Version ..... : V0.0 du 28/11/17
Licence ..... : Copyright (C) 2017  Joris SERRAND

                This program is free software: you can redistribute it and/or modify
                it under the terms of the GNU General Public License as published by
                the Free Software Foundation, either version 3 of the License, or
                (at your option) any later version.

                This program is distributed in the hope that it will be useful,
                but WITHOUT ANY WARRANTY; without even the implied warranty of
                MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
                GNU General Public License for more details.

                You should have received a copy of the GNU General Public License
                along with this program.  If not, see <http://www.gnu.org/licenses/>

Compilation . : Avec l'IDE Arduino
****************************************************************************************************/

const int pin_rx_serial = 19;//Sur une carte Arduino MEGA utilisation de la pin Rx = 19 pour le serial 1
String msg = ""; //Déclaration de la variable contenant le message reçu

/*******************************
    Macro interruption
*******************************/
void serial_read()
{
  char carac; //Variable de réception des caractères arrivants sur le serial
  msg = ""; //Initialisation de message
  sei(); //Désactivation des interruptions
  while(Serial1.available()>0)
  {
    delay(1);// Ne pas enlever cette pause !
    if(Serial1.available()>0)
    {
      carac = (char)Serial1.read();
      msg += carac; //Stockage du message dans msg, caractère par caractère
      if(_bite == '#') // # est le symbole de fin de chaine choisi
      {
        Serial.println(msg);//Affichage du message receptionné sur le moniteur série
        break;
      }
    }
  }
  cli();//Réactivation des interruptions
}


/*******************************
      Initialisations
*******************************/
void setup()
{
  Serial.begin(9600); //Initialisation du serial pour affichage messages de test sur moniteur serie
  Serial1.begin(115200);//Initialisation du serial1 où l'interruption sera déclenchée
  attachInterrupt(digitalPinToInterrupt(pin_rx_serial), serial_read, FALLING); //Initialisation de l'interruption
}



/*******************************
    Programme principal
*******************************/
void loop()
{
   while(msg!="vu#") //Clignotement led 2 tant que msg différent de "vu#"
  {
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
  }

  digitalWrite(2,LOW); //Extinction de la led quand msg = "vu#"
}

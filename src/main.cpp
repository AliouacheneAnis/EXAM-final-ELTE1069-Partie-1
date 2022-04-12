/*
  Titre      : Controle LED avec clavier matriciel 
  Auteur     : Anis Aliouachene
  Date       : 12/04/2022
  Description: partie clavier de l'examen ELTE1069 
  Version    : 0.0.1
*/


#include <Arduino.h>
#include "Fonction.h"

void setup() {

  Serial.begin(9600);
  // Debut communication I2C    
  Wire.begin();                       

 
}

void loop() {
// Appeler la fonction 
  readKp4x4();       
}

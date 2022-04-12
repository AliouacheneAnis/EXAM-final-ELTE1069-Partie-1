#include<Arduino.h>
#include <Keypad.h>
#include <SPI.h>
#include <Wire.h>  

//Constants
#define ROWS 4
#define COLS 4

//Parameters
const char kp4x4Keys[ROWS][COLS]  = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};

// Setup Pin
byte rowKp4x4Pin [4] = {10, 9, 8, 7};  
byte colKp4x4Pin [4] = {5, 4, 3, 1};

//Variables
Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);
char Caractere; 

// Declaration Fonction 
void readKp4x4(); 
void eteint();


void readKp4x4() {

 // function readKp4x4 
 //  Read button states from keypad
  char customKey = kp4x4.getKey();
  
  if (customKey) {
      
      switch (customKey)
      {  
        
        case 'A':  // Dans le cas de pression sur la touche A 
            Caractere = 'A';
            //Serial.println('A'); 
            break;

        case 'B': // Dans le cas de pression sur la touche B
            Caractere = 'B';
            //Serial.println('B'); 
            break;

        case 'C': // Dans le cas de pression sur la touche C
            Caractere = 'C';
            //Serial.println('C'); 
            break;

        case 'D': // Dans le cas de pression sur la touche D
            Caractere = 'D';
            //Serial.println('D'); 
            break;
        

      default:   // Dans le cas de pression sur les touches numeriques entre 0 et 9 
          Serial.println("Error"); 
          break;
      }  

      Serial.println(Caractere);
      Wire.beginTransmission(4); // debut communication avec I2C 
      Wire.write(Caractere); // Envoi par I2C le caractere
      Wire.endTransmission(); // fin communication I2C 
	 Serial.println("Envoie via I2C réussie");

 }

}

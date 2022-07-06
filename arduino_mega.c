/*
 * uno:Serial.write ( '1' ) ;
 open then close 
sol_1     = 1 2
sol_23    = 3 4
sol_45    = 5 6
sag_1     = 7 8
sag_23    = 9 a
sag-45    = b c


y2_voice.play(  1 ); 

    * 
      distance = ultrasonic.read();   ekran.setCursor(0,1);

            ekran.print(distance);

    
  * stepper 
  boyun.step(350 , -350 );
  sol_omuz.step(750);
  sag_omuz.step(750);


digital 22 agiz
24 led 
* agiz.write (0) ;agiz.write (120) ;
  *agiz_delay (int a eyes , int  b time in sconds  ) ;  // needs fixing 

  * IR =   if (digitalRead ( 5 )== HIGH ) 

  * DHT = sicaklik = dht.readTemperature();

   * talking led = digitalWrite ( 24 , 1 ) ;

  
* screen 
 ekran.setCursor(0,1);
   ekran.print("connecting UNO");


 
 

*/

#include <Metro.h> 
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <Stepper.h>
#include <Ultrasonic.h>
#include <DHT.h>
 #include "LedControl.h"
#include <Metro.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define STEPS 32//
LedControl eyes = LedControl ( 11 , 13 , 12 , 2 ) ;//

Ultrasonic ultrasonic(3, 2); // trig . echo//

Stepper sol_omuz (STEPS, 41, 39, 38, 40); // sol//
Stepper sag_omuz (STEPS, 45, 43, 42, 44);   // sağ//
Stepper boyun (STEPS, 49, 47, 46, 48);     // boyun /

Servo agiz  ;       // agiz 22

DHT dht(DHTPIN, DHTTYPE);//

Metro time2000 = Metro ( 2000 ) ;
Metro time200 = Metro ( 200 ) ;
Metro time3000 = Metro ( 3000 ) ;

DFRobotDFPlayerMini y2_voice ; //


 char eye_mode = '0' ;  // 0 IS FOR SIMPLE EYE 
 
 int wonder_eyes_check = 1 ;

char dil ; // for the dil

char flushing ;

char ses ; // to take input from the geeetch

int distance; // ultrasonic

float sicaklik ; // sicaklik 

int random_joke ; 

LiquidCrystal_I2C ekran(0x27,16 ,2 ); // 

 

void setup() {
    pinMode ( 10 , OUTPUT ) ;
  digitalWrite ( 10 , 0 ) ; 
  delay ( 50 ) ;
  pinMode ( 24 , OUTPUT ) ; 
digitalWrite ( 24 , 0 ) ;

  pinMode ( 5 , INPUT ) ;

    dht.begin();

agiz.attach (22)  ;
agiz.write (0)    ;
agiz.write (120)    ;

delay  (100 ) ;

    sol_omuz.setSpeed(1500);
    sag_omuz.setSpeed(1500);
    boyun.setSpeed(1000);
    
digitalWrite ( 10 , 1 ) ; 

 // sol_omuz.step(-1000);
  //sag_omuz.step(-1000);
  digitalWrite ( 10 , 0 ) ; 
 delay ( 100 ) ; 
 
            
 eyes.shutdown (0 , false ) ;
 eyes.setIntensity ( 0 , 1) ;
 eyes.clearDisplay (0);
  eyes.shutdown (1 , false ) ;
 eyes.setIntensity ( 1 , 1) ;
 eyes.clearDisplay (1);
 reset_metros () ;
   the_eyes ( '0' ) ; 

   ekran.init();                    
   ekran.backlight(); 
   clear_display (  );
   ekran.print("connecting UNO");
   Serial.begin ( 9600 ) ; // uno
delay ( 1000 ) ;
   clear_display (  );
   ekran.print("connected UNO  ");
delay ( 1000 ) ; 
   clear_display (  );

   
   ekran.print("connecting voice");
   Serial2.begin ( 9600 ) ; 
Serial2.write(0xAA);
delay(1000);
Serial2.write(0x37);
delay(1000);
Serial2.write(0xAA);
delay(1000);
Serial2.write(0x21);
delay(1000);
   delay ( 1000 ) ;
   clear_display (  );
   ekran.print("connected voice");
   delay ( 1000 ) ;
      clear_display (  );
   ekran.print("connecting DFP");
   Serial3.begin ( 9600 ) ; 
if (!y2_voice.begin(Serial3)) { 
    while(true);
  }
     clear_display (  );
   ekran.print("connected DFP");
  y2_voice.volume(30);      
 delay ( 1000 ) ;
reset_fingers () ; 
// UART finished 
   clear_display (  );
   ekran.print("UART connectted");
 delay ( 1000 ) ;

// choose the language mode 
diller :

y2_voice.play(  1 ); 

agiz_delay ( 5 , '0' ) ;

  digitalWrite ( 10 , 1 ) ; 

  sol_omuz.step(2000);
Serial.write ( '2' ) ;
Serial.write ( '4' ) ;
Serial.write ( '6' ) ;
  boyun.step(350  );
    digitalWrite ( 10 , 0 ) ; 


agiz_delay ( 5 ,  '0' ) ;

  digitalWrite ( 10 ,1 ) ; 

  boyun.step(-350  );  
  
  digitalWrite ( 10 , 0 ) ; 


Serial.write ( '1' ) ;
Serial.write ( '3' ) ;
Serial.write ( '5' ) ;
  digitalWrite ( 10 ,1 ) ; 

  sol_omuz.step(-2000);
agiz_delay (19 ,  '0' ) ;
  digitalWrite ( 10 ,0 ) ; 


     clear_display (  );
   ekran.print("choose Language");
pinMode ( 6 , INPUT ) ; 
pinMode ( 7 , INPUT ) ; 
pinMode ( 8 , INPUT ) ; 
while ( true ) {
  if ( digitalRead ( 6 ) == HIGH ) {
      clear_display (  );
   ekran.print("ARABIC");
    dil = 'A' ; 
    break ;
  }
  else  if ( digitalRead ( 7 ) == HIGH ) {
   clear_display (  );
   ekran.print("ENGLISH");
    dil = 'E' ; 
    break ;
  }
  else  if ( digitalRead ( 8 ) == HIGH ) {
   clear_display (  );
   ekran.print("TURKISH");
    dil = 'T' ; 
    break ;
  }
  }
delay ( 250 ) ;


switch (dil)  {
case 'T' : 
y2_voice.play( 2 );  
digitalWrite ( 10 ,1 ) ; 

  sol_omuz.step(1000);
  sag_omuz.step(1000);
  digitalWrite ( 10 , 0 ) ; 

break ;
case 'A' : 
y2_voice.play(  4 );   digitalWrite ( 10 , 1 ) ; 

  sol_omuz.step(1000);
  sag_omuz.step(1000);
  digitalWrite ( 10 , 0 ) ; 

break ;
case 'E' : 
y2_voice.play( 3 );  

digitalWrite ( 10 , 1 ) ; 

  sol_omuz.step(1000);
  sag_omuz.step(1000);
  digitalWrite ( 10 , 0 ) ; 

break ;
default :
goto diller ;
break ; 
}


       reset_metros () ;


}

// start the real code 


void loop() {
   the_eyes ( '0' ) ; 
Serial2.flush() ;
seria2_flushing () ;
delay (50 ) ; 
ses = Serial2.read () ;
  
  switch(ses) {
      case 0x11:       // selam 
       reset_metros () ;
       selam () ;
seria2_flushing () ;

          reset_metros () ;
              break;
              
      case 0x12:   // distance 
                reset_metros () ;

       mesafe () ;
seria2_flushing () ;
                 reset_metros () ;

             break;
             
      case 0x13:  // sicaklik 
                reset_metros () ;

             temperature (); 
seria2_flushing () ;
                   reset_metros () ;

             break;
      
      case 0x14:  // jokes
                reset_metros () ;

          jokes () ;
seria2_flushing () ;
                      reset_metros () ;

            break;
      
      case 0x15:  // test
                reset_metros () ;

        test () ;
seria2_flushing () ;
                   reset_metros () ;

            break;

  }

}
void seria2_flushing () {
  do
      { flushing = Serial2.read();
      } while (Serial2.available() > 0);
      Serial2.flush() ;

}

void selam () {
  digitalWrite ( 10 , 1 ) ; 

   sag_omuz.step(5000); 
   digitalWrite ( 10 , 0 ) ; 

talk ( 320 , 321 , 8 ) ; 
agiz_delay ( 15 , '2') ;

while ( true ) {

if ( digitalRead ( 5 )== LOW ) {
  break ; // IR sensor
}
}
// close sag el 
talk ( 322 , 323 , 9 ) ;
  digitalWrite ( 10 , 1 ) ; 

      boyun.step(350);
  digitalWrite ( 10 , 0 ) ; 

Serial.write ( '8' ) ;
Serial.write ( 'a' ) ;
Serial.write ( 'c' ) ;
agiz_delay ( 2   , '2') ;
reset_fingers () ;  digitalWrite ( 10 , 1) ; 

      boyun.step(-350);
   sag_omuz.step(-5000);  digitalWrite ( 10 , 0 ) ; 
       reset_metros () ;


}

void mesafe () {
  talk ( 115 , 116 , 5 ) ;
  agiz_delay ( 2 ,'3' ) ; 
  digitalWrite ( 10 , 1 ) ; 

  sol_omuz.step(5000);  digitalWrite ( 10 , 0 ) ; 

Serial.write ( '2' ) ;
Serial.write ( '6' ) ;
mesafe_bir_daha :
       delay ( 1000 ) ;

       distance = ultrasonic.read(); 
    clear_display (  );
      ekran.print(distance);
      delay ( 1000 ) ;
if ( distance >= 0 && distance < 10 ) {
talk ( 117 , 118 , 19 ) ;
}
else if ( distance >= 10 && distance < 20 ) {
talk ( 119 , 120 , 20 ) ;
} 
else if ( distance >= 20 && distance < 30 ) {
talk ( 121 , 122 , 21 ) ;
} 
else if ( distance >= 30 && distance < 40 ) {
talk ( 123 , 124 , 22 ) ;
} 
else if ( distance >= 40 && distance < 50 ) {
talk ( 125 , 126 , 23 ) ;
} 
else if ( distance >= 50 && distance < 60 ) {
talk ( 127 , 128 , 24 ) ;
} 
else if ( distance >= 60 && distance < 70 ) {
talk ( 129 , 130 , 25 ) ;
} 
else if ( distance >= 70 && distance < 80 ) {
talk ( 131 , 132 , 26 ) ;
} 
else if ( distance >= 80 && distance < 90 ) {
talk ( 133 , 134 , 27) ;
} 
else if ( distance >= 90 && distance < 100 ) {
talk ( 135 , 136 , 28 ) ;
} 
else if ( distance >= 100 && distance < 110 ) {
talk ( 137 , 138 , 29 ) ;
} 
else if ( distance >= 110 && distance < 120 ) {
talk ( 139 , 140 , 30 ) ;
} 
else if ( distance >= 120 && distance < 130 ) {
talk ( 141 , 142 , 31 ) ;
} 
else if ( distance >= 130 && distance < 140 ) {
talk ( 143 , 144 , 32 ) ;
} 
else if ( distance >= 140 && distance < 150 ) {
talk ( 145 , 146 , 33 ) ;
} 
else if ( distance >= 150 && distance < 160 ) {
talk ( 147 , 148 , 34 ) ;
} 
else if ( distance >= 160 && distance < 170 ) {
talk ( 149 , 150 , 35 ) ;
} 
else if ( distance >= 170 && distance < 180 ) {
talk ( 151 , 152 , 36 ) ;
} 
else if ( distance >= 180 && distance < 190 ) {
talk ( 153 , 154 , 37 ) ;
} 
else if ( distance >= 190 && distance < 200) {
talk ( 155 , 156 , 38 ) ;
} 
else if ( distance >= 200 && distance < 210 ) {
talk ( 157 , 158 , 39 ) ;
} 
else if ( distance >= 210 && distance < 220 ) {
talk ( 159 , 160 , 40 ) ;
} 
else if ( distance >= 220 && distance < 230 ) {
talk ( 161 , 162 , 41 ) ;
} 
else if ( distance >= 230 && distance < 240 ) {
talk ( 163 , 164 , 42 ) ;
} 
else if ( distance >= 240 && distance < 250 ) {
talk ( 165 , 166 , 43 ) ;
} 
else if ( distance >= 250 && distance < 260 ) {
talk ( 167 , 168 , 44 ) ;
} 
else if ( distance >= 260 && distance < 270 ) {
talk ( 169 , 170 , 45 ) ;
} 
else if ( distance >= 270 && distance < 280 ) {
talk ( 171 , 172 , 46 ) ;
} 
else if ( distance >= 280 && distance < 290 ) {
talk ( 173 , 174 , 47 ) ;
} 
else if ( distance >= 290 && distance < 300 ) {
talk ( 175 , 176 , 48 ) ;
} 
else {
  goto mesafe_bir_daha ;
}
  agiz_delay ( 3 , '3' ) ;
  digitalWrite ( 10 , 1 ) ; 

 sol_omuz.step(-5000);  digitalWrite ( 10 , 0 ) ; 

 reset_fingers () ;
Serial2.flush() ;
       reset_metros () ;

}
void temperature () {
  
  talk ( 177 , 178 , 6 ) ;
  agiz_delay ( 2 , '3' ) ; 
  digitalWrite ( 10 , 1) ; 

  sag_omuz.step(5000);  digitalWrite ( 10 , 0 ) ; 

Serial.write ( '8' ) ;
Serial.write ( 'a' ) ;
sicaklik_bir_daha :
       delay ( 1000 ) ;

sicaklik = dht.readTemperature();

clear_display (  );
      ekran.print(sicaklik);
      delay ( 1000 ) ;

if ( sicaklik >= 0 && sicaklik < 1 ) {
talk ( 179 , 180 , 49 ) ;
}
else if ( sicaklik >= 1 && sicaklik < 2 ) {
talk ( 181 , 231 , 50 ) ;
}
else if ( sicaklik >= 2 && sicaklik < 3 ) {
talk ( 182 , 232 , 51 ) ;
}
else if ( sicaklik >= 3 && sicaklik < 4 ) {
talk ( 183 , 233 , 52 ) ;
}
else if ( sicaklik >= 4 && sicaklik < 5 ) {
talk ( 184 , 234 , 53 ) ;
}
else if ( sicaklik >= 5 && sicaklik < 6 ) {
talk ( 185 , 235 , 54 ) ;
}
else if ( sicaklik >= 6 && sicaklik < 7 ) {
talk ( 186 , 236 , 55 ) ;
}
else if ( sicaklik >= 7 && sicaklik < 8 ) {
talk ( 187 , 237 , 56 ) ;
}
else if ( sicaklik >= 8 && sicaklik < 9 ) {
talk ( 188 , 238 , 57 ) ;
}
else if ( sicaklik >= 9 && sicaklik < 10 ) {
talk ( 189 , 239 , 58 ) ;
}
else if ( sicaklik >= 10 && sicaklik < 11 ) {
talk ( 190 , 240 , 59 ) ;
}
else if ( sicaklik >= 11 && sicaklik < 12 ) {
talk ( 191 , 241 , 60 ) ;
}
else if ( sicaklik >= 12 && sicaklik < 13 ) {
talk ( 192 , 242 , 61 ) ;
}
else if ( sicaklik >= 13 && sicaklik < 14 ) {
talk ( 193 , 243 , 62 ) ;
}
else if ( sicaklik >= 14 && sicaklik < 15 ) {
talk ( 194 , 244 , 63 ) ;
}
else if ( sicaklik >= 15 && sicaklik < 16 ) {
talk ( 195 , 245 , 64 ) ;
}
else if ( sicaklik >= 16 && sicaklik < 17 ) {
talk ( 196 , 246 , 65 ) ;
}
else if ( sicaklik >= 17 && sicaklik < 18 ) {
talk ( 197 , 247 , 66 ) ;
}
else if ( sicaklik >= 18 && sicaklik < 19 ) {
talk ( 198 , 248 , 67 ) ;
}
else if ( sicaklik >= 19 && sicaklik < 20 ) {
talk ( 199 , 249 , 68 ) ;
}
else if ( sicaklik >= 20 && sicaklik < 21 ) {
talk ( 200 , 250 , 69 ) ;
}
else if ( sicaklik >= 21 && sicaklik < 22 ) {
talk ( 201 , 260 , 70 ) ;
}
else if ( sicaklik >= 22 && sicaklik < 23 ) {
talk ( 202 , 261 , 71 ) ;
}
else if ( sicaklik >= 23 && sicaklik < 24 ) {
talk ( 203 , 262 , 72 ) ;
}
else if ( sicaklik >= 24 && sicaklik < 25 ) {
talk ( 204 , 263 , 73 ) ;
}
else if ( sicaklik >= 25 && sicaklik < 26 ) {
talk ( 205 , 264 , 74 ) ;
}
else if ( sicaklik >= 26 && sicaklik < 27 ) {
talk ( 206 , 265 , 75 ) ;
}
else if ( sicaklik >= 27 && sicaklik < 28 ) {
talk ( 207 , 266 , 76 ) ;
}
else if ( sicaklik >= 28 && sicaklik < 29 ) {
talk ( 208 , 267 , 77 ) ;
}
else if ( sicaklik >= 29 && sicaklik < 30 ) {
talk ( 209 , 268 , 78 ) ;
}
else if ( sicaklik >= 30 && sicaklik < 31 ) {
talk ( 210 , 269 , 79 ) ;
}
else if ( sicaklik >= 31 && sicaklik < 32 ) {
talk ( 211 , 270 , 80 ) ;
}
else if ( sicaklik >= 32 && sicaklik < 33 ) {
talk ( 212 , 271 , 81) ;
}
else if ( sicaklik >= 33 && sicaklik < 34 ) {
talk ( 213 , 272 , 82 ) ;
}
else if ( sicaklik >= 34 && sicaklik < 35 ) {
talk ( 214 , 273 , 83 ) ;
}
else if ( sicaklik >= 35 && sicaklik < 36 ) {
talk ( 215 , 274 , 84 ) ;
}
else if ( sicaklik >= 36 && sicaklik < 37 ) {
talk ( 216 , 275 , 85 ) ;
}
else if ( sicaklik >= 37 && sicaklik < 38 ) {
talk ( 217 , 276 , 86 ) ;
}
else if ( sicaklik >= 38 && sicaklik < 39 ) {
talk ( 218 , 277 , 87 ) ;
}
else if ( sicaklik >= 39 && sicaklik < 40 ) {
talk ( 219 , 278 , 88 ) ;
}
else if ( sicaklik >= 40 && sicaklik < 41 ) {
talk ( 220 , 279 , 89 ) ;
}
else if ( sicaklik >= 41 && sicaklik < 42 ) {
talk ( 221 , 280 , 90 ) ;
}
else if ( sicaklik >= 42 && sicaklik < 43 ) {
talk ( 222 , 281 , 91) ;
}
else if ( sicaklik >= 43 && sicaklik < 44 ) {
talk ( 223 , 282 , 92 ) ;
}
else if ( sicaklik >= 44 && sicaklik < 45 ) {
talk ( 224 , 283 , 93 ) ;
}
else if ( sicaklik >= 45 && sicaklik < 46 ) {
talk ( 225 , 284 , 94 ) ;
}
else if ( sicaklik >= 46 && sicaklik < 47 ) {
talk ( 226 , 285 , 95 ) ;
}
else if ( sicaklik >= 47 && sicaklik < 48 ) {
talk ( 227 , 286 , 96 ) ;
}
else if ( sicaklik >= 48 && sicaklik < 49 ) {
talk ( 228 , 287 , 97 ) ;
}
else if ( sicaklik >= 49 && sicaklik < 50 ) {
talk ( 229 , 288 , 98 ) ;
}
else if ( sicaklik >= 50 && sicaklik < 1 ) {
talk ( 230 , 289 , 99 ) ;
}
      else {
        clear_display (  );
      ekran.print("0-50 arasi degil");
  goto sicaklik_bir_daha ;
}
agiz_delay ( 2  , '3' ) ;
// if cok sicak osmanniye 
if ( sicaklik >= 30 ) {
  Serial.write ( '2' ) ;
Serial.write ( '4' ) ;
Serial.write ( '6' ) ;
Serial.write ( '8' ) ;
Serial.write ( 'a' ) ;
Serial.write ( 'c' ) ;
talk ( 290 , 291 , 7 ) ;
agiz_delay ( 11  , '3' ) ;

}
 reset_fingers () ;  digitalWrite ( 10 ,1 ) ; 

 sag_omuz.step(-5000);  digitalWrite ( 10 , 0 ) ; 

 Serial2.flush() ;
       reset_metros () ;

}

void jokes () {

    digitalWrite ( 10 , 1 ) ; 

  sag_omuz.step(5000);
    sol_omuz.step(5000);
  digitalWrite ( 10 , 0 ) ; 

Serial.write ( '2' ) ;
Serial.write ( '6' ) ;
Serial.write ( '8' ) ;
Serial.write ( 'c' ) ;

  joke_again :
       random_joke =    random(1, 14);


       
     switch ( random_joke ) {

case 0 :
  talk ( 292 , 293  , 100 ) ;

break ;

case 1 :
  talk ( 294 , 295, 101 ) ;

break ;

case 2 :
  talk ( 296 , 297  , 102 ) ;

break ;

case 3 :
  talk ( 298 , 299  , 103 ) ;

break ;

case 4 :
  talk ( 300 , 301  , 104 ) ;

break ;

case 5 :
  talk ( 302 , 303  , 105 ) ;

break ;

case 6 :
  talk ( 304 , 305  , 106 ) ;

break ;

case 7 :
  talk ( 306 , 307  , 107 ) ;

break ;

case 8 :
  talk ( 308 , 309  , 108) ;

break ;

case 9 :
  talk ( 310 , 311  , 109 ) ;

break ;

case 10 :
  talk ( 312 , 313  , 110 ) ;

break ;

case 11 :
  talk ( 314 , 315  , 111 ) ;

break ;

case 12 :
  talk ( 316 , 317  , 112 ) ;

break ;
case 13 :
  talk ( 318 , 319  , 113 ) ;

break ;

default : 
goto joke_again ;
break ;
     
     }
  agiz_delay ( 3 , '3' ) ;
  digitalWrite ( 10 , 1) ; 

 
  sag_omuz.step(-5000);
    sol_omuz.step(-5000);  digitalWrite ( 10 , 0 ) ; 

reset_fingers () ; 
Serial2.flush() ;

       reset_metros () ;

}

void test () {
talk ( 320 , 321 , 10 ) ; 
agiz_delay ( 5 , '3' ) ;
talk ( 322 , 323 , 11 ) ; 
delay (5000);
talk ( 324 , 325 , 12 ) ; 
agiz_delay ( 1 , '3' ) ;
  reset_metros ();
delay ( 500);
  the_eyes ( '0' ) ; 
  delay ( 2000 ) ;
  the_eyes ( '1' ) ;
  delay ( 2000 ) ;
   
  the_eyes ( '2' ) ; 
  delay ( 2000 ) ;
  
  the_eyes ( '3' ) ; 
  delay ( 2000 ) ;
  
  the_eyes ( '4' ) ; 
  delay ( 2000 ) ;
  
  the_eyes ( '5' ) ; 
delay ( 2000 ) ;
  
talk ( 326 , 327 , 13 ) ; 
agiz_delay ( 5 , '3' ) ;

talk ( 328 , 329 , 14 ) ; 
agiz_delay (1  , '3' ) ;


Serial.write ( '2' ) ;
delay ( 1000 ) ;
Serial.write ( '4' ) ;
delay ( 1000 ) ;
Serial.write ( '6' ) ;
delay ( 1000) ;
Serial.write ( '8' ) ;
delay ( 1000 ) ;
Serial.write ( 'a' ) ;
delay ( 1000 ) ;
Serial.write ( 'c' ) ;
delay ( 1000 ) ;

Serial.write ( '1' ) ;
delay ( 1000 ) ;
Serial.write ( '3' ) ;
delay ( 1000 ) ;
Serial.write ( '5' ) ;
delay ( 1000 ) ;
Serial.write ( '7' ) ;
delay ( 1000 ) ;
Serial.write ( '9' ) ;
delay ( 1000 ) ;
Serial.write ( 'b' ) ;
delay ( 1000 ) ;

 talk ( 330 , 331 , 15 ) ; 
agiz_delay ( 1 , '3' ) ;
  digitalWrite ( 10 , 1) ; 

      boyun.step(350);
      boyun.step(-700);
      boyun.step(350);
  digitalWrite ( 10 , 0 ) ; 

        
 talk ( 332 , 333 , 16 ) ; 
agiz_delay ( 1 ,'3' ) ; 
  digitalWrite ( 10 , 1) ; 

   sag_omuz.step(5000);
   sol_omuz.step(5000);
   sag_omuz.step(-5000);
   sol_omuz.step(-5000);
  digitalWrite ( 10 , 0 ) ; 


        
 talk ( 334 , 335 , 17 ) ; 
agiz_delay ( 1 , '3' ) ;

  clear_display () ; 
   ekran.print ( "TEST  TEST" ) ; 
delay ( 2500 ) ;
   
        the_eyes ( '3' ) ;
 talk ( 336 , 337 , 18 ) ; 
agiz_delay ( 11 ,'3' ) ;

Serial2.flush() ;
       reset_metros () ;

}
                           // for moving system 

void reset_fingers () {
  
Serial.write ( '1' ) ;
delay ( 100 ) ;
Serial.write ( '3' ) ;
delay ( 100 ) ;
Serial.write ( '5' ) ;
delay ( 100 ) ;
Serial.write ( '7' ) ;
delay ( 100 ) ;
Serial.write ( '9' ) ;
delay ( 100 ) ;
Serial.write ( 'b' ) ;
delay ( 100 ) ;


agiz.write (0) ;

  
  }



void agiz_delay (int a , char b ) {
digitalWrite ( 24 , 1 ) ;
    
int agiz_delay_counter = 0 ; 

while ( agiz_delay_counter < a ) {
  agiz.write (0) ;
delay ( 250  ) ;
agiz.write (120) ;
delay ( 250  ) ; 

agiz.write (0) ;
delay ( 250  ) ;
agiz.write (120) ;
delay ( 250  ) ;
   the_eyes ( b ) ; 

agiz_delay_counter = agiz_delay_counter + 1 ;
}   
digitalWrite ( 24 ,0) ;

}

void clear_display () {
      ekran.clear () ;  
   ekran.setCursor(0,0);
   ekran.print("^H_K_A_A_Y robot^");
   ekran.setCursor(0,1);
}

void talk ( int x , int y  , int z ) {
  
  switch ( dil ) {
    case 'E' :
   y2_voice.play( x ); 

    break ;
    case 'A' :
   y2_voice.play( y ); 

    break ;
    case 'T' :
   y2_voice.play( z ); 

    break ;
    
  }
  
}









  
void the_eyes ( char x ) {
eye_mode = x ;
switch(eye_mode) {
      case '0' :        //simple
     
simple_eyes () ;
      break;
      
      case '1':       // died
    
died_eyes ();
      break;
      
      case '2':      // evil
      
evil_eyes ();
      break;
      
      case '3':      // wonder 
      
wonder_eyes () ;
      break;
      
      case '4':      // angry
     angry_eyes_start () ;

angry_eyes () ;
      break;
      
      case '5':     // heart
    
heart_eyes () ;
      break;
      
default : break ;
            }

  
}

void reset_metros () {
  time2000.reset()  ;
  time200.reset()  ;
   time3000.reset()  ;

}
 
void cleardisplay () {
 eyes.clearDisplay (0);
 eyes.clearDisplay (1); 
  }

  
void simple_eyes () { 
eye_simple () ; 
if ( time2000 . check() == 1 ) {
cleardisplay () ;
eye_simple_eff1 () ;
delay ( 25 ) ; 
cleardisplay () ;
eye_simple_eff2 () ;
delay ( 25 ) ; 
cleardisplay () ;
eye_simple_eff3 () ;
delay ( 25 ) ; 
}
eye_simple () ; 

}

void died_eyes () {
  eyes.setRow(0,0,B00111100); 
  eyes.setRow(0,1,B11110011); 
  eyes.setRow(0,2,B01110011); 
  eyes.setRow(0,3,B11011111); 
  eyes.setRow(0,4,B11011111); 
  eyes.setRow(0,5,B01110011); 
  eyes.setRow(0,6,B11110011); 
  eyes.setRow(0,7,B00111100); 
 
  eyes.setRow(1,0,B00111100); 
  eyes.setRow(1,1,B11110011); 
  eyes.setRow(1,2,B01110011); 
  eyes.setRow(1,3,B11011111); 
  eyes.setRow(1,4,B11011111); 
  eyes.setRow(1,5,B01110011); 
  eyes.setRow(1,6,B11110011); 
  eyes.setRow(1,7,B00111100); 
 

  }


void evil_eyes () {
  
  cleardisplay () ;

eye_evil (); 
if ( time200 . check() == 1 ) {
cleardisplay () ;
eye_evil_eff() ;
delay ( 50 ) ; 
}

}


void wonder_eyes () {
   cleardisplay () ;

eye_normal_0_right () ;

if ( time3000 . check() == 1 ) {
cleardisplay () ;

if ( wonder_eyes_check == 1 ) {
  
eye_normal_1_right () ; ;
delay ( 100 ) ; 
cleardisplay () ;
eye_normal_2_right () ; ;
delay ( 100 ) ; 
cleardisplay () ;
eye_normal_3_right () ;
delay ( 200 ) ; 
wonder_eyes_check = 0 ;
}
else if ( wonder_eyes_check == 0 ) {
cleardisplay () ;

eye_normal_1_left () ; ;
delay ( 100 ) ; 
cleardisplay () ;

eye_normal_2_left () ; ;
delay ( 100 ) ; 
cleardisplay () ;
eye_normal_3_left () ;
delay ( 200 ) ; 
wonder_eyes_check = 1 ;
}
}}

void angry_eyes_start () {
  cleardisplay () ;

eye_angry_0 () ; 
delay ( 250 ) ; 
cleardisplay () ;
eye_angry_1 () ;
delay ( 250 ) ; 
cleardisplay () ;
eye_angry_2 () ;
delay ( 250 ) ; 


  }
  
void heart_eyes () {
  cleardisplay () ;

eye_heart (); 
if ( time200 . check() == 1 ) {
cleardisplay () ;
eye_heart_eff() ;
delay ( 50 ) ; 
}
}



void eye_angry_0 () {
  
  eyes .setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000010); 
  eyes.setRow(0,7,B01111100); 

  eyes.setRow(1,0,B01111100); 
  eyes.setRow(1,1,B10000010); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  } 
void eye_angry_1 () {
   
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10000010); 
  eyes.setRow(0,6,B10000100); 
  eyes.setRow(0,7,B01111000); 

  eyes.setRow(1,0,B01111000); 
  eyes.setRow(1,1,B10000100); 
  eyes.setRow(1,2,B10000010); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_angry_2 () {
    
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B11000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011010); 
  eyes.setRow(0,5,B10000100); 
  eyes.setRow(0,6,B10001000); 
  eyes.setRow(0,7,B01110000); 

  eyes.setRow(1,0,B01110000); 
  eyes.setRow(1,1,B10001000); 
  eyes.setRow(1,2,B10000100); 
  eyes.setRow(1,3,B10011010); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B11000001); 
  eyes.setRow(1,7,B01111110); 
  }
void angry_eyes () {
     
  eyes.setRow(0,0,B00111110); 
  eyes.setRow(0,1,B01000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011010); 
  eyes.setRow(0,5,B10000100); 
  eyes.setRow(0,6,B10001000); 
  eyes.setRow(0,7,B01110000); 

  eyes.setRow(1,0,B01110000); 
  eyes.setRow(1,1,B1001000); 
  eyes.setRow(1,2,B10000100); 
  eyes.setRow(1,3,B10011010); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B01000001); 
  eyes.setRow(1,7,B00111110); 
  }
  
void eye_simple () {
  eyes.setRow(0,0,B00000000); 
  eyes.setRow(0,1,B00111100); 
  eyes.setRow(0,2,B00100100); 
  eyes.setRow(0,3,B00110100); 
  eyes.setRow(0,4,B00110100); 
  eyes.setRow(0,5,B00100100); 
  eyes.setRow(0,6,B00111100); 
  eyes.setRow(0,7,B00000000); 

  eyes.setRow(1,0,B00000000); 
  eyes.setRow(1,1,B00111100); 
  eyes.setRow(1,2,B00100100); 
  eyes.setRow(1,3,B00110100); 
  eyes.setRow(1,4,B00110100); 
  eyes.setRow(1,5,B00100100); 
  eyes.setRow(1,6,B00111100); 
  eyes.setRow(1,7,B00000000); 
  }
void eye_simple_eff1 () {
  eyes.setRow(0,0,B00000000); 
  eyes.setRow(0,1,B00111000); 
  eyes.setRow(0,2,B00101000); 
  eyes.setRow(0,3,B00111000); 
  eyes.setRow(0,4,B00111000); 
  eyes.setRow(0,5,B00101000); 
  eyes.setRow(0,6,B00111000); 
  eyes.setRow(0,7,B00000000); 

  eyes.setRow(1,0,B00000000); 
  eyes.setRow(1,1,B00111000); 
  eyes.setRow(1,2,B00101000); 
  eyes.setRow(1,3,B00111000); 
  eyes.setRow(1,4,B00111000); 
  eyes.setRow(1,5,B00101000); 
  eyes.setRow(1,6,B00111000); 
  eyes.setRow(1,7,B00000000); 
  }
void eye_simple_eff2 () {
  eyes.setRow(0,0,B00000000); 
  eyes.setRow(0,1,B00110000); 
  eyes.setRow(0,2,B00110000); 
  eyes.setRow(0,3,B00110000); 
  eyes.setRow(0,4,B00110000); 
  eyes.setRow(0,5,B00110000); 
  eyes.setRow(0,6,B00110000); 
  eyes.setRow(0,7,B00000000); 

  eyes.setRow(1,0,B00000000); 
  eyes.setRow(1,1,B00110000); 
  eyes.setRow(1,2,B00110000); 
  eyes.setRow(1,3,B00110000); 
  eyes.setRow(1,4,B00110000); 
  eyes.setRow(1,5,B00110000); 
  eyes.setRow(1,6,B00110000); 
  eyes.setRow(1,7,B00000000); 

  }
  void eye_simple_eff3 () {
  eyes.setRow(0,0,B00000000); 
  eyes.setRow(0,1,B00100000); 
  eyes.setRow(0,2,B00100000); 
  eyes.setRow(0,3,B00100000); 
  eyes.setRow(0,4,B00100000); 
  eyes.setRow(0,5,B00100000); 
  eyes.setRow(0,6,B00100000); 
  eyes.setRow(0,7,B00000000); 

  eyes.setRow(1,0,B00000000); 
  eyes.setRow(1,1,B00100000); 
  eyes.setRow(1,2,B00100000); 
  eyes.setRow(1,3,B00100000); 
  eyes.setRow(1,4,B00100000); 
  eyes.setRow(1,5,B00100000); 
  eyes.setRow(1,6,B00100000); 
  eyes.setRow(1,7,B00000000); 

  }

  
void eye_normal_0_right () {
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  
  }
void eye_normal_1_right () {
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10000001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10011001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10000001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10011001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_normal_2_right () {
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10000001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10011001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10000001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10011001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_normal_3_right () {
    eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10000001); 
  eyes.setRow(0,4,B10000001); 
  eyes.setRow(0,5,B10011001); 
  eyes.setRow(0,6,B10011001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10000001); 
  eyes.setRow(1,4,B10000001); 
  eyes.setRow(1,5,B10011001); 
  eyes.setRow(1,6,B10011001); 
  eyes.setRow(1,7,B01111110); 
  }
  
void eye_normal_0_left () {
   eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10000001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10011001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10000001); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10011001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_normal_1_left () {
  
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10011001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10000001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10011001); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10000001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_normal_2_left () {
    
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10000001); 
  eyes.setRow(0,2,B10011001); 
  eyes.setRow(0,3,B10011001); 
  eyes.setRow(0,4,B10000001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10000001); 
  eyes.setRow(1,2,B10011001); 
  eyes.setRow(1,3,B10011001); 
  eyes.setRow(1,4,B10000001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }
void eye_normal_3_left () {
    
  eyes.setRow(0,0,B01111110); 
  eyes.setRow(0,1,B10011001); 
  eyes.setRow(0,2,B10011001); 
  eyes.setRow(0,3,B10000001); 
  eyes.setRow(0,4,B10000001); 
  eyes.setRow(0,5,B10000001); 
  eyes.setRow(0,6,B10000001); 
  eyes.setRow(0,7,B01111110); 

  eyes.setRow(1,0,B01111110); 
  eyes.setRow(1,1,B10011001); 
  eyes.setRow(1,2,B10011001); 
  eyes.setRow(1,3,B10000001); 
  eyes.setRow(1,4,B10000001); 
  eyes.setRow(1,5,B10000001); 
  eyes.setRow(1,6,B10000001); 
  eyes.setRow(1,7,B01111110); 
  }

  
  void eye_evil () {
  eyes.setRow(0,0,B00000111); 
  eyes.setRow(0,1,B00011110); 
  eyes.setRow(0,2,B01111100); 
  eyes.setRow(0,3,B11111100); 
  eyes.setRow(0,4,B11001100); 
  eyes.setRow(0,5,B11001000); 
  eyes.setRow(0,6,B01111000); 
  eyes.setRow(0,7,B00111000); 
 
  eyes.setRow(1,7,B00000111); 
  eyes.setRow(1,6,B00011110); 
  eyes.setRow(1,5,B01111100); 
  eyes.setRow(1,4,B11111100); 
  eyes.setRow(1,3,B11001100); 
  eyes.setRow(1,2,B11001000); 
  eyes.setRow(1,1,B01111000); 
  eyes.setRow(1,0,B00111000); 
 
  }
void eye_evil_eff () {
  eyes.setRow(0,0,B00001110); 
  eyes.setRow(0,1,B00111100); 
  eyes.setRow(0,2,B01111100); 
  eyes.setRow(0,3,B11111100); 
  eyes.setRow(0,4,B11001100); 
  eyes.setRow(0,5,B11001100); 
  eyes.setRow(0,6,B01111000); 
  eyes.setRow(0,7,B00111000); 
 
  eyes.setRow(1,7,B00001110); 
  eyes.setRow(1,6,B00111100); 
  eyes.setRow(1,5,B01111100); 
  eyes.setRow(1,4,B11111100); 
  eyes.setRow(1,3,B11001100); 
  eyes.setRow(1,2,B11001100); 
  eyes.setRow(1,1,B01111000); 
  eyes.setRow(1,0,B00111000); 
  }

  

  
void eye_heart() { 

eyes.setRow(0,0,B00011100); 
eyes.setRow(0,1,B00111110); 
eyes.setRow(0,2,B01111110); 
eyes.setRow(0,3,B11111100); 
eyes.setRow(0,4,B11111100); 
eyes.setRow(0,5,B01111110); 
eyes.setRow(0,6,B00111110); 
eyes.setRow(0,7,B00011100); 
eyes.setRow(1,0,B00011100); 
eyes.setRow(1,1,B00111110); 
eyes.setRow(1,2,B01111110); 
eyes.setRow(1,3,B11111100); 
eyes.setRow(1,4,B11111100); 
eyes.setRow(1,5,B01111110); 
eyes.setRow(1,6,B00111110); 
eyes.setRow(1,7,B00011100); 


  }
  void eye_heart_eff () {
    
    
eyes.setRow(0,0,B00000000); 
eyes.setRow(0,1,B00011100); 
eyes.setRow(0,2,B01111100); 
eyes.setRow(0,3,B11111000); 
eyes.setRow(0,4,B11111000); 
eyes.setRow(0,5,B01111100); 
eyes.setRow(0,6,B00011100); 
eyes.setRow(0,7,B00000000); 
eyes.setRow(1,0,B00000000); 
eyes.setRow(1,1,B00011100); 
eyes.setRow(1,2,B01111100); 
eyes.setRow(1,3,B11111000); 
eyes.setRow(1,4,B11111000); 
eyes.setRow(1,5,B01111100); 
eyes.setRow(1,6,B00011100); 
eyes.setRow(1,7,B00000000); 
    }

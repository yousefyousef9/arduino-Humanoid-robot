    // open then close 
// sol_1      1 2
// sol_23     3 4
// sol_45     5 6

// sag_1      7 8
// sag_23     9 a
// sag-45     b c

// pumpa mission = d


#include <Servo.h>
char receiver  ;
Servo  sol_parmak_1 ;
Servo sol_parmak_23 ;
Servo sol_parmak_45 ;
Servo sag_parmak_1  ; 
Servo sag_parmak_23 ;
Servo sag_parmak_45 ;
void setup() {
 Serial.begin(9600);
pinMode( 11 , INPUT );
  
sol_parmak_1.attach (2) ;
sol_parmak_23.attach (3) ;
sol_parmak_45.attach (4) ;

sol_parmak_1.write (0) ;
sol_parmak_23.write (0) ;
sol_parmak_45.write (0) ;

sag_parmak_1.attach (7) ;
sag_parmak_23.attach (8) ;
sag_parmak_45.attach (9) ;

sag_parmak_1.write (0) ;
sag_parmak_23.write (0) ;
sag_parmak_45.write (0) ;
//pinMode ( 12 , OUTPUT ) ; // led 
//pinMode ( 13 , OUTPUT ) ; // pumpa 
}
void loop() {
    receiver = Serial.read();
 switch ( receiver ) {
  
// sol el
case '1' :  // sol_parmak_1 open 
sol_parmak_1.write( 0 ) ;
break ;
case '2' : // sol_parmak_1 close 
sol_parmak_1.write (120) ;
break ;
case '3' : // sol_parmak_23 open 
sol_parmak_23.write (0) ;
break ;
case '4' : // sol_parmak_23 close  
sol_parmak_23.write (120) ;
break ;
case '5' : // sol_parmak_45 open 
sol_parmak_45.write (0) ;
break ;
case '6' : // sol_parmak_45 close 
sol_parmak_45.write (130) ;
break ;

// sag el 
 
case '7' :  // sag_parmak_1 open 
sag_parmak_1.write (0) ;
break ;
case '8' : // sag_parmak_1 close 
sag_parmak_1.write (135) ;
break ;
case '9' : // sag_parmak_23 open 
sag_parmak_23.write (0) ;
break ;
case 'a' : // sag_parmak_23 close  
sag_parmak_23.write (135) ;
break ;
case 'b' : // sag_parmak_45 open 
sag_parmak_45.write (0) ;
break ;
case 'c' : // sag_parmak_45 close 
sag_parmak_45.write (120) ;
break ;

 }
    receiver = 0 ;
    delay ( 50 ) ;}

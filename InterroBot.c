//THIS IS A TEST by kash 



#include <stdlib.h>
#include <stdio.h>
#include <IRremote.h>

#define LEDr PIN#PLACEHOLDER // red LED         }
#define LEDb PIN#PLACEHOLDER // blue LED        }       PIN#PLACEHOLDER must be replaced with actual pin #
#define LEDy PIN#PLACEHOLDER // yellow LED      }

int MAXbase;    // HIGHEST VALUE RECORDED by GSR in baseline method. Should NOT be reset unless victim is changed.
int MINbase;    // LOWEST VALUE RECORDED by GSR in baseline method. Should NOT be reset unless victim is changed.
int AVGbase;    // the average of the above two. AVGbase = (MAXbase + MINbase) / 2


setup() {

        // probably need more things here.
        // INCLUDE:
        //GSR sensor
        // Servo 1
        // Servo 2

        pinMode(LEDb, OUTPUT); // BLUE LED; should only be HIGH when baseline is set.
        pinMode(LEDr, OUTPUT); // RED LED; should only be HIGH when awaiting input from remote.
        irrecv.enableIRIn(); // Start the receiver for the remote

        boolean NAMEGOESHERE = false
        //boolean NAMEGOESHERE will remain false until BASELINE is called. May have to be
        // moved to outside setup(), but what do I know? I can't C!

        NAMEGOESHERE = CALL TO BASELINE METHOD, WHICH RETURNS true as a value.

        BASELINE also sets values for MAXbase, MINbase, and AVGbase, though it doesn't return them.

        if (NAMEGOESHERE == true) {
                digitalWrite(LEDb, HIGH) // blue LED lights up, which means our baseline values are set.
        }
}

baseline()      {       //FUNCTION SHOULD ONLY BE USED ONCE... unless a new victim is chosen.

        Should return a BOOLEAN value: true

        VARS:
        TEMPmax // temporary max
    TEMPmin // temporary min
    TEMPavg // temporary avg, won't be set until end of this method.

    FIRSTval // FIRST VALUE READ BY SENSOR; should NOT be updated by if/else/etc.
    CURRval // CURRENT VALUE READ BY SENSOR

    TODO:

    digitalWrite(LEDr, HIGH); // WAITING FOR INPUT/SIGNAL TO PROCEED.

    1. Activate remote.
    2. WAIT FOR INPUT FROM REMOTE.

      DURING THIS TIME, the victim should be settled down and hooked up to the GSR. This step is just in case
      s/he HASN'T been already hooked up.

      Signal to proceed should be 1. IN OTHER WORDS, person holding remote should press 1.
      If any other button is pressed, do nothing.
      If 1, go to next step.

    3.

                  
    **DEACTIVATE REMOTE to prevent accidental button mashing.
    
      a. Activate sensor. SEE GSR CODE FOR REFERENCE.
      b. Wait 2-5 seconds (2000-5000) for readings to stabilize. Reason? Don't want min to be 0.
      c. AFTER above wait, RECORD values for TEN seconds. DO NOT STORE IN ARRAY OR LIST. Instead, use if statements.
      
       *** IF ARDUINO CAN'T PROCESS QUICKLY ENOUGH, try using an array/list and extracting the lowest/highest values.
       *** to save space, that list should be cleared after this method ends.
       
          At first, set TEMPmin and TEMPmax to whatever the FIRST value received by GSR is.
          
          TEMPmax = FIRSTval
          TEMPmin = FIRSTval
          
          NEXT, use IF statements:
          
          IF (CURRval > TEMPmax) // if the current value is greater than the temp. maximum...
              TEMPmax = CURRval // then update the temp. maximum.
              
          IF (CURRval < TEMPmin) // if the current value is less than the temp minimum...
               TEMPmin = CURRval // then update the temp. minimum.
               
      4. After ten seconds, PAUSE GSR READING. Don't stop it--just pause.
      
      5. Set the values. . .
      
        TEMPavg = (TEMPmax + TEMPmin) / 2
        
        MAXbase = TEMPmax
        MINbase = TEMPmin
        AVGbase = TEMPavg
        
        ** MAKE SURE THEY HOLD OUTSIDE OF BASELINE METHOD'S SCOPE.
        
        6. Power down LEDr (red LED)
        
           digitalWrite(LEDr, LOW); // YAY, WE CAN MOVE ON.
           
        7. RETURN TRUE. At this point, LEDb (blue LED) should be on.
}       

vicResponse()   {       //** METHOD GOES HERE: VICRESPONSE.
    WAITING FOR VICTIM'S RESPONSE TO A QUESTION.
    SHOULD RETURN: TEMPavg

    Has similar functionality to BASELINE method, but uses two button presses.

    VARS:
    TEMPmax // temporary max
    TEMPmin // temporary min
    TEMPavg // temporary avg, won't be set until end of this method.

    FIRSTval // FIRST VALUE READ BY SENSOR; should NOT be updated by if/else/etc.
    CURRval // CURRENT VALUE READ BY SENSOR

   // int buttonPress = 0 // while this is zero, continue recording. Remains zero until 1 is pressed on remote.

    TODO:

    1. Activate remote.
    2. Activate GSR. Wait 2 seconds to stabilize.

    BEGIN RECORDING.

    WHILE (BUTTON ON REMOTE IS NOT PRESSED)
        digitalWrite(LEDr, HIGH); // PROMPT FOR VICTIM TO SAY YES/NO
        RECORD UNTIL VICTIM RESPONDS.

          At first, set TEMPmin and TEMPmax to whatever the FIRST value received by GSR is.

          TEMPmax = FIRSTval
          TEMPmin = FIRSTval

          NEXT, use IF statements:

          IF (CURRval > TEMPmax) // if the current value is greater than the temp. maximum...
              TEMPmax = CURRval // then update the temp. maximum.

          IF (CURRval < TEMPmin) // if the current value is less than the temp minimum...
               TEMPmin = CURRval // then update the temp. minimum.

     ****As soon as victim answers, press 1 on remote to end recording.

    TURN OFF RED LED.
    digitalWrite(LEDr, LOW);

    **DEACTIVATE REMOTE to prevent accidental button mashing.

    3. TEMPavg = (TEMPmax + TEMPmin) / 2

       RETURN TEMPavg.
}


main()  {
        return 0;
}


//KASH BETTER NOT HAVE CHANGED ANYTHING!!!!

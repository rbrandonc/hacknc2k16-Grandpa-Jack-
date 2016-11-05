#include <SimpleSDAudio.h>

int IRpin = A0;
int distance;
long randomnumber;
int fade = 1;
int led = 0;

void initialize() {
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) {
    Serial.println(F("You messed up the sd card"));
    while (1);
  } else {
    Serial.println(F("You didn't mess up the sd card"));
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);

  randomSeed(analogRead(5));



  while (1 == 1) {
    distance = analogRead(IRpin);
    
    if (led > 254) {
      fade = -1;
    }

    if (led < 1) {
      fade = 1;
    }

    led += fade;

    analogWrite(3, led);
    delay(5);



    if (distance > 1000) {
      delay(400);
      //SdPlay.enable();
      initialize();

      int last = randomnumber;

      //while(randomnumber = last){
      randomnumber = random(0, 9);
      //}

      Serial.print(distance);

      switch (randomnumber) {
        case 1:
          SdPlay.setFile("1.AFM");
          break;
        case 2:
          SdPlay.setFile("2.AFM");
          break;
        case 3:
          SdPlay.setFile("3.AFM");
          break;
        case 4:
          SdPlay.setFile("4.AFM");
          break;
        case 5:
          SdPlay.setFile("5.AFM");
          break;
        case 6:
          SdPlay.setFile("6.AFM");
          break;
        case 8:
          SdPlay.setFile("8.AFM");
          break;
      }


      SdPlay.play();
      while (!SdPlay.isStopped()) {
        digitalWrite(7, HIGH);
        delay(50);
        digitalWrite(7, LOW);
        delay(200);
        }
      SdPlay.deInit();
      digitalWrite(7, LOW);

    }
  }

}


void loop(void) {


}

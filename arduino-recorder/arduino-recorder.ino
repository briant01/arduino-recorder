//define pins
const int button1 = D2;
const int button2 = D3;
const int button3 = D5;
const int button4 = D7;
const int button5 = D9;
const int button6 = D10;
const int button7 = D12;
const int buzzer = D13;
const int soundSensor = D6;

const int pinButtons[] = { D1, D2, D3, D5, D7, D9, D10, D12 };
int sensorVal[8];
bool sensorValPress[8];

const int pinButtonsLeng = sizeof(pinButtons) / sizeof(pinButtons[0]);
const int sensorValLeng = sizeof(sensorVal) / sizeof(sensorVal[0]);

//pwm delays of different notes
int noteHighC = 950;
int noteB = 1000;
int noteA = 1125;
int noteG = 1250;
int noteF = 1400;
int noteE = 1500;
int noteD = 1675;
int noteLowC = 1860;
int loudness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(D6, INPUT);

  //initilizing all buttons as input pullup
  for (int i = 0; i < pinButtonsLeng; i++) {
    pinMode(pinButtons[i], INPUT_PULLUP);
  }
}
void loop() {

  //read ky-038 digital signal
  loudness = digitalRead(D6);

  //have a variable set to different button presses
  for (int i = 0; i < sensorValLeng; i++) {
    sensorVal[i] = digitalRead(pinButtons[i]);
  }

  //have a variable to keep track whether a button is pressed
  for (int i = 0; i < sensorValLeng; i++) {
    sensorValPress[i] = (sensorVal[i] == LOW);
  }

  //code will run when mic picks up loud signal, indicating the blowing of a recorder
  if (loudness == 1) {
    //note B
    if (sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteB);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteB);
      }
    } else if (!sensorValPress[1]) {
      digitalWrite(buzzer, HIGH);
    }

    //note high C
    if (sensorValPress[2] && !sensorValPress[1] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 20; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteHighC);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteHighC);
      }
    } else if (!sensorValPress[2]) {
      digitalWrite(buzzer, HIGH);
    }

    //note A
    if (sensorValPress[1] && sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteA);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteA);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2]) {
      digitalWrite(buzzer, HIGH);
    }

    //note G
    if (sensorValPress[1] && sensorValPress[2] && sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteG);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteG);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3]) {
      digitalWrite(buzzer, HIGH);
    }

    //note F
    if (sensorValPress[1] && sensorValPress[2] && sensorValPress[3] && sensorValPress[4] && !sensorValPress[5] && sensorValPress[6] && sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteF);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteF);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[6] && !sensorValPress[7]) {
      digitalWrite(buzzer, HIGH);
    }

    //note E
    if (sensorValPress[1] && sensorValPress[2] && sensorValPress[3] && sensorValPress[4] && sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteE);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteE);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5]) {
      digitalWrite(buzzer, HIGH);
    }

    //note D
    if (sensorValPress[1] && sensorValPress[2] && sensorValPress[3] && sensorValPress[4] && sensorValPress[5] && sensorValPress[6] && !sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteD);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteD);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6]) {
      digitalWrite(buzzer, HIGH);
    }

    //note Low C
    if (sensorValPress[1] && sensorValPress[2] && sensorValPress[3] && sensorValPress[4] && sensorValPress[5] && sensorValPress[6] && sensorValPress[7]) {
      for (int i = 10; i > 0; --i) {
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(noteLowC);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(noteLowC);
      }
    } else if (!sensorValPress[1] && !sensorValPress[2] && !sensorValPress[3] && !sensorValPress[4] && !sensorValPress[5] && !sensorValPress[6] && !sensorValPress[7]) {
      digitalWrite(buzzer, HIGH);
    }
  }
}
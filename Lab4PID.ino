int enA=9;
int in1=8;
int in2=7;

int sensorA=3;
int sensorB=2;
int channelA;
bool channelB;
int counter=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorA, INPUT);
pinMode(sensorB, INPUT);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
attachInterrupt(digitalPinToInterrupt(sensorA), tick, RISING);
Serial.print("counter");
//analogWrite(enA, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(enA, 255);

  if (counter<1000){;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  //else if (counter>999 && counter<1001){;
  //  analogWrite(enA,50);
  }
  else if(counter>1000){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  Serial.println(counter);
}

void tick(){
  channelB=digitalRead(sensorB);
  if (channelB == LOW){;
  counter=counter+1;
  }
  else
  counter=counter-1;
}

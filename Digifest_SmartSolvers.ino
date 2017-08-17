const int trig_pin = 7;
const int echo_pin = 6;
const int led_pin = 13;
const int led_green = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(led_green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1) {
  long duration, cm;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  char data = Serial.read();
  switch(data) {
    case '1':
    digitalWrite(led_green, HIGH);
    break;
   case '2':
    digitalWrite(led_pin, HIGH);
    break;
   case '3':
    digitalWrite(led_green, HIGH);
    break;
   case '4':
    digitalWrite(led_pin, HIGH);
    break;
   case '5':
    digitalWrite(led_green, HIGH);
    break;
   case '6':
    digitalWrite(led_pin, HIGH);
    break;
   case '7':
    digitalWrite(led_green, HIGH);
    break;
   case '8':
    digitalWrite(led_pin, HIGH);
    break;
   case '9':
    digitalWrite(led_green, HIGH);
    break;
  }

  if(cm <= 10) {
    digitalWrite(led_green, LOW);
    digitalWrite(led_pin, LOW);
    break;
  }
  delay(100);
}
}

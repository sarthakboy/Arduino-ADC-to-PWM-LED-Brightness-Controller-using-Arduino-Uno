void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);

}

void loop() {

int reading = analogRead(A0);
Serial.println(reading);
int brightness = (reading*255)/1023;
analogWrite(9, brightness);

}
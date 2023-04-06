int Led_pin = 9;
int Analog_pin = A5;
int switchPin = 2;
void setup() {
    Serial.begin(9600);
    pinMode(switchPin, INPUT_PULLUP);
    pinMode(Led_pin, OUTPUT);
}

void loop(){
    int val = analogRead(Analog_pin);
    val = map(val, 0, 1023, 0, 255);
    // analogWrite(Led_pin, val);
    if(digitalRead(switchPin) == LOW) {
        analogWrite(Led_pin, 255);
    }
    else{
        analogWrite(Led_pin, val);
    }
    // Serial.println(val);
}
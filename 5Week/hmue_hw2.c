int led = 3;
int sw = 5;
int value = 0;
void setup() {
    pinMode(led, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(sw) == LOW) {
        if(value == 0){
            value = 1;
            digitalWrite(led, HIGH);
            delay(300);
        }    
        else{
            value = 0;
            digitalWrite(led, LOW);
            delay(300);
        }
    }
}
// 상수값 설정
const int ledPin = 9; // LED 핀 번호
const int switchPin = 2; // 택트 스위치 핀 번호
int brightness = 0; // LED 밝기값 변수

void setup() {
  // 핀 모드 설정
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // 가변저항 값을 읽어와 LED 밝기값 조절
  brightness = analogRead(A0) / 4;
  analogWrite(ledPin, brightness);

  // 택트 스위치를 누르면 LED 밝기를 최대값으로 설정
  if (digitalRead(switchPin) == LOW) {
    analogWrite(ledPin, 255);
    delay(500); // 0.5초 동안 대기
  }
}
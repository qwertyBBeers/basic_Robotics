// 상수값 설정
const int ledPin = 9; // LED 핀 번호
const int switchPin = 2; // 택트 스위치 핀 번호
int ledState = LOW; // LED 상태 변수
int buttonState = HIGH; // 택트 스위치 상태 변수
int lastButtonState = HIGH; // 이전 택트 스위치 상태 변수
unsigned long lastDebounceTime = 0; // 디바운스 타이머 변수
unsigned long debounceDelay = 50; // 디바운스 딜레이 변수
unsigned long blinkInterval = 500; // LED 깜빡이는 주기

void setup() {
  // 핀 모드 설정
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // 택트 스위치 디바운스 처리
  int reading = digitalRead(switchPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        ledState = !ledState; // LED 상태 반전
        if (ledState == HIGH) { // LED 켜기
          digitalWrite(ledPin, HIGH);
        } else { // LED 끄기
          digitalWrite(ledPin, LOW);
        }
      }
    }
  }
  lastButtonState = reading;

  // 택트 스위치를 계속 누르고 있을 때, LED 깜빡이기
  if (buttonState == LOW) {
    if (millis() - lastDebounceTime > blinkInterval) {
      ledState = !ledState; // LED 상태 반전
      digitalWrite(ledPin, ledState);
      lastDebounceTime = millis();
    }
  }
}
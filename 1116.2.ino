int ledPin = 9; // PWM pin connected to LED

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int bright;

  if (Serial.available() > 0) {
    bright = Serial.parseInt();
    analogWrite(ledPin, bright);
  }
}

// void setup() {
//   Serial.begin(9600);      
//   pinMode(ledPin, OUTPUT); // Set LED pin as output
//   // pinMode(LED_BUILTIN, OUTPUT);

//   // Handshake
// //   while (Serial.available() <= 0) {
// //     digitalWrite(LED_BUILTIN, HIGH); // Blink LED while waiting for serial data
// //     delay(300);
// //     digitalWrite(LED_BUILTIN, LOW);
// //     delay(50);
// //   }
// // }

// void loop() {
//   int brightness;
//   if (Serial.available() > 0) {
//     // Read brightness value sent from p5.js
//     brightness = Serial.read();
//     brightness = constrain(brightness, 0, 255); // Ensure brightness is in valid range
//     analogWrite(ledPin, brightness); // Set LED brightness
//   }
// }

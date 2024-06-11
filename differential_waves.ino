// Pins
const int pinA = 11; // OC1A
const int pinB = 12; // OC1B

void setup() {
  // Set the OC1A and OC1B pins as outputs
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);

  // Disable Timer1 interrupts to safely configure
  noInterrupts();
  
  // Set Fast PWM mode with ICR1 
  TCCR1A = (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10); // Prescaler of 1
  
  // Set the top value for ICR1 
  ICR1 = 4; // for 3 MHz at 16 MHz with prescaler 1
  
  // Set the duty cycle (50%)
  OCR1A = 2; // 50% duty cycle for OC1A
  OCR1B = 2; // 50% duty cycle for OC1B
  
  // Enable interrupts
  interrupts();
}

void loop() {

}

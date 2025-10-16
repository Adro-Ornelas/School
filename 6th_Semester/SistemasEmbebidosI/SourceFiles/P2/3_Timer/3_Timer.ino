// 3_Timer

#define LED1 2      // LED 1 en D2 (timer)
#define LED2 3      // LED 2 en D3 (pulsos )

volatile byte segundos = 0;
volatile byte pulsos = 0;

void setup() {

  // LEDs como pines de salida
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  // Timer1 para LED 1, 5 segundos off, 5 segundos on
  TCCR1A = 0;       // Modo normal, desconectado de OC1A
  TCCR1B = 0;

  // WGM12 NO NECESARIO
  TCCR1B |= (1 << CS10)|(1 << CS12);  // Modo CTC Presc de 1024
 
  TCNT1 = 0;        // Timer inicia en cero                
  OCR1A = 15625;     // (15625 * 1024) / 16Mhz = 1s
  TIMSK1 |= (1 << OCIE1A); // Activa interrupcion por comparacion

  // Timer0 para encender led con 30 pulsos externos y apagar con 30 (T0 es D4)

  TCCR0A = 0;       // Modo normal, desconectado de OC1A
  TCCR0B = 0;
  TCCR0B |= (1 << CS02)|(1 << CS01)|(1 << CS00);  // Fuente de reloj externa en T0, (en subida)
 
  TCNT0 = 0;        // Timer inicia en cero                
  OCR0A = 4;        // Contar cinco pulsos (30 ?????????????)
  TIMSK0 |= (1 << OCIE0A); // Activa interrupcion por comparacion

}

void loop() {
  // Nada en loop
}

ISR(TIMER0_COMPA_vect){

  TCNT0 = 0;        // Reinicia contador
  digitalWrite(LED2, !digitalRead(LED2));  // Toggle LED  
  
}

ISR(TIMER1_COMPA_vect){
  
  TCNT1 = 0;          // Reinicia contador
  ++segundos;
  if(segundos == 5) { // Cada 5 segundos prende o apaga el LED
    digitalWrite(LED1, !digitalRead(LED1));  // Toggle LED
    segundos = 0;
  }
}

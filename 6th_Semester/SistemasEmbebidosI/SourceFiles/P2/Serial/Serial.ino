// SIMULACION DE SEÑAL SENOIDAL Y CUADRADA

// Variables de tiempo
float t = 0;
float dt = 0.1;  // paso de tiempo

void setup() {
  Serial.begin(9600); // inicializa comunicación serial
}

void loop() {
  
  // Señal senoidal: A*sin(2πft)
  float seno = 100 * sin(2 * PI * 0.1 * t); // A = 100, f = 0.1 Hz
  
  // Señal cuadrada
  float tri = 0;
  float periodo = 10; // 10 segundos por ciclo (Igual que senoidal (1 / 0.1 Hz) = 10s)
  float t_mod = fmod(t, periodo);
  
  if (t_mod < periodo / 2) {
    tri = 100;
  } else {
    tri = -100;
  }

  // Enviar por Serial separadas por tabulador
  Serial.print(seno);
  Serial.print("\t"); // Tambien sirve ", "
  Serial.println(tri);

  // Aumentar tiempo
  t += dt;
  delay(100); // 100 ms de pausa
}

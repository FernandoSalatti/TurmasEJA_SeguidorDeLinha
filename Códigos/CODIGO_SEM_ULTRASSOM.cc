// Definição dos pinos de controle do motor
#define M1 9 // Pino_Velocidade 1º Motor (0 a 255) _ Porta IN2 ponte H;
#define M2 11 // Pino_Velocidade 2º Motor (0 a 255) _ Porta IN4 ponte H;
#define dir1 8 // Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW) _ porta IN1ponte H;
#define dir2 10 // Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW) _ porta IN3ponte H;

// Definição dos pinos dos sensores
#define pin_S1 6
#define pin_S2 7

bool Sensor1 = 0;
bool Sensor2 = 0;

int velocidade = 130; // O valor pode ir de 0 até 255, ajuste conforme a pista (pistas menores ou curvas mais fechadas requerem velocidades menores).

void setup() {

  // Configuração dos pinos
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);

  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
}

void loop() {

  // Leitura dos sensores
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);

  // Lógica para seguir linha preta
  if (Sensor1 == 0 && Sensor2 == 0) { // Ambos sensores na linha (seguir em frente)

    analogWrite(M1, velocidade);
    analogWrite(M2, velocidade);

  } else if (Sensor1 == 1 && Sensor2 == 0) { // Sensor1 na linha, Sensor2 fora (virar para umlado)

    analogWrite(M1, velocidade);
    analogWrite(M2, 0);

  } else if (Sensor1 == 0 && Sensor2 == 1) { // Sensor2 na linha, Sensor1 fora (virar para ooutro lado)

    analogWrite(M1, 0);
    analogWrite(M2, velocidade);

  } else {

    analogWrite(M1, 0);
    analogWrite(M2, 0);
  }
}
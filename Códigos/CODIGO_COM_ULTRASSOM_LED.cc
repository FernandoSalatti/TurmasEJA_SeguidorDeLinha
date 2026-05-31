// Definição dos pinos de controle do motor
#define M1 9
#define M2 11
#define dir1 8
#define dir2 10
// LEDs
#define LED_VERDE 12
#define LED_VERMELHO 13

// Sensores de linha
#define pin_S1 6
#define pin_S2 7
bool Sensor1 = 0;
bool Sensor2 = 0;

// Ultrassônico
#define TRIG 4
#define ECHO 5

long duracao;
float distancia = 999;

unsigned long tempoAnterior = 0;
const unsigned long intervaloUS = 100; // mede a cada 100ms

int velocidade = 130;

void setup() {

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
}

float medirDistancia() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracao = pulseIn(ECHO, HIGH, 20000);

  if (duracao == 0) return 999;

  return duracao * 0.034 / 2;
}

void loop() {

  // 🔵 Atualiza ultrassônico apenas no intervalo definido
  if (millis() - tempoAnterior >= intervaloUS) {
    tempoAnterior = millis();
    distancia = medirDistancia();
  }

  // 🔴 Se tiver obstáculo perto, para tudo
  if (distancia < 15) {
    analogWrite(M1, 0);
    analogWrite(M2, 0);

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);

    return;
  }

  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERMELHO, LOW);

  // 🟢 Leitura dos sensores de linha (roda o tempo todo, bem rápido)
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);

  if (Sensor1 == 0 && Sensor2 == 0) {

    analogWrite(M1, velocidade);
    analogWrite(M2, velocidade);

  } else if (Sensor1 == 1 && Sensor2 == 0) {

    analogWrite(M1, velocidade);
    analogWrite(M2, 0);

  } else if (Sensor1 == 0 && Sensor2 == 1) {

    analogWrite(M1, 0);
    analogWrite(M2, velocidade);

  } else {

    analogWrite(M1, 0);
    analogWrite(M2, 0);
  }
}
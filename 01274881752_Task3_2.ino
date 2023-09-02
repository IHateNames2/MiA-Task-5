#define TRIG_PIN_N 2
#define ECHO_PIN_N 3
#define TRIG_PIN_E 4
#define ECHO_PIN_E 5
#define TRIG_PIN_S 6
#define ECHO_PIN_S 7
#define TRIG_PIN_W 8
#define ECHO_PIN_W 9

void setup() {
  pinMode(TRIG_PIN_N, OUTPUT);
  pinMode(ECHO_PIN_N, INPUT);
  pinMode(TRIG_PIN_E, OUTPUT);
  pinMode(ECHO_PIN_E, INPUT);
  pinMode(TRIG_PIN_S, OUTPUT);
  pinMode(ECHO_PIN_S, INPUT);
  pinMode(TRIG_PIN_W, OUTPUT);
  pinMode(ECHO_PIN_W, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  float distance_N = getDistance(TRIG_PIN_N, ECHO_PIN_N);
  float distance_E = getDistance(TRIG_PIN_E, ECHO_PIN_E);
  float distance_S = getDistance(TRIG_PIN_S, ECHO_PIN_S);
  float distance_W = getDistance(TRIG_PIN_W, ECHO_PIN_W);

  float x = (distance_W - distance_E) / 2;
  float y = (distance_S - distance_N) / 2;

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("m, y: ");
  Serial.print(y);
  Serial.println("m");
  
  delay(1000);
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (in meters)
  float distance = duration * (0.034 / (2 *100));
  
  return distance;
}

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Stop();
  Serial.println("Bluetooth Car Ready!");
}

void loop() {
  if (Serial.available() > 0) {
    char value = Serial.read();
    value = toupper(value);

    Serial.print("Received Command: ");
    Serial.println(value);

    switch (value) {
      case 'F': Forward(); break;
      case 'B': Backward(); break;
      case 'S': Stop(); break;
      case 'L': Left(); break;
      case 'R': Right(); break;
      default:
        Serial.println("Invalid Command, Stopping!");
        Stop();
        break;
    }
  }
}

void Forward() {
  Serial.println("Moving Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Backward() {
  Serial.println("Moving Backward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  Serial.println("Stopping");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Left() {
  Serial.println("Turning Left");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Right() {
  Serial.println("Turning Right");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

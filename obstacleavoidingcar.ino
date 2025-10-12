#define trigPin 13
#define echoPin 12
#define motor 7
#define buzzer 6

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motor, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
  
    long duration, distance;

    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the echo pulse duration
    duration = pulseIn(echoPin, HIGH);

    // Convert time to distance (in cm)
    distance = (duration / 2.0) / 29.412;

    // Ignore invalid readings
    if (distance > 400 || distance == 0) {
        return;  // Ignore unrealistic values
    }

    // Control motor and buzzer based on distance
    if (distance < 30) {
        digitalWrite(motor, HIGH);  
        digitalWrite(buzzer, HIGH);
    } else {
        digitalWrite(motor, LOW);   
        digitalWrite(buzzer, LOW);
    }

    delay(100);  // Reduced delay for faster response
}

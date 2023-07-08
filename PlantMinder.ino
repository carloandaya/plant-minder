#define relay1 2
#define relay2 3
#define relay3 4
#define relay4 5

#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3

int dryValues[] = {507, 505};
int wetValues[] = {200, 192};
int relays[] = {relay1, relay2, relay3, relay4};
int sensors[] = {sensor1, sensor2, sensor3, sensor4};

int moistureReading = 0;
int percentageReading = 0;

void setup() {
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  for (int pin = 0; pin < sizeof(relays); pin++) {
    digitalWrite(relays[pin], HIGH);
  }
  
}

void loop() {  

  for (int pin = 0; pin < (sizeof(dryValues) / sizeof(dryValues[0])); pin++) {
    moistureReading = analogRead(sensors[pin]);
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(moistureReading);
    percentageReading = map(moistureReading, wetValues[pin], dryValues[pin], 100, 0);
    Serial.print(pin); 
    Serial.print(": ");    
    Serial.println(percentageReading);

    if (percentageReading < 50) {
      digitalWrite(relays[pin], LOW);
      delay(1000);
      digitalWrite(relays[pin], HIGH);
      delay(9000);
    }

  }
}

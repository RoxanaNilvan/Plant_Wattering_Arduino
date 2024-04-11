
int sensor_pin = A8;       //Sensor Pin
int relay_pin = 39;         //Relay Pin

void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(33, OUTPUT);
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, LOW);
    Serial.println("Motor ON ");
    digitalWrite(33, HIGH);
    digitalWrite(28, LOW);
    digitalWrite(30, LOW);
  }
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
    Serial.println("There is some moisture, Soil is medium");
    digitalWrite(relay_pin, HIGH);
    Serial.println("Motor OFF");
    digitalWrite(28, HIGH);
    digitalWrite(30, LOW);
    digitalWrite(33, LOW);
  }
  else if(sensor_data < 400)
  {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, HIGH);
    Serial.println("Motor OFF");
    digitalWrite(30, HIGH);
    digitalWrite(28, LOW);
    digitalWrite(33, LOW);
  }

  delay(100);
}

// Analogue input
#define MIC_ANALOG_INPUT A0

// Leds pins

#define LED_PIN_1 2
#define LED_PIN_2 3
#define LED_PIN_3 4
#define LED_PIN_4 5
#define LED_PIN_5 6

#define LAST_VALUE_COUNT 100

int lastValues[LAST_VALUE_COUNT];
int counter = 0;

int getLastLowValue()
{
  int result = lastValues[0];
  for (int i = 1; i < LAST_VALUE_COUNT; i++)
  {
    if (lastValues[i] < result)
    {
      result = lastValues[i];
    }
  }
  return result;
}

int getLastHighValue()
{
  int result = lastValues[0];
  for (int i = 1; i < LAST_VALUE_COUNT; i++)
  {
    if (lastValues[i] > result)
    {
      result = lastValues[i];
    }
  }
  return result;
}

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(MIC_ANALOG_INPUT);
  // Serial.println(micValue);

  lastValues[counter++] = micValue;
  if (counter >= LAST_VALUE_COUNT) {
    counter = 0;
  }

  // Off all leds
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, LOW);
  digitalWrite(LED_PIN_4, LOW);
  digitalWrite(LED_PIN_5, LOW);


  int lowValue = getLastLowValue();
  int highValue = getLastHighValue();
 
  // Define the range of the sensor
   int value = map(micValue, lowValue + 4, highValue - 4, 0, 5);

  // On the leds one by one

  if (value >= 1) {
    digitalWrite(LED_PIN_1, HIGH);
  }
  if (value >= 2) {
    digitalWrite(LED_PIN_2, HIGH);
  }
  if (value >= 3) {
    digitalWrite(LED_PIN_3, HIGH);
  }
  if (value >= 4) {
    digitalWrite(LED_PIN_4, HIGH);
  }
  if (value >= 5) {
    digitalWrite(LED_PIN_5, HIGH);
  }
  delay(20);
}

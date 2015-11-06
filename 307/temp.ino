int buttonPin = 13;
int buttonState = 0;
int lastButtonState = LOW;
int buttonData;
int sequence = 0;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {

	Serial.begin(9600);
	pinMode(buttonPin, INPUT);
}

void loop() {

	int sensor1Value = analogRead(A0);
	int sensor2Value = analogRead(A1);
	buttonState = digitalRead(buttonPin);

	if (buttonState != lastButtonState) {
    	lastDebounceTime = millis();
  	}

  	if ((millis() - lastDebounceTime) > debounceDelay) {
		if (buttonState != buttonData) {
			buttonData = buttonState;

			if (buttonState == HIGH) {

				String outString = "This is number: ";
				sequence += 1;

				String outString1 = outString + sequence;
				String outString2 = outString1 + " temperature voltage: ";
				String outString3 = outString2 + sensor1Value;
				String outString4 = outString3 + " LDR voltage: ";
				String outString5 = outString4 + sensor2Value;

				Serial.println(outString5);
			}
		}
  	}

  	lastButtonState = buttonState;
}

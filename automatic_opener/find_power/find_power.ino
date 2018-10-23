
long maximum = 0;
void setup(){
	pinMode(A0,INPUT);

	Serial.begin(9600);
}

void loop(){

	long reading = analogRead(A0);

	if (reading > maximum)
		maximum = reading;

	Serial.print("solar on A0: ");
	Serial.print(reading,DEC);
	Serial.print(" (max: ");
	Serial.print(maximum,DEC);
	Serial.println(")");
	delay(10000);			//wait roughly 10 seconds for next reading
}

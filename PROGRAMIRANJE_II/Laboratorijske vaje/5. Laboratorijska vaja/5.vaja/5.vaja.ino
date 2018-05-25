#define led LED_BUILTIN

unsigned long prej = 0;
unsigned long interval;
int ledState = 0;
float vrednost;
float razdalja;
float meja = 40.0;

void setup(){
	Serial.begin(9600);
	pinMode(led, OUTPUT);
}

void loop(){
	
	vrednost = analogRead(A0);
	razdalja = 13 * pow(vrednost, -1) * 100;
	interval = map(razdalja, 4, 40, 100, 1000);

	unsigned long sedaj = millis();

	if(sedaj - prej >= interval){
		if(razdalja < meja){
			if(ledState == 0){
				Serial.println(razdalja);
				digitalWrite(led, HIGH);
				ledState = 1;
			}
			else{
				digitalWrite(led, LOW);
				ledState = 0;
			}
		}
		else{
			digitalWrite(led, LOW);
		}
		prej = sedaj;
	}
	if(razdalja > 40){digitalWrite(led, LOW);}
}
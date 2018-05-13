#define senzor1 analogRead(A0)
#define senzor2 analogRead(A1)
float razdalja(int analog);
float raz1, raz2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raz1 = razdalja(senzor1);
  raz2 = razdalja(senzor2);
  if(raz1 <=40 && raz1 >= 4){
  	Serial.print("Razdalja:\t");
  	Serial.print(raz1,0);
  }
  delay(100);
}

float razdalja(int analog){
//  float raz = analog * 0.004882813; /* 5V */
  float raz = analog * 0.003222656; /* 3.3V */
  raz = 13 * pow(raz, -1);
  return raz;
}

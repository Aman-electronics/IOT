float soil_moisture;
float sm_percentege;
int pump = 2;      //pump is on GPIO 2

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(pump,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
soil_moisture = analogRead(A0);
sm_percentege = map(soil_moisture,0,1023,100,0);
if(sm_percentege <=30)
{
  digitalWrite(pump, LOW);
  Serial.println("Soil is DRY");
}
else if (sm_percentege>>31 && sm_percentege <40)
{
  digitalWrite(pump, LOW);
  Serial.println("Soil moisture is Optimum");
}
else if (sm_percentege >=40)
{
digitalWrite(pump, HIGH);
Serial.println("Soil moisture is wet");
}

Serial.print("Soil Moisture=");
Serial.println(soil_moisture);
Serial.print("Soil Moisture % =");
Serial.print(sm_percentege);
Serial.println("%");
delay(1000);
}

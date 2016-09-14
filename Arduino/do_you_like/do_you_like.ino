void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Start UART system @ 9600 baud
  pinMode(2, OUTPUT); //port 2 Set to Output
  Serial.print("DO YOU LIKE ARDUINO?\n"); // Say Stuff 

void Blink()
{
  digitalWrite(2, HIGH); // sets a out put (boolean)
  delay(500); // wait for 500 msec
  digitalWrite(2, LOW);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() && Serial.read() == 'y') // sees if anyone is trying to input, reads the data if there is any
  {
    while (true)
    {
      Blink(); // references function
    }
  }

}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // Start UART system @ 9600 baud
 
}

void loop() {
  char data = Serial.read();
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    switch (data) 
    {
    case "ls" :
    
    break;
    case "cd":
    
    break;
    case "mkdir":
    
    break;
    default:
    
    break;
    }
    
  }



}

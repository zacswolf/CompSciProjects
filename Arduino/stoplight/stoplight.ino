void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
}

int red = 0;
int yellow = 0;
int green = 0;



void ToggleRed()
{
  if (red == 0)
  {
    digitalWrite(2, HIGH);
    red = 1;
  }
  else
  {
    digitalWrite(2, LOW);
    red = 0;
  }
}

void ToggleYellow()
{
  if (yellow == 0)
  {
    digitalWrite(3, HIGH);
    yellow = 1;
  }
  else
  {
    digitalWrite(3, LOW);
    yellow = 0;
  }
}

void ToggleGreen()
{
  if (green == 0)
  {
    digitalWrite(4, HIGH);
    green = 1;
  }
  else
  {
    digitalWrite(4, LOW);
      green = 0;
  }
}

void Clear() 
{
  red = 0;
  green = 0;
  yellow = 0;
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void Show()
{
 Clear();
 ToggleRed();
 delay(100);
 ToggleYellow();
 delay(100);
 ToggleGreen();
 delay(100);
 ToggleGreen();
 delay(100);
 ToggleYellow();
 delay(100);
 ToggleRed();
 delay(100);
 ToggleRed();
 delay(100);
 ToggleYellow();
 delay(100);
 ToggleGreen();
 delay(100);
 ToggleGreen();
 delay(100);
 ToggleYellow();
 delay(100);
 ToggleRed();
 delay(100);
 ToggleRed();
 ToggleGreen();
 delay(100);
 ToggleYellow();
 delay(50);
 ToggleRed();
 ToggleGreen();
 delay(100);
 ToggleYellow();

 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) // sees if anyone is trying to input, reads the data if there is any
  {
    char data = Serial.read();
    // case switch
    if (data == 'y')
    {
     ToggleYellow();
    }
    if (data == 'r')
    {
     ToggleRed();
    }
    if (data == 'g')
    {
     ToggleGreen();
    }
    if (data == 'c')
    {
     Clear();
    }
  }
  
  
  /*ToggleRed();
  ToggleGreen();
  delay(500);
  ToggleRed();
  ToggleGreen();
  ToggleYellow();
  delay(500);
*/
}

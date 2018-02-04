int p1 = 1;
int p2 = 2;
int p3 = 3;
int p4 = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(p4, 1);
  digitalWrite(p4, 0);
  digitalWrite(p1, random(LOW,HIGH));
  digitalWrite(p2, random(LOW,HIGH));
  digitalWrite(p3, random(LOW,HIGH));
  delay(1000);
}

/* BT 4 LedButton
 *  -------------
 *  
 * Toggle state LED on pin 6 when serial bluetooth read char '1',
 * Toggle state LED on pin 7 when serial bluetooth read char '2',
 * Toggle state LED on pin 8 when serial bluetooth read char '3',
 * Toggle state LED on pin 9 when serial bluetooth read char '4',
 * 
 * Send char '1' via serial bluetooth when BUTTON on pin 2 pressed,
 * Send char '2' via serial bluetooth when BUTTON on pin 3 pressed,
 * Send char '3' via serial bluetooth when BUTTON on pin 4 pressed,
 * Send char '4' via serial bluetooth when BUTTON on pin 5 pressed,
 * 
 * 2014, www.bluino.com
 * @author: MansurKamsur
 */

int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;
byte theByte=0;

void setup(){
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(115200);
}
void loop(){
  if (Serial.available()>0)
  {
    theByte=Serial.read();
    if (theByte==49){
      if (flag1==0) {
        digitalWrite(6,HIGH);
        flag1=1;
      }else {
        digitalWrite(6,LOW);
        flag1=0;
      }
    }
    
    else if (theByte==50){
      if (flag2==0) {
        digitalWrite(7,HIGH);
        flag2=1;
      }else {
        digitalWrite(7,LOW);
        flag2=0;
      }
    }
    
    else if (theByte==51){
      if (flag3==0) {
        digitalWrite(8,HIGH);
        flag3=1;
      }else {
        digitalWrite(8,LOW);
        flag3=0;
      }
    }
    
    else if (theByte==52){
      if (flag4==0) {
        digitalWrite(9,HIGH);
        flag4=1;
      }else {
        digitalWrite(9,LOW);
        flag4=0;
      }
    }
    
    
  }
  
    if (digitalRead(2)==LOW) {Serial.println("1"); delay(300);}
    if (digitalRead(3)==LOW) {Serial.println("2"); delay(300);}
    if (digitalRead(4)==LOW) {Serial.println("3"); delay(300);}
    if (digitalRead(5)==LOW) {Serial.println("4"); delay(300);}
  
  
}



String state;
String word1;
String word2;
void setup() {
  
  Serial2.begin(9600);
  Serial.begin(9600);
 Serial.println("welcome");
 
    }  

void loop() {
 // Serial.println("I am void loop");
    if   ( Serial2.available() )      { 
      state = Serial2.readString(); 
   Serial.println(state);
   word1=state.substring( 1 , 12);
    word2=state.substring( 13 , 17);
    Serial.println(word1);
    Serial.println(word2);

     
}//end serial available
}//end loop

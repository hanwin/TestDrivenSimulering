#include <DHT.h>;


#define DHTPIN 12     
#define DHTTYPE DHT22   
#define LED_BLUE 2
#define LED_YELLOW 3
#define LED_RED 4
#define BUTTON 5
DHT dht(DHTPIN, DHTTYPE); 



int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
    int button_state; 
    
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    button_state = digitalRead(BUTTON);

    (button_state) ? print_hum(hum) : print_temp(temp);

}

void print_temp(int t){
  
      if (t > 15 && t < 20){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    else if (t >= 20 && temp < 25 ){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
      return 0b110;
      
    }
    else if (t >= 25){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, HIGH);
    }
    else {
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
}

void print_hum(int h){
  
      if (h > 45 && h < 50){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    else if (h >= 50 && h < 55 ){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
      return 0b110;
      
    }
    else if (h >= 55){
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, HIGH);
    }
    else {
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
}
   

#include "DHT.h"


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

int temp_condition_test( int temp_value, int expected_value ){
  return ( temp_value == expected_value );
}
void unitTest(){
  int fail[50];
  int i = 0, j = 0;

  for( ;i < 50; i++){
    fail[i] = temp_condition_test( print_temp(i), j ); 
    switch(i){
      case 15: j++;
      break;  
      case 19: j++;
      break;
      case 24: j++;  
    }
  }
}
void loop()
{
    int button_state; 
    int status = 0;
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    button_state = digitalRead(BUTTON);

    status = (button_state) ? print_hum(hum) : print_temp(temp);
    led_action( status);
    
   // (button_state) ? print_hum(hum) : print_temp(temp);

}

void led_action( int led){
  switch(led){
    case 1:
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
      break;
     case 2:
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
      break;
     case 3:
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, HIGH);
      break;
    default:
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
      break;
  }
}
int print_temp(int t){
  int status = 0;
      if (t > 15 && t < 20){
      status = 1;
    }
    else if (t >= 20 && temp < 25 ){
      status = 2;
      
    }
    else if (t >= 25){
      status = 3;
    }
   return status;
}

int print_hum(int h){
  
  int status = 0;
      if (h > 45 && h < 50){
      status = 1;
    }
    else if (h >= 50 && h < 55 ){
      status = 2;
      
    }
    else if (h >= 55){
      status = 3;
    }
    return status;
}
   


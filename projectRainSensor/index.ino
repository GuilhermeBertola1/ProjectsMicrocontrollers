#define sensorChuva A1
#define sentitoPositivo 2
#define sentitoNegativo 3

int valorLimiteChuva = 500;           
bool chuva = false;

bool fatorMotor = 0;

int time = 0;

void setup(){    
  
  pinMode(sensorChuva, INPUT);
  pinMode(sentitoPositivo, OUTPUT);
  pinMode(sentitoNegativo, OUTPUT);
  
  Serial.begin(9600);

}

void loop(){
  
  SensorDeChuva();
  HighMotor();
  
  delay(1000);                                                   
}

void SensorDeChuva(){
  
  int valorSensorChuva = analogRead(sensorChuva);                
  
  Serial.print("Sensor de chuva = ");                           
  Serial.print(valorSensorChuva);                               
  
  if (valorSensorChuva < valorLimiteChuva){
    
    Serial.println(" => Esta chovendo");                        
    chuva = true;  
    
  }else{
    
    Serial.println(" => O tempo esta seco");                    
   	chuva = false;
    
  }

}

void HighMotor(){

  if(fatorMotor == 0){
  	if(chuva == true){
      	Serial.println("Motor 1 ativo");
    	do{
  			
 			Serial.println(time + 1);
      
    		digitalWrite(sentitoNegativo, LOW);
    		digitalWrite(sentitoPositivo, HIGH);
          	time++;
          	delay(1000);
    	}while(time < 5);
      
      	time = 0;
      	digitalWrite(sentitoPositivo, LOW);
      	fatorMotor = 1;
  	}
  }
  
  if(fatorMotor == 1){
  	if(chuva == false){
      	Serial.println("Motor 2 ativo");
    	do{
        	
  			Serial.println(time + 1);
      
    		digitalWrite(sentitoPositivo, LOW);
    		digitalWrite(sentitoNegativo, HIGH);
          	time++;
          	delay(1000);
    	}while(time < 5);
      
      	time = 0;
      	digitalWrite(sentitoNegativo, LOW);
      	fatorMotor = 0;
  	}
 }

}

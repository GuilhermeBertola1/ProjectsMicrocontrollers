#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>

//declaracao de vetores e variavel referente aos dados dos usuarios
#define nUsuarios 4
String nomesUsu []= {"0001", "0002", "0003","0004"};
String senhacorr[]= {"4787", "4200", "5454", "0024"};
//-------------------------------------

//declaracao de variaveis tipo define
#define END_SLAVE 7
#define pinPot A3
#define pinPwm 10
//-----------------------------------

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //configuracao dos pinos para lcd

//configurcao do servo motor----------------------------
Servo servo1; //configuracao do objeto do servo motor
byte pinServo = 9; //configuracao do pino do servo motor
//------------------------------------------------------

//declaracao de variaveis do tipo int, string e bool
int i = 0;
int indice = 0;

String A;
String C;

bool fatorM = false;
bool statusID = false;
//--------------------------------------------------

void setup(){
  
  Serial.begin(9600); //iniciando o monitor serial
  
  lcd.begin(16, 2); //iniciando o lcd
  lcd.print("DIGITE O SEU ID:"); //imprime uma mensagem no lcd
  lcd.setCursor(0,2); //posiciona o cursor no lcd
  Serial.println("Lcd iniciado com sucesso"); //mostra uma mensagem no monitor serial

  Wire.begin(); //Inicializa a interface I2C como Master
  Serial.println("Arduino master iniciado com sucesso"); //mostra uma mensagem no monitor serial
  
  servo1.attach(pinServo); //Anexe a variável Servo a um pino
  Serial.println("Servo motor iniciado com sucesso"); //mostra uma mensagem no monitor serial
  
}

int VoltsCalc(byte canal); //declaracao da funcao VoltsCalc

void loop(){
 
 int pwm; //declaracao da variavel do tipo int
 pwm = pwmLer(pinPot); //atribui o valor da funcao passando o parametro pinPot na variavel pwm
 analogWrite(pinPwm, pwm); //le no pino pinPwm e a variavel pwm atraves da funcao
 
 bool status = false; //atribui o valor de false para a variavel status
 bool fatorK = false; //atribui o valor de false para a variavel fatorK
   
   Wire.beginTransmission(END_SLAVE); //Inicia transmissão
   Wire.write("1"); //Envia comando "1" para ler tecla
   Wire.endTransmission(); //Finaliza transmissão

   Wire.requestFrom(END_SLAVE, 1); //Solicita dados do Slave (1 byte)
   if(Wire.available()){ //Enquanto houver dados no buffer da I2C enviados pelo Slave
    status = char(Wire.read()); //Ler dado retornado pelo Slave
   }

   Wire.beginTransmission(END_SLAVE); //Inicia transmissão
   Wire.write("2"); //Envia comando "2" para ler tecla
   Wire.endTransmission(); //Finaliza transmissão

   Wire.requestFrom(END_SLAVE, 1); //Solicita dados do Slave (1 byte)
   String B; //declara a string B
   if(Wire.available()){ //Enquanto houver dados no buffer da I2C enviados pelo Slave
    B = char(Wire.read()); //Ler dado retornado pelo Slave
   }
  
if(fatorM == false){ //se o valor de fatorM for igual a false

   if(B.charAt(0) != A.charAt(0) || status == true){ //se a string B no indice 0 diferente da string A no indice 0 ou se a variavel status for igual a true

      Serial.println(B); //mostra uma mensagem no monitor serial

      A = B; //atribui o valor da string B em A
      C += B; //incrementa o valor da string B em C

      lcd.setCursor(6,1); //posiciona o cursor no lcd
      lcd.print(C); //imprime uma mensagem no lcd

      status = false; //atribui o valor de false para status

     if(C.length() == 4){ //se o tamanho da string C for igual a 4

       Serial.println("ID da conta:"); //mostra uma mensagem no monitor serial
       Serial.println(C); //mostra uma mensagem no monitor serial

       for(i=0;i < nUsuarios;i++){ //estrutura de repeticao caso i for menor que nUsuarios

         if(C == nomesUsu[i]){ //se a string C for igual ao valor do vetor nomeUsu no indice i

           statusID = true; //atribui o valor true na variavel statusID
           indice = i; //atribui o i na variavel indice
           fatorK = true; //atribui o valor true fatorK
           fatorM = true; //atribui o valor true fatorM
           
           Serial.println("ID existente"); //mostra uma mensagem no monitor serial
           lcd.clear(); //limpa a tela do lcd
           lcd.setCursor(2,0); //posiciona o cursor no lcd
           lcd.print("ID EXISTENTE");//imprime uma mensagem no lcd
           delay(3000); //espera 3 segundos
             
       	   lcd.clear(); //limpa a tela do lcd
       	   C = ""; //atribui o valor nulo na string C
           
           lcd.print("DIGITE A SENHA:"); //imprime uma mensagem no lcd
           lcd.setCursor(0,2); //posiciona o cursor no lcd

         }
       }
       
       if(fatorK == false){ //se a variavel fatorK for igual a false
       
       	 Serial.println("ID inexistente"); //mostra uma mensagem no monitor serial
         lcd.setCursor(0,0); //posiciona o cursor no lcd
         lcd.clear(); //limpa a tela do lcd
         lcd.print("ID INEXISTENTE"); //imprime uma mensagem no lcd
         delay(3000); //espera 3 segundos
         
         C = ""; //atribui o valor nulo na string C
       	 lcd.clear(); //limpa a tela do lcd
       	 status = false; //atribui o valor de false para a variavel status
         
         lcd.print("DIGITE O SEU ID:"); //imprime uma mensagem no lcd
  		 lcd.setCursor(0,2); //posiciona o cursor no lcd
       
       }
     }
   }
 }
     
 if(statusID){ //se o valor da variavel statusID for igual a true
  
    if(B.charAt(0) != A.charAt(0) || status == true){ //se a string B no indice 0 diferente da string A no indice 0 ou se a variavel status for igual a true
   
   		A = B; //atribui o valor da string B em A
        C += B; //incrementa o valor da string B em C
      
        lcd.setCursor(6,1); //posiciona o cursor no lcd
    	lcd.print(C); //imprime uma mensagem no lcd
          
    	status = false; //atribui o valor de false para status
          
        if(C.length() == 4){ //se o tamanho da string C for igual a 4
       
       		if(C == senhacorr[indice]){ //se a string C for igual ao valor do vetor senhacorr no indice i
          
            	Serial.println("Senha correta"); //mostra uma mensagem no monitor serial
       			lcd.setCursor(0,0); //posiciona o cursor no lcd
       			lcd.clear(); //limpa a tela do lcd
       			lcd.print("SENHA CORRETA"); //imprime uma mensagem no lcd
            
            	servo1.write(180); //Grava um valor em graus no servo 
       			servo1.read(); //Le o ângulo atual do servo
       			delay(3000); //espera 3 segundos
       
       			servo1.write(90); //Grava um valor em graus no servo
       			servo1.read(); //Le o ângulo atual do servo
       			delay(3000); //espera 3 segundos
       
       			C = ""; //atribui o valor nulo na string C
              	indice = 0; //atribui o valor de zero na variavel indice
       			lcd.clear(); //limpa a tela do lcd
       			status = false; //atribui o valor de false para status
              	fatorM = false; //atribui o valor de false para fatorM
              	statusID = false; //atribui o valor de false para statusID
       
       			lcd.print("DIGITE O SEU ID:"); //imprime uma mensagem no lcd
       			lcd.setCursor(0,2); //posiciona o cursor no lcd
          
          	}else{ //se nao
     
       			Serial.println("Senha incorreta"); //mostra uma mensagem no monitor serial
       			lcd.setCursor(0,0); //posiciona o cursor no lcd
       			lcd.clear(); //limpa a tela do lcd
       			lcd.print("SENHA INCORRETA"); //imprime uma mensagem no lcd
       			delay(3000); //espera 3 segundos
       
       			C = ""; //atribui o valor nulo na string C
       			lcd.clear(); //limpa a tela do lcd
       			status = false; //atribui o valor de false para status
       
       			lcd.print("DIGITE A SENHA:"); //imprime uma mensagem no lcd
       			lcd.setCursor(0,2); //posiciona o cursor no lcd
            }
     	  }
        }
	  }
  
delay(1000); //espera 1 segundos
}

int pwmLer(byte canal){ //declaracao de funcao

    //declaracao de funcoes do tipo unsigned int e int
  	unsigned int AD;
  	int ADpwm;
    //------------------------------------------------
  
    AD = analogRead(canal); //leitura analogica da tensao do pino A0 e atribui para variavel LeituraDeVolts
  	ADpwm = AD / 4; //atribui o valor de volts para variavel Volts
	return ADpwm; //retorna o valor da variavel ADpwm
};
#include <LiquidCrystal.h> //declaracao da biblioteca

#define TEMPO 2000

int Temp[]={A0, A1, A2, A3, A4, A5}; //declaracao de vetores
int numSensores[6];
int restDiv[6];
int TempRe[6];

byte i; //declaracao de variavel tipo byte

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //configuracao dos pinos para lcd

void setup(){
  
  lcd.begin(16,2); //iniciando o lcd
	
  for(i=0;i<6;i++){ //estrutura de repeticao caso i for menor que 6
  
    pinMode(Temp[i], INPUT); //configurando os pinos que estao no array Temp nos indices i
    
  }
  
  Serial.begin(9600); //iniciando o monitor serial
  
}

void loop(){
	
  for(i=0;i<6;i++){ //estrutura de repeticao caso i for menor que 6
  
    TempRe[i]= map(analogRead(Temp[i]), 20, 358, -40, 125); //operacao logica para adquirir o valor da temperatura no sensor e atribuir no array TempRe no indice i
    numSensores[i] = i + 1; //incrementacao no array numSensores no indice i
  
  }
  
  for(i=0;i<6;i++){ //estrutura de repeticao caso i for menor que 6
  
    restDiv[i] = numSensores[i] % 2; //operacao de resto de divisao e atribuicao do valor do array restDiv no indice i
    
    if(restDiv[i] == 1){ //estrutura de condicao caso o valor do array restDiv no indice i for igual 1 executa o bloco do if
            
      lcd.setCursor(1,0); //posiciona o cursor no lcd
      lcd.print("Sensor "); //imprime uma mensagem no lcd
      lcd.print(numSensores[i]); //coloca o valor do array numSensores no indice i no lcd
      lcd.print(": "); //imprime uma mensagem no lcd
      lcd.print(TempRe[i]); //coloca o valor do array TempRe no indice i no lcd
      
      delay(TEMPO);
    
    }else{ //se o valor do array for diferente executa o bloco else
    
      lcd.setCursor(1,1); //posiciona o cursor no lcd
      lcd.print("Sensor "); //imprime uma mensagem no lcd
      lcd.print(numSensores[i]); //coloca o valor do array numSensores no indice i no lcd
      lcd.print(": "); //imprime uma mensagem no lcd
      lcd.print(TempRe[i]); //coloca o valor do array TempRe no indice i no lcd
           
      delay(TEMPO);
      
    }
    
    if(i == 1 || i == 3 || i == 5){ //estrutura de condicao caso o i for igual a 1 ou a 3 ou a 5
    
    	lcd.clear(); //limpa a tela do lcd
    
    }

  }
  
}
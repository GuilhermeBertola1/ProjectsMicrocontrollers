#include <Wire.h>
#include <Keypad.h>

byte pinos[] = {3, 4, 5, 6, 8, 9, 10, 11}; // Declaracao da array dos pinos do arduino

char Tecla; // Declaracao de uma variavel char

//Configuracao do keyPad-------------------
const byte linhas = 4;  
const byte colunas = 4;

char teclas[linhas][colunas] = 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte Pines_L[linhas] = {pinos[0],pinos[1],pinos[2],pinos[3]};
byte Pines_C[colunas] = {pinos[4],pinos[5],pinos[6],pinos[7]};

Keypad teclado = Keypad(makeKeymap(teclas), Pines_L, Pines_C, linhas, colunas); //mapeamento do teclado keypad e criação do objeto teclado
//-----------------------------------------

//declaracoes de variaveis
#define END_SLAVE 7 //Endereço I2C do Slave
char Z;
bool status = false;
String receber;
//------------------------

void setup(){
 
 Serial.begin(9600); //iniciando o monitor serial
 
 Wire.begin(END_SLAVE); //Inicializa I2C como Slave
 Wire.onRequest(Resposta); //Configura rotina de resposta ao Master
 Wire.onReceive(SlaveRecebe); //Configura rotina de leitura de dados enviados pelo Master

 Serial.println("Arduino Slave iniciado"); //aparece uma mensagem no monitor serial
 
}

void loop(){
  Tecla = teclado.waitForKey(); //inclementa a na variavel Tecla o valor da tecla pressionada atraves da funcao waitForKey
  
  if(Tecla == Z){ //se a variavel Tecla tiver um valor igual a variavel Z
  
    status = true; //atribui valor de true para variael status
  
  }else{ //se a variavel Tecla nao for igual a Z
  
    Serial.println("NAO"); //mostra uma mensagem no monitor serial
  
  }
  
  Z = Tecla; //atribui o valor da variavel Tecla em Z
  
  //delay(1000); //talvez seja uma ideia boa tirar esse delay
}

void SlaveRecebe(int bytes) //Ler dados enviados pelo Master
{
 if(Wire.available()) //Enquanto houver dados no buffer de entrada da I2C
  Serial.println("Master pediu dados"); //mostra uma mensagem no monitor serial
  receber = char(Wire.read()); //atribui o dado disponivel no I2C na varial receber
}

void Resposta(){ //Função de resposta ao Master
  
  if(receber == "1"){ //se o valor da variavel receber for igual a 1
  
    Wire.write(status); //responde ao Master com o valor da variavel status
    status = false; //atribui o valor de false na varialvel status
    receber = ""; //atribui o valor de nulo na variavel receber
      
  }
  
  if(receber == "2"){ //se o valor da variavel receber for igual a 2
   if(Tecla){ //se tiver valor na variavel Tecla
     Wire.write(Tecla); //responde ao Master com o valor da variavel Tecla
     Serial.println(Tecla); //mostra uma mensagem no monitor serial
     receber = ""; //atribui o valor de nulo na variavel receber
   }
  }
}

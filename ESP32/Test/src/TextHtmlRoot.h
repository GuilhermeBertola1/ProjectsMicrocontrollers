#include <String.h>
#include <TextScript.h>
#include <TextCss.h>

String messageHTML(){

    String textoHTML;
    textoHTML = "<html>";

    textoHTML += "<head>";
    textoHTML += "<meta charset='UTF-8'>";
    textoHTML += "<title>ESP8266</title>";
    textoHTML += CSS;
    textoHTML += "</head>";

    textoHTML += "<body>";
    textoHTML += "Web server ESP8266 <br>";
    textoHTML += "iniciado com sucesso <br>";

    textoHTML += "<div id='Quadro'></div>";
    textoHTML += "<div id='Quadro1'></div>";
    textoHTML += "<div id='Quadro2'></div>";
    textoHTML += "<div id='Quadro3'></div>";

    textoHTML += "<div id='BOTOES'>";
    textoHTML += "<button class='button' id='button1' >DESLIGAR SENSOR</button>";
    textoHTML += "<button class='button' id='button2' >LIGAR LED</button>";
    textoHTML += "</div>";

    textoHTML += "<button type='button'>Click Me!</button> <br>";
    textoHTML += JS;
    textoHTML += "</body>";

    textoHTML += "</html>";

    return textoHTML;
}
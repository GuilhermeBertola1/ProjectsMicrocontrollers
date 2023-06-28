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
    textoHTML += "<button type='button'>Click Me!</button> <br>";
    textoHTML += JS;
    textoHTML += "</body>";

    textoHTML += "</html>";

    return textoHTML;
}
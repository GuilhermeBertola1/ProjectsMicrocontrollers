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

    textoHTML += "<div>";

    textoHTML += "<input type='checkbox' class='checkbox' id='chk'/>";
    
    textoHTML += "<label class='label' for='chk'>";
    textoHTML += "<div class='ball'></div>";
    textoHTML += "</label>";

    textoHTML += "<input type='checkbox' class='checkbox1' id='chk1'/>";

    textoHTML += "<label class='label1' for='chk1'>";
    textoHTML += "<div class='ball1'></div>";
    textoHTML += "</label>";

    textoHTML += "<input type='checkbox' class='checkbox2' id='chk2'/>";

    textoHTML += "<label class='label2' for='chk2'>";
    textoHTML += "<div class='ball2'></div>";
    textoHTML += "</label>";

    textoHTML += "<input type='checkbox' class='checkbox3' id='chk3'/>";

    textoHTML += "<label class='label3' for='chk3'>";
    textoHTML += "<div class='ball3'></div>";
    textoHTML += "</label>";
    
    textoHTML += "</div>";

    textoHTML += JS;
    textoHTML += "</body>";

    textoHTML += "</html>";

    return textoHTML;
}
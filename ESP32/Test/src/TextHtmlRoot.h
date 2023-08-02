#include <String.h>
#include <TextScript.h>
#include <TextCss.h>
//#include <chart.h>

String messageHTML(uint8_t ph, uint8_t sm){

    String textoHTML;
    textoHTML = "<html>";

    textoHTML += "<head>";
    textoHTML += "<meta charset='UTF-8'>";
    textoHTML += "<title>ESP8266</title>";
    textoHTML += "<script>";
    
    textoHTML += "</script>";
    textoHTML += CSS;
    textoHTML += "</head>";

    textoHTML += "<body>";

    textoHTML += "<header>";
    textoHTML += "<div class='info-header'>";
    textoHTML += "<div class='logo'>";
    textoHTML += "<h3>Web Server ESP82266</h3>";
    textoHTML += "</div>";
    textoHTML += "</div>";
    textoHTML += "</header>";

    textoHTML += "<section class='sidebar'></section>";
    textoHTML += "<main class='main'></main>";

    textoHTML += "<div>";

    if(ph){
        textoHTML += "<input type='checkbox' class='checkbox' id='chk' checked='checked'/>";
    }else{
        textoHTML += "<input type='checkbox' class='checkbox' id='chk'/>";
    }
    
    textoHTML += "<label class='label' for='chk'>";
    textoHTML += "<div class='ball'></div>";
    textoHTML += "</label>";

    textoHTML += "<div class='logoPH'>";
    textoHTML += "<h3>Botao Ponte H</h3>";
    textoHTML += "</div>";

    if(sm){
        textoHTML += "<input type='checkbox' class='checkbox1' id='chk1' checked='checked'/>";
    }else{
        textoHTML += "<input type='checkbox' class='checkbox1' id='chk1'/>";
    }

    textoHTML += "<label class='label1' for='chk1'>";
    textoHTML += "<div class='ball1'></div>";
    textoHTML += "</label>";

    textoHTML += "<div class='logoSM'>";
    textoHTML += "<h3>Botao SM</h3>";
    textoHTML += "</div>";

    textoHTML += "<input type='checkbox' class='checkbox2' id='chk2'/>";

    textoHTML += "<label class='label2' for='chk2'>";
    textoHTML += "<div class='ball2'></div>";
    textoHTML += "</label>";

    textoHTML += "<input type='checkbox' class='checkbox3' id='chk3'/>";

    textoHTML += "<label class='label3' for='chk3'>";
    textoHTML += "<div class='ball3'></div>";
    textoHTML += "</label>";
    
    textoHTML += "</div>";

    textoHTML += "<canvas id='canvasGrafico' class='canvasGrafico'></canvas>";
    textoHTML += "<ul id='monitoramento' class='tabelademonitoramento'></ul>";

    textoHTML += "<div>";
    textoHTML += "<h2 id='tempo' class='tempo'></h2>";
    textoHTML += "</div>";

    textoHTML += scriptJS(sm);
    textoHTML += "</body>";

    textoHTML += "</html>";

    return textoHTML;
}
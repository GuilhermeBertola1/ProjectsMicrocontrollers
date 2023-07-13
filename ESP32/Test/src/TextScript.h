#include <String.h>

String scriptJS(uint8_t ph){

    String script;

    script = "<script>";
    script += "const chk = document.getElementById('chk');";
    script += "const chk1 = document.getElementById('chk1');";
    script += "const chk2 = document.getElementById('chk2');";
    script += "const chk3 = document.getElementById('chk3');";
    script += "chk.addEventListener('change', () => {if(chk.checked){ window.location = 'http://192.168.4.1/PhON'; }else{ window.location = 'http://192.168.4.1/PhOFF'; } });";
    script += "chk1.addEventListener('change', () => {if(chk1.checked){ window.location = 'http://192.168.4.1/SensorON' }else{ window.location = 'http://192.168.4.1/SensorOFF'; } });";
    script += "chk2.addEventListener('change', () => {if(chk2.checked){ console.log(true); }else{ console.log(false);} });";
    script += "chk3.addEventListener('change', () => {if(chk3.checked){ console.log(true); }else{ console.log(false);} });";
    script += "window.onload = function(){var canvas = document.getElementById('canvasGrafico'); let arrayList = []; let tempo = 0; if (canvas) {var altura = 230; var largura = 1000; var x = 0; var valor; canvas.setAttribute('width', largura); canvas.setAttribute('height', altura); var ctx = canvas.getContext('2d'); ctx.fillStyle = 'white'; ctx.fillRect(0, 0, largura, altura); ctx.font = '30px Courier';} function desenharGrafico(){if(x === 995){x = 0; ctx.beginPath(); ctx.clearRect(0, 0, largura, altura); ctx.fillStyle = 'white'; ctx.fillRect(0, 0, largura, altura); ctx.closePath();} x+=5; valor = parseInt(Math.random() * 200); ctx.lineTo(x, altura-valor); ctx.stroke(); ctx.fillStyle = 'white'; ctx.fillRect(0, 0, largura, 30); ctx.fillStyle = 'red'; if(x <= 930){ ctx.fillText(valor, x, 30); }else{ ctx.fillText(valor, 930, 30); } arrayList.push(valor); document.getElementById('monitoramento').innerHTML = arrayList.map(y => `<li>${y} - Tempo(s): ${tempo}</li>`).join("");} setInterval(desenharGrafico, 1000); }";
    script += "</script>";

    return script;
}

/*const char JS[] = R"===(
    <script>
        const chk = document.getElementById('chk');
        const chk1 = document.getElementById('chk1');
        const chk2 = document.getElementById('chk2');
        const chk3 = document.getElementById('chk3');

        chk.addEventListener('change', () => {
            if(chk.checked){
                console.log(true);
            }else{
                console.log(false);
            }
        });

        chk1.addEventListener('change', () => {
            if(chk1.checked){
                console.log(true);
            }else{
                console.log(false);
            }
        });

        chk2.addEventListener('change', () => {
            if(chk2.checked){
                console.log(true);
            }else{
                console.log(false);
            }
        });

        chk3.addEventListener('change', () => {
            if(chk3.checked){
                console.log(true);
            }else{
                console.log(false);
            }
        });

    </script>
)===";*/
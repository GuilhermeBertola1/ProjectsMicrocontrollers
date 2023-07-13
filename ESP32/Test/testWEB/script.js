const chk = document.getElementById('chk');
const chk1 = document.getElementById('chk1');
const chk2 = document.getElementById('chk2');
const chk3 = document.getElementById('chk3');

chk.addEventListener('change', () => {
    if(chk.checked){
        console.log(true);
        window.location='file:///c%3A/Users/guilh/OneDrive/Documents/GitHub/ProjectsMicrocontrollers/ESP32/Test/testWEB/index.html/PH';
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

window.onload = function(){
	var canvas = document.getElementById("canvasGrafico");
    let arrayList = [];
    let tempo = 0;
	if (canvas) {
		//altura da canvas
        var altura = 230;
        //largura da canvas
        var largura = 1000;
        //posição horizontal inicial do gráfico
        var x = 0;
        //valor dos pontos do gráfico, que será alterado aleatoriamente
        var valor;

        //formatando a canvas
        canvas.setAttribute("width", largura);
        canvas.setAttribute("height", altura);

        //obtendo o contexto 2d
        var ctx = canvas.getContext("2d");

        ctx.fillStyle = "white";
        ctx.fillRect(0, 0, largura, altura);
        ctx.font = "30px Courier";
	}

    function desenharGrafico() {
        if(x === 995){
            x = 0;

            ctx.beginPath();
            ctx.clearRect(0, 0, largura, altura);
            ctx.fillStyle = "white";
            ctx.fillRect(0, 0, largura, altura);
            ctx.closePath();
        }

        //define o avanço horizontal
        x+=5;
        //gera um valor aleatório entre 0 e 100
        valor = parseInt(Math.random() * 200);
        //desenha uma linha até a posição gerada
        ctx.lineTo(x, altura-valor);
        ctx.stroke();
        //desenha um retangulo onde está sendo escrito o valor do gráfico
        ctx.fillStyle = "white";
        ctx.fillRect(0, 0, largura, 30);
        //desenha o texto indicando o valor do gráfico, na posição x atual
        ctx.fillStyle = "red";
        if(x <= 930){
            ctx.fillText(valor, x, 30);
        }else{
            ctx.fillText(valor, 930, 30);
        }
        arrayList.push(valor);
        document.getElementById('monitoramento').innerHTML = arrayList.map(y => `<li>${y} - Tempo(s): ${tempo}</li>`).join("");
    }
    
    setInterval(desenharGrafico, 1000);
};


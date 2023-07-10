#include <String.h>

String scriptJS(){

    String script;

    script = "<script>";
    script += "const chk = document.getElementById('chk');";
    script += "const chk1 = document.getElementById('chk1');";
    script += "const chk2 = document.getElementById('chk2');";
    script += "const chk3 = document.getElementById('chk3');";
    script += "chk.addEventListener('change', () => {if(chk.checked){ window.location = 'http://192.168.4.1/PhON'; }else{ window.location = 'http://192.168.4.1/PhOFF'; } });";
    script += "chk1.addEventListener('change', () => {if(chk1.checked){ console.log(true); }else{ console.log(false);} });";
    script += "chk2.addEventListener('change', () => {if(chk2.checked){ console.log(true); }else{ console.log(false);} });";
    script += "chk3.addEventListener('change', () => {if(chk3.checked){ console.log(true); }else{ console.log(false);} });";
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
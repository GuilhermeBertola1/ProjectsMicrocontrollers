#include <pontH.h>
#include <sensorModule.h>

const char JS[] = R"===(
    <script>
        const button1 = document.getElementById('button1');
        const button2 = document.getElementById('button2');

        function botaoJS(){
            console.log("DESLIGOU");
        }

        function botaoJS2(){
            console.log("LIGOU");
        }

        button1.addEventListener('click', botaoJS);
        button2.addEventListener('click', botaoJS2);

    </script>
)===";
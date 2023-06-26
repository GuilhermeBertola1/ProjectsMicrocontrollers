#include <pontH.h>
#include <sensorModule.h>

const char JS[] = R"===(
    <script>
        const button = document.querySelector('button');

        function botaoJS(){
            console.log("LIGOU");
        }

        button.addEventListener('click', botaoJS);

    </script>
)===";
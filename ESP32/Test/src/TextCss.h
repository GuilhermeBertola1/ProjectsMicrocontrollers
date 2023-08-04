const char CSS[] = R"===(
    <style>
    * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
        font-family: Verdana, Geneva, Tahoma, sans-serif;
    }

    body {
        background-color: aliceblue;
        grid-template-columns: 300px 1fr;
        grid-template-rows: 60px 1fr;

        height: 100vh;
        margin: 0;
    }

    header {
        background-color: aqua;
        padding: 20px 2%;
        display: flex;
        position: absolute;
        width: 100%;
        height: 10%;
    }

    .information {
        max-width: 1100px;
        padding: 0 2%;
        display: flex;
        margin: 0 auto;
    }

    .checkbox {
        opacity: 0;
        position: absolute;
    }

    .checkbox1 {
        opacity: 0;
        position: absolute;
    }

    .checkbox2 {
        opacity: 0;
        position: absolute;
    }

    .checkbox3 {
        opacity: 0;
        position: absolute;
        top: 10%;
    }

    .logo {
        display: inline-block;
        position: absolute;
        left: 2.5%;
        top: 30%;
    }

    .label {
        background-color: black;
        border-radius: 50px;
        cursor: pointer;

        display: inline-block;
        left: 17%;
        top: 13%;
        justify-content: space-around;

        padding: 5px;
        position: absolute;
        height: 26px;
        width: 50px;
    }

    .logoPH {
        color: black;
        position: absolute;
        display: inline-block;
        left: 4%;
        top: 13%;
    }

    .label1 {
        background-color: black;
        border-radius: 50px;
        cursor: pointer;

        display: inline-block;
        left: 17%;
        top: 18%;
        justify-content: space-around;

        padding: 5px;
        position: absolute;
        height: 26px;
        width: 50px;
    }

    .logoSM {
        color: black;
        position: absolute;
        display: inline-block;
        left: 4%;
        top: 18%;
    }

    .label2 {
        background-color: black;
        border-radius: 50px;
        cursor: pointer;

        display: inline-block;
        left: 17%;
        top: 23%;
        justify-content: space-between;

        padding: 5px;
        position: absolute;
        height: 26px;
        width: 50px;
    }

    .label3 {
        background-color: black;
        border-radius: 50px;
        cursor: pointer;

        display: inline-block;
        left: 17%;
        top: 28%;
        justify-content: space-between;

        padding: 5px;
        position: absolute;
        height: 26px;
        width: 50px;
    }

    .label .ball {
        background-color: red;
        border-radius: 50%;
        position: absolute;
        top: 2px;
        left: 2px;

        height: 22px;
        width: 22px;

        transform: translateX(0px);
        transition: transform 0.2s linear;
    }

    .label1 .ball1 {
        background-color: red;
        border-radius: 50%;
        position: absolute;
        top: 2px;
        left: 2px;

        height: 22px;
        width: 22px;

        transform: translateX(0px);
        transition: transform 0.2s linear;
    }

    .label2 .ball2 {
        background-color: red;
        border-radius: 50%;
        position: absolute;
        top: 2px;
        left: 2px;

        height: 22px;
        width: 22px;

        transform: translateX(0px);
        transition: transform 0.2s linear;
    }

    .label3 .ball3 {
        background-color: red;
        border-radius: 50%;
        position: absolute;
        top: 2px;
        left: 2px;

        height: 22px;
        width: 22px;

        transform: translateX(0px);
        transition: transform 0.2s linear;
    }

    .checkbox:checked + .label .ball {
        background-color: green;
        transform: translateX(24px);
    }

    .checkbox1:checked + .label1 .ball1 {
        background-color: green;
        transform: translateX(24px);
    }

    .checkbox2:checked + .label2 .ball2 {
        background-color: green;
        transform: translateX(24px);
    }

    .checkbox3:checked + .label3 .ball3 {
        background-color: green;
        transform: translateX(24px);
    }

    .canvasGrafico {
        display: inline-block;
        position: absolute;
        top: 68%;
        left: 0%;
        width: 70%;
        padding: 8px 10px;
    }

    .tabelademonitoramento {
        position: absolute;
        left: 70%;
        top: 49.6%;
        justify-content: center;
        display: inline-block;
        background-color: gray;
        width: 30%;
        height: 50%;
        overflow-y: scroll;
        word-break: break-all;
        padding: 8px 10px;
    }
    </style>
)===";
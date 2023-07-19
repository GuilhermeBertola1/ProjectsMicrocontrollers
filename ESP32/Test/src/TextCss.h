const char CSS[] = R"===(
    <style>
        *{
            margin: 0;
            padding: 0;
            border: 0;
            box-sizing: border-box;
            font-family: Verdana, Geneva, Tahoma, sans-serif;
        }

        body{
            background-color: aliceblue;
            grid-template-columns: 300px 1fr;
            grid-template-rows: 60px 1fr;

            height: 100vh;
            margin: 0;
        }

        header{
            background-color: aqua;
            padding:20px 2%;
            display: flex;
            justify-content: space-between;
        }

        .info-header{
            color: black;
            display: flex;
            justify-content: space-around;
            width: 240px;
        }

        .sidebar{
            background-color: black;

        }

        .main{
            background-color: aliceblue;

        }

        .checkbox{
            opacity: 0;
            position: absolute;
        }

        .checkbox1{
            opacity: 0;
            position: absolute;
        }

        .checkbox2{
            opacity: 0;
            position: absolute;
        }

        .checkbox3{
            opacity: 0;
            position: absolute;
            top: 10%;
        }

        .label{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 200px;
            top: 13%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .logoPH{
            color: black;
            display: flex;
            position: absolute;
            left: 33px;
            top: 13%;
        }

        .label1{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 200px;
            top: 18%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .logoSM{
            color: black;
            display: flex;
            position: absolute;
            left: 33px;
            top: 18%;
        }

        .label2{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 200px;
            top: 23%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .label3{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 200px;
            top: 28%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .label .ball{
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

        .label1 .ball1{
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

        .label2 .ball2{
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

        .label3 .ball3{
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

        .canvasGrafico{
            display: flex;
            position: absolute;
            top: 69.4%;
        }

        .tabelademonitoramento{
            position: absolute;
            background-color: gray;
            width: 400px;
            height: 400px;
            overflow-y: scroll;
            word-break: break-all;

            top: 47.4%;
            left: 67%;   
        }

        .tempo{
            position: absolute;
            left: 90%;
            top: 20%;
        }
    </style>
)===";
const char CSS[] = R"===(
    <style>
        *{
            margin: 0;
            padding: 0;
            border: 0;
            box-sizing: border-box;
        }

        body{
            background-color: aliceblue;
            display: flex;
            align-items: center;
            justify-content: center;

            height: 100vh;
            margin: 0;
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
            left: 1%;
            top: 2%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .label1{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 1%;
            top: 52%;
            justify-content: space-between;

            padding: 5px;
            position: absolute;
            height: 26px;
            width: 50px;
        }

        .label2{
            background-color: black;
            border-radius: 50px;
            cursor: pointer;

            display: flex;
            left: 51%;
            top: 2%;
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
            left: 51%;
            top: 52%;
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

        #Quadro{
            display: flex;
            position: absolute;
            border:solid 1px;
            height: 50%;
            width: 50%;
            top: 0%;
            left: 0%;
        }

        #Quadro1{
            display: flex;
            position: absolute;
            border:solid 1px;
            height: 50%;
            width: 50%;
            top: 0%;
            right: 0%;
        }

        #Quadro2{
            display: flex;
            position: absolute;
            border:solid 1px;
            height: 50%;
            width: 50%;
            top: 50%;
            left: 0%;
        }

        #Quadro3{
            display: flex;
            position: absolute;
            border:solid 1px;
            height: 50%;
            width: 50%;
            top: 50%;
            left: 50%;
        }
    </style>
)===";
const char CSS[] = R"===(
    <style>
        *{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body{
            background-color: rgb(160, 51, 160);
            display: flex;
        }

        #BOTOES{
            display: flex;
        }

        .button{
            padding: 5px 10px 5px 10px;
            border-radius: 10px;
        }

        #button1.button{
            background-color: rgb(26, 172, 123);
            position: absolute;
            top: 10%;
            left: 80%;

        }

        #button2.button{
            background-color: rgb(133, 31, 131);
            position: absolute;
            top: 10%;
            left: 10%;
        }

        #Quadro{
            display: flex;
            position: absolute;
            background-color: rgb(74, 183, 34);
            width: 50%;
            height: 50%;
            margin: 0;
        }

        #Quadro1{
            display: flex;
            position: absolute;
            background-color: rgb(183, 34, 54);
            width: 50%;
            height: 50%;
            left: 50%;
        }

        #Quadro2{
            display: flex;
            position: absolute;
            background-color: rgb(86, 34, 183);
            width: 50%;
            height: 50%;
            top: 50%;
        }

        #Quadro3{
            display: flex;
            position: absolute;
            background-color: rgb(151, 183, 34);
            width: 50%;
            height: 50%;
            top: 50%;
            left: 50%;
        }
    </style>
)===";
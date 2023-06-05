import  express  from "express";
import bodyParser from "body-parser";
import cors from "cors";

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(cors());

const test = {

    'name': 'Motor',
    'rotation': 12,
    'type': 'motor',
    'value': 2

}

app.get('/', (req, res) => res.json(test));

app.listen(3000, () => {
    console.log("Servidor rodando: http://127.0.0.1:3000/");
});
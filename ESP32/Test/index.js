import  express  from "express";
import db from "./Sscr/dbConnect.js"

const app = express();

db.on("error", console.log.bind(console, 'Erro de conexao'));
db.once("open", () => {
  console.log("Conexao com o banco feita com sucesso");
});

app.get('/', function(req, res){
  res.send("Hello word");
});

app.get('/projeto', function(req, res){
  res.send("PROJETO COM ESP8266");
});

app.listen(3000, function(){
  console.log("Servidor rodando: http://localhost:3000");
});
//localhost:3000
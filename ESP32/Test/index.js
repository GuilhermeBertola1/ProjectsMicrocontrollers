import  express  from "express";
import db from "./Sscr/dbConnect.js"
import routes from "./Sscr/routers/prin.js";

const app = express();

db.on("error", console.log.bind(console, 'Erro de conexao'));
db.once("open", () => {
  console.log("Conexao com o banco feita com sucesso");
});

app.use(express.json());
routes(app);

export default app;

app.listen(3000, function(){
  console.log("Servidor rodando: http://localhost:3000");
});
//localhost:3000
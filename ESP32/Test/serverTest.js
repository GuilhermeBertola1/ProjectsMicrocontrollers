import  express  from "express";
const app = express();

app.get("/", function(req, res){
    res.send("OPA");
});

app.listen(8080, function(){
    console.log("Servidor rodando: http://localhost:8080");
});
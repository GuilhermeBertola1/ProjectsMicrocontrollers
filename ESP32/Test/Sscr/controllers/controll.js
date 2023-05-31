import DataInform from "../models/modelData.js";

class DataController{

    static procurarVarial = (req, res) => {
        DataInform.find((err, data) => {
            res.status(200).json(data);
        });
    }

    static addVariavel = (req, res) => {
        let variavel = new DataInform(req.body);
        variavel.save((err) => {
            if(err){
                res.status(500).send({message: `${err.message} - falha no enviou do cadastro`})
            }else{
                res.status(201).send(variavel.toJSON());
            }
        });
    }

    static attVariavel = (req, res) => {
        const id = req.params.nome;
        DataInform.findByIdAndUpdate(nome, {$set: req.body}, (err) => {
            if(!err){
                res.status(200).send({message: "Valor atualizado com sucesso"});
            }else{
                res.status(500).send({message: err.message});
            }
        });
    }

    static excluirVariavel = (req, res) => {
        const id = req.params.nome;
        DataInform.findByIdAndDelete(nome, (err) => {
            if(!err){
                res.status(200).send({message: "Valor removido com sucesso!"});
            }else{
                res.status(500).send({message: err.message});
            }
        });
    }
};

export default DataController;
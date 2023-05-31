import express, { Router } from "express";
import DataController from "../controllers/controll.js";

const router = express.Router();

router
    .get("/Motor", DataController.procurarVarial)
    .post("/Motor", DataController.addVariavel)
    .put("/Motor", DataController.attVariavel)
    .delete("/Motor", DataController.excluirVariavel)

export default router;
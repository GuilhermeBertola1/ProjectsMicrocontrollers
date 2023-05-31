import express from "express";
import dataVariavel from "./routers.js"

const routes = (app) => {
    app.route('/').get((req, res) => {
        res.status(200).send('boaa')
    });

    /*app.use(
        express.json(),
        dataVariavel
    )*/
}

export default routes;
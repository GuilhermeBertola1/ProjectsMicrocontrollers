import mongoose from "mongoose";

const informationSchema = new mongoose.Schema(
    {
        nome: {type: String, require: true},
        valor: {type: String, require: true}
    },
    {
        versionKey: false
    }
);

const DataInform = mongoose.model("Data", informationSchema);
export default DataInform;
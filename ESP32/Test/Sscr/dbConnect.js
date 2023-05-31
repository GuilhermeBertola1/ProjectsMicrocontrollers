import mongoose from "mongoose";

mongoose.connect("mongodb+srv://AGENTE007:guiciber123@clusther100.a7wirmx.mongodb.net/");

const db = mongoose.connection;
export default db;
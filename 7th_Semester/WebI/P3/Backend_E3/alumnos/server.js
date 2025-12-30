// server.js

import express from "express";

// Permisos para acceder al sistema
import cors from "cors";

// Importar conexión propia
import connection from "./db.js"

// Guaradr instancia de express
const app = express();
app.use(cors());
app.use(express.json());

// Crear alumno  (POST)

app.post("/api/alumnos", (req, res) => {

    
    const {nombre, edad, curso} = req.body;
    const sql = `INSERT INTO alumnos(nombre, edad, curso) VALUES(?,?,?)`;

    connection.query(sql, [nombre, edad, curso],
    (err, result) => {
        if(err)
            return res.status(500).json({error:err});
        res.json({mensaje: "Alumno agregado correctamente", id: result.instantId });
    });
    
});



// Listar Alumnos (GET)
app.get("/api/alumnos", (req, res) => {
    connection.query("SELECT * FROM alumnos", (err, results) => {
        if(err)
            return res.status(500).json({error:err});
        res.json(results);
    });
});



// Configurar front
app.use(express.static("public"));


// Puerto de servidor
const PORT = 3000;
app.listen(PORT, () => console.log('Servidor corriendo en http://localhost:${POST}'));

<?php

class BaseDeDatos
{
    private $con;
    public function __construct()
    {
        try {
            $this->con = new PDO('mysql:host=localhost;dbname=bd_musica', 'root', '');
            $this->con->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            die("Error de conexión: " . $e->getMessage());
        }
    }

    public function ingreso($usr, $pass)
    {
        $sql = $this->con->prepare("SELECT * FROM usuario WHERE BINARY `Email` = ? AND BINARY `Contraseña` = ?");
        $sql->execute([$usr, $pass]);
        $res = $sql->fetchAll();

        if (count($res) > 0) {
            return $res[0]['id_usuario'];
        }
        return -1;
    }
}
<?php
include "based.php";

error_reporting(E_ALL);
ini_set('display_errors', 1);

require_once "based.php";

if (isset($_GET['usr']) && isset($_GET['pass'])) {
    $usr = $_GET['usr'];
    $pass = $_GET['pass'];

    $bd = new BaseDeDatos();  // <- Aquí debe crearse sin error
    $res = $bd->ingreso($usr, $pass);

    echo json_encode(['usr' => $res]);
} else {
    echo json_encode(['usr' => -1]);
}

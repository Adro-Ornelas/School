<?php
    // conexion.php

    // Data
    $servidor = "localhost";    // IP del servidor en base de datos
    $usuario = "root";          // Usuario MySQL
    $pwd = "";                  // contraseña
    $baseDatos = "tienda";      // Nombre BD

    $conexion = new mysqli($servidor, $usuario, $pwd, $baseDatos);

    // Crear conexión
    if($conexion->connect_error) {

        // Mata proceso
        die("Error en la conexión".$conexion->connect_error);
    }

    echo "Conexión exitorsa<br>";
    // Consulta simple
    $sql = "SELECT id, nombre, precio FROM productos";
    $resultado = $conexion->query($sql);

    // Verifica resultados
    if($resultado->num_rows > 0) {

        // Mostrar datos 
        while($fila = $resultado->fetch_assoc()) {
            echo "ID: ".$fila["id"]." - Nombre: ".$fila["nombre"]." - Precio: $ ".$fila["precio"]."<br>";
        
        }
    } else {
        echo "No hay productos";
    }

    // Cerrar conexión


?>
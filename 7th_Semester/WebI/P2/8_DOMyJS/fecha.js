// fecha.js

/*
    Cargar escuchador o voyerista (listener) cuando el documento
    esté cargado
*/
document.addEventListener("DOMContentLoaded", ()=> {

    const btnFecha = document.getElementById("btnFecha");
    const paraph = document.getElementById("resultado");

    btnFecha.addEventListener("click", ()=> {

        const fecha = new Date();
        paraph.textContent = "Fecha: " + fecha;

    });


});
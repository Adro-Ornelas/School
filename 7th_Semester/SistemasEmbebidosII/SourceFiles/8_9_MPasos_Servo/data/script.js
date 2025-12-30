// script.js
let gateway = `ws://${window.location.hostname}/ws`;
let websocket;
window.addEventListener('load', onload);
let direction;
let sizeAng = 0;    // Guarda número de ángulos
let angles = new Array(100);

function onload(event) {
    initWebSocket();
}

function initWebSocket() {
    console.log('Trying to open a WebSocket connection…');
    websocket = new WebSocket(gateway);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    console.log('Connection opened');
}

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function move(dirc) {

    // Obtiene radio button seleccionado
    const selectedRadio = document.querySelector('input[name="velocidad"]:checked');
    const velocidad = selectedRadio.value;

    // Velocidad es 1 para baja y 2 para alta
    // dirc es UP o DW (CCW o CW)
    // Envía MOVE:dirc&velocidad
    // console.log(dirc+"&"+velocidad);

    // Mueve engranaje (ícono) según motor a pasos
    const motorPasosP = document.getElementById("motor-state");
    motorPasosP.style.color = "blue";
    
    if (dirc=="DW"){
        document.getElementById("gear").classList.add("spin");
        motorPasosP.innerHTML = "bajando... (cw)";
    }
    else{
        document.getElementById("gear").classList.add("spin-back");
        motorPasosP.innerHTML ="subiendo... (ccw)";
    }

    websocket.send("MOVE:"+dirc+"&"+velocidad);

}

function submitForm(){
    const rbs = document.querySelectorAll('input[name="direction"]');
    direction;
    for (const rb of rbs) {
        if (rb.checked) {
            direction = rb.value;
            break;
        }
    }

    document.getElementById("motor-state").innerHTML = "motor spinning...";
    document.getElementById("motor-state").style.color = "blue";
    if (direction=="CW"){
        document.getElementById("gear").classList.add("spin");
    }
    else{
        document.getElementById("gear").classList.add("spin-back");
    }
    
    websocket.send("MOVE:"+direction);
}

function onMessage(event) {
    console.log(event.data);
    direction = event.data;
    if (direction=="stop"){ 
      document.getElementById("motor-state").innerHTML = "motor detenido"
      document.getElementById("motor-state").style.color = "red";
      document.getElementById("gear").classList.remove("spin", "spin-back");
    }
    else if(direction=="CW" || direction=="CCW"){
        document.getElementById("motor-state").innerHTML = "motor spinning...";
        document.getElementById("motor-state").style.color = "blue";
        if (direction=="CW"){
            document.getElementById("gear").classList.add("spin");
        }
        else{
            document.getElementById("gear").classList.add("spin-back");
        }
    }
}




let slider = document.getElementById("myRange");
let output = document.getElementById("demo");
output.innerHTML = slider.value; // Display the default slider value

// Update the current slider value (each time you drag the slider handle)
slider.oninput = function() {
  // Pone en texto el número de grados
  let grad = this.value;
  output.innerHTML = grad;

//   Envía grados a ESP32
  websocket.send("ROT:"+grad);

} 

function mostrarInputAng() {

    // Obtiene cantidad de angulos
    const inputnAng = document.getElementById("NAng");
    sizeAng = inputnAng.value;

    // No se permiten más de 100 ángulos 
    if(sizeAng > 100 || sizeAng < 1){
        inputnAng.value = '';
        inputnAng.placeholder = 'No más de 100 ángulos';
        return;
    }
    // Obtener el contenedor donde se añadirán los inputs
    const contenedor = document.getElementById('contenedorDeInputs');
    
    // Limpiar el contenedor antes de añadir nuevos inputs (para evitar acumulación)
    contenedor.innerHTML = '';

        // 3. Iterar "n" veces para crear y añadir los inputs
    for (let i = 0; i < sizeAng; i++) {
        // Crear un nuevo elemento input
        const nuevoInput = document.createElement('input');
        
        // Establecer atributos para el input (tipo, nombre, placeholder, etc.)
        nuevoInput.type = 'text';
        nuevoInput.name = 'input_' + i;
        nuevoInput.placeholder = 'Ángulo número ' + (i + 1);
        nuevoInput.classList = "txt-1";
        nuevoInput.type = "number";

        // Añadir el input al contenedor
        contenedor.appendChild(nuevoInput);
        
    }

    // Muestra botón de mandar ángulos
    document.getElementById('btn_sendAngles').style.display = 'block';

}

function sendAngles() {


    // Obtener el contenedor donde se añadirán los inputs
    const contenedor = document.getElementById('contenedorDeInputs');

    // Selecciona todos los inputs
    const inputs = contenedor.querySelectorAll('input');

    // Indice de arreglo de valores
    sizeAng = 0;

    // Itera todos los input y guarda en el arrelgo los valores
    inputs.forEach((input) => {

        // La propiedad 'value' contiene el texto actual del input
        let valorActual = input.value;

        angles[sizeAng++] = valorActual  || 0;  // SI es vacío pone cero

        // Valor absoluto
        angles[sizeAng-1] = Math.abs(angles[sizeAng-1]);
        // valores.push(valorActual);
    });


    // El primer dígito es el número de ángulos
    // Formato: ANG:3&90&180&100
    let response = 'ANG:'+sizeAng;
    // Imprime en consola el arreglo
    for(let i = 0; i < sizeAng; ++i) {
        response +='&'+angles[i];
    }
    
    // console.log(response);
    websocket.send(response);


}

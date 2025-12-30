// main.js

document.addEventListener('DOMContentLoaded', ()=> {

  // Obtiene la ventana modal
  let modal = document.getElementById('myModal');

  // Botones que abren los modales
  let phoneButton = document.getElementById('phoneButton');
  let emailButton = document.getElementById('emailButton');

  // Ontener el  <span> que cierra la ventana
  let span = document.getElementsByClassName('close')[0];


  //---------FUNCIONES PARA VENTANA FLOTANTE EN PRINICPAL----------------
  phoneButton.addEventListener('click', () => {
    appearModalP('Número de teléfono: 33-3-48-79-175')
  });
  emailButton.addEventListener('click', () => {
    appearModalP('Dirección de correo electrónico: a22300918@ceti.mx')
  });
  
  function appearModalP(message) {
    modal.style.display='block';
    document.getElementById('modal_paragraph1').textContent = message;
  }

  // Cuando el usuario presiona el <span> (x), cierra el modal
  span.onclick = function() {
    modal.style.display = 'none';
  }

  // Cuando el usuario hace clic fuera del modal, se cierra
  window.onclick = function(event) {
    if (event.target == modal) {
      modal.style.display = 'none';
    }
  }


  //----------------CARRUSEL DE IMÁGENES---------------------

  // Obtiene todas las imágenes dentro del carrusel en forma de arreglo
  const imagenes = document.querySelectorAll('.img-carrusel');
  // El índice comienza en cero
  let indice = 0;

  function actualizarCarrusel() {

    // Remueve todo los estados actuales

    imagenes.forEach(img => {
      img.classList.remove('img-activa', 'img-anterior', 'img-siguiente');
      img.style.zIndex = 1;
    });

    // Actualiza índices y normaliza para que no se salga el índice del rango
    const total = imagenes.length;
    const anterior = (indice - 1 + total) % total;
    const siguiente = (indice + 1) % total;
    
    // Muestra nuevas imágenes
    imagenes[indice].classList.add('img-activa');
    imagenes[anterior].classList.add('img-anterior');
    imagenes[siguiente].classList.add('img-siguiente');
  }

  // Si se presiona siguiente, aumenta el índice y actualiza
  document.getElementById('siguiente').addEventListener('click', () => {
    indice = (indice + 1) % imagenes.length;
    actualizarCarrusel();
  });

  // Si se presiona anterior, decrementa el índice y actualiza
  document.getElementById('anterior').addEventListener('click', () => {
    indice = (indice - 1 + imagenes.length) % imagenes.length;
    actualizarCarrusel();
  });


  // Carga carrusel por primera vez, con indice=0
  actualizarCarrusel();

});
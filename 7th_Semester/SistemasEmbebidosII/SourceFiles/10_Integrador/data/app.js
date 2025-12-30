/* app.js
   Conexión WebSocket y lógica UI para controlar el vivero via ESP32.
   Mensajes enviados (ejemplos):
     LIGHT:TOGGLE
     WATER:TRIGGER
     FAN:TOGGLE
     TEMP:REQ

   Mensajes recibidos esperados (ejemplos):
     LIGHT:ON
     LIGHT:OFF
     WATER:ON
     WATER:OFF
     FAN:ON
     FAN:OFF
     TEMP:25.4
     HUM:55
     LUX:300
     STATE:LIGHT=ON;FAN=OFF;WATER=OFF;TEMP=25.4;HUM=55;LUX=300
*/

(() => {
  // Elementos UI
  const btnLight = document.getElementById('btn-light');
  const btnWater = document.getElementById('btn-water');
  const btnFan = document.getElementById('btn-fan');
  const thermo = document.getElementById('thermo');

  const tempValue = document.getElementById('temp-value');
  const humValue = document.getElementById('hum-value');
  const luxValue = document.getElementById('lux-value');

  const statusEl = document.getElementById('status');
  const logEl = document.getElementById('log');

  // Estado local opcional
  let state = {
    light: false,
    fan: false,
    watering: false,
    temp: null,
    hum: null,
    lux: null
  };

  // Construir URL ws/wss según la página
  function makeWsUrl(path = '/ws') {
    const proto = (location.protocol === 'https:') ? 'wss:' : 'ws:';
    return proto + '//' + location.host + path;
  }

  // Crear WebSocket
  const WS_URL = makeWsUrl(); // por defecto /ws
  log(`Intentando conectar ${WS_URL}`);
  const ws = new WebSocket(WS_URL);

  ws.onopen = () => {
    log('WebSocket abierto');
    setStatus('Conectado', true);
    // pedir estado inicial
    ws.send('STATE:REQ');
  };

  ws.onclose = (ev) => {
    log('WebSocket cerrado');
    setStatus('Desconectado', false);
  };

  ws.onerror = (err) => {
    console.error(err);
    log('Error WebSocket: ' + (err && err.message ? err.message : 'unknown'));
    setStatus('Error', false);
  };

  ws.onmessage = (event) => {
    log('← ' + event.data);
    handleIncoming(String(event.data).trim());
  };

  // envía y registra
  function send(msg) {
    if (ws.readyState === WebSocket.OPEN) {
      ws.send(msg);
      log('→ ' + msg);
    } else {
      log('No conectado. No se envió: ' + msg);
    }
  }

  // UI: listeners
  btnLight.addEventListener('click', () => {
    send('LIGHT:TOGGLE');
    // optimista: cambiar visual (se corregirá si ESP responde)
    toggleLightUI();
  });

  btnWater.addEventListener('click', () => {
    // animación al presionar: añadir clase 'watering' por 3s (requisito)
    btnWater.classList.add('watering');
    send('WATER:TRIGGER');
    // detener la animación en 3.5s
    setTimeout(() => btnWater.classList.remove('watering'), 3500);
  });

  btnFan.addEventListener('click', () => {
    send('FAN:TOGGLE');
    toggleFanUI();
  });

  // Al presionar el termómetro pedimos temperatura
  thermo.addEventListener('click', () => {
    // efecto visual corto
    thermo.classList.add('active');
    setTimeout(() => thermo.classList.remove('active'), 600);
    send('TEMP:REQ');
  });

  // Actualizar UI helpers
  function toggleLightUI(onState) {
    if (typeof onState === 'boolean') {
      state.light = onState;
    } else {
      state.light = !state.light;
    }
    if (state.light) {
      btnLight.classList.add('on');
      btnLight.setAttribute('aria-pressed', 'true');
    } else {
      btnLight.classList.remove('on');
      btnLight.setAttribute('aria-pressed', 'false');
    }
  }

  function toggleFanUI(onState) {
    if (typeof onState === 'boolean') {
      state.fan = onState;
    } else {
      state.fan = !state.fan;
    }
    if (state.fan) {
      btnFan.classList.add('on');
      btnFan.setAttribute('aria-pressed', 'true');
    } else {
      btnFan.classList.remove('on');
      btnFan.setAttribute('aria-pressed', 'false');
    }
  }

  function setWateringUI(onState) {
    state.watering = !!onState;
    if (state.watering) {
      btnWater.classList.add('watering');
    } else {
      btnWater.classList.remove('watering');
    }
  }

  function setTemp(v) {
    state.temp = v;
    tempValue.textContent = (v === null ? '-- °C' : `${v} °C`);
    // ajustar mercurio (visual) si quisieras: cambiar transform de .thermo-merc
    const merc = document.querySelector('.thermo-merc');
    if (merc && v !== null) {
      // solo visual: map temp aprox entre 0-40 °C al espacio disponible
      const t = Math.max(0, Math.min(40, parseFloat(v)));
      const pct = (t / 40) * 60; // 0..60 px up
      merc.style.transform = `translateY(${pct}px)`;
    }
  }
  function setHum(v){
    state.hum = v;
    humValue.textContent = (v === null ? '--' : `${v}`);
  }
  function setLux(v){
    state.lux = v;
    luxValue.textContent = (v === null ? '--' : `${v}`);
  }

  // Registrar logs
  function log(msg){
    const time = new Date().toLocaleTimeString();
    logEl.textContent += `[${time}] ${msg}\n`;
    logEl.scrollTop = logEl.scrollHeight;
  }
  function setStatus(txt, ok){
    statusEl.textContent = txt;
    statusEl.style.color = ok ? '#b7ffc4' : '#ffb3b3';
  }

  // Manejo de mensajes entrantes
  function handleIncoming(message){
    // Si viene STATE:KEY=VAL;KEY2=VAL2;...
    if (message.startsWith('STATE:')) {
      const payload = message.slice(6);
      const parts = payload.split(';').map(s => s.trim()).filter(Boolean);
      parts.forEach(p => {
        const [k,v] = p.split('=');
        applyKeyValue(k?.trim(), v?.trim());
      });
      return;
    }

    // Mensajes individuales
    if (message.startsWith('LIGHT:')) {
      const val = message.split(':')[1];
      toggleLightUI(val === 'ON');
      return;
    }
    if (message.startsWith('WATER:')) {
      const val = message.split(':')[1];
      setWateringUI(val === 'ON');
      return;
    }
    if (message.startsWith('FAN:')) {
      const val = message.split(':')[1];
      toggleFanUI(val === 'ON');
      return;
    }
    if (message.startsWith('TEMP:')) {
      // notifyClients("TEMP:X");
      const val = message.split(':')[1];
      setTemp(isNumeric(val) ? Number(parseFloat(val).toFixed(1)) : val);
      return;
    }
    if (message.startsWith('HUM:')) {
      // notifyClients("HUM:X");
      const val = message.split(':')[1];
      setHum(isNumeric(val) ? Math.round(Number(val)) : val);
      return;
    }
    if (message.startsWith('LUX:') || message.startsWith('LIGHTLEVEL:')) {
      // notifyClients("LUX:X");
      const val = message.split(':')[1];
      setLux(isNumeric(val) ? Math.round(Number(val)) : val);
      return;
    }

    // Si no reconocemos, lo registramos
    log('No reconocido: ' + message);
  }

  function applyKeyValue(k, v) {
    if (!k) return;
    const key = k.toUpperCase();
    switch (key) {
      case 'LIGHT': toggleLightUI(v === 'ON'); break;
      case 'FAN': toggleFanUI(v === 'ON'); break;
      case 'WATER': setWateringUI(v === 'ON'); break;
      case 'TEMP': setTemp(isNumeric(v) ? Number(parseFloat(v).toFixed(1)) : v); break;
      case 'HUM': setHum(isNumeric(v) ? Math.round(Number(v)) : v); break;
      case 'LUX':
      case 'LIGHTLEVEL': setLux(isNumeric(v) ? Math.round(Number(v)) : v); break;
      default:
        // no reconocido
        log(`KEY desconocida: ${k}=${v}`);
    }
  }

  function isNumeric(n){ return !isNaN(parseFloat(n)) && isFinite(n); }

  // Exponer ws por debugging en consola
  window._vivero = { ws, send, state };

  // Inicial UI (por si no recibe estado inicial)
  toggleLightUI(false);
  toggleFanUI(false);
  setWateringUI(false);
  setTemp(null);
  setHum(null);
  setLux(null);

})();

const themeBtn = document.getElementById("themeToggle");

// Cambiar tema
themeBtn.addEventListener("click", () => {
    document.body.classList.toggle("light-mode");

    if (document.body.classList.contains("light-mode")) {
        themeBtn.innerText = "🌞 Modo Claro";
    } else {
        themeBtn.innerText = "🌙 Modo Oscuro";
    }
});

// Mantener el tema después de recargar (opcional)
if (localStorage.getItem("theme") === "light") {
    document.body.classList.add("light-mode");
    themeBtn.innerText = "🌞 Modo Claro";
}

themeBtn.addEventListener("click", () => {
    const mode = document.body.classList.contains("light-mode") ? "light" : "dark";
    localStorage.setItem("theme", mode);
});

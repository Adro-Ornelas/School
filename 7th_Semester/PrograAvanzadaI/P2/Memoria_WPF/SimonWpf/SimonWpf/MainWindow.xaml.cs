using System;
using System.Collections.Generic;
using System.Media;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace SimonWpf
{
    public partial class MainWindow : Window
    {
        // Numero de buttons
        private int NUMERO_DE_buttons = 16;
        // Arreglo de botones, necesario para acceder a sus eventos
        private Button[] buttons;
        // Areglo de sonidos para asignar a botones
        private SoundPlayer[] soundPlayers;
        // Lista de secuencia de posiciones de botones elegidos por Computadora
        private List<int> secuencia = new List<int>();
        // Lista de secuencia de posiciones de botones elegidos por usuario
        private List<int> secuenciaUsuario = new List<int>();
        // Generar números aleatorios
        private Random random = new Random();
        // Flag para bloquear interfaz cuando es turno de la computadora
        private bool watingInput = false;

        // Colores de los botones, ya definidos gracias a Brush
        private Brush[] coloresbuttons = new Brush[]
        {

            Brushes.ForestGreen, Brushes.CadetBlue, Brushes.SlateBlue, Brushes.DarkKhaki,
            Brushes.MediumVioletRed, Brushes.DarkOrange, Brushes.MediumSlateBlue, Brushes.Tomato,
            Brushes.Coral, Brushes.MediumSeaGreen, Brushes.SteelBlue, Brushes.Goldenrod,

            Brushes.IndianRed, Brushes.Peru, Brushes.SeaGreen, Brushes.DarkCyan,
        };

        // Main sólo inicia layout y juego
        public MainWindow()
        {
            InitializeComponent();
            InicializarJuego();
        }

        private void InicializarJuego()
        {

            int columnas = (int)Math.Ceiling(Math.Sqrt(NUMERO_DE_buttons));
            int filas = (int)Math.Ceiling((double)NUMERO_DE_buttons / columnas);
            
            // Establece dimensiones de botones
            ButtonGrid.Columns = columnas;
            ButtonGrid.Rows = filas;

            // Inicializa arreglo con número de botones
            buttons = new Button[NUMERO_DE_buttons];

            // soundPlayers = new SoundPlayer[NUMERO_DE_buttons];


            // Inicializa todos los botones
            for (int i = 0; i < NUMERO_DE_buttons; i++)
            {
                var b = new Button
                {
                    Tag = i,
                    Margin = new Thickness(6),
                    FontWeight = FontWeights.Bold,
                    Content = "",
                    Background = coloresbuttons[i % coloresbuttons.Length]
                };

                b.Click += Boton_Click; // Añade la función
                buttons[i] = b;         // Asigna Botón
                ButtonGrid.Children.Add(b); // Agrega a Layout

                // Añade el sonido a los botones
                try
                {
                    string ruta = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Sounds", $"blipselect_{i + 1}.wav");
                    if (System.IO.File.Exists(ruta))
                    {
                        soundPlayers[i] = new SoundPlayer(ruta);
                        soundPlayers[i].LoadAsync();
                    }
                    else
                    {
                        soundPlayers[i] = null;
                        Console.WriteLine($"No se encontró sonido: {ruta}");
                    }
                }
                catch (Exception ex)
                {
                    soundPlayers[i] = null;
                    Console.WriteLine($"Error cargando sonido índice {i}: {ex.Message}");
                }
            }

            BtnStart.IsEnabled = true;
            TxtStatus.Text = "Presiona Iniciar";
        }

        private async void BtnStart_Click(object sender, RoutedEventArgs e)
        {


            // Reproduce sonido al hacer click
            // MediaPlayer player = new MediaPlayer();
            // player.Open(new Uri("pack://siteoforigin:,,,/memoria_sounds-restart.wav"));
            // player.Play();

            BtnStart.IsEnabled = false;
            secuencia.Clear();
            secuenciaUsuario.Clear();
            TxtStatus.Text = "Preparando...";
            await Task.Delay(250);
            AgregarNuevoABaraja();
            await MostrarSecuenciaAsync();


        }

        private void Boton_Click(object sender, RoutedEventArgs e)
        {
            if (!watingInput) return; // ignorar clicks fuera de turno

            if (sender is Button b && b.Tag is int index)
            {
                int idx = index;
                ReproducirYResaltarAsync(idx);
                secuenciaUsuario.Add(idx);

                int posicion = secuenciaUsuario.Count - 1;
                if (secuencia[posicion] != idx)
                {
                    // fallo
                    watingInput = false;
                    TxtStatus.Text = "¡Fallaste! Presiona Iniciar para reiniciar.";
                    MessageBox.Show($"Perdiste en el paso {posicion + 1}.", "Simon", MessageBoxButton.OK, MessageBoxImage.Information);
                    BtnStart.IsEnabled = true;
                    return;
                }

                if (secuenciaUsuario.Count == secuencia.Count)
                {
                    // correcto
                    watingInput = false;
                    TxtStatus.Text = "¡Bien!";
                    secuenciaUsuario.Clear();
                    AgregarNuevoABaraja();
                    _ = Task.Run(async () =>
                    {
                        await Task.Delay(800);
                        await Dispatcher.InvokeAsync(async () => await MostrarSecuenciaAsync());
                    });
                }
            }
        }

        private void AgregarNuevoABaraja()
        {
            int nuevo = random.Next(NUMERO_DE_buttons);
            secuencia.Add(nuevo);
            Console.WriteLine("Secuencia ahora: " + string.Join(",", secuencia));
        }

        private async Task MostrarSecuenciaAsync()
        {
            TxtStatus.Text = $"Mostrando secuencia ({secuencia.Count})...";
            BtnStart.IsEnabled = false;
            // deshabilitar entradas
            watingInput = false;
            foreach (var idx in secuencia)
            {
                await ReproducirYResaltarAsync(idx);
                await Task.Delay(350); // tiempo entre buttons
            }

            watingInput = true;
            secuenciaUsuario.Clear();
            TxtStatus.Text = $"Tu turno: longitud {secuencia.Count}";
        }

        // Resaltar botón
        private async Task ReproducirYResaltarAsync(int index)
        {
            if (index < 0 || index >= buttons.Length) return;

            var btn = buttons[index];
            var colorOriginal = btn.Background;
            btn.Background = new SolidColorBrush(Colors.LightYellow);
            try
            {
                var player = soundPlayers[index];
                if (player != null)
                {
                    // SoundPlayer.Play() 
                    player.Play();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error reproduciendo sonido: " + ex.Message);
            }


            // Delay para visualizar animaci[ón]
            await Task.Delay(450);
            // Regresa a color orignial
            btn.Background = colorOriginal;
        }
    }
}

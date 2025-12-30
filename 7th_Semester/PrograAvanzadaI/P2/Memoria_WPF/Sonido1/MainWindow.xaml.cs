using System.Windows;
using System.Windows.Media;


namespace Sonido1
{
    public partial class MainWindow : Window
    {
        private bool colorWhite = true;        
        private MediaPlayer player = new MediaPlayer();
        public MainWindow()
        {
            InitializeComponent();

            
            

        }

        void OnClick2(object sender, RoutedEventArgs e)
        {
            if(colorWhite)
                btn2.Background = Brushes.Pink;
            else
                btn2.Background = Brushes.White;
            colorWhite = !colorWhite;

            player.Open(new Uri("C:\\users\\usuario1\\Documents\\PrograAvanzada\\P2\\Memoria_WPF\\Sonido1\\memoria_sounds\\recortado.mp3"));
            player.Play();
        }
    }
}

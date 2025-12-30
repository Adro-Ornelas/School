package com.example.memory;

import androidx.appcompat.app.AppCompatActivity;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    // Constantes de tamaño de cuadrículo
    public static final int nRows = 4;
    public static final int nCols = 4;
    private int[] colors;
    private int[] sounds;

    // Número de rondas y como índece de secuencia
    private int indSecuencia = 0;
    // Secuencia de botones presionados
    private int[] secuencia = new int[200];

    private int usr_indSecuencia = 0;
    private int[] usr_secuencia = new int[200];

    private boolean usuarioCorrecto = true;

    private GridLayout gridButtons;

    Context context = this;

    // Arreglo de Buttons
    private Button[][] btnsArray = new Button[nRows][nCols];
    private TextView edtPuntos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sonidoInicio();

        gridButtons = findViewById(R.id.gridButtons);
        edtPuntos = findViewById(R.id.edtPuntos);

        iniciarLayout();

        animacionInicio(() ->
                animacionInicio2(() ->
                        iniciarJuego()));

//        animacionInicio(() -> {});
//        animacionInicio2(() -> {});
        //iniciarJuego();

    }

    private void setBotonesHabilitados(boolean habilitar) {
        for (int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                btnsArray[r][c].setEnabled(habilitar);
            }
        }
    }

    private void animacionInicio(Runnable alfinalizar) {

        // Deshabilita botones
        setBotonesHabilitados(false);
        AnimatorSet set = new AnimatorSet();
        List<Animator> anims = new ArrayList<>();

        // Corrimiento
        for(int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                // Animación (de color a negro y de negro a color a través de alpha)
                ObjectAnimator animator = ObjectAnimator.ofFloat(btnsArray[r][c], "alpha", 1f, 0f, 1f);
                animator.setDuration(500); // 1 second duration
                animator.setStartDelay((r * nCols + c) * 100); // retardo entre botones
                anims.add(animator);
                //animator.start();
            }
        }

        set.playTogether(anims);
        set.addListener(new AnimatorListenerAdapter() {
            @Override
            public void onAnimationEnd(Animator animation) {
                super.onAnimationEnd(animation);
                setBotonesHabilitados(true);
                if (alfinalizar != null) alfinalizar.run();

            }
        });

        set.start();

    }

    public void animacionInicio2(Runnable alfinalizar){

        // Que todos desaparecen y aparecen

        AnimatorSet set = new AnimatorSet();
        List<Animator> anims = new ArrayList<>();

        for(int r = 0; r < nRows; ++r){
            for(int c = 0; c < nCols; ++c){
                // Animación (de color a negro y de negro a color a través de alpha)
                ObjectAnimator animator = ObjectAnimator.ofFloat(btnsArray[r][c], "alpha", 1f, 0f, 1f);
                animator.setDuration(500); // 1 second duration
                //animator.setStartDelay(2000); // retardo entre botones
                anims.add(animator);
                //animator.start();
            }
        }


        set.playTogether(anims);
        set.addListener(new AnimatorListenerAdapter() {
            @Override
            public void onAnimationEnd(Animator animation) {
                super.onAnimationEnd(animation);
                setBotonesHabilitados(true);
                if (alfinalizar != null) alfinalizar.run();

            }
        });

        set.start();
    }

   private void iniciarJuego() {


       // Deshabilita botones
       setBotonesHabilitados(false);

        // Actualia puntos
        edtPuntos.setText("" + indSecuencia);

        // Genera número aleatorio de 0 - 15
        Random rand = new Random();
        int nuevoIndSec = rand.nextInt(16);

        // Añade lugar
        secuencia[indSecuencia++] = nuevoIndSec;

        // Anima toda la secuencia en pantalla
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                animSecuencia(0);
            }
        },700); // Delay hasta que el usuario pueda presionar un botón
    }

    private void animSecuencia(int ind) {

        // Si todavía hay botón por animar
        if (ind < indSecuencia) {
            // Anima el actual y mada a animar el siguiente
            animClick(secuencia[ind], () -> animSecuencia(ind + 1));
        } else {
            // Cuando ya acabó de animar, activa botones
            setBotonesHabilitados(true);
        }


    }

    private void animClick(int nuevoIndSec, Runnable alfinalizar){

        //btnsArray[nuevoIndSec / 4][nuevoIndSec % 4].performClick();

        // Anima y  ejecuta el sonido del botón requerido
        animarYSonidoBoton(btnsArray[nuevoIndSec / 4][nuevoIndSec % 4], nuevoIndSec);


        new Handler(Looper.getMainLooper()).postDelayed(() -> {
            if(alfinalizar != null) {
                alfinalizar.run();
//                usr_indSecuencia = 0;
            }
        }, 400);
    }

    private void iniciarLayout() {

        // Inicializa arreglo de sonidos
        sounds = new int[] {
                R.raw.sound1,
                R.raw.sound2,
                R.raw.sound3,
                R.raw.sound4,
                R.raw.sound5,
                R.raw.sound6,
                R.raw.sound7,
                R.raw.sound8,
                R.raw.sound9,
                R.raw.sound10,
                R.raw.sound11,
                R.raw.sound12,
                R.raw.sound13,
                R.raw.sound14,
                R.raw.sound15,
                R.raw.sound16
        };

        colors = new int[] {
                getResources().getColor(R.color.color1, getTheme()),
                getResources().getColor(R.color.color2, getTheme()),
                getResources().getColor(R.color.color3, getTheme()),
                getResources().getColor(R.color.color4, getTheme()),
                getResources().getColor(R.color.color5, getTheme()),
                getResources().getColor(R.color.color6, getTheme()),
                getResources().getColor(R.color.color7, getTheme()),
                getResources().getColor(R.color.color8, getTheme()),
                getResources().getColor(R.color.color9, getTheme()),
                getResources().getColor(R.color.color10, getTheme()),
                getResources().getColor(R.color.color11, getTheme()),
                getResources().getColor(R.color.color12, getTheme()),
                getResources().getColor(R.color.color13, getTheme()),
                getResources().getColor(R.color.color14, getTheme()),
                getResources().getColor(R.color.color15, getTheme()),
                getResources().getColor(R.color.color16, getTheme()),

        };

        for (int r = 0; r < nRows; ++r) {
            for(int c = 0; c < nCols; ++c) {

                // Calcula índice actual para color y sonido
                final int index = r * 4 + c;
                Button newButton = new Button(this);

                // newButton.setText(String.valueOf(index));

                // Ajustar el tamaño y posición de cada botón del gridLayout dinámicamente
                GridLayout.LayoutParams gridButtonParams = new GridLayout.LayoutParams();
                gridButtonParams.rowSpec = GridLayout.spec(r, 1f);
                gridButtonParams.columnSpec = GridLayout.spec(c, 1f);
                gridButtonParams.width = 0;
                gridButtonParams.height = 0;
                gridButtonParams.setMargins(15, 15, 15, 15);

                // Añade la configuración al botón
                newButton.setLayoutParams(gridButtonParams);

                // Agrega color de fondo
                newButton.setBackgroundColor(colors[index]);

                // Agrega voyerista (clickListener a botón)
                newButton.setOnClickListener(v -> {

                    animarYSonidoBoton((Button) v, index);

                    // Evalúa decisión de usaurio
                    if(secuencia[usr_indSecuencia++] == index) {
                        // Cuando es el último botón y es correcto
                        if(usr_indSecuencia == indSecuencia) {
                            iniciarJuego();
                            usr_indSecuencia = 0;
                        }
                    } else {

                        // El usuario perdió, no puede presionar hasta reiniciar
                        setBotonesHabilitados(false);

                        Toast.makeText(context, "PERDISTE EN "+(indSecuencia-1)+", REINICIANDO", Toast.LENGTH_SHORT).show();
                        new Handler().postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                // Reinicia índices (suficiente para reiniciar el juego
                                indSecuencia = usr_indSecuencia = 0;

                                // Sonido de reinicio
                                MediaPlayer mp = MediaPlayer.create(context, R.raw.restart);
                                mp.start();

                                // Parpadea interfaz y vuelve a iniciar
                                animacionInicio2(() -> iniciarJuego());

                            }
                        }, 2000);
                    }

                });

                // Agrega botón a la cuadrículo (grid)
                gridButtons.addView(newButton);

                // Añade botón al arreglo
                btnsArray[r][c] = newButton;
            }

        }
    }

    private void animarYSonidoBoton(Button v, int index) {

        MediaPlayer mediaPlayer = MediaPlayer.create(context, sounds[index]);
        mediaPlayer.start();

        // Animación (de color a negro y de negro a color a través de alpha)
        ObjectAnimator animator = ObjectAnimator.ofFloat(v, "alpha", 1f, 0f, 1f);
        animator.setDuration(500); // 1 second duration
        animator.start();

    }

    private void sonidoInicio() {
        // Reproduce sonido de incicio
        MediaPlayer mp_start = MediaPlayer.create(context, R.raw.start_8_bits);
        mp_start.start();
    }
}
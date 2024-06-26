/* 
 * File:   Queue.h
 * Author: Adro Ornelas
 *
 * Created on 2 de marzo de 2024, 07:37 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#define TAMQUEUE 10

class Queue {   // First In First Out
protected:
    int fila[TAMQUEUE];
    int frente, fondo;
public:
    Queue();
    
    bool eliminar(int* num);
    bool empty();       // Vaciar
    int  getFrente();   // Cardinalidad
    int  getFondo();   // Cardinalidad
    bool insetar(int num);
    bool isFull();
    bool isEmpty();
    bool isThere(int);
    void print();
    
};

#endif /* QUEUE_H */


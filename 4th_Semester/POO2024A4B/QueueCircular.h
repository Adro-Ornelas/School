/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueCircular.h
 * Author: Adro Ornelas
 *
 * Created on 19 de marzo de 2024, 08:15 AM
 */

#ifndef QUEUECIRCULAR_H
#define QUEUECIRCULAR_H
#include "Queue.h"

class QueueCircular : public Queue {
public:
    int cardinalidad();
    void print();
    bool eliminar(int*);
    bool isThere(int);
    bool isFull();
    bool insetar(int);
};

#endif /* QUEUECIRCULAR_H */


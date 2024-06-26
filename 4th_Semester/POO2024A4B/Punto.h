#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    double x, y;
public:
    Punto();
    Punto(double coord_x, double coord_y);    // Constructor
    void   print();
    double distancia(Punto punto2);
    double getX();
    double getY();
};

#endif /* PUNTO_H */


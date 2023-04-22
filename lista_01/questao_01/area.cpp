#include <iostream>
#include <math.h>
#include "area.hpp"

using namespace std;

float areaTriangulo(int a,int b){
  return ((a * b)/2);
}

float areaRetagulo(int a, int b){
  return (a * b);
}

float areaCirculo(int raio){
  return (pow(raio, 2) * 3.14);
}

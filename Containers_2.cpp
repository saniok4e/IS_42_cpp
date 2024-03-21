#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Vector {
private:
    std::vector<double> data;
    int size;
public:
    Vector(int size) :size(size) {
        data.resize(size);
    }
    ~Vector() {}
    void fillVector() {
        for (int i = 0; i < size; i++) {
            std::cin >> data[i];
        }
    }
    void printVector() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
    }
    void printNorm() {
        double norm = calculateNorm();
        cout << "norma= " << norm << std::endl;
    }
    double calculateNorm() const {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }
    Vector add(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
    Vector subtract(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }
    double scalarProduct(const Vector& other) {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * other.data[i];
        }
        return result;
    }
    Vector multiplyByScalar(double scalar) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }
    int compareByNorm(const Vector& other) {
        double norm1 = calculateNorm();
        double norm2 = other.calculateNorm();
        if (norm1 == norm2) return 0;
        else if (norm1 < norm2) return -1;
        else return 1;
    }
};

void main() {
    setlocale(LC_ALL, "Eng");
    int size;
    cin >> size;
    Vector vector1(size);
    Vector vector2(size);
    vector1.fillVector();
    vector2.fillVector();
    double scalar;
    cin >> scalar;
    cout << "vector1= ";
    vector1.printVector();
    vector1.printNorm();
    cout << "vector2= ";
    vector2.printVector();
    vector2.printNorm();
    Vector sum = vector1.add(vector2);
    cout << "summa= ";
    sum.printVector();
    cout << endl;
    Vector difference = vector1.subtract(vector2);
    cout << "raznost= ";
    difference.printVector();
    cout << endl;
    double dotProduct = vector1.scalarProduct(vector2);
    cout << "scalar= " << dotProduct << endl;
    Vector scaledVector1 = vector1.multiplyByScalar(scalar);
    cout << "mult chislo * Vector1= ";
    scaledVector1.printVector();
    cout << endl;
    Vector scaledVector2 = vector2.multiplyByScalar(scalar);
    cout << "mult chislo * Vector2= ";
    scaledVector2.printVector();
    cout << endl;
    int comparison = vector1.compareByNorm(vector2);
    if (comparison == 0) {
        cout << "norma(Vector1) = norma(Vector2)" << endl;
    }
    else if (comparison < 0) {
        cout << "norma(Vector1) < norma(Vector2)" << endl;
    }
    else {
        cout << "norma(Vector1) > norma(Vector2)" << endl;
    }
}
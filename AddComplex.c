#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex* createComplex(double real, double imag) {
    Complex* complexNumber = (Complex*)malloc(sizeof(Complex));
    if (complexNumber != NULL) {
        complexNumber->real = real;
        complexNumber->imag = imag;
    }
    return complexNumber;
}

void destroyComplex(Complex* complexNumber) {
    if (complexNumber != NULL) {
        free(complexNumber);
    }
}

Complex* addComplex(Complex* c1, Complex* c2) {
    Complex* result = createComplex(c1->real + c2->real, c1->imag + c2->imag);
    return result;
}

Complex* subtractComplex(Complex* c1, Complex* c2) {
    Complex* result = createComplex(c1->real - c2->real, c1->imag - c2->imag);
    return result;
}

Complex* multiplyComplex(Complex* c1, Complex* c2) {
    Complex* result = createComplex(
        c1->real * c2->real - c1->imag * c2->imag,
        c1->real * c2->imag + c1->imag * c2->real
    );
    return result;
}

int main() {
    double real1, imag1, real2, imag2;
    
    printf("Enter real and imaginary parts of the first complex number: ");
    scanf("%lf %lf", &real1, &imag1);
    
    printf("Enter real and imaginary parts of the second complex number: ");
    scanf("%lf %lf", &real2, &imag2);

    Complex* num1 = createComplex(real1, imag1);
    Complex* num2 = createComplex(real2, imag2);

    Complex* sum = addComplex(num1, num2);
    Complex* diff = subtractComplex(num1, num2);
    Complex* product = multiplyComplex(num1, num2);

    printf("Sum: %.2f + %.2fi\n", sum->real, sum->imag);
    printf("Difference: %.2f + %.2fi\n", diff->real, diff->imag);
    printf("Product: %.2f + %.2fi\n", product->real, product->imag);

    destroyComplex(num1);
    destroyComplex(num2);
    destroyComplex(sum);
    destroyComplex(diff);
    destroyComplex(product);

    return 0;
}


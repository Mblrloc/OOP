#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
#include <string>
using namespace std;

// В этой программе мы рисуем в картинку комплексную функцию,
// которая задаётся в функции func

struct Color {
	unsigned char r, g, b;
};

Complex func(Complex z, Complex c) {
	return z * z + c;
}


int main(int argc, char *argv[]) {
    int N = std::atoi(argv[1]);
    float x = std::stof(argv[2], nullptr);
    float y = std::stof(argv[3], nullptr);
    cout << "N = " << N << "c = " << x << " + " << y << "i" << std::endl;
	int width = 800, height = 800;
	float x0 = -2.0f, x1 = 2.0f;
	float y0 = -2.0f, y1 = 2.0f;
	
	// Выделяем память под пиксели
	Color* data = (Color*)malloc(sizeof(Color) * width * height);

	// data - это массив цветов размером width * height
	// Задаём значения этого массива так, чтобы
	// реальная часть функции func соответствовала зелёному цвету,
	// а мнимая часть -- синей компоненте цвета
    Complex c = {x, y};
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex z = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};
            Complex f = func(z, c);
            for (int i1 = 0; i1 < N; i1++) {
			    f = func(f, c);
            }
			data[i + width * j].r = 0;
			data[i + width * j].g = f.re;
			data[i + width * j].b = f.im;
		}
	}

	// Сохраняем массив цветов data как картинку в формате .ppm
	FILE* file = fopen(argv[4], "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);

	// Освобождаем память
	free(data);
}
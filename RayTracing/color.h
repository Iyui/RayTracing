#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <windows.h>
#include <iostream>
#include <fstream>  
using namespace std;

void write_color(std::ostream &out, color pixel_color) {
	//写下每个颜色分量转换后的值[0,255]
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);

	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

void write_color(color pixel_color, ofstream &OutImage, int samples_per_pixel) {
	//写下每个颜色分量转换后的值[0,255]
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);


	int ir = static_cast<int>(255.999 * clamp(r, 0.0, 0.999));
	int ig = static_cast<int>(255.999 * clamp(g, 0.0, 0.999));
	int ib = static_cast<int>(255.999 * clamp(b, 0.0, 0.999));
	OutImage << ir << ' ' << ig << ' ' << ib << '\n';
}


typedef struct BGR
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}BGR;

typedef struct RGB
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}RGB;

#endif
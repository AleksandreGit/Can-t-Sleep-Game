/*
* The aim of this class is to re-create the Perlin Noise on C++
* It is widely inspired by the original version proposed by its creator Ken Perlin
* https://mrl.cs.nyu.edu/~perlin/noise/
* 
*/

#pragma once
#include <math.h>  
#include <iostream>
#include <random>

class PerlinNoise
{
public:
	PerlinNoise(float seed);

	double noise1D(double x);
	double noise2D(double x, double y);
	double noise3D(double x, double y, double z);
	void reseed(float seed);

private:
	double fade(double t);
	double lerp(double t, double a, double b);
	double grad(int hash, double x, double y, double z);

	int p[512];
};


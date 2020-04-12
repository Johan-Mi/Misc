#include <stdint.h>
#include <stddef.h>

typedef struct {
	float x, y, z;
} Float3d;

typedef struct {
	float x, y, z;
	float rx, ry;
} Camera;

typedef struct {
	float r, g, b;
} Rgb;

typedef struct {
	size_t p1, p2, p3;
	Rgb color;
} Tri;

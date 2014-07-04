/*

 **Triangle Angles Calculator**
 Written by Michael Nasta
 Idea by James Harnett
 May 28th, 2014

*/

#include <stdio.h>
#include <math.h>

// User provides points of triangles in the coordinate plane
// and the program returns the angles of the triangle.
// Can probably create some functions for the formulas.

int main(int argc, char *argv[]) {
	
	printf("Specify the points of a triangle to find its angles.\n\n");
	
	// point A, accept x- and y-coords
	float Axcoord, Aycoord;
	
	printf("What is the x-coordinate of Point A?\n");
	scanf(" %f", &Axcoord);
	printf("What is the y-coordinate of Point A?\n");
	scanf(" %f", &Aycoord);
	
	// point B, accept x- and y-coords
	float Bxcoord, Bycoord;
		
	printf("What is the x-coordinate of Point B?\n");
	scanf(" %f", &Bxcoord);
	printf("What is the y-coordinate of Point B?\n");
	scanf(" %f", &Bycoord);
	
	// point C, accept x- and y-coords
	float Cxcoord, Cycoord;
		
	printf("What is the x-coordinate of Point C?\n");
	scanf(" %f", &Cxcoord);
	printf("What is the y-coordinate of Point C?\n");
	scanf(" %f", &Cycoord);
	
	// squareRoot((x1-x2)^2+(y1-y2)^2)
	// a^2 = b^2 + c^2 - 2bccosA
	float distAB = sqrt(((Axcoord-Bxcoord)*(Axcoord-Bxcoord)) + ((Aycoord-Bycoord)*(Aycoord-Bycoord)));
	float distBC = sqrt(((Bxcoord-Cxcoord)*(Bxcoord-Cxcoord)) + ((Bycoord-Cycoord)*(Bycoord-Cycoord)));
	float distAC = sqrt(((Axcoord-Cxcoord)*(Axcoord-Cxcoord)) + ((Aycoord-Cycoord)*(Aycoord-Cycoord)));
	
	// c = arcCcos((a^2 + b^2 - c^2)/2ab);
	float angleA = acos(((distAB * distAB) + (distAC * distAC) - (distBC * distBC)) / (2 * distAB * distAC)) * 57.2957795;
	float angleB = acos(((distBC * distBC) + (distAB * distAB) - (distAC * distAC)) / (2 * distBC * distAB)) * 57.2957795;
	float angleC = acos(((distBC * distBC) + (distAC * distAC) - (distAB * distAB)) / (2 * distBC * distAC)) * 57.2957795;
	
	float perimeter = distAB + distBC + distAC;
	// 1/2 ab sin c
	float area = sqrt((perimeter / 2) * ((perimeter / 2) - distBC) * ((perimeter / 2) - distAC) * ((perimeter / 2) - distAB));
	
	// Print the results of the triangle
	printf("Point A: (%.3f, %.3f)\n", Axcoord, Aycoord);
	printf("Point B: (%.3f, %.3f)\n", Bxcoord, Bycoord);
	printf("Point C: (%.3f, %.3f)\n", Cxcoord, Cycoord);
	printf("Distance from A-B: %.3f\n", (float)round((distAB * 100) / 100));
	printf("Distance from B-C: %.3f\n", (float)round((distBC * 100) / 100));
	printf("Distance from A-C: %.3f\n", (float)round((distAC * 100) / 100));
	printf("Perimeter: %.3f\n", (float)round((perimeter * 100) / 100));
	printf("Area: %.3f\n", (float)round((area * 100) / 100));
	printf("Angle A: %.3f degrees\n", (float)round((angleA * 100) / 100));
	printf("Angle B: %.3f degrees\n", (float)round((angleB * 100) / 100));
	printf("Angle C: %.3f degrees\n", (float)round((angleC * 100) / 100));
	
	// Could probably get rid of the 100s and the typecasting

	return 0;

}
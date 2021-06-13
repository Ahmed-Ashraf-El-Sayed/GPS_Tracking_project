#include <cmath>
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#define pi 3.14159265358979323846
void SystemInit(){}
float deg2rad(float deg) {
    return (deg * pi / 180);
}
float rad2deg(float rad) {
    return (rad * 180 / pi);
}

float distance(float lat1, float lon1, float lat2, float lon2) {
    float theta, dist;
    
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    }
    else {
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) * cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        dist = dist * 1.609344 *1000; 
         }
		return dist;
	}
float distance_total (float lat1, float lon1, float lat2, float lon2)
{ // used to accumlate the distance to get the total
	float Total=0;
	if(lon1!=0 && lat1 !=0){ 
		Total = distance(lat1,lon1,lat2,lon2);
	}
	return Total;
}
   
    int main(){
   float  x1=40.76532;
  float  x2=20.867456;
   float  y1=20.89123;
   float  y2=20.980842;   
   float  c=distance(x1,x2,y1,y2);
		printf("%1f",c);		
		}
		

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265

int choice=0;
double x,y,z,r,theta,phi,rho;
int main(){
	while(choice !=5){
		printf("\n*********\n 1.Sperical to Cartesian\n 2. Cartesian to Spherical\n 3. Cartesian to Cylindrical\n 4. Spherical to Cylindrical\n 5. Exit\n*********\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter r, theta, and phi: ");
				scanf("%lf%lf%lf",&r,&theta,&phi);
				printf("\nx=%lf y=%lf z=%lf\n",r*sin(M_PI*theta/180)*cos(M_PI*phi/180),r*sin(M_PI*theta/180)*sin(M_PI*phi/180),r*cos(M_PI/180*theta));
				break;
			case 2:
				printf("Enter x, y and z: ");
				scanf("%lf%lf%lf",&x,&y,&z);
				printf("\nr=%lf theta=%lf phi=%lf",sqrt(pow(x,2)+pow(y,2)+pow(z,2)), atan(y/x)*180/M_PI, (atan(sqrt(pow(x,2)+pow(y,2)))*180/M_PI)/z );
				break;
			case 3:
				printf("Enter x, y and z: ");
				scanf("%lf%lf%lf",&x,&y,&z);
				printf("\nrho=%lf theta=%lf z=%lf", sqrt(pow(x,2)+pow(y,2)), atan(y/x)*180/M_PI, z);
				break;
			case 4:
				printf("Enter r, theta and phi: ");
				scanf("%lf%lf%lf",&r, &theta, &phi);
				printf("\nrho=%lf theta=%lf z=%lf", r*sin(M_PI/180*phi), theta, r*cos(M_PI/180*phi));
				break;
			default:
				break;
		}
	}
	return 0;
}

/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include<iostream>
#include<string.h>

#define PI 3.141592654
#define n 3

using namespace std;

void geometria(float px,float py,float x,float y,int rotation,float rgb);
void triangulo_escaleno(float px,float py,float x,float y,int rotation,float rgb);
void Triangulo_Equilatero(float px,float py,float x,float y,int rotation,float rgb);
float tangent(float px, float py);
float pitagoras(int cat_ad,int cat_op);


double GrausParaRadiano(int graus);
double RadianosParaGraus(double radianoGR);
 
int valor;

 
/*Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Black and opaque
   glPolygonMode(GL_FRONT,GL_FILL);
   //glPolygonMode(GL_BACK,GL_LINE);
   
  // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
   int valor;
   /*Triangulo Escaleno*/
    triangulo_escaleno(350.0f,400.0f,-400.0f,470.0f,180,1.0f);
   /*Triangulo Equilatero*/
    Triangulo_Equilatero(400.0f,400.0f,400.0f,200.0f,0,1.0f);
    geometria(300.0f,350.0f,0.0f,0.0f,0,1.0f);
    glFlush();  // Render now
   
   
    
    
}


void  Triangulo_Equilatero(float px,float py,float x,float y,int rotation,float rgb){
	 int vetX[2],vetY[2],aglcos[2],aglsin[2]; 
	 float angulos[3] = {0,(2*PI)/3,(4*PI)/3};
	 
     for(int i=0;i<n;i++){
     	aglcos[i] =  px * cos(angulos[i] + GrausParaRadiano(rotation));
    	aglsin[i] =  py * sin(angulos[i] + GrausParaRadiano(rotation));
	 }
	 
	 /*
	for(int i=0;i<n;i++){
		cout<<"COS="<<aglcos[i]<<endl;
		cout<<"SIN="<<aglsin[i]<<endl;  
	}
	*/
	
	for(int i=0;i<n;i++){
	switch(i){
		
    	case 0:	
    	 vetX[i] = x + aglcos[i];
	     vetY[i] = y + aglsin[i];
    	break;
		
		
		case 1:
		 vetX[i] = vetX[i-1] + aglcos[i];	
	     vetY[i] = vetY[i-1] + aglsin[i];
		break;	
		
		case 2:
		 vetX[i] = vetX[i-1] + aglcos[i];	
	     vetY[i] = vetY[i-1] + aglsin[i];
		break;	
		
		
		default:
		 break;
	}		
		
	  }
	
		
	
	for(int i=0;i<n;i++){
		cout<<"VECTX"<< vetX[i] <<endl;
		cout<<"VECTY="<<vetY[i]<<endl;  
	}
	

      glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
       glColor3f(1.0f, 0.0f, 0.0f); // Blue
       glVertex2f(vetX[0]/1000.0f, vetY[0]/1000.0f);
       glColor3f(0.0f, 1.0f, 0.0f);
       glVertex2f(vetX[1]/1000.0f,vetY[1]/1000.0f);
       glVertex2f(vetX[2]/1000.0f,vetY[2]/1000.0f);
       glColor3f(0.0f, 0.0f, 1.0f);
      glEnd();

	  	
	  	

	
}





 
 void triangulo_escaleno(float px,float py,float x,float y,int rotation,float rgb){
 	float  angulo180 = PI;
 	float vet1_ag = angulo180 + tangent(px,py);
 	float vet2_ag = angulo180 - tangent(px,py);
 	float pitag = pitagoras(px/2,py);
 	int vetX[2],vetY[2],aglcos[2],aglsin[2];
	 	
 	cout<<"Pitagoras: "<<pitag<<endl;
 	cout<<"Angulo1: "<<vet1_ag<<endl;
 	cout<<"Angulo2: "<<vet2_ag<<endl;
 	
 	//Sin Cos
 	float retangular_vet1 = px * cos(0 + rotation);
 	float retangular_vet2 = pitag * cos(vet1_ag + GrausParaRadiano(rotation));
	float retangular_vet3 = pitag * cos(vet2_ag + GrausParaRadiano(rotation));
 	
 	
 	//Sin
    float retangular_vet1SIN = px  *   sin(0 + rotation);
  	float retangular_vet2SIN  = pitag * sin(vet1_ag + GrausParaRadiano(rotation));
	float retangular_vet3SIN  = pitag * sin(vet2_ag + GrausParaRadiano(rotation));
 	
 	
 	aglcos[0] = retangular_vet1;aglcos[1] = retangular_vet2;aglcos[2] = retangular_vet3;  
    aglsin[0] = retangular_vet1SIN;aglsin[1] = retangular_vet2SIN;aglsin[2] = retangular_vet3SIN;
	 
 
    cout<<retangular_vet1<<endl;
 	cout<<retangular_vet2<<endl;
 	cout<<retangular_vet3<<endl;
 	
 	cout<<retangular_vet1SIN<<endl;
 	cout<<retangular_vet2SIN<<endl;
 	cout<<retangular_vet3SIN<<endl;
 	
 	
 	
 	for(int i=0;i<n;i++){
 	  switch(i){	 
 	   case 0:
        vetX[i] = x + aglcos[i];
        vetY[i] = y + aglsin[i];
        break;
        
        case 1:
         vetX[i] = vetX[i-1]  + aglcos[i];
         vetY[i] = vetY[i-1]  + aglsin[i];	
         break;
         
        case 2:
         vetX[i] = vetX[i-1]  + aglcos[i];
         vetY[i] = vetY[i-1]  + aglsin[i];	
         break;
		  
        default:
		 break;
      }
   }
   
   
   	for(int i=0;i<n;i++){
     cout<<"VetorX"<<vetX[i]<<endl; 
     cout<<"VetorY"<<vetY[i]<<endl; 
   }
   
     glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
      glColor3f(1.0f, 0.0f, 0.0f); // Blue
      glVertex2f(vetX[0]/1000.0f, vetY[0]/1000.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(vetX[1]/1000.0f,vetY[1]/1000.0f);
      glVertex2f(vetX[2]/1000.0f,vetY[2]/1000.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glEnd();
      
   
   
 	
 
 }
 
 float pitagoras(int cat_ad,int cat_op){
 	return sqrt(pow(cat_ad,2) + pow(cat_op,2));
 	
 }
 
 
 float tangent(float px, float py){
 	px = px/2;
 	return atan((py/px));

 }
 
 
 
 
void geometria(float px,float py,float x,float y,int rotation,float rgb){
	glColor3f(rgb, 0.0f, rgb); // Yellow
	double anguloMais_si[5];
	double anguloMais_cos[5];
	float veX[4],veY[4];  
	float retagu_relaX[4],retagu_relaY[4];
	double angulo[5] ={0,PI/2,(2*PI)/3,PI,3*PI/2};
	                //90///120///180//270
              
	
	for(int i=0;i<5;i++){        
    	double polar_si = sin(angulo[i]+GrausParaRadiano(rotation));   
    	double polar_cos = cos(angulo[i]+GrausParaRadiano(rotation)); 
        anguloMais_si[i] = polar_si;
        anguloMais_cos[i] = polar_cos;
        
        
    
        if(i>0)
          cout<<"\n"<<"Seno & Cons"<<(RadianosParaGraus(angulo[i])+rotation)<<" "<<anguloMais_si[i]<<endl;
		 
		else
	     cout<<"\n"<<"Seno & Cons"<<rotation<<" "<<anguloMais_si[i]<<endl;	   
	}

        for(int i=0;i<4;i++){ 
        
         switch(i){
           case 0:
	         retagu_relaX[i] = px* anguloMais_cos[0];
		     retagu_relaY[i] = py* anguloMais_si[0];
		     veX[i] = x +  retagu_relaX[i];
		     veY[i] = y +  retagu_relaY[i];
		     break;
		     
		    case 1:
		     retagu_relaX[i] = px* anguloMais_cos[1];
		     retagu_relaY[i] = py* anguloMais_si[1];
		     veX[i] = veX[i-1] +  retagu_relaX[i];
		     veY[i] = veY[i-1] +  retagu_relaY[i];
		     break;
		     
		    case 2:
		     retagu_relaX[i] = px* anguloMais_cos[3];
		     retagu_relaY[i] = py* anguloMais_si[3];
		     veX[i] = veX[i-1] +  retagu_relaX[i];
		     veY[i] = veY[i-1] +  retagu_relaY[i];
		     break; 
		    
		    
		    case 3:
		     retagu_relaX[i] = px* anguloMais_cos[4];
		     retagu_relaY[i] = py* anguloMais_si[4];
		     veX[i] = veX[i-1] +  retagu_relaX[i];
		     veY[i] = veY[i-1] +  retagu_relaY[i];
		     break;
		     
			default:
			 break; 
		 }
	        cout<<i<<"AngleCOS="<<anguloMais_cos[i]<<"\t";
	        cout<<i<<"AngleSIN="<<anguloMais_si[i]<<"\t";
	        cout<<"COS="<<retagu_relaX[i];cout<<"\t"<<"SIN="<<retagu_relaY[i]<<endl;		
	       
        }

          for(int i=0;i<4;i++){
            cout<<"X="<<veX[i]<<endl;
            cout<<"Y="<<veY[i]<<endl;
        }
            
          	
          

	
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(0.0f, 0.0f, 1.0f); // Red
      glVertex2f(veX[0]/1000.0f,veY[0]/1000.0f);                           // Define vertices in counter-clockwise (CCW) order
      glVertex2f(veX[1]/1000.0f,veY[1]/1000.0f);     //  so that the normal (front-face) is facing you
      glVertex2f(veX[2]/1000.0f,veY[2]/1000.0f);
      glVertex2f(veX[3]/1000.0f,veY[3]/1000.0f);
    glEnd();
	
	
/*	
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(0.0f, 0.0f, 1.0f); // Red
      glVertex2f(px/1000.0f,0.0f);                           // Define vertices in counter-clockwise (CCW) order
      glVertex2f(0.0f,py/1000.0f);     //  so that the normal (front-face) is facing you
      glVertex2f((px-(px*2.0f))/1000.0f,0.0f);
      glVertex2f(0.0f,(py-(py*2.0f))/1000.0f);
      glEnd();
*/
	
}


double GrausParaRadiano(int graus){
	return graus *(PI/180);
}

double RadianosParaGraus(double radianoGR){
	return radianoGR * (180/PI);
}
 
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   //cout<<tangent(350,400)<<endl;	
   cout<<"Iniciar Software"<<endl;	
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}

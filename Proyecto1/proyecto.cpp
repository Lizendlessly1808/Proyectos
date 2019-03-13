#include "Main.h"
//declaracion de variables
float v0X = 0.0;
float v0Y = 0.0;

float l = 0.0;
float h = 0.0;

float P1X = 0.0;
float P1Y = 0.0;
float P2X = 0.0;
float P2Y = 0.0;

float Usup = 0.0;
float Uinf = 0.0;
float Uizq = 0.0;
float Uder = 0.0;

float Yder = 0.0;
float Yizq = 0.0;
float Xsup = 0.0;
float Xinf = 0.0;




void InitGL(GLvoid)     // Inicializamos parametros

{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
}



void display(void)   // Creamos la funcion donde se dibuja

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Realización de la ventana

	//linea horizontal de abajo
	glBegin(GL_POLYGON); 

	glColor3f(0.6f, 0.6f, 0.6f);//color RGB en flotante
	glVertex3f(v0X,v0Y, 1.0f);
	glVertex3f(v0X+l,v0Y, 1.0f);
	glVertex3f(v0X+l,v0Y-1, 1.0f);
	glVertex3f(v0X, v0Y-1, 1.0f);
	glEnd();

	//linea vertical derecha
	glBegin(GL_POLYGON); 

	glColor3f(0.6f, 0.6f, 0.6f);//color RGB en flotante
	glVertex3f(v0X+l, v0Y-1, 1.0f);
	glVertex3f(v0X+l+1, v0Y-1, 1.0f);
	glVertex3f(v0X+l+1,v0Y+h+1, 1.0f);
	glVertex3f(v0X+l,v0Y+h+1, 1.0f);
	glEnd();

	//linea horizontal de arriba
	glBegin(GL_POLYGON); 

	glColor3f(0.6f, 0.6f, 0.6f);//color RGB en flotante
	glVertex3f(v0X+l,v0Y+h, 1.0f);
	glVertex3f(v0X+l,v0Y+h+1, 1.0f);
	glVertex3f(v0X, v0Y+h+1, 1.0f);
	glVertex3f(v0X, v0Y+h, 1.0f);
	glEnd();

	//linea vertical izquierda
	glBegin(GL_POLYGON); 

	glColor3f(0.6f, 0.6f, 0.6f);//color RGB en flotante
	glVertex3f(v0X, v0Y+h+1, 1.0f);
	glVertex3f(v0X-1, v0Y+h+1, 1.0f);
	glVertex3f(v0X-1,v0Y-1, 1.0f);
	glVertex3f(v0X,v0Y-1, 1.0f);
	glEnd();

	//Diseño Switch parte izquierda
	glBegin(GL_POLYGON);

	glColor3f(0.4f, 0.7f, 1.0f);//color RGB en flotante
	glVertex3f(v0X - 1, v0Y + h + 1, 1.0f);
	glVertex3f(v0X- 1 - (l / 2)-4, v0Y + h + 1, 1.0f);
	glVertex3f(v0X- 1 - (l / 2)-4, v0Y-1, 1.0f);
	glVertex3f(v0X-1, v0Y-1, 1.0f);
	glEnd();
	 
	//Diseño botones izquierdos
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);//color RGB en flotante
	glVertex3f(v0X - 2, v0Y + 3, 1.0f);
	glVertex3f(v0X - 5, v0Y + 3, 1.0f);
	glVertex3f(v0X - 5, v0Y + 4, 1.0f);
	glVertex3f(v0X - 2, v0Y + 4, 1.0f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);//color RGB en flotante
	glVertex3f(v0X - 3, v0Y +2, 1.0f);
	glVertex3f(v0X - 4, v0Y +2, 1.0f);
	glVertex3f(v0X - 4, v0Y + 5, 1.0f);
	glVertex3f(v0X - 3, v0Y + 5, 1.0f);
	glEnd();


	//Diseño Switch parte derecha
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);//color RGB en flotante
	glVertex3f(v0X + l + 1, v0Y - 1, 1.0f);
	glVertex3f(v0X+l+1+(l/2)+4, v0Y - 1, 1.0f);
	glVertex3f(v0X+l + 1 + (l/2)+4, v0Y +h+ 1, 1.0f);
	glVertex3f(v0X + l + 1, v0Y +h + 1, 1.0f);
	glEnd();

	//Diseño botones derechos
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);//color RGB en flotante
	glVertex3f(v0X + l + 2, v0Y+h-2, 1.0f);
	glVertex3f(v0X + l + 5, v0Y+h-2, 1.0f);
	glVertex3f(v0X + l + 5, v0Y + h-3 , 1.0f);
	glVertex3f(v0X + l + 2, v0Y + h-3, 1.0f);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);//color RGB en flotante
	glVertex3f(v0X + l + 3, v0Y + h -1, 1.0f);
	glVertex3f(v0X + l + 4, v0Y + h -1, 1.0f);
	glVertex3f(v0X + l + 4, v0Y + h - 4, 1.0f);
	glVertex3f(v0X + l + 3, v0Y + h - 4, 1.0f);
	glEnd();

	//Dibujo de la linea
	//Si se dibuja completa

	glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante
	glBegin(GL_LINES);
	glVertex2f(P1X, P1Y);
	glVertex2f(P2X, P2Y);
	glEnd();

	if (P1X >= v0X && P1X <= l && P1Y >= v0Y && P1Y <= h && P2X >= v0X && P2X <= l && P2Y >= v0Y && P2Y <= h)
	{
		glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante
		glBegin(GL_LINES);
		glVertex2f(P1X, P1Y);
		glVertex2f(P2X, P2Y);
		glEnd();
	}
	else
	{
		if (P1X >= v0X && P1X <= l && P1Y >= v0Y && P1Y <= h)
			glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante	
		{
			if (P2X > l && P2Y >= v0Y && P2Y <= h)
				glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante
			glBegin(GL_LINES);
			glVertex2f(P1X, P1Y);
			glVertex2f(v0X, Yizq);
			glEnd();

		}

		if (P2X >= v0X && P2X <= l && P2Y >= v0Y && P2Y <= h)
			glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante	
		{
			if (P1X > l && P1Y >= v0Y && P1Y <= h)
				glColor3f(0.0f, 0.0f, 1.0f);//color RGB en flotante
			glBegin(GL_LINES);
			glVertex2f(P2X, P2Y);
			glVertex2f(v0X, Yizq);
			glEnd();

	}

	
		
	
	glFlush();

}



void reshape(int width, int height)   // Creamos funcion Reshape

{

	if (height == 0)										// Prevenir division entre cero

	{

		height = 1;

	}



	glViewport(0, 0, width, height);



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Ortogonal
	glOrtho(-30, 30, -30, 30, -30, 30);
	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();

}



// Termina la ejecucion del programa cuando se presiona ESC

void keyboard(unsigned char key, int x, int y)

{

	switch (key)

	{

	case 27: exit(0);

		break;

	}

	glutPostRedisplay();

}



int main(int argc, char** argv)   // Main Function

{
	//Medidas de la ventana
	printf("Introduce las medidas de tu ventana \n");

	printf("Dame el punto V0 (origen) de tu ventana \n");
	printf("Punto inicial en x: \n ");
	scanf("%f", &v0X);
	system("cls");

	printf("Punto inicial en y: \n");
	scanf("%f", &v0Y);
	system("cls");

	printf("Dame el largo de tu ventana \n");
	scanf("%f", &l);
	system("cls");

	printf("Dame el ancho de tu ventana \n");
	scanf("%f", &h);
	system("cls");

	//Medidas de la linea a dibujar 

	printf("Dame el punto 1 de tu linea \n");
	printf("Punto inicial en X \n");
	scanf("%f", &P1X);
	system("cls");

	printf("Punto inicial en Y \n");
	scanf("%f", &P1Y);
	system("cls");
	printf("Dame el punto 2 de tu linea \n");
	printf("Punto final en X \n");
	scanf("%f", &P2X);
	system("cls");
	printf("Punto final en Y \n");
	scanf("%f", &P2Y);
	system("cls");

	//Menu
	printf("Medidas de tu ventana: ");
	printf("\n\t V0=(%f,%f)", v0X, v0Y);
	printf("\n\t Con largo de: %f ", l);
	printf("\n\t Con ancho de: %f ", h);

	printf("\n\nVertices de tu linea: ");
	printf("\n\t Punto 1=(%f,%f)", P1X, P1Y);
	printf("\n\t Punto 2=(%f,%f)\n", P2X, P2Y);
	//Algoritmo para saber si la linea se dibuja, se recorta o se descarta (no se dibuja)
	//definiendo el patron, queda derecha, arriba, izquierda, abajo


	if (P1X >= v0X && P1X <= l && P1Y >= v0Y && P1Y <= h && P2X >= v0X && P2X <= l && P2Y >= v0Y && P2Y <= h)
		printf("\nSe dibuja\n");

	else
		//Calcula los valores en binario de cada punto
		//Para P1
	
		if (P1X >= v0X && P1X <= l && P1Y >= v0Y && P1Y <= h)
			//printf("Su valor de P1 es de 0000 \n");

		if (P1X < v0X && P1Y < v0Y)
			//printf("Su valor de P1 es de 1001 \n");
		if (P1X < v0X && P1Y < h && P1Y > v0Y)
			//printf("Su valor de P1 es de 1000 \n");
		if (P1X < v0X && P1Y > h)
			//printf("Su valor de P1 es de 1100 \n");

		if (P1X > v0X && P1X < l && P1Y > h)
			//printf("Su valor de P1 es de 0100 \n");
		if (P1X > v0X && P1X < l && P1Y < v0Y)
			//printf("Su valor de P1 es de 0001 \n");

		if (P1X > l && P1Y > h)
			//printf("Su valor de P1 es de 0110 \n");
		if (P1X > l && P1Y < h && P1Y > v0Y && P1Y < h)
			//printf("Su valor de P1 es de 0010 \n");
		if (P1X > l && P1Y < v0Y)
			//printf("Su valor de P1 es de 0011 \n");



		//Para P2
		if (P2X >= v0X && P2X <= l && P2Y >= v0Y && P2Y <= h)
			//printf("Su valor de P2 es de 0000 \n");

		if (P2X < v0X && P2Y < v0Y)
			//printf("Su valor de P2 es de 1001 \n");
		if (P2X < v0X && P2Y < h && P2Y > v0Y)
			//printf("Su valor de P2 es de 1000 \n");
		if (P2X < v0X && P2Y > h)
			//printf("Su valor de P2 es de 1100 \n");

		if (P1X > v0X && P2X < l && P2Y > h)
			//printf("Su valor de P2 es de 0100 \n");
		if (P1X > v0X && P2X < l && P2Y < v0Y)
			//printf("Su valor de P2 es de 0001 \n");

		if (P2X > l && P2Y > h)
			//printf("Su valor de P2 es de 0110 \n");
		if (P2X > l && P2Y < h && P2Y > v0Y && P2Y < h)
			//printf("Su valor de P2 es de 0010 \n");
		if (P2X > l && P2Y < v0Y)
			//printf("Su valor de P2 es de 0011 \n");
	

	//Calcula si se descarta
	if (P1X < v0X && P1Y < v0Y)
		if (P2X < v0X && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < v0Y)
		if (P2X < v0X && P2Y < h && P2Y > v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < v0Y)
		if (P2X < v0X && P2Y > h)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < v0Y)
		if (P2X > v0X && P2X < l && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < v0Y)
		if (P2X > l && P2Y < v0Y)
			printf(" \nSe descarta");


	if (P1X > l && P1Y < h)
		if (P2X > l && P2Y < h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h)
		if (P2X > v0X && P2X < l && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h)
		if (P2X < v0X && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h)
		if (P2X > l && P2Y < h && P2Y > v0Y && P2Y < h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h)
		if (P2X > l && P2Y < v0Y)
			printf(" \nSe descarta");



	if (P1X < v0X && P1Y > h)
		if (P2X < v0X && P2Y > h)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y > h)
		if (P2X < v0X && P2Y < h && P2Y > v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y > h)
		if (P2X < v0X && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y > h)
		if (P2X > l && P2Y < h && P2Y > v0Y && P2Y < h)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y > h)
		if (P2X > l && P2Y > h)
			printf(" \nSe descarta");



	if (P1X > l && P1Y < v0Y)
		if (P2X > l && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < v0Y)
		if (P2X > v0X && P2X < l && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < v0Y)
		if (P2X < v0X && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < v0Y)
		if (P2X > v0X && P2X < l && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < v0Y)
		if (P2X > l && P2Y > h)
			printf(" \nSe descarta");



	if (P1X > v0X && P1X < l && P1Y > h)
		if (P2X > v0X && P2X < l && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > v0X && P1X < l && P1Y > h)
		if (P2X < v0X && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > v0X && P1X < l && P1Y > h)
		if (P2X > l && P2Y > h)
			printf(" \nSe descarta");



	if (P1X > v0X && P1X < l && P1Y < v0Y)
		if (P1X > v0X && P1X < l && P1Y < v0Y)
			printf(" \nSe descarta");
	if (P1X > v0X && P1X < l && P1Y < v0Y)
		if (P2X < v0X && P2Y < v0Y)
			printf(" \nSe descarta");
	if (P1X > v0X && P1X < l && P1Y < v0Y)
		if (P2X > l && P2Y < v0Y)
			printf(" \nSe descarta");





	if (P1X < v0X && P1Y < h && P1Y > v0Y)
		if (P1X < v0X && P1Y < h && P1Y > v0Y)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < h && P1Y > v0Y)
		if (P2X < v0X && P2Y > h)
			printf(" \nSe descarta");
	if (P1X < v0X && P1Y < h && P1Y > v0Y)
		if (P2X < v0X && P2Y < v0Y)
			printf(" \nSe descarta");




	if (P1X > l && P1Y < h && P1Y > v0Y && P1Y < h)
		if (P1X > l && P1Y < h && P1Y > v0Y && P1Y < h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h && P1Y > v0Y && P1Y < h)
		if (P2X > l && P2Y > h)
			printf(" \nSe descarta");
	if (P1X > l && P1Y < h && P1Y > v0Y && P1Y < h)
		if (P2X > l && P2Y < v0Y)
			printf(" \nSe descarta");



	//Calcula el punto de recorte con Liang-Barsky

		Usup = (((v0Y + h) - (P1Y)) / (P2Y - P1Y));
		Uinf = (((v0Y)-(P1Y)) / (P2Y - P1Y));
		Uizq = (((v0X)-(P1X)) / (P2X - P1X));
		Uder = (((v0X + l) - (P1X)) / (P2X - P1X));

		if (Usup >= 0 && Usup <= 1)
		{
			printf(" \n\n Su valor Usup es: %f", Usup);
			Xsup = (P1X + (Usup*(P2X - P1X)));
			printf("\n El punto de recorte se da en: (%f,%f)", Xsup, v0Y + l);
		}
		
		if (Uinf >= 0 && Uinf <= 1)
		{
			printf("\n\n Su valor Uinf es: %f", Uinf);
			Xinf = (P1X + Uinf * (P2X - P1X));
			printf(" \n El punto de recorte se da en: (%f,%f)", Xinf, v0Y);
		}

		if (Uizq >= 0 && Uizq <= 1)
		{
			printf("\n\n Su valor Uizq es: %f", Uizq);
			Yizq = (P1Y + Uizq * (P2Y - P1Y));
			printf("\n El punto de recorte se da en: (%f,%f)", v0X, Yizq);
		}

		if (Uder >= 0 && Uder <= 1)
		{
			printf("\n\n Su valor Uder es: %f", Uder);
			Yder = (P1Y + Uder * (P2Y - P1Y));
			printf(" \n El punto de recorte se da en: (%f,%f)", v0X + l, Yder);
		}


	




	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(800,800);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto 1"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;


}
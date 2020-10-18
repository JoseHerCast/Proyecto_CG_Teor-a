
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2(GLuint text, GLuint text2, int rep_u, int rep_v);
	void prismaM(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1);
	void lego_2X4(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1);
	void lego_2X2(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1);
	void lego_1X4(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1);
	void lego_1X2(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1);
	void torso(GLuint text, GLuint text2, GLuint text3);
	void pierna(GLfloat diffuse1[], GLfloat specular1[], GLfloat shininess1, GLfloat diffuse2[], GLfloat specular2[], GLfloat shininess2);
	void plano(GLuint text);
	void skybox(float altura, float largo, float profundidad, GLuint text);
	void texturaGUI(GLuint text);

};

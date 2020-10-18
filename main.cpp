//Semestre 2017 - 2
//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include <irrKlang.h>

using namespace irrklang;


//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

using namespace std;

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int velocidad_dia = 1;
float factor_dia = 0.5;
int vel_per = 10;
bool night = false;
bool luna = false;
bool step1 = true;
bool step2 = false;
bool step3 = true;
bool step4 = false;
bool movePer = false;
float x_lego_brick = 2.0;
float z_lego_brick = 1.0;
float y_lego_brick = 0.5;
float Ang_manecilla = 0.0;
float moveLuna[3] = { -200.0,0.0,90.0 };
float rotLuna = 0.0;
float _02rotLegDer = 0.0;
float _02rotLegIzq = 0.0;
char cadena_v[2] = "";
char vel_dia[30] = "";
float cuprotpieder = 0.0;
float cuprotpieizq = 0.0;
GLfloat _02ang = 0.0;
GLfloat cupang = 0.0;


//Camaras
CCamera objCamera;	//Create object camera 1
GLfloat initCamPos[] = { 0.0f,6.0f,6.0f };
CCamera objCamera2;	//Create object camera 2
GLfloat initCamPos2[] = { 0.0f,6.0f,6.0f };
CCamera freeCamera;	//Create object free camera
GLfloat initCamPos3[] = { 0.0f,6.0f,6.0f };
CCamera airCamera;	//Create object air camera
GLfloat initCamPos4[] = { 0.0f,25.0f,45.0f };
bool firstCharacter = true;
bool _3rdPerson = true;
bool freeC = false;
bool airC = false;
//bool secondCharacter = true;


GLfloat g_lookupdown = 0.0f;    // Look Position In The Y-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

int GLindices[40]={};

GLfloat LightAmbient[] = { 0.2f,0.2f,0.2f, 1.0f }; 			// Ambient Light Values
GLfloat LightPosition[] = { 1.0,1.0,0.0,0.0 };
GLfloat DayLightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };		// Diffuse Light Values
GLfloat DayLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };		// Specular Light Values

GLfloat NightLightDiffuse[] = { 0.3f, 0.3f, 0.3f, 1.0f };	// Diffuse Light Values
GLfloat NightLightSpecular[] = { 0.3, 0.3, 0.3, 1.0 };		// Specular Light Values

//Luz de reflector
//GLfloat LampDiffuse[] = { 0.91,1,0.07,1.0};
//GLfloat LampPosition[] = {0.0, 0.0, 0.0, 1.0 };
//GLfloat LampDirection[] = {0.25,-1.0,0.5};
//float LampCutOff = 45.0;
//float LampExponent = 5;

//Luz de farol1
GLfloat focoDiffuse[] = { 1.0f, 1.0f, 0.54f, 1.0f };
GLfloat focoSpecular[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat focoPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat focoDirection[] = { 1.0,0.0,0.0 };
GLfloat focoDirection1[] = { 0.0, -1.0, 0.0 };//Cyan
GLfloat focoDirection2[] = { 0.0,-1.0,0.0 };//verde
GLfloat focoDirection3[] = { 0.0,-1.0,0.0 };//rojo
GLfloat focoDirection4[] = { 0.0,-1.0,0.0 };//morado
//Material Diffusse foco
GLfloat materialfocoama[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat shininess = 0.0;

//Lampara 1
GLfloat materialfocyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat focoDiffusecyan[] = { 0.0f, 1.0f, 1.0f, 1.0f };
//Lampara 2
GLfloat materialfocoverde[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat focoDiffuseverde[] = { 0.0f, 1.0f, 0.0f, 1.0f };
//Lampara 3
GLfloat materialfocorojo[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat focoDiffuserojo[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//Lampara 4
GLfloat materialfocomora[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat focoDiffusemora[] = { 1.0f, 0.0f, 1.0f, 1.0f };

GLfloat _02DiffuseB[] = {0.0,0.0,0.0,1.0};
GLfloat _02DiffuseW[] = { 1.0,1.0,1.0,1.0 };
GLfloat _02DiffuseR[] = { 0.69,0.28,0.27,1.0 };
GLfloat _02DiffuseG[] = { 0.44,0.44,0.44,1.0 };
GLfloat _02DiffuseGr[] = { 0.03,0.17,0.04,1.0 };
GLfloat _02Specular[] = {0.3,0.3,0.3,1.0};
GLfloat _02Shininess = 10.0;

//Cuphead
GLfloat Diffusenegro[] = { 0.0,0.0,0.0,1.0 };
GLfloat Diffuseblanco[] = { 1.0,1.0,1.0,1.0 };
GLfloat Diffuserojo[] = { 1.0,0.0,0.0,1.0 };
GLfloat Diffusecafe[] = { 0.75,0.56,0.25,1.0 };
GLfloat Specularcup[] = { 0.3,0.3,0.3,1.0 };
GLfloat Shininesscup = 10.0;

//Texturas entorno 3D
CTexture t_sky; //Skybox
CTexture t_sky2; //Skybox
CTexture t_Street;	//Pavimento
CTexture t_Grass;	//Pasto01
CTexture t_Banqueta; //Banqueta
CTexture t_Street2;	//Pavimento
CTexture t_Grass2;	//Pasto01
CTexture t_Banqueta2; //Banqueta
CTexture t_Moon;
CTexture t_02_Front;//Textura 02 frente
CTexture t_02_Back;//Textura 02 trasera
CTexture t_02_Sides;//Textura 02 lateral
CTexture t_01_Front;//Textura cuphead frente
CTexture t_01_Back;//Textura cuphead trasera
CTexture t_01_Sides;//Textura cuphead lateral

//Texturas de la interfaz 2D en pantalla
CTexture clock;
CTexture manecilla;

//Figuras
CFiguras sky_cube;
CFiguras room_cube;
CFiguras suelo;
CFiguras Moon;
CFiguras Personaje1;
CFiguras Personaje2;
CFiguras Lego_brick;

//2D GUI
CFiguras Reloj;
CFiguras Manecilla;
//Modelos
CModel Shop;
CModel Bank;
CModel House;
CModel Temple;
CModel Tree;
CModel Lantern;
CModel Zero;
CModel ArmZero;
CModel Cuphead;
CModel ArmCup;
CModel Center;
CModel Trash;
CModel Arbusto;
CModel Arbusto2;
CModel Fuente;
CModel Lampara;

//Objetos de audio

bool Pause = false;
bool Alarma = false;
ISoundEngine* engine;
ISound* snd1;
ISound* snd2;
ISoundSource* jumpZ;
ISoundSource* rooster;
ISoundSource* cupson;

///NEW  Keyframes
float rotlamp1 = 0, rotlamp2 = 0, rotlamp3 = 0, rotlamp4 = 0;
int velgiro = 4;


#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	float rotlamp1;
	float rotlamp2;
	float rotlamp3;
	float rotlamp4;
	float rotinc1;
	float rotinc2;
	float rotinc3;
	float rotinc4;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;
bool play = false;
int playIndex = 0;

void Init_Key_Frame() {
	FrameIndex = 0;
	for (int i = 0; i < MAX_FRAMES; i++)
	{

		KeyFrame[i].rotlamp1 = 0;
		KeyFrame[i].rotlamp2 = 0;
		KeyFrame[i].rotlamp3 = 0;
		KeyFrame[i].rotlamp4 = 0;
		KeyFrame[i].rotinc1 = 0;
		KeyFrame[i].rotinc2 = 0;
		KeyFrame[i].rotinc3 = 0;
		KeyFrame[i].rotinc4 = 0;
	}
}
//Inicializamos el sistema de audio y comenzamos a reproducir el audio de fondo
void startAudio() {

	engine = createIrrKlangDevice();

	if (!engine) {
		printf("\nError al inciar el sistema de audio");
	}

	snd1 = engine->play2D("Audio/nostalgic.wav", true, false, true);
	snd2 = engine->play2D("Audio/electro.wav", true, true, true);
	//Inicializamos recursos de sonido
	jumpZ = engine->addSoundSourceFromFile("Audio/zeroJump.wav");
	jumpZ->setDefaultVolume(0.4);

	rooster = engine->addSoundSourceFromFile("Audio/rooster.wav");
	rooster->setDefaultVolume(0.4);

	cupson = engine->addSoundSourceFromFile("Audio/Cuphead.wav");
	cupson->setDefaultVolume(0.4);

}
//Esta función carga las texturas
void Texture_Load() {

	t_sky.LoadTGA("Textures/Sky/sky5.tga");
	t_sky.BuildGLTexture();
	t_sky.ReleaseImage();

	t_sky2.LoadTGA("Textures/Sky/sky6.tga");
	t_sky2.BuildGLTexture();
	t_sky2.ReleaseImage();

	t_Street.LoadTGA("Textures/LEGO/t_gray_l.tga");
	t_Street.BuildGLTexture();
	t_Street.ReleaseImage();
	GLindices[0] = t_Street.GLindex;

	t_Grass.LoadTGA("Textures/LEGO/t_green_l.tga");
	t_Grass.BuildGLTexture();
	t_Grass.ReleaseImage();
	GLindices[1] = t_Grass.GLindex;

	t_Banqueta.LoadTGA("Textures/LEGO/t_gray2_l.tga");
	t_Banqueta.BuildGLTexture();
	t_Banqueta.ReleaseImage();
	GLindices[2] = t_Banqueta.GLindex;

	t_Moon.LoadTGA("Textures/Objects/t_moon.tga");
	t_Moon.BuildGLTexture();
	t_Moon.ReleaseImage();

	t_02_Back.LoadTGA("Textures/02/t_back.tga");
	t_02_Back.BuildGLTexture();
	t_02_Back.ReleaseImage();

	t_02_Front.LoadTGA("Textures/02/t_front.tga");
	t_02_Front.BuildGLTexture();
	t_02_Front.ReleaseImage();

	t_02_Sides.LoadTGA("Textures/02/t_sides.tga");
	t_02_Sides.BuildGLTexture();
	t_02_Sides.ReleaseImage();

	t_01_Back.LoadTGA("Textures/01/t_back.tga");
	t_01_Back.BuildGLTexture();
	t_01_Back.ReleaseImage();

	t_01_Front.LoadTGA("Textures/01/t_front.tga");
	t_01_Front.BuildGLTexture();
	t_01_Front.ReleaseImage();

	t_01_Sides.LoadTGA("Textures/01/t_sides.tga");
	t_01_Sides.BuildGLTexture();
	t_01_Sides.ReleaseImage();

	//Texturas de noche
	t_Street2.LoadTGA("Textures/LEGO/t_gray_l4.tga");
	t_Street2.BuildGLTexture();
	t_Street2.ReleaseImage();

	t_Grass2.LoadTGA("Textures/LEGO/t_green2_l.tga");
	t_Grass2.BuildGLTexture();
	t_Grass2.ReleaseImage();

	t_Banqueta2.LoadTGA("Textures/LEGO/t_gray3_l.tga");
	t_Banqueta2.BuildGLTexture();
	t_Banqueta2.ReleaseImage();

	//Texturas de la interfaz en pantalla
	clock.LoadTGA("Textures/GUI/day_night_clock.tga");
	clock.BuildGLTexture();
	clock.ReleaseImage();

	manecilla.LoadTGA("Textures/GUI/manecilla.tga");
	manecilla.BuildGLTexture();
	manecilla.ReleaseImage();

}
//Esta función carga los modelos 3D
void Models_Load() {
	//Cargar el modelo
	Shop._3dsLoad("Models/Shop/Shop.3ds");
	Shop.LoadTextureImages();
	Shop.GLIniTextures();
	Shop.ReleaseTextureImages();

	Bank._3dsLoad("Models/Banca/Banca.3ds");
	Bank.LoadTextureImages();
	Bank.GLIniTextures();
	Bank.ReleaseTextureImages();

	House._3dsLoad("Models/Casa/Casa.3ds");
	House.LoadTextureImages();
	House.GLIniTextures();
	House.ReleaseTextureImages();

	Temple._3dsLoad("Models/Templo/Templo.3ds");
	Temple.LoadTextureImages();
	Temple.GLIniTextures();
	Temple.ReleaseTextureImages();

	Tree._3dsLoad("Models/Arbol/Arbol2.3ds");
	Tree.LoadTextureImages();
	Tree.GLIniTextures();
	Tree.ReleaseTextureImages();

	Lantern._3dsLoad("Models/Farol/Farol.3ds");
	Lantern.LoadTextureImages();
	Lantern.GLIniTextures();
	Lantern.ReleaseTextureImages();

	Zero._3dsLoad("Models/Personaje/Zero/Zero.3ds");
	Zero.LoadTextureImages();
	Zero.GLIniTextures();
	Zero.ReleaseTextureImages();

	ArmZero._3dsLoad("Models/Personaje/Zero/Brazo.3ds");
	ArmZero.LoadTextureImages();
	ArmZero.GLIniTextures();
	ArmZero.ReleaseTextureImages();

	Cuphead._3dsLoad("Models/Personaje/Cuphead/Cuphead.3ds");
	Cuphead.LoadTextureImages();
	Cuphead.GLIniTextures();
	Cuphead.ReleaseTextureImages();

	ArmCup._3dsLoad("Models/Personaje/Cuphead/Brazo.3ds");
	ArmCup.LoadTextureImages();
	ArmCup.GLIniTextures();
	ArmCup.ReleaseTextureImages();

	Trash._3dsLoad("Models/Bote/Bote.3ds");
	Trash.LoadTextureImages();
	Trash.GLIniTextures();
	Trash.ReleaseTextureImages();

	Arbusto._3dsLoad("Models/Arbusto/Arbusto.3ds");
	Arbusto.LoadTextureImages();
	Arbusto.GLIniTextures();
	Arbusto.ReleaseTextureImages();

	Arbusto2._3dsLoad("Models/Arbusto/Arbusto2.3ds");
	Arbusto2.LoadTextureImages();
	Arbusto2.GLIniTextures();
	Arbusto2.ReleaseTextureImages();

	Fuente._3dsLoad("Models/Fuente/Fuente.3ds");
	Fuente.LoadTextureImages();
	Fuente.GLIniTextures();
	Fuente.ReleaseTextureImages();

	Lampara._3dsLoad("Models/Lampara/Lampara.3ds");
	Lampara.LoadTextureImages();
	Lampara.GLIniTextures();
	Lampara.ReleaseTextureImages();
	
}
//Esta función crea y administra las luces.
void Luces() {
	
	//Luz principal del entorno
	glLightfv(GL_LIGHT0,GL_AMBIENT,LightAmbient);
	
	
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

	//Luz del foco1
	glLightfv(GL_LIGHT1, GL_DIFFUSE, focoDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, focoDirection);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.5);


	////Luz del foco2
	glLightfv(GL_LIGHT2, GL_DIFFUSE, focoDiffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, focoDirection);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 2.5);

	//Luz del foco3
	glLightfv(GL_LIGHT3, GL_DIFFUSE, focoDiffuseverde);
	glLightfv(GL_LIGHT3, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, focoDirection2);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 10);
	//glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 2.5);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 128);

	//Luz del foco4
	glLightfv(GL_LIGHT4, GL_DIFFUSE, focoDiffuserojo);
	glLightfv(GL_LIGHT4, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, focoDirection3);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10);
	//glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 2.5);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 128);

	//Luz del foco5
	glLightfv(GL_LIGHT5, GL_DIFFUSE, focoDiffusemora);
	glLightfv(GL_LIGHT5, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, focoDirection4);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 10);
	//glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 2.5);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 128);

	//Luz del foco6
	glLightfv(GL_LIGHT6, GL_DIFFUSE, focoDiffusecyan);
	glLightfv(GL_LIGHT6, GL_SPECULAR, NightLightSpecular);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, focoDirection1);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 10);
	////glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 2.5);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 128);

	if (night == true) {
		glLightfv(GL_LIGHT0, GL_DIFFUSE, NightLightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, NightLightSpecular);
	}
	else {
		glLightfv(GL_LIGHT0, GL_DIFFUSE, DayLightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, DayLightSpecular);
	}

	
	if (night == true) {
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		glEnable(GL_LIGHT6);
	
	}
	else {
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		glDisable(GL_LIGHT6);
	}

}
//Esta función oscurece las texturas
void Oscurecer() {
	
	t_Street.GLindex = t_Street2.GLindex;
	t_Grass.GLindex = t_Grass2.GLindex;
	t_Banqueta.GLindex = t_Banqueta2.GLindex;

}
//Esta función restaura el valor original del indice de la textura de día
void Restaurar_Indice() {
	
	t_Street.GLindex = GLindices[0];
	t_Grass.GLindex = GLindices[1];
	t_Banqueta.GLindex = GLindices[2];

}
//Esta funcion guarda el frame
void guardaFrame ()
{
	printf("frameindex %d\n", FrameIndex);



	KeyFrame[FrameIndex].rotlamp1 = rotlamp1;
	KeyFrame[FrameIndex].rotlamp2 = rotlamp2;
	KeyFrame[FrameIndex].rotlamp3 = rotlamp3;
	KeyFrame[FrameIndex].rotlamp4 = rotlamp4;

	FrameIndex++;
}
//Esta funcion sirve para resetear las rotaciones de las lamparas
void resetElements()
{


	rotlamp1 = KeyFrame[0].rotlamp1;
	rotlamp2 = KeyFrame[0].rotlamp2;
	rotlamp3 = KeyFrame[0].rotlamp3;
	rotlamp4 = KeyFrame[0].rotlamp4;

}
//Función de interpolación
void interpolacion()
{


	KeyFrame[playIndex].rotinc1 = (KeyFrame[playIndex + 1].rotlamp1 - KeyFrame[playIndex].rotlamp1) / i_max_steps;
	KeyFrame[playIndex].rotinc2 = (KeyFrame[playIndex + 1].rotlamp2 - KeyFrame[playIndex].rotlamp2) / i_max_steps;
	KeyFrame[playIndex].rotinc3 = (KeyFrame[playIndex + 1].rotlamp3 - KeyFrame[playIndex].rotlamp3) / i_max_steps;
	KeyFrame[playIndex].rotinc4 = (KeyFrame[playIndex + 1].rotlamp4 - KeyFrame[playIndex].rotlamp4) / i_max_steps;
}
//Esta función dibuja una estructura básica de piso
void Dibuja_suelo ()
{

		glPushMatrix();
			glScalef(40, 0.1, 7);
			suelo.prisma2(t_Street.GLindex, 0,3,1);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-25.5);
			glScalef(40,0.1,40);
			suelo.prisma2(t_Grass.GLindex, NULL, 5,5);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,25.5);
			glScalef(40,0.1,40);
			suelo.prisma2(t_Grass.GLindex,NULL, 5,5);
		glPopMatrix();

		glPushMatrix(); //Banqueta
			glTranslatef(0.0, 0.0, -4.5);
			glScalef(40, 0.1, 2);
			suelo.prisma2(t_Banqueta.GLindex, 0,20,1);
		glPopMatrix();

		glPushMatrix(); //Banqueta
			glTranslatef(0.0, 0.0,4.5);
			glScalef(40, 0.1, 2);
			suelo.prisma2(t_Banqueta.GLindex, 0,20,1);
		glPopMatrix();
}
//Esta función dibuja una plataforma de bloques LEGO y tamaño variable
void Dibuja_plataforma(int largo, int ancho, GLfloat diffuse[], GLfloat specular[], GLfloat shininess) {
	glPushMatrix();
		glTranslatef(0.0,y_lego_brick,0.0);
		Lego_brick.lego_2X4(diffuse,specular,shininess);
		glPushMatrix();
		for (int i = 0; i <largo; i++) {
			glTranslatef(0.0, 0.0, z_lego_brick);
			Lego_brick.lego_2X4(diffuse,specular,shininess);
		}
		glPopMatrix();
		glPushMatrix();
		for (int i = 0; i <largo; i++) {
			glTranslatef(0.0, 0.0, -z_lego_brick);
			Lego_brick.lego_2X4(diffuse,specular,shininess);
		}
		glPopMatrix();

		glPushMatrix();
			for (int j = 0; j <(ancho/2);j++) {
				glTranslatef(x_lego_brick, 0.0, 0.0);
				Lego_brick.lego_2X4(diffuse,specular,shininess);
				glPushMatrix();
				for (int i = 0; i <largo; i++) {
					glTranslatef(0.0, 0.0, z_lego_brick);
					Lego_brick.lego_2X4(diffuse,specular,shininess);
				}
				glPopMatrix();
				glPushMatrix();
				for (int i = 0; i <largo; i++) {
					glTranslatef(0.0, 0.0, -z_lego_brick);
					Lego_brick.lego_2X4(diffuse,specular,shininess);
				}
				glPopMatrix();
			}
		glPopMatrix();

		glPushMatrix();
			for (int j = 0; j <(ancho/2); j++) {
				glTranslatef(-x_lego_brick, 0.0, 0.0);
				Lego_brick.lego_2X4(diffuse,specular,shininess);
				glPushMatrix();
				for (int i = 0; i <largo; i++) {
					glTranslatef(0.0, 0.0, z_lego_brick);
					Lego_brick.lego_2X4(diffuse,specular,shininess);
				}
				glPopMatrix();
				glPushMatrix();
				for (int i = 0; i <largo; i++) {
					glTranslatef(0.0, 0.0, -z_lego_brick);
					Lego_brick.lego_2X4(diffuse,specular,shininess);
				}
				glPopMatrix();
			}
		glPopMatrix();
	glPopMatrix();
}
//Esta función dibuja una torre de bloques LEGO 2X4 de altura variable
void Dibuja_torre_2X4(int altura,GLfloat diffuse [], GLfloat specular [], GLfloat shininess){
	glPushMatrix();
		glTranslatef(0.0, y_lego_brick, 0.0);
		Lego_brick.lego_2X4(diffuse,specular,shininess);
		glPushMatrix();
		for (int i = 0; i < altura;i++) {
			glTranslatef(0.0, y_lego_brick, 0.0);
			Lego_brick.lego_2X4(diffuse,specular,shininess);
		}
		glPopMatrix();
	glPopMatrix();
}
//Esta función dibuja una torre de bloques LEGO 1X4 de altura variable
void Dibuja_torre_1X4(int altura, GLfloat diffuse[], GLfloat specular[], GLfloat shininess) {
	glPushMatrix();
		glTranslatef(0.0, y_lego_brick, 0.0);
		Lego_brick.lego_1X4(diffuse, specular, shininess);
		glPushMatrix();
			for (int i = 0; i < altura; i++) {
				glTranslatef(0.0, y_lego_brick, 0.0);
				Lego_brick.lego_1X4(diffuse, specular, shininess);
			}
		glPopMatrix();
	glPopMatrix();
}
//Esta función dibuja una torre de bloques LEGO 2X2 de altura variable
void Dibuja_torre_2X2(int altura, GLfloat diffuse[], GLfloat specular[], GLfloat shininess) {
	glPushMatrix();
		glTranslatef(0.0, y_lego_brick, 0.0);
		Lego_brick.lego_2X2(diffuse, specular, shininess);
		glPushMatrix();
			for (int i = 0; i < altura; i++) {
				glTranslatef(0.0, y_lego_brick, 0.0);
				Lego_brick.lego_2X2(diffuse, specular, shininess);
			}
		glPopMatrix();
	glPopMatrix();
}
//Esta función dibuja una torre de bloques LEGO 1X2 de altura variable
void Dibuja_torre_1X2(int altura, GLfloat diffuse[], GLfloat specular[], GLfloat shininess) {
	glPushMatrix();
	glTranslatef(0.0, y_lego_brick, 0.0);
	Lego_brick.lego_1X2(diffuse, specular, shininess);
	glPushMatrix();
	for (int i = 0; i < altura; i++) {
		glTranslatef(0.0, y_lego_brick, 0.0);
		Lego_brick.lego_1X2(diffuse, specular, shininess);
	}
	glPopMatrix();
	glPopMatrix();
}
//Esta función dibuja al personaje Zero-Two
void Dibuja_personaje() {

	glPushMatrix();//Dibuja Zero
		glDisable(GL_LIGHTING);
		Personaje1.torso(t_02_Front.GLindex,t_02_Back.GLindex,t_02_Sides.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0.0,-0.62,-0.0);
		glScalef(1.0,0.25,0.5);
		Personaje1.prismaM(_02DiffuseR, _02Specular, _02Shininess);
	glPopMatrix();
	//Piernas
	glPushMatrix();
		glTranslatef(0.08, -1.02, 0.0);
		glRotatef(_02rotLegDer, 1.0, 0.0, 0.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		glScalef(0.8, 1.2, 0.8);
		glScalef(0.35, 0.35, 0.35);
		Personaje1.pierna(_02DiffuseB, _02Specular, _02Shininess, _02DiffuseW, _02Specular, _02Shininess);
	glPopMatrix();
	glPushMatrix();
	/*	glRotatef(rotLeg,1.0,0.0,0.0);*/
		glTranslatef(-0.5, -1.02, 0.0);
		glRotatef(_02rotLegIzq, 1.0, 0.0, 0.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		glScalef(0.8, 1.2, 0.8);
		glScalef(0.35, 0.35, 0.35);
		Personaje1.pierna(_02DiffuseB, _02Specular, _02Shininess, _02DiffuseW, _02Specular, _02Shininess);
	glPopMatrix();
	//Cabeza
	glPushMatrix();
		glTranslatef(0.0, -1.7, 0.0);
		glDisable(GL_LIGHTING);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		Zero.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//Brazos
	glPushMatrix();
		glTranslatef(0.0, -2.0, -0.1);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		ArmZero.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
}
//Esta función dibuja al personaje Cuphead
void Dibuja_personaje2() {
	glPushMatrix();//Dibuja Cuphead
		glDisable(GL_LIGHTING);
		Personaje2.torso(t_01_Front.GLindex, t_01_Back.GLindex, t_01_Sides.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0.0, -0.62, -0.0);
		glScalef(1.0, 0.25, 0.5);
		Personaje2.prismaM(Diffuserojo, Specularcup, Shininesscup);
	glPopMatrix();
	//Piernas
	glPushMatrix();
		glTranslatef(0.08, -1.02, 0.0);
		glRotatef(cuprotpieder, 1.0, 0.0, 0.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		glScalef(0.8, 1.2, 0.8);
		glScalef(0.35, 0.35, 0.35);
		Personaje2.pierna(Diffuseblanco, Specularcup, Shininesscup, Diffusecafe, Specularcup, Shininesscup);
	glPopMatrix();
	glPushMatrix();
	/*	glRotatef(rotLeg,1.0,0.0,0.0);*/
		glTranslatef(-0.5, -1.02, 0.0);
		glRotatef(cuprotpieizq, 1.0, 0.0, 0.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		glScalef(0.8, 1.2, 0.8);
		glScalef(0.35, 0.35, 0.35);
		Personaje2.pierna(Diffuseblanco, Specularcup, Shininesscup, Diffusecafe, Specularcup, Shininesscup);
	glPopMatrix();
//Cabeza
	glPushMatrix();
		glTranslatef(0.0, -1.7, 0.0);
		glDisable(GL_LIGHTING);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		Cuphead.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
//Brazos
	glPushMatrix();
		glTranslatef(0.0, -2.0, -0.1);
		glDisable(GL_LIGHTING);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		ArmCup.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}
//Esta función dibuja la interfaz grafica 2D en pantalla
void OnScreen_GUI() {

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1.0,1.0,-1.0,1.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();

			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glPushMatrix();
				glTranslatef(0.8, 0.8, 0.0);
				glPushMatrix();
					glTranslatef(0.0,0.0,-0.1);
					glScalef(0.25,0.25,1.0);
					Reloj.texturaGUI(clock.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0,0.0,0.1);
					glRotatef(Ang_manecilla, 0.0, 0.0, 1.0);
					glScalef(0.15, 0.15, 1.0);
					Manecilla.texturaGUI(manecilla.GLindex);
				glPopMatrix();
			glPopMatrix();
			glDisable(GL_ALPHA_TEST);

			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_BLEND);
	
	
	Texture_Load();

	Models_Load();

	startAudio();

	//END NEW//////////////////////////////
	//Posicion y dirección de la camara inicial

	objCamera.Position_Camera(initCamPos[0], initCamPos[1], initCamPos[2], 0, 2.0f, 0, 0, 1, 0);
	objCamera2.Position_Camera(initCamPos2[0], initCamPos2[1], initCamPos2[2], 0, 2.0f, 0, 0, 1, 0);
	freeCamera.Position_Camera(initCamPos3[0], initCamPos3[1], initCamPos3[2], 0, 2.0, 0, 0, 1, 0);
	airCamera.Position_Camera(initCamPos4[0], initCamPos4[1], initCamPos4[2], 0, 0, 0, 0, 1, 0);

	//NEW Iniciar variables de KeyFrames
	
	Init_Key_Frame();
}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}
///Función de submenú con opciones
void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex < MAX_FRAMES)
		{
			guardaFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex > 1)
		{

			resetElements();
			//First Interpolation
			interpolacion();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;
	case 2: //Reset buffer
		Init_Key_Frame();


	}
}
//Función de menu principal
void menu(int id)
{

}
//Esta función dibuja el kiosko
void kiosco()
{
	//Aqui comienza la construcción del kiosko
			glPushMatrix();//Plataforma principal
				glPushMatrix();
					glPushMatrix();
						Dibuja_plataforma(2,2, _02DiffuseG, _02Specular, _02Shininess);
						for (int i = 0; i < 4;i++) {
							glTranslatef(0.0, y_lego_brick, 0.0);
							Dibuja_plataforma(2,2, _02DiffuseG, _02Specular, _02Shininess);
						}
					glPopMatrix();
					glPushMatrix();
						glTranslatef(z_lego_brick * 3.5,0.0,0.0);
						glPushMatrix();
							glTranslatef(0.0,0.0,x_lego_brick*0.75);
							glRotatef(90,0.0,1.0,0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0.0, 0.0, -x_lego_brick * 0.25);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(z_lego_brick, 0.0, x_lego_brick*0.25);
						glRotatef(90, 0.0, 1.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(-z_lego_brick * 3.5, 0.0, 0.0);
						glPushMatrix();
							glTranslatef(0.0, 0.0, x_lego_brick * 0.75);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0.0, 0.0, -x_lego_brick * 0.25);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(-z_lego_brick, 0.0, x_lego_brick * 0.25);
						glRotatef(90, 0.0, 1.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0,0.0, -z_lego_brick * 3);
						glPushMatrix();
							glTranslatef(x_lego_brick/2,0.0,0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(-x_lego_brick / 2, 0.0, 0.0);
							Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(0.0,0.0,-z_lego_brick);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

				glPopMatrix();
				
				glPushMatrix();//Escaleras
					glTranslatef(0.0,0.0,z_lego_brick*3);
					Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPushMatrix();
						glTranslatef(-x_lego_brick, 0.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick, 0.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glTranslatef(0.0, 0.0, z_lego_brick);
					glPushMatrix();
						glTranslatef(-x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(4, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glTranslatef(0.0, 0.0, z_lego_brick);
					glPushMatrix();
						glTranslatef(-x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(3, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(3, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glTranslatef(0.0, 0.0, z_lego_brick);
					glPushMatrix();
						glTranslatef(-x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(2, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(2, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glTranslatef(0.0, 0.0, z_lego_brick);
					glPushMatrix();
						glTranslatef(-x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(1, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(1, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();

					glTranslatef(0.0, 0.0, z_lego_brick);
					glPushMatrix();
						glTranslatef(-x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(0, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(x_lego_brick/2, 0.0, 0.0);
						Dibuja_torre_2X4(0, _02DiffuseG, _02Specular, _02Shininess);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();//Barrotes
					glTranslatef(x_lego_brick*1.75,y_lego_brick*5,z_lego_brick*2);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-x_lego_brick * 1.75, y_lego_brick * 5, -z_lego_brick );
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(x_lego_brick * 1.75, y_lego_brick * 5, -z_lego_brick );
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-x_lego_brick * 1.75, y_lego_brick * 5, z_lego_brick * 2);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-x_lego_brick*0.75 , y_lego_brick * 5, -z_lego_brick * 3);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(x_lego_brick * 0.75, y_lego_brick * 5, -z_lego_brick * 3);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-x_lego_brick * 0.75, y_lego_brick * 5, z_lego_brick * 4);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(x_lego_brick * 0.75, y_lego_brick * 5, z_lego_brick * 4);
					Dibuja_torre_2X2(10, _02DiffuseGr, _02Specular, _02Shininess);
				glPopMatrix();

				glPushMatrix();//Techo
					glTranslatef(0.0, y_lego_brick * 16, 0.0);
					glPushMatrix();//primer capa
						Dibuja_plataforma(2, 2, _02DiffuseGr, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0,0.0,z_lego_brick*5);
						Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(z_lego_brick * 3.5, 0.0, 0.0);
						glPushMatrix();
							glTranslatef(0.0, 0.0, x_lego_brick * 0.75);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0.0, 0.0, -x_lego_brick * 0.25);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(z_lego_brick, 0.0, x_lego_brick * 0.25);
						glRotatef(90, 0.0, 1.0, 0.0);
						Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(-z_lego_brick * 3.5, 0.0, 0.0);
						glPushMatrix();
							glTranslatef(0.0, 0.0, x_lego_brick * 0.75);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0.0, 0.0, -x_lego_brick * 0.25);
							glRotatef(90, 0.0, 1.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(-z_lego_brick, 0.0, x_lego_brick * 0.25);
						glRotatef(90, 0.0, 1.0, 0.0);
						Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, 0.0, -z_lego_brick * 3);
						glPushMatrix();
							glTranslatef(x_lego_brick / 2, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(-x_lego_brick / 2, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(0.0, 0.0, -z_lego_brick);
						Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0, 0.0, z_lego_brick * 3);
						Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPushMatrix();
							glTranslatef(-x_lego_brick, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(x_lego_brick, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glTranslatef(0.0, 0.0, z_lego_brick);
						glPushMatrix();
							glTranslatef(-x_lego_brick / 2, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(x_lego_brick / 2, 0.0, 0.0);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
					glPopMatrix();
					
					glPushMatrix();//Segunda capa
						
						glTranslatef(x_lego_brick*0.25,y_lego_brick,0.0);
						Dibuja_plataforma(1, 1, _02DiffuseGr, _02Specular, _02Shininess);
						glPushMatrix();
							glTranslatef(-x_lego_brick*0.25, 0.0, z_lego_brick * 4.5);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0.0,0.0,-z_lego_brick*2);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick*0.75,0.0,0.0);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(0.0,0.0,z_lego_brick*0.75);
							Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick*0.5, 0.0, -z_lego_brick*0.25);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0.0,0.0,-z_lego_brick*2.75);
							glPushMatrix();
								glTranslatef(x_lego_brick * 0.25, 0.0, 0.0);
								Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-x_lego_brick*0.25,0.0,0.0);
								Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-x_lego_brick * 0.75, 0.0, 0.0);
								Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-x_lego_brick*0.25, 0.0, -z_lego_brick*0.75);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();
							glTranslatef(z_lego_brick*1.5,0.0,0.0);
							glPushMatrix();
								glRotatef(90,0.0,1.0,0.0);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(z_lego_brick, 0.0, 0.0);
								glRotatef(90, 0.0, 1.0, 0.0);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(x_lego_brick*0.5,0.0,z_lego_brick*1.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(x_lego_brick, 0.0, z_lego_brick*0.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(0.0, 0.0, z_lego_brick * 1.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPushMatrix();
									glTranslatef(0.0,0.0,z_lego_brick);
									Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
								glPushMatrix();
									glTranslatef(0.0, 0.0, -z_lego_brick*3);
									Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
							glPopMatrix();

						glPopMatrix();

						glPushMatrix();
							glTranslatef(0.0, 0.0, z_lego_brick * 2);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick * 0.75, 0.0, 0.0);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(0.0, 0.0, -z_lego_brick * 0.75);
							Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick * 0.5, 0.0, z_lego_brick * 0.25);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(0.0, 0.0, z_lego_brick);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick * 0.5, 0.0, -z_lego_brick);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(-x_lego_brick * 0.5, 0.0, -z_lego_brick);
							Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(-z_lego_brick * 1.5, 0.0, 0.0);
							glPushMatrix();
								glRotatef(90, 0.0, 1.0, 0.0);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-z_lego_brick, 0.0, 0.0);
								glRotatef(90, 0.0, 1.0, 0.0);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-z_lego_brick*2, 0.0, 0.0);
								glRotatef(90, 0.0, 1.0, 0.0);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0.0, 0.0, z_lego_brick * 2.75);
							Dibuja_torre_1X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glTranslatef(0.0, 0.0, z_lego_brick*0.75);
							Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPushMatrix();
								glTranslatef(-x_lego_brick*0.75, 0.0, 0.0);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glTranslatef(0.0,0.0,-z_lego_brick*0.75);
								Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();//Tercera capa
							glTranslatef(-x_lego_brick*0.25, y_lego_brick, z_lego_brick*0.5);
							Dibuja_plataforma(1, 1, _02DiffuseGr, _02Specular, _02Shininess);

							glPushMatrix();
								glTranslatef(0.0,0.0,-z_lego_brick*2);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glTranslatef(0.0,0.0,-z_lego_brick*0.75);
								Dibuja_torre_1X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(0.0, 0.0, z_lego_brick * 2);
								Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glTranslatef(0.0, 0.0, z_lego_brick * 0.75);
								Dibuja_torre_1X4(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(z_lego_brick*1.5,0.0,0.0);
								glPushMatrix();
									glRotatef(90,0.0,1.0,0.0);
									Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
								glTranslatef(z_lego_brick,0.0,0.0);
								glPushMatrix();
									glRotatef(90, 0.0, 1.0, 0.0);
									Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-z_lego_brick * 1.5, 0.0, 0.0);
								glPushMatrix();
									glRotatef(90, 0.0, 1.0, 0.0);
									Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
								glTranslatef(-z_lego_brick, 0.0, 0.0);
								glPushMatrix();
									glRotatef(90, 0.0, 1.0, 0.0);
									Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();
							glPopMatrix();

							glPushMatrix();
								glTranslatef(x_lego_brick*0.75,0.0,z_lego_brick*1.5);
								Dibuja_torre_2X2(0,_02DiffuseGr,_02Specular,_02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(-x_lego_brick * 0.75, 0.0, z_lego_brick * 1.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(-x_lego_brick * 0.75, 0.0, -z_lego_brick * 1.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(x_lego_brick * 0.75, 0.0, -z_lego_brick * 1.5);
								Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
							glPopMatrix();

							glPushMatrix();//cuarte capa
								glTranslatef(0.0,y_lego_brick,0.0);
								Dibuja_plataforma(1,1,_02DiffuseGr,_02Specular,_02Shininess);
								glPushMatrix();
									glTranslatef(z_lego_brick * 1.25,0.0,0.0);
									glPushMatrix();
										glTranslatef(0.0,0.0,x_lego_brick*0.25);
										glRotatef(90,0.0,1.0,0.0);
										Dibuja_torre_1X4(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(0.0, 0.0, -x_lego_brick * 0.5);
										glRotatef(90, 0.0, 1.0, 0.0);
										Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(z_lego_brick*0.75, 0.0, 0.0);
										Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
								glPopMatrix();

								glPushMatrix();
									glTranslatef(-z_lego_brick * 1.25, 0.0, 0.0);
									glPushMatrix();
										glTranslatef(0.0, 0.0, x_lego_brick * 0.25);
										glRotatef(90, 0.0, 1.0, 0.0);
										Dibuja_torre_1X4(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(0.0, 0.0, -x_lego_brick * 0.5);
										glRotatef(90, 0.0, 1.0, 0.0);
										Dibuja_torre_1X2(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(-z_lego_brick * 0.75, 0.0, 0.0);
										Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
								glPopMatrix();

								glPushMatrix();
									glTranslatef(0.0,0.0,z_lego_brick*2);
									Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();

								glPushMatrix();
									glTranslatef(0.0, 0.0, -z_lego_brick * 2);
									Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
								glPopMatrix();

								glPushMatrix();//quinta capa
									glTranslatef(0.0, y_lego_brick,0.0);
									glPushMatrix();
										glTranslatef(0.0,0.0,z_lego_brick*0.5);
										Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(0.0, 0.0, -z_lego_brick * 0.5);
										Dibuja_torre_2X4(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
									
									glPushMatrix();//Punta
										glTranslatef(0.0,y_lego_brick,0.0);
										Dibuja_torre_2X2(0, _02DiffuseGr, _02Specular, _02Shininess);
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			//Aqui termina la construcción del kiosko
}
//Función de dibujo
void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	//Llamar a crear luces

	Luces();

	if (night == true) {
		Oscurecer();
	}
	else {
		Restaurar_Indice();
	}
		
	glPushMatrix();

		glRotatef(g_lookupdown, 1.0f, 0, 0);

		if (_3rdPerson == true) {
			if (firstCharacter == true) {
				gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
					objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			}
			else {
				gluLookAt(objCamera2.mPos.x, objCamera2.mPos.y, objCamera2.mPos.z,
					objCamera2.mView.x, objCamera2.mView.y, objCamera2.mView.z,
					objCamera2.mUp.x, objCamera2.mUp.y, objCamera2.mUp.z);
			}
		}
		else if (freeC == true) {
			gluLookAt(freeCamera.mPos.x, freeCamera.mPos.y, freeCamera.mPos.z,
				freeCamera.mView.x, freeCamera.mView.y, freeCamera.mView.z,
				freeCamera.mUp.x, freeCamera.mUp.y, freeCamera.mUp.z);
		}
		else if (airC == true) {
			gluLookAt(airCamera.mPos.x, airCamera.mPos.y, airCamera.mPos.z,
				airCamera.mView.x, airCamera.mView.y, airCamera.mView.z,
				airCamera.mUp.x, airCamera.mUp.y, airCamera.mUp.z);
		}
		glPushMatrix();		

		
			glPushMatrix(); //Se pinta el cielo
				glDisable(GL_LIGHTING);
				if (night == true) {
					sky_cube.skybox(1000.0, 500.0, 500.0, t_sky2.GLindex);
				}
				else {
					sky_cube.skybox(1000.0, 500.0, 500.0, t_sky.GLindex);
				}
				
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();//Se dibuja_suelo
				glDisable(GL_LIGHTING);
				glPushMatrix();
					glTranslatef(25.5,0.0,0.0);
					Dibuja_suelo();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0,0.0,-24.5);
					glPushMatrix(); //Banqueta
						glTranslatef(-4.5, 0.0, 0.0);
						glScalef(2, 0.1, 42);
						suelo.prisma2(t_Banqueta.GLindex, 0, 1, 20);
					glPopMatrix();
					glPushMatrix();//asfalto
						glScalef(7, 0.1, 42);
						glRotatef(90.0, 0.0, 1.0, 0.0);
						suelo.prisma2(t_Street.GLindex, 0, 3, 1);
					glPopMatrix();
					glPushMatrix(); //Banqueta
						glTranslatef(4.5, 0.0, 0.0);
						glScalef(2, 0.1, 42);
						suelo.prisma2(t_Banqueta.GLindex, 0, 1, 20);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//asfalto
					glScalef(11, 0.1, 7);
					suelo.prisma2(t_Street.GLindex, 0, 1, 1);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0, 0.0, 24.5);
					glPushMatrix(); //Banqueta
						glTranslatef(-4.5, 0.0, 0.0);
						glScalef(2, 0.1, 42);
						suelo.prisma2(t_Banqueta.GLindex, 0, 1, 20);
					glPopMatrix();
					glPushMatrix();//asfalto
						glScalef(7, 0.1, 42);
						glRotatef(90.0, 0.0, 1.0, 0.0);
						suelo.prisma2(t_Street.GLindex, 0, 3, 1);
					glPopMatrix();
					glPushMatrix(); //Banqueta
						glTranslatef(4.5, 0.0, 0.0);
						glScalef(2, 0.1, 42);
						suelo.prisma2(t_Banqueta.GLindex, 0, 1, 20);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-25.5, 0.0, 0.0);
					Dibuja_suelo();
				glPopMatrix();
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			//glPushMatrix();
			//	kiosco();
			//glPopMatrix();

			//Renderizado de personajes
			glPushMatrix();
				glTranslatef(objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
				glRotatef(_02ang, 0.0, 1.0, 0.0);
				Dibuja_personaje();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(objCamera2.mView.x, objCamera2.mView.y, objCamera2.mView.z);
				glRotatef(cupang, 0.0, 1.0, 0.0);
				Dibuja_personaje2();
			glPopMatrix();

			if (night == true) {
				glPushMatrix();
					glTranslatef(moveLuna[0], moveLuna[1], moveLuna[2]);
					glRotatef(rotLuna, 0.0, 1.0, 0.0);
					glRotatef(90, 0.0, 1.0, 0.0);
					glScalef(10.0, 10.0, 10.0);
					glDisable(GL_LIGHTING);
					Moon.esfera(1.0, 15, 15, t_Moon.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
			}

			//Aqui empieza el renderizado de los modelos que no son personajes.
			if (night == true) {
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else {
				glBlendFunc(GL_ONE, GL_ZERO);
			}

			glPushMatrix();//Street Furniture en X
				//Botes de basura
				glPushMatrix();
					glTranslatef(22.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(21.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(35.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(34.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				//Bancas
				glPushMatrix();
					glTranslatef(18.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(18.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Se implementan luces
				glPushMatrix();
				glTranslatef(10.0, 2.0, 10.0);
				glLightfv(GL_LIGHT1, GL_POSITION, focoPosition);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-10.0, 2.0, -10.0);
				glLightfv(GL_LIGHT2, GL_POSITION, focoPosition);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				//Faroles
				glPushMatrix();
					glTranslatef(12.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(12.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Arbustos
				glPushMatrix();
					glTranslatef(18.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(18.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//Street Furniture en -Z
				glRotatef(90,0.0,1.0,0.0);

				//Botes de basura
				glPushMatrix();
					glTranslatef(22.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(21.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(35.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(34.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				//Bancas
				glPushMatrix();
					glTranslatef(18.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(18.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Se implementan luces
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				//Faroles
				glPushMatrix();
					glTranslatef(12.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(12.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Arbustos
				glPushMatrix();
					glTranslatef(18.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(18.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//Street Furniture en Z
				glRotatef(-90,0.0,1.0,0.0);

				//Botes de basura
				glPushMatrix();
					glTranslatef(22.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(21.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(35.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(34.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				//Bancas
				glPushMatrix();
					glTranslatef(18.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(18.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Se implementan luces
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				//Faroles
				glPushMatrix();
					glTranslatef(12.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(12.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(25.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Arbustos
				glPushMatrix();
					glTranslatef(18.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(18.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//Street Furniture en -X
				glRotatef(180,0.0,1.0,0.0);
				//Botes de basura
				glPushMatrix();
					glTranslatef(22.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(21.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(35.0, 0.0, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(34.5, 0.0, 6.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Trash.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				//Bancas
				glPushMatrix();
					glTranslatef(18.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, -6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(18.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(31.7, 0.8, 6.9);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					Bank.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Se implementan luces
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(12.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(25.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, -5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoama);
					glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoama);
					glMaterialf(GL_FRONT, GL_SHININESS, shininess);
					glTranslatef(38.0, 5.5, 5.0);
					glutSolidSphere(0.2, 50, 50);
				glPopMatrix();

				//Faroles
				glPushMatrix();
					glTranslatef(12.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(12.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(25.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(25.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(38.0, 0.0, 5.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lantern.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Arbustos
				glPushMatrix();
					glTranslatef(18.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(18.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, 8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(31.7, -0.5, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					Arbusto.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();

			//Entorno Templo
			glPushMatrix();
				glPushMatrix();
					glTranslatef(114.0, 7.3, -162.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-20.0, 0.0, 1.0, 0.0);
					Temple.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
						glTranslatef(10.0, 0.2, -35.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(30.0, 0.2, -8.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(12.0, 0.2, -15.0);
					glRotatef(45,0.0,1.0,0.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Arbusto2.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
			glPopMatrix();

			//Entorno Shop 
			glPushMatrix();
				glPushMatrix();
					glTranslatef(-40.0, -18.5, -10.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(90.0, 0.0, 1.0, 0.0);
					Shop.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-40.0, 0.2, -10.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-45.0, 0.2, -25.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-35.0, 0.2, -35.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-20.0, 0.2, -30.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
			glPopMatrix();

			//Entorno casa
			glPushMatrix();
				glPushMatrix();
					glTranslatef(-45.0, -20.7, -60.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(-50.0, 0.0, 1.0, 0.0);
					House.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-40.0, 0.2, 20.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-20.0, 0.2, 40.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-35.0, 0.2, 45.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-45.0, 0.2, 35.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//Lamparas kiosco
				glPushMatrix();
					glTranslatef(0.0, 7.4, -3.5);
					glRotatef(0.0+rotlamp1, 0.0, 1.0, 0.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lampara.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
					glPushMatrix();
						glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocyan);
						glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocyan);
						glMaterialf(GL_FRONT, GL_SHININESS, shininess);
						glTranslatef(0.0, -1.0, 1.0);
						glutSolidSphere(0.8, 50, 50);
						glLightfv(GL_LIGHT6, GL_POSITION, focoPosition);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-3.9, 7.4, 0.5);
					glRotatef(90+rotlamp2, 0.0, 1.0, 0.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lampara.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
					glPushMatrix();
						glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocorojo);
						glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocorojo);
						glMaterialf(GL_FRONT, GL_SHININESS, shininess);
						glTranslatef(0.0, -1.0, 1.0);
						glutSolidSphere(0.8, 50, 50);
						glLightfv(GL_LIGHT4, GL_POSITION, focoPosition);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 7.4, 4.0);
					glRotatef(180+rotlamp3, 0.0, 1.0, 0.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lampara.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
					glPushMatrix();
						glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocoverde);
						glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocoverde);
						glMaterialf(GL_FRONT, GL_SHININESS, shininess);
						glTranslatef(0.0, -1.0, 1.0);
						glutSolidSphere(0.8, 50, 50);
						glLightfv(GL_LIGHT3, GL_POSITION, focoPosition);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(3.9, 7.4, 0.5);
					glRotatef(270.0+rotlamp4, 0.0, 1.0, 0.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Lampara.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
					glPushMatrix();
						glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialfocomora);
						glMaterialfv(GL_FRONT, GL_SPECULAR, materialfocorojo);
						glMaterialf(GL_FRONT, GL_SHININESS, shininess);
						glTranslatef(0.0, -1.0, 1.0);
						glutSolidSphere(0.8, 50, 50);
						glLightfv(GL_LIGHT5, GL_POSITION, focoPosition);
					glPopMatrix();
				glPopMatrix();

			glPopMatrix(); 
		glPopMatrix(); 

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//Entorno Feuente
			glPushMatrix();
				glRotatef(180,0.0,1.0,0.0);
				glPushMatrix();
					glTranslatef(-20.0, 0.0, -20.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					glRotatef(90.0, 0.0, 1.0, 0.0);
					Fuente.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(-40.0, 0.2, -10.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-45.0, 0.2, -25.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-35.0, 0.2, -35.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-20.0, 0.2, -30.0);
					glDisable(GL_LIGHTING);
					glScalef(0.2, 0.2, 0.2);
					Tree.GLrender(NULL, _SHADED, 1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();
	
			glPopMatrix();
	glPopMatrix();



	//Aqui se dibuja la GUI en 2D
	glDisable(GL_LIGHTING);
	
	OnScreen_GUI();

	glEnable(GL_LIGHTING);
	//Se pinta el texto con la velocidad del dia
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(0.97, 0.53, 0.09);
	_itoa((velocidad_dia), cadena_v, 10);
	strcpy(vel_dia, "Velocidad del dia X ");
	strcat(vel_dia, cadena_v);
	pintaTexto(-14, 12.0, -14.0, (void*)font, vel_dia);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );
}

void animacion()
{
	//Animación del reloj de dia/noche
	if (Ang_manecilla > -360) {
		Ang_manecilla -= factor_dia * velocidad_dia;
		if (Ang_manecilla > -180) {
			night = false;
		}
		else {
			night = true;
		}
	}
	else {
		Ang_manecilla = 0.0;
		engine->play2D(rooster);
	}

	//Animación Luna

	if (night == true) {//La nube voladora solo aparece durante el día
		luna = true;
		if (luna == true) {
			moveLuna[2] -= 0.1 * velocidad_dia;
			rotLuna += 0.1;
			moveLuna[1] = 200 - pow(moveLuna[2], 2) / 300;//Trayectoria parabólica
		}
	}
	else {
		luna = false;
		moveLuna[2] = 90.0;
		if (rotLuna > 360) {
			rotLuna = 0.0;
		}
	}


	//Animación piernas personaje1

	if (_3rdPerson == true && firstCharacter == true && movePer == true)
	{
		if (step1)
		{
			_02rotLegDer += 1 * vel_per;
			_02rotLegIzq -= 1 * vel_per;
			if (_02rotLegDer >= 40)
			{
				step1 = false;
				step2 = true;
			}
		}
		if (step2)
		{
			_02rotLegDer -= 1 * vel_per;
			_02rotLegIzq += 1 * vel_per;
			if (_02rotLegDer <= -40)
			{
				step2 = false;
				step1 = true;

			}
		}
		movePer = false;
	}
	else if (_3rdPerson == true && firstCharacter == false && movePer == true) 
	{
		if (step3)
		{
			cuprotpieder += 1 * vel_per;
			cuprotpieizq -= 1 * vel_per;
			if (cuprotpieder >= 40)
			{
				step3 = false;
				step4 = true;
			}
		}
		if (step4)
		{
			cuprotpieder -= 1 * vel_per;
			cuprotpieizq += 1 * vel_per;
			if (cuprotpieder <= -40)
			{
				step4 = false;
				step3 = true;

			}
		}
		movePer = false;
	}

	//Cámara aerea
	if (airC == true) {
		airCamera.Rotate_Camera(0.01);
	}

	//Movimiento lamparas
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2) //end total animation?
			{
				printf("Termina animacion \n");
				playIndex = 0;
				play = false;
			}
			else
			{
				i_curr_steps = 0;
				//Interpolation
				interpolacion();
			}
		}
		else
		{
			//Draw animation
			rotlamp1 += KeyFrame[playIndex].rotinc1;
			rotlamp2 += KeyFrame[playIndex].rotinc2;
			rotlamp3 += KeyFrame[playIndex].rotinc3;
			rotlamp4 += KeyFrame[playIndex].rotinc4;
	

			i_curr_steps++;
		}
	}
	glutPostRedisplay();

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 2000.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		if (_3rdPerson == true) {
			movePer = true;
			if (firstCharacter == true) {
				objCamera.Move_Camera(CAMERASPEED + 0.2);
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);
			}
			else {
				objCamera2.Move_Camera(CAMERASPEED + 0.2);
			}
		}
		else if (freeC == true) {
			freeCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		break;

	case 's':
	case 'S':
		if (_3rdPerson == true) {
			movePer = true;
			if (firstCharacter == true) {
				objCamera.Move_Camera(-(CAMERASPEED + 0.2));
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);
			}
			else {
				objCamera2.Move_Camera(-(CAMERASPEED + 0.2));
			}
		}
		else if (freeC == true) {
			freeCamera.Move_Camera(-(CAMERASPEED + 0.2));
		}
		break;

	case 'a':
	case 'A':

		if (_3rdPerson == true) {
			if (firstCharacter == true) {
				objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);
			}
			else {
				objCamera2.Strafe_Camera(-(CAMERASPEED + 0.4));
			}
		}
		else if (freeC == true) {
			freeCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		}
		break;

	case 'd':
	case 'D':

		if (_3rdPerson == true) {
			if (firstCharacter == true) {
				objCamera.Strafe_Camera(CAMERASPEED + 0.4);
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);
			}
			else {
				objCamera2.Strafe_Camera(CAMERASPEED + 0.4);
			}
		}
		else if (freeC == true) {
			freeCamera.Strafe_Camera(CAMERASPEED + 0.4);
		}
		break;

	case '+':
		if (velocidad_dia >= 10) {
			velocidad_dia += 0;
		}
		else {
			velocidad_dia += 1;
		}
		break;

	case '-':
		if (velocidad_dia < 2) {
			velocidad_dia -= 0;
		}
		else {
			velocidad_dia -= 1;
		}
		break;

	case 'p':
	case 'P':

		Pause ^= true;
		////Aqui llamamos a la función para pausar/reanudar el audio
		snd1->setIsPaused(Pause);
		//snd2->setIsPaused(!Pause);
		break;
	case 'j':
	case 'J':
		Init_Key_Frame();
		break;
	case 'l':
	case 'L':
		if (play == false && (FrameIndex > 1))
		{

			resetElements();
			//First Interpolation				
			interpolacion();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;

	case 'k'://
	case 'K':
		if (FrameIndex < MAX_FRAMES)
		{
			guardaFrame();
		}

		break;
		//Activar o desactivar camara aerea
	case 'g':
	case 'G':
		if (_3rdPerson == true) {

			_3rdPerson = false;
			airC = true;
		}
		else if (freeC == true) {
			freeC = false;
			airC = true;
		}
		else {
			_3rdPerson = true;
			if (firstCharacter == true) {
				engine->play2D(jumpZ);
			}
			else {
				engine->play2D(cupson);
			}
			freeC = false;
			airC = false;
		}
		break;
		//Activar o desactivr camara libre
	case 'f':
	case 'F':
		if (_3rdPerson == true) {

			_3rdPerson = false;
			freeC = true;
		}
		else if (airC == true) {
			airC = false;
			freeC = true;
		}
		else {
			_3rdPerson = true;
			if (firstCharacter == true) {
				engine->play2D(jumpZ);
			}
			else {
				engine->play2D(cupson);
			}
			freeC = false;
			airC = false;
		}
		break;

	case 'c':
	case 'C':
		firstCharacter ^= true;
		if (firstCharacter == true) {
			_3rdPerson = true;
			freeC = false;
			airC = false;
			engine->play2D(jumpZ);
		}
		else {
			_3rdPerson = true;
			freeC = false;
			airC = false;
			engine->play2D(cupson);
		}
		
		break;

	case 'v':
		if (rotlamp1>-45) {
			rotlamp1 -= velgiro;
		}
		printf("%f \n", rotlamp1);
		break;

	case 'V':
		if (rotlamp1<45) {
			rotlamp1 += velgiro;
		}
		printf("%f \n", rotlamp1);
		break;

	case 'b':
		if (rotlamp2>-45) {
			rotlamp2 -= velgiro;
		}
		printf("%f \n", rotlamp2);
		break;

	case 'B':
		if (rotlamp2<45) {
			rotlamp2 += velgiro;
		}
		printf("%f \n", rotlamp2);
		break;

	case 'n':
		if (rotlamp3>-45) {
			rotlamp3 -= velgiro;
		}
		printf("%f \n", rotlamp3);
		break;

	case 'N':
		if (rotlamp3<45) {
			rotlamp3 += velgiro;
		}
		printf("%f \n", rotlamp3);
		break;

	case 'm':
		if (rotlamp4 > -45) {
			rotlamp4 -= velgiro;
		}
		printf("%f \n", rotlamp4);
		break;

	case 'M':
		if (rotlamp4 < 45) {
			rotlamp4 += velgiro;
		}
		printf("%f \n", rotlamp4);
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		if (freeC == true) {
			freeCamera.UpDown_Camera(CAMERASPEED);
		}
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (freeC == true) {
			freeCamera.UpDown_Camera(-CAMERASPEED);
		}
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		if (_3rdPerson == true) {
			if (firstCharacter == true) {
				objCamera.Rotate_Camera(-CAMERASPEED);
				printf("\nCoordenadas de la camara: %f, %f", objCamera.mPos.x, objCamera.mPos.z);
				_02ang += atan(CAMERASPEED) * 180 / IK_PI32;
			}
			else {
				objCamera2.Rotate_Camera(-CAMERASPEED);
				printf("\nCoordenadas de la camara: %f, %f", objCamera.mPos.x, objCamera.mPos.z);
				cupang += atan(CAMERASPEED) * 180 / IK_PI32;
			}
		}
		else if (freeC == true) {
			freeCamera.Rotate_View(-CAMERASPEED);
		}
		break;

	case GLUT_KEY_RIGHT:
		if (_3rdPerson == true) {
			if (firstCharacter == true) {
				objCamera.Rotate_Camera(CAMERASPEED);
				printf("\nCoordenadas de la camara: %f, %f", objCamera.mPos.x, objCamera.mPos.z);
				_02ang -= atan(CAMERASPEED) * 180 / IK_PI32;
			}
			else{
				objCamera2.Rotate_Camera(CAMERASPEED);
				printf("\nCoordenadas de la camara: %f, %f", objCamera.mPos.x, objCamera.mPos.z);
				cupang -= atan(CAMERASPEED) * 180 / IK_PI32;
			}
		}
		else if (freeC == true) {
			freeCamera.Rotate_View(CAMERASPEED);
		}
		break;

	default:
		break;
	}
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(800, 800);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Final"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);

	//Implementación de menú
	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar cuadro de escena", 0);
	glutAddMenuEntry("Reproducir animacion", 1);
	glutAddMenuEntry("Resetear cuadros",2);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion kiosko", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	engine->drop();//Eliminamos el sistema de audio
	snd1->drop();
	snd2->drop();

	return 0;
}

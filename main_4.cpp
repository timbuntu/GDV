// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include "Wuerfel.h"

float fRotation = 315.0;

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
}

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   //gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);      //Schauen von Vorne
   gluLookAt(0, 3, 4, 0, 0, 0, 0, 1, 0);      //Schauen von Vorne Oben
   //gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);      //Schauen von Rechts
   //gluLookAt(1, 1, 0, 0, 0, 0, 0, 1, 0);      //Schauen von Rechts Oben
   glClearColor(1., 0.5, 0, 1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glutWireCube(0.2);
   
   glTranslatef(0.1, 0.1, 0);
   glRotatef(fRotation, 0, 0, 1);
   glPushMatrix();
   
   //Unterarm
   glTranslatef(0.8, 0, 0);
   glScalef(2, 0.5, 1);
   glTranslatef(0.2, 0, 0);
   Wuerfel(0.4);
   
   //Oberarm
   glPopMatrix();
   glScalef(2, 1, 1);
   glTranslatef(0.2, 0, 0);
   Wuerfel(0.4);
   
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
   // Graphikfensters statt
    // Matrix für Transformation: Frustum->viewport
    glMatrixMode(GL_PROJECTION);
    // Aktuelle Transformations-Matrix zuruecksetzen
    glLoadIdentity ();
    // Viewport definieren
    glViewport(0,0,width,height);
    // Frustum definieren (siehe unten)
    //glOrtho( -1., 1., -1., 1., 0.0, 1.5);
    gluPerspective(45, 1, 0.1, 6.0);
    // Matrix für Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   std::cout << "value=" << value << std::endl;
   
   fRotation -= 359.0;
   if(fRotation <= 0.0)
       fRotation += 360.0;
   
   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
   glutCreateWindow( "Denis Hirt; Tim Christen" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
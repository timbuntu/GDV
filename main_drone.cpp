// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include "Wuerfel.h"
#include "Drone.h"

Drone drone;
Drone drone2;
Vector cameraPos, cameraLookAt, cameraUp;

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearDepth(1.0);
    cameraPos.set(0, 10, 25);
    cameraLookAt.set(0, 10, 0);
    cameraUp.set(0, 1, 0);
    drone.move(Vector(0, 10, 10));
    drone2.move(Vector(6, 5, 0));
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    GLfloat buffer[] = {
        0.87, 0.72, 0.53,   1, 1, 1,    0.87, 0.72, 0.53,   1, 1, 1,
        1, 1, 1,    0.87, 0.72, 0.53,   1, 1, 1,    0.87, 0.72, 0.53,
        0.87, 0.72, 0.53,   1, 1, 1,    0.87, 0.72, 0.53,   1, 1, 1,
        1, 1, 1,    0.87, 0.72, 0.53,   1, 1, 1,    0.87, 0.72, 0.53
    };
    
    glTexImage2D(GL_TEXTURE_2D,     // 2D Textur
                 0,                 // Detailsstufe (für Mipmaps)
                 1,                 // Farbkomponenten (1 für Grauwerte)
                 4, // Breite
                 4,// Höhe
                 0,                 // Rand
                 GL_RGB,            // Pixel-Format (Grauwerte)
                 GL_FLOAT,           // Datentyp der Komponenten (0 bis 255)
                 buffer);           // Pixel-Puffer
}

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glLoadIdentity ();   //Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   gluLookAt(cameraPos.getX(), cameraPos.getY(), cameraPos.getZ(),
           cameraLookAt.getX(), cameraLookAt.getY(), cameraLookAt.getZ(),
           cameraUp.getX(), cameraUp.getY(), cameraUp.getZ());
   glClearColor(0, 0, 0.8, 1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glBegin(GL_POLYGON);
   glColor3f(0.87, 0.72, 0.53);
   glTexCoord2f(0, 0);
   glVertex3f(-100, 0, 100);
   glTexCoord2f(0, 200);
   glVertex3f(-100, 0, -100);
   glTexCoord2f(200, 200);
   glVertex3f(100, 0, -100);
   glTexCoord2f(200, 0);
   glVertex3f(100, 0, 100);
   glEnd();
   
   drone.draw();
   
   drone2.draw();
   
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
    gluPerspective(45, 1, 0.1, 50.0);
    // Matrix für Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   //std::cout << "value=" << value << std::endl;
   
   drone.step();
   drone2.step();
   
   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'w':
            drone.addImpulse(Vector(0, 0, -0.1));
            break;
        case 's':
            drone.addImpulse(Vector(0, 0, 0.1));
            break;
        case 'a':
            drone.addImpulse(Vector(-0.1, 0, 0));
            break;
        case 'd':
            drone.addImpulse(Vector(0.1, 0, 0));
            break;
        case ' ':
            drone.addImpulse(Vector(0, 0.1, 0));
            break;
        case 'y':
            drone.addImpulse(Vector(0, -0.1, 0));
            break;
        case '1':
            cameraPos.set(0, 10, 25);
            cameraUp.set(0, 1, 0);
            break;
        case '2':
            cameraPos.set(25, 10, 0);
            cameraUp.set(0, 1, 0);
            break;
        case '3':
            cameraPos.set(-25, 10, 0);
            cameraUp.set(0, 1, 0);
            break;
        case '4':
            cameraPos.set(0, 50, 0);
            cameraUp.set(0, 0, -1);
            break;
        case '+':
            drone.setRotorRotationSpeed(drone.getRotorRotationSpeed()+1);
            break;
        case '-':
            drone.setRotorRotationSpeed(drone.getRotorRotationSpeed()-1);
            break;
        default:
            break;
    }
}

void keyboardUp(unsigned char key, int x, int y) {
    switch(key) {
        case 'w':
            drone.addImpulse(Vector(0, 0, 0.1));
            break;
        case 's':
            drone.addImpulse(Vector(0, 0, -0.1));
            break;
        case 'a':
            drone.addImpulse(Vector(0.1, 0, 0));
            break;
        case 'd':
            drone.addImpulse(Vector(-0.1, 0, 0));
            break;
        case ' ':
            drone.addImpulse(Vector(0, -0.1, 0));
            break;
        case 'y':
            drone.addImpulse(Vector(0, 0.1, 0));
            break;
        default:
            break;
    }
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
   
   glutKeyboardFunc(keyboard);
   glutKeyboardUpFunc(keyboardUp);
   
   Init();
   glutMainLoop();
   return 0;
}
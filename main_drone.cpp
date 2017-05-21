
#include <iostream> 
#include <GL/freeglut.h>
#include "Wuerfel.h"
#include "Drone.h"

//Zwei Drohnen
Drone drone;
Drone drone2;
//Variablen für Kameraperspektive
Vector cameraPos, cameraLookAt, cameraUp;

void Init()	
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearDepth(1.0);
    glClearColor(0, 0, 0.8, 1);
    
    //Initiale Kameraperspektive setzen
    cameraPos.set(0, 10, 25);
    cameraLookAt.set(0, 10, 0);
    cameraUp.set(0, 1, 0);
    
    //Initiale Positionen der Drohnen setzen
    drone.move(Vector(0, 10, 10));
    drone2.move(Vector(6, 5, 0));
    
    //2D-Textur generieren
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    //Parameter für Texturen setzen
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    GLfloat pixels[] = {
        0.87, 0.72, 0.53,   1, 1, 1,      0.87, 0.72, 0.53,   1, 1, 1,
        1, 1, 1,    0.87,   0.72, 0.53,   1, 1, 1,            0.87, 0.72, 0.53,
        0.87, 0.72, 0.53,   1, 1, 1,      0.87, 0.72, 0.53,   1, 1, 1,
        1, 1, 1,    0.87,   0.72, 0.53,   1, 1, 1,            0.87, 0.72, 0.53
    };
    
    glTexImage2D(GL_TEXTURE_2D,     // 2D Textur
                 0,                 // Detailsstufe (für Mipmaps)
                 GL_RGB,            // internes Format
                 4,                 // Breite
                 4,                 // Höhe
                 0,                 // Rand (Muss 0 sein)
                 GL_RGB,            // format des pixel buffer
                 GL_FLOAT,          // Datentyp der Komponenten
                 pixels);           // Pixel-Puffer
}

void RenderScene() //Zeichenfunktion
{
   glLoadIdentity ();   //Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   
   gluLookAt(cameraPos.getX(), cameraPos.getY(), cameraPos.getZ(),
           cameraLookAt.getX(), cameraLookAt.getY(), cameraLookAt.getZ(),
           cameraUp.getX(), cameraUp.getY(), cameraUp.getZ());
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   //Den Boden zeichnen (Mit Textur)
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
   
   //Die Drohnen zeichnen
   drone.draw();
   drone2.draw();
   
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
    // Matrix für Transformation: Frustum->viewport
    glMatrixMode(GL_PROJECTION);
    // Aktuelle Transformations-Matrix zuruecksetzen
    glLoadIdentity ();
    // Viewport definieren
    glViewport(0,0,width,height);
    // Frustum definieren
    gluPerspective(45, 1, 0.1, 50.0);
    // Matrix für Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   //Die Position und andere Variablen der Drohnen aktualisieren
   drone.step();
   drone2.step();
   
   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}

//Handler für das Runterdrücken von Tasten
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

//Handler für das Loslassen von Tasten
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
    // GLUT initialisieren
   glutInit( &argc, argv );
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize( 600, 600 );                          // Fenster-Konfiguration
   glutCreateWindow( "Denis Hirt; Tim Christen" );          // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );                          // Zeichenfunktion registrieren
   glutReshapeFunc( Reshape );                              //Reshape-Funktion registrieren
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   
   //Handler für Tastatureingaben registrieren
   glutKeyboardFunc(keyboard);
   glutKeyboardUpFunc(keyboardUp);
   
   Init();
   glutMainLoop();
   return 0;
}
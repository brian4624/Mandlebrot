// Graphics.cpp - Simple graphics library for COSC students
#include <iostream>
using namespace std;
#include "Graphics.h"
#include "Timer.h"
#include "about.h"

// class variables ------------------------------------------------------------
const double Graphics::FRAME_MSEC = 1.0 / Graphics::FPS * 1000.0; // millisecs
Graphics * Graphics::instance = NULL;
int Graphics::frames = 0;

// default constructor --------------------------------------------------------
Graphics::Graphics() {
    elapsed_time = 0;
    fractal.init( WINDOW_WIDTH, WINDOW_HEIGHT );
    fractal.initBitmap();
}

// start the graphics application ---------------------------------------------
void Graphics::start( void ) {
    cout << "GLUT app running" << endl;
    cout << "  framerate = " << FPS;
    cout << " (" << FRAME_MSEC << " msecs/frame)" << endl;
}

void Graphics::glut_init( int argc, char * argv[] ) {
    setInstance();  
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition( WINDOW_X, WINDOW_Y );
    glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
    glutCreateWindow( name.c_str() );

    glutDisplayFunc( displayWrapper );
    glutKeyboardFunc( keyboardWrapper );
    glutSpecialFunc( specialKeyboardWrapper );
    glutMouseFunc( mouseClicksWrapper );
    glutIdleFunc( animateWrapper );
    glutMainLoop();
}

// helper functions
void Graphics::setInstance() {
    instance = this;
}

// GLUT display methods -------------------------------------------------------
void Graphics::display() {
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    unsigned char * buffer = fractal.generate();
    glDrawPixels( WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, buffer );
    ++frames;
    glutSwapBuffers();
}

void Graphics::displayWrapper() {
    instance->display();
}

// animation method -----------------------------------------------------------

void Graphics::animateWrapper() {
    instance->animate();
}

void Graphics::animate() {
    if(!timer.running()) {
        timer.start();
    }
    timer.stop();
    double milliseconds = timer.get_elapsed_time();
    elapsed_time += FRAME_MSEC;
    if( elapsed_time >= FRAME_MSEC ) {
        glutPostRedisplay();
        elapsed_time -= FRAME_MSEC;
    }
    timer.start();
}

    
// keyboard handler code ------------------------------------------------------

void Graphics::keyboard( unsigned char key, int x, int y ) {
    cout << "key = " << key << endl;
    if( key == 27  || key == 'q' ) {
        cout << "Application terminated:" << endl;
        cout << "  frames: " << frames << endl;
        exit( 0 );
    }
}

void Graphics::keyboardWrapper( unsigned char key, int x, int y ) {
    instance->keyboard( key, x, y);
}

// special keyboard handler ---------------------------------------------------
// responds to button presses and relocates the position of the image in a corresponding manner
void Graphics::specialKeyboard( int key, int x, int y ) {
    cout << "special key = " << key << endl;
    if( key == GLUT_KEY_UP ) fractal.yOff -= 1;
    if( key == GLUT_KEY_DOWN) fractal.yOff += 1;
    if( key == GLUT_KEY_LEFT) fractal.xOff += 1;
    if( key == GLUT_KEY_RIGHT) fractal.xOff -= 1;
    if( key == GLUT_KEY_F1) fractal.scale *= 1.1;
    if( key == GLUT_KEY_F2) fractal.scale *= 0.9;
    
    cout << "xOff: " << fractal.xOff << " yOff: " << fractal.yOff << endl;
    
}

void Graphics::specialKeyboardWrapper( int key, int x, int y ) {
    instance-> specialKeyboard( key, x, y );
}

// special mouse handler ------------------------------------------------------
// work in progress to properly recenter the image.
// I don't know what you mean when you say center. Also, where is the center of the image supposed to be at?
int left_button_state = 0;
void Graphics::mouseClicks(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        fractal.xOff = x/100;
        fractal.yOff = y/100;
        cout << "x: " << x << " y: " << y << endl;
    }
}

void Graphics::mouseClicksWrapper( int button, int state, int x, int y) {
    instance-> mouseClicks( button, state, x, y);
}








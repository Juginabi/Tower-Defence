/* Tower-Defence
 *
 * Author: Jukka Vatjus-Anttila <jukka.vatjusanttila@gmail.com>
 *
 * For conditions of distribution and use, see copyright notice in LICENSE.txt
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <string>

// Needed for X11 server connection
#include "X11/Xlib.h"

// EGL library
#include "EGL/egl.h"

// OpenGL ES 2.0 libraries and extension
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

#include "../GameLogic/cMapper.h"

namespace renderer {

class X11Window;
class GLESv2Context;

class cRenderer
{
public:
    /// Destructor, sets instanceFlag to false so getInstance creates new on request
    ~cRenderer();

    /// Returns singleton pointer
    static cRenderer* getInstance();

    /// Get renderwindow for inputmapper
    X11Window* getRenderwindow();

    void update(float);

    /// Not implemented properly
    void drawFPS(float spentTime);

    /// Set background color
    void setBGcolor(float, float, float, float);
private:
    /// Private constructor because singleton instance is gotten from getInstance()
    cRenderer();

    /// Status for singleton instance pointer
    static bool instanceFlag_;

    /// Pointer to this singleton class
    static cRenderer* thisPointer_;

    /// X11Window pointer
    X11Window *xWindow_;

    /// GLESv2 context pointer
    GLESv2Context *renderContext_;

    /// GameLogic pointer
    static gamelogic::cMapper* mapper_;
};


}
#endif

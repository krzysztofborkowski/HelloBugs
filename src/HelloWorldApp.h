// © You i Labs Inc. 2000-2020. All rights reserved.
#ifndef _HELLO_WORLD_APP_H_
#define _HELLO_WORLD_APP_H_

#include <framework/YiApp.h>
#include <signal/YiSignalHandler.h>

class CYIAbstractTimeline;

/*!
 \defgroup helloworld Hello World
 \brief This basic sample displays a rotating image.
 
 \details <H3>Purpose:</H3>
 To demonstrate how to load a simple view and and to manually trigger animations.
 <H3>Suggested Learning Activities:</H3>
 Modify the animation in the After Effects file (HelloWorld.aep), export the composition using the You.i Engine Affect Effects plugin and launch the application to view the changes.

 */

#if defined(DOXY)
// This namespace provides a unique path to each class in the samples documentation.
namespace yi::documentation::helloworld
{
#endif

/*!
 \ingroup helloworld
 */
class HelloWorldApp : public CYIApp, public CYISignalHandler
{
public:
    HelloWorldApp();
    virtual ~HelloWorldApp();

    /*!
        \details Pure virtual of CYIApp.
     
        \snippet HelloWorldApp.cpp UserInit
     */
    virtual bool UserInit() override;
    /*!
        \details Pure virtual of CYIApp.
     */
    virtual bool UserStart() override;
    /*!
        \details Signal handler for the spin animation timeline completing.
     */
    void OnSpinAnimationCompleted();

private:
    // Store a pointer to the spin animation timeline
    CYIAbstractTimeline *m_pSpinAnimation;
};

#if defined(DOXY)
}
#endif

#endif //_HELLO_WORLD_APP_H_

// © You i Labs Inc. 2000-2020. All rights reserved.
#include "HelloWorldApp.h"
#include "logging/YiLogger.h"

#include <animation/YiTimeline.h>
#include <automation/YiWebDriverLocator.h>
#include <scenetree/YiSceneManager.h>
#include <view/YiSceneView.h>

#define LOG_TAG "HelloWorldApp"

HelloWorldApp::HelloWorldApp()
    : m_pSpinAnimation(nullptr)
{
}

HelloWorldApp::~HelloWorldApp()
{
}

bool HelloWorldApp::UserInit()
{
    //! [UserInit]
    // Start the web driver for allowing the use of Appium.
    CYIWebDriver *pWebDriver = CYIWebDriverLocator::GetWebDriver();
    if (pWebDriver)
    {
        pWebDriver->Start();
    }

    // Load the MainComp CYISceneView. This is the main scene view for this sample application. The main scene view is loaded here in the CYIApp subclass due to the simplicity of this application.
    // Larger applications would have seperate screens each containing a main scene view with the loading handled by the screen's CYIAbstractScreenViewController subclass.
    std::unique_ptr<CYISceneView> pOwnedSceneViewMain = GetSceneManager()->LoadScene("HelloWorld_MainComp.layout", CYISceneManager::ScaleType::Fit, CYISceneManager::VerticalAlignmentType::Center, CYISceneManager::HorizontalAlignmentType::Center);
    CYISceneView *pSceneViewMain = pOwnedSceneViewMain.get();
    if (!pSceneViewMain)
    {
        YI_ASSERT(false, LOG_TAG, "Loading scene 'HelloWorld_MainComp.layout' failed.");
        return false;
    }
    // Add the scene to the SceneManager with a layer index of 0, since this is the only scene the layer index isn't important.
    GetSceneManager()->AddScene("MainComp", std::move(pOwnedSceneViewMain), 0, CYISceneManager::LayerType::Opaque);
    GetSceneManager()->StageScene("MainComp");

    // Get the SpinAnimation timeline from the main composition and cache it for later use.
    m_pSpinAnimation = pSceneViewMain->GetTimeline("SpinAnimation");
    if (!m_pSpinAnimation)
    {
        YI_ASSERT(false, LOG_TAG, "Failed to find 'SpinAnimation' timeline.");
        return false;
    }

    // Connect to the CompletedForward signal to restart the animation when it completes.
    m_pSpinAnimation->CompletedForward.Connect(*this, &HelloWorldApp::OnSpinAnimationCompleted, EYIConnectionType::Async);

    // Start playing the timeline in a forward direction.
    m_pSpinAnimation->StartForward();

    return true;

    //! [UserInit]
}

bool HelloWorldApp::UserStart()
{
    return true;
}

void HelloWorldApp::OnSpinAnimationCompleted()
{
    // Timeline has ended. Restart the animation for a continuous loop.
    m_pSpinAnimation->StartForward();
}

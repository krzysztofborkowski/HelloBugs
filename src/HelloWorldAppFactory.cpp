// © You i Labs Inc. 2000-2020. All rights reserved.
#include "AppFactory.h"
#include "HelloWorldApp.h"

#define APP_NAME "Hello World"

#if defined(YI_PS4) || defined(YI_UWP)
#    define APP_WIDTH (1920)
#    define APP_HEIGHT (1080)
#else
#    define APP_WIDTH (1280)
#    define APP_HEIGHT (960)
#endif

std::unique_ptr<CYIApp> AppFactory::Create()
{
    return std::make_unique<HelloWorldApp>();
}

int AppFactory::GetWindowWidth()
{
    return APP_WIDTH;
}

int AppFactory::GetWindowHeight()
{
    return APP_HEIGHT;
}

const char *AppFactory::GetWindowName()
{
    return APP_NAME;
}

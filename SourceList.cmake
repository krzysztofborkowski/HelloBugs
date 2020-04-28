# Set the list of files as relative paths from the YI_SOURCE_DIR.
# When the project's CMakeLists.txt file evaluates these variables
# the values will be transformed into full paths.

set (YI_PROJECT_SOURCE
    src/HelloWorldApp.cpp
    src/HelloWorldAppFactory.cpp
)

set (YI_PROJECT_HEADERS
    src/HelloWorldApp.h
)

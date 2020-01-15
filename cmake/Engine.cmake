#############################################################################
# Name:      Engine.cmake
# Purpose:   3D engine
# Author:    Alexander Sherstnev
# Created:   2018-01-29
# Copyright: (c) 2018 Alexander Sherstnev
# Licence:   MIT
#############################################################################

include_directories(include/Engine)

list(APPEND Headers
    include/Engine/Math/Vector.h
    include/Engine/Math/Matrix.h
    include/Engine/Core.h

    include/Engine/Render/Mesh.h
    include/Engine/Render/RenderContext.h
    include/Engine/Render/Renderer.h
    include/Engine/Render/SoftwareRenderer.h

    include/Engine/Scene/Camera.h
    include/Engine/Scene/Entity.h
    include/Engine/Scene/BaseScene.h
    include/Engine/Scene/DefaultScene.h

    include/Engine/MainLoop.h
    include/Engine/BaseApplication.h
)

list(APPEND Sources
    src/Engine/Render/SoftwareRenderer.cpp

    src/Engine/Scene/BaseScene.cpp
    src/Engine/Scene/DefaultScene.cpp

    src/Engine/MainLoop.cpp
    src/Engine/BaseApplication.cpp
)

if (UseWX)
    list(APPEND Headers
        include/Engine/wx/wxRenderContext.h
        include/Engine/wx/wxBaseApplication.h
    )

    list(APPEND Sources
        src/Engine/wx/wxRenderContext.cpp
        src/Engine/wx/wxRenderPanel.cpp
        src/Engine/wx/wxRenderFrame.cpp
        src/Engine/wx/wxBaseApplication.cpp
    )
endif()

list(APPEND Headers
    include/Engine/Engine.h
)

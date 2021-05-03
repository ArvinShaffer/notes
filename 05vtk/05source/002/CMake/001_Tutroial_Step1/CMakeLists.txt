cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(001_Tutorial_Step1)

find_package(VTK COMPONENTS
  vtkCommonColor
  vtkCommonCore
  vtkFiltersSources
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
  )

if (NOT VTK_FOUND)
  message("skipping Tutorial_Step1: ${VTK_NOT_FOUND_MESSAGE}")
  return()
endif()

message(STATUS "VTK_VERSION: ${VTK_VERSION}")

if (VTK_VERSION VERSION_LESS "8.90.0")
  include(${VTK_USE_FILE})
  add_executable(001_Tutorial_Step1 MACOSX_BUNDLE 001_Tutorial_Step1.cxx)
  target_link_libraries(001_Tutorial_Step1 PRIVATE ${VTK_LIBRARIES})
else ()
  add_executable(001_Tutorial_Step1 MACOSX_BUNDLE 001_Tutorial_Step1.cxx)
  target_link_libraries(001_Tutorial_Step1 PRIVATE ${VTK_LIBRARIES})

  vtk_module_autoinit(
    TARGETS Tutorial_Step1
    MODULES ${VTK_LIBRARIES}
    )
endif ()


cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(Tutorial_Step6)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonTransforms
  vtkFiltersSources
  vtkInteractionStyle
  vtkInteractionWidgets
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

if (NOT VTK_FOUND)
  message("Skipping Tutorial_Step6: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(Tutorial_Step6 MACOSX_BUNDLE Tutorial_Step6.cxx )
  target_link_libraries(Tutorial_Step6 PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  add_executable(Tutorial_Step6 MACOSX_BUNDLE Tutorial_Step6.cxx )
  target_link_libraries(Tutorial_Step6 PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS Tutorial_Step6
    MODULES ${VTK_LIBRARIES}
    )
endif ()

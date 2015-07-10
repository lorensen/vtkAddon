message(STATUS "vtkAddon: Building as a Remote VTK module")

set(Module_SRCS
  vtkOrientedBSplineTransform.cxx
  vtkOrientedGridTransform.cxx
  vtkTestingOutputWindow.cxx
  )

vtk_module_library(vtkAddon ${Module_SRCS})

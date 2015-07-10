set(DOCUMENTATION "This module contains Slicer additions to vtk.")

vtk_module( vtkAddon
  DESCRIPTION
    "${DOCUMENTATION}"
  DEPENDS
    vtkCommonDataModel
    vtkFiltersHybrid
  TEST_DEPENDS
    vtkTestingCore
  KIT
    vtkRemote
)

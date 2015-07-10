vtk_add_test_cxx(${vtk-module}CxxTests tests
  vtkLoggingMacrosTest1.cxx,NO_VALID,NO_DATA
  )
vtk_test_cxx_executable(${vtk-module}CxxTests tests)

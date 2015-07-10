/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

=========================================================================auto=*/

/// \brief vtkOrientedGridTransform - arbitrarily oriented displacement field
/// deformation transformation.
///
/// This transforms extends vtkGridTransform to arbitrary grid orientation.
///

#ifndef __vtkOrientedGridTransform_h
#define __vtkOrientedGridTransform_h

#include "vtkAddonModule.h" // For export macro

#include "vtkGridTransform.h"

class VTKADDON_EXPORT vtkOrientedGridTransform : public vtkGridTransform
{
public:
  static vtkOrientedGridTransform *New();
  vtkTypeMacro(vtkOrientedGridTransform,vtkGridTransform);
  virtual void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get the b-spline grid axis directions.
  // This transform class will never modify the data.
  // Must be an orthogonal, normalized matrix.
  // The 4th column and 4th row are ignored.
  virtual void SetGridDirectionMatrix(vtkMatrix4x4*);
  vtkGetObjectMacro(GridDirectionMatrix,vtkMatrix4x4);

  // Description:
  // Make another transform of the same type.
  vtkAbstractTransform *MakeTransform();

protected:
  vtkOrientedGridTransform();
  ~vtkOrientedGridTransform();

  // Description:
  // Update the displacement grid.
  void InternalUpdate();

  // Description:
  // Copy this transform from another of the same type.
  void InternalDeepCopy(vtkAbstractTransform *transform);

  // Description:
  // Internal functions for calculating the transformation.
  void ForwardTransformPoint(const double in[3], double out[3]);
  void ForwardTransformPoint(const float in[3], float out[3])
  {
    ForwardTransformPoint(in, out);
  }

  void ForwardTransformDerivative(const double in[3], double out[3],
                                  double derivative[3][3]);
  void ForwardTransformDerivative(const float in[3], float out[3],
                                  float derivative[3][3])
  {
    ForwardTransformDerivative(in, out, derivative);
  }

  void InverseTransformDerivative(const double in[3], double out[3],
                                  double derivative[3][3]);
  void InverseTransformDerivative(const float in[3], float out[3],
                                  float derivative[3][3])
  {
    InverseTransformDerivative(in, out, derivative);
  }

  // Description:
  // Grid axis direction vectors (i, j, k) in the output space
  vtkMatrix4x4* GridDirectionMatrix;

  // Description:
  // Transforms a point from the output coordinate system to the
  // grid index (IJK) coordinate system.
  vtkMatrix4x4* GridIndexToOutputTransformMatrixCached;
  vtkMatrix4x4* OutputToGridIndexTransformMatrixCached;

private:
  vtkOrientedGridTransform(const vtkOrientedGridTransform&);  // Not implemented.
  void operator=(const vtkOrientedGridTransform&);  // Not implemented.
};

#endif

/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkLBFGSOptimizer.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef __itkLBFGSOptimizer_h
#define __itkLBFGSOptimizer_h

#include "itkSingleValuedNonLinearVnlOptimizer.h"
#include "vnl/algo/vnl_lbfgs.h"

namespace itk
{
  
/** \class LBFGSOptimizer
 * \brief Wrap of the vnl_lbfgs minimizer to be adapted for Registration
 *
 */

template <class TCostFunction>
class ITK_EXPORT LBFGSOptimizer : 
    public SingleValuedNonLinearVnlOptimizer<TCostFunction> 

{
public:
  /**
   * Standard "Self" typedef.
   */
  typedef LBFGSOptimizer  Self;

  /**
   * Standard "Superclass" typedef.
   */
  typedef   SingleValuedNonLinearOptimizer<TCostFunction> Superclass;

  /** 
   * Smart pointer typedef support 
   */
  typedef SmartPointer<Self>   Pointer;
  typedef SmartPointer<const Self>  ConstPointer;


  /**
   *  Parameters type.
   *  it defines a position in the optimization search space
   */
  typedef typename TCostFunction::ParametersType ParametersType;


  /**
   *  Measure type.
   *  it defines a type used to return the cost function value 
   */
  typedef typename TCostFunction::MeasureType MeasureType;


  /**
   *  Derivative type.
   *  it defines a type used to return the cost function derivative 
   */
  typedef typename TCostFunction::DerivativeType DerivativeType;

 
 /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro( LBFGSOptimizer, 
      SingleValuedNonLinearOptimizer );

  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /**
   * Internal Optimizer Type
   */
  typedef   vnl_lbfgs       InternalOptimizerType;

  /**
   * Method for getting access to the internal optimizer
   */
  InternalOptimizerType & GetOptimizer(void);

  /**
   * Start optimization with an initial value
   */
  void StartOptimization( void );
 
protected:

  LBFGSOptimizer();
  virtual ~LBFGSOptimizer() {};
  LBFGSOptimizer(const Self&) {}
  void operator=(const Self&) {}

  InternalOptimizerType     m_LBFGS;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkLBFGSOptimizer.txx"
#endif

#endif




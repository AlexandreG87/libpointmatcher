// kate: replace-tabs off; indent-width 4; indent-mode normal
// vim: ts=4:sw=4:noexpandtab
/*

Copyright (c) 2010--2018,
François Pomerleau and Stephane Magnenat, ASL, ETHZ, Switzerland
You can contact the authors at <f dot pomerleau at gmail dot com> and
<stephane at magnenat dot net>

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH-ASL BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#pragma once

#include "PointMatcher.h"

#include <vector>

//! Find the covariance of the surface for every point using of neighbour points
template<typename T>
struct SurfaceCovarianceDataPointsFilter: public PointMatcher<T>::DataPointsFilter
{
	typedef PointMatcherSupport::Parametrizable Parametrizable;
	typedef PointMatcherSupport::Parametrizable P;
	typedef Parametrizable::Parameters Parameters;
	typedef Parametrizable::ParameterDoc ParameterDoc;
	typedef Parametrizable::ParametersDoc ParametersDoc;
	typedef Parametrizable::InvalidParameter InvalidParameter;
	
	typedef typename PointMatcher<T>::Vector Vector;
	typedef typename PointMatcher<T>::Matrix Matrix;	
	typedef typename PointMatcher<T>::DataPoints DataPoints;
	typedef typename PointMatcher<T>::DataPoints::InvalidField InvalidField;

	inline static const std::string description()
	{
		return "This filter estimate the covariance matrix of the nearest neighbour around each points.";
	}
	inline static const ParametersDoc availableParameters()
	{
		return {
			{"knn", "number of nearest neighbors to consider, including the point itself", "5", "3", "2147483647", &P::Comp<unsigned>},
			{"maxDist", "maximum distance to consider for neighbors", "inf", "0", "inf", &P::Comp<T>},
			{"epsilon", "approximation to use for the nearest-neighbor search", "0", "0", "inf", &P::Comp<T>},
			{"keepDensities", "whether the point densities should be added as descriptors to the resulting cloud", "0"},
		};
	}
	
	const unsigned knn;
	const T maxDist;
	const T epsilon;
	const bool keepDensities;

SurfaceCovarianceDataPointsFilter(const Parameters& params = Parameters());
	virtual ~SurfaceCovarianceDataPointsFilter() {};
	virtual DataPoints filter(const DataPoints& input);
	virtual void inPlaceFilter(DataPoints& cloud);
};

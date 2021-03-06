#ifndef PYTHON_POINTMATCHER_ICP_SEQUENCE_H
#define PYTHON_POINTMATCHER_ICP_SEQUENCE_H

#include "pypoint_matcher_helper.h"

namespace python
{
	namespace pointmatcher
	{
		void pybindICPSequence(py::class_<PM>& p_class);
	}
}

#endif //PYTHON_POINTMATCHER_ICP_SEQUENCE_H

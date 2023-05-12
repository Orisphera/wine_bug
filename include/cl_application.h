#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H

#include "cl_base.h"

class cl_application : public cl_base
{
	public:
		using cl_base :: cl_base;
		void build_tree_objects ( );
		int exec_app ( );
};

#endif

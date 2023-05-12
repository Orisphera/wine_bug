#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <string>
#include <vector>

class cl_base
{
	private:
		cl_base * p_head_object;
		std::vector < cl_base * > subordinate_objects;
		std::string s_object_name;
		int i_state;
	public:
		cl_base ( cl_base * p_head_object, std::string s_object_name = "Base object" );
		bool set_name ( std :: string s_new_name );
		std::string get_name ( );
		cl_base * get_head ( );
		cl_base * get_child ( std :: string s_child_name );
		cl_base * find_ob_st ( std :: string s_name );
		cl_base * find_ob_et ( std :: string s_name );
		void print_ob_tree_no_labels ( int indent = 0 );
		void print_ob_tree_ready_labels ( int indent = 0 );
		void set_state ( int i_state );
};

#endif

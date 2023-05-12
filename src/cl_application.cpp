#include "cl_application.h"

#include <iostream>
#include <string>
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

void cl_application :: build_tree_objects ( )
{
	std :: string s_root_name;
	std :: cin >> s_root_name;
	this -> set_name ( s_root_name );
	cl_base * last_added = this;
	while ( true )
	{
		std :: string s_head_name;
		std :: cin >> s_head_name;
		if ( s_head_name == "endtree" )
		{
			break;
		}
		cl_base * p_head = last_added -> find_ob_et ( s_head_name );
		std :: string s_child_name;
		std :: cin >> s_child_name;
		int i_class;
		std :: cin >> i_class;
		if ( this -> find_ob_st ( s_child_name ) == nullptr ) {
			switch ( i_class ) {
				case 2: last_added = new cl_2 ( p_head ); break;
				case 3: last_added = new cl_3 ( p_head ); break;
				case 4: last_added = new cl_4 ( p_head ); break;
				case 5: last_added = new cl_5 ( p_head ); break;
				case 6: last_added = new cl_6 ( p_head );
			}
		}
	}
}

int cl_application :: exec_app ( )
{
	std :: cout << "Object tree" << std :: endl;
	this -> print_ob_tree_no_labels ( );
	std :: string s_name;
	int i_state;
	while ( std :: cin >> s_name >> i_state )
	{
		this -> find_ob_st ( s_name ) -> set_state ( i_state );
	}
	std :: cout << std :: endl << "The tree of objects and their readiness" << std :: endl;
	this -> print_ob_tree_ready_labels ( );
	return 0;
}

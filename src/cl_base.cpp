#include "cl_base.h"

#include <iostream>

cl_base :: cl_base ( cl_base * p_head_object, std :: string s_object_name)
{
	this -> p_head_object = p_head_object;
	this -> s_object_name = s_object_name;
	if ( p_head_object )
	{
		p_head_object -> subordinate_objects.push_back ( this );
	}
}

bool cl_base :: set_name ( std :: string s_new_name )
{
	if ( this -> get_head ( ) != nullptr && this -> get_head ( ) -> get_child ( s_new_name ) != nullptr )
	{
		return false;
	}
	this -> s_object_name = s_new_name;
	return true;
}

std :: string cl_base :: get_name ( )
{
	return this -> s_object_name;
}

cl_base * cl_base :: get_head ( )
{
	return this -> p_head_object;
}

cl_base * cl_base :: get_child ( std :: string s_child_name )
{
	for ( int i_child = 0; i_child < this -> subordinate_objects . size ( ); ++ i_child )
	{
		if ( this -> subordinate_objects [ i_child ] -> get_name ( ) == s_child_name )
		{
			return this -> subordinate_objects [ i_child ];
		}
	}
	return nullptr;
}

cl_base * cl_base :: find_ob_st ( std :: string s_name )
{
	if ( this -> s_object_name == s_name )
	{
		return this;
	}
	cl_base * ans = nullptr;
	for ( auto i : this -> subordinate_objects )
	{
		cl_base * cur = i -> find_ob_st ( s_name );
		if ( cur != nullptr)
		{
			if ( ans != nullptr )
			{
				return nullptr;
			}
			ans = cur;
		}
	}
	return ans;
}

cl_base * cl_base :: find_ob_et ( std :: string s_name )
{
	if ( this -> get_head ( ) == nullptr )
	{
		return this -> find_ob_st ( s_name );
	}
	return this -> get_head ( ) -> find_ob_et ( s_name );
}

void cl_base :: print_ob_tree_no_labels ( int indent )
{
	std :: cout << std :: string ( 4 * indent, ' ' ) << this -> get_name ( );
	for ( auto i : this -> subordinate_objects )
	{
		std :: cout << std :: endl;
		i -> print_ob_tree_no_labels ( );
	}
}

void cl_base :: print_ob_tree_ready_labels ( int indent )
{
	std :: cout << std :: string ( 4 * indent, ' ' ) << this -> get_name ( );
	if ( this -> i_state )
	{
		std :: cout << " is not ready";
	}
	else
	{
		std :: cout << " is ready";
	}
	for ( auto i : this -> subordinate_objects )
	{
		std :: cout << std :: endl;
		i -> print_ob_tree_no_labels ( );
	}
}

void cl_base :: set_state ( int i_state )
{
	this -> i_state = i_state;
	if ( i_state )
	{
		if ( ! this -> get_head ( ) -> i_state)
		{
			this -> i_state = 0;
		}
		return;
	}
	for ( auto i : this -> subordinate_objects )
	{
		i -> set_state ( 0 );
	}
}

#include "Node.h"

/**************************************
*
*	Adam Lelas
*	X00106580
*
***************************************/

bool Node::isLeaf()
{
	if (left == NULL && right == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

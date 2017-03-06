#include "Node.h"

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

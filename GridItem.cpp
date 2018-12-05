#include "GridItem.h"

GridItem::GridItem(char symbol) : symbol_(symbol)
{
	//
}

char GridItem::get_symbol() const {
	return symbol_;
}

// Class cannot be instantiated
bool GridItem::is_at_position(int x, int y)
{
	return false;
}
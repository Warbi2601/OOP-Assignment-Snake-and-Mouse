#pragma once
class GridItem
{
public:
	GridItem(char symbol);
	
	char get_symbol() const;
	// Virtual functions to be overriden in derivative classes
	virtual bool is_at_position(int x, int y) = 0;
private:
	char symbol_;
};


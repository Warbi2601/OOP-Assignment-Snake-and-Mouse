#pragma once
class GridItem
{
public:
	GridItem(char symbol);
	// virtual ~GridItem() = 0; // Pure virtual to create abstract class(?)
	
	char get_symbol() const;
	// Virtual functions to be overriden in derivative classes
	virtual bool is_at_position(int x, int y) = 0;
private:
	char symbol_;
};


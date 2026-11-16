#include "Level.h"

Level::Level()
{

	neprijatelji.push_back(Enemy());

}

int Level::br_nepr() const 
{

	return neprijatelji.size();

}

int Level::br_oruz() const
{

	return oruzja.size();

}

/**
 * @file treasuremap.cpp
 * @description Implementations for PA2, TreasureMap class
 * @author (your CWLs)
**/

#include "treasuremap.h"
#include "queue.h"
using namespace std;

TreasureMap::TreasureMap(const PNG& baseim, const PNG& mazeim, pair<int, int> s) {
	base = baseim;
	maze = mazeim;
	start = s;
}

void TreasureMap::SetGrey(PNG& im, pair<int, int> loc) {
	RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	pixel-> r = 2*(pixel->r/4);
	pixel-> g = 2*(pixel->g/4);
	pixel-> b = 2*(pixel->b/4);
}

void TreasureMap::SetLOB(PNG& im, pair<int, int> loc, int d) {
	uint64_t d_mod = d%64; // get the 6 least significant bits of d
	uint8_t r_mod = (d_mod >> 4) & 0b11; // get the 2 most significant bits of d 
	uint8_t g_mod = (d_mod >> 2) & 0b11;
	uint8_t b_mod = d_mod & 0b11;

	RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	pixel->r = pixel->r & r_mod; // set the 2 least significant bits of r to be the 2 most significant bits of d
	pixel->g = pixel->g & g_mod;
	pixel->b = pixel->b & b_mod;
}

PNG TreasureMap::RenderMap() {
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return PNG();
}


PNG TreasureMap::RenderMaze() {
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return PNG();
}

bool TreasureMap::Good(vector<vector<bool>>& v, pair<int, int> curr, pair<int, int> next) {
	// within the image
	if (next.first < 0 || next.first >= maze.width()) return false;
	if (next.second < 0 || next.second >= maze.height()) return false;

	// unvisited
	if(v[next.first][next.second]) return false;
	
	// same colour as curr in the maze image
	if(maze.getPixel(next.first, next.second) != maze.getPixel(curr.first, curr.second)) return false;

	return true;
}

vector<pair<int, int>> TreasureMap::Neighbours(pair<int, int> curr) {
	/* REPLACE THE LINES BELOW WITH YOUR CODE */
	vector<pair<int, int>> v;
	return v;
}

/***********************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE       *
* FUNCTIONS IN treasuremap-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW                  *
***********************************************/

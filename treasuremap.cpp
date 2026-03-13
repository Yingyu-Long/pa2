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
	RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	int r = pixel->r;
	int g = pixel->g;
	int b = pixel->b;
	
	

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
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return false;
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

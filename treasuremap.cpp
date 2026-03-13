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
	int d_mod = d%64; // get the 6 least significant bits of d
	unsigned char r_mod = (d_mod >> 4) & 0b11; // get the 2 most significant bits of d 
	unsigned char g_mod = (d_mod >> 2) & 0b11;
	unsigned char b_mod = d_mod & 0b11;

	RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	pixel->r = (pixel->r & 252) | r_mod; // set the 2 least significant bits of r to be the 2 most significant bits of d
	pixel->g = (pixel->g & 252) | g_mod;
	pixel->b = (pixel->b & 252) | b_mod;
}

PNG TreasureMap::RenderMap() {
	PNG base_copy = PNG(base);
	vector<vector<bool>> visited(base_copy.height(), vector<bool>(base_copy.width(), false));
	vector<vector<int>> distance(base_copy.height(), vector<int>(base_copy.width(), 0));
	Queue <pair<int, int>> q;
	visited[start.second][start.first] = true;
	distance[start.second][start.first] = 0;
	q.Enqueue(start);
	while(!q.IsEmpty()){
		pair<int, int> current = q.Dequeue();
		vector<pair<int, int>> neighbors = Neighbours(current);
		for(pair<int, int> neighbor : neighbors) {
			if(Good(visited, current, neighbor)) {
				visited[neighbor.second][neighbor.first] = true;
				distance[neighbor.second][neighbor.first] = distance[current.second][current.first] + 1;
				SetLOB(base_copy , neighbor, distance[neighbor.second][neighbor.first]);
				q.Enqueue(neighbor);
			}
		}
	}
	return base_copy;
}


PNG TreasureMap::RenderMaze() {
	PNG base_copy = PNG(base);
	for (int dx = -3; dx <= 3; dx++) {
		for (int dy = -3; dy <= 3; dy++) {
			int x = start.first + dx;
			int y = start.second + dy;
			if(x >=0 && x <base_copy.width() && y >= 0 && y < base_copy.height()) {
				RGBAPixel* pixel = base_copy.getPixel(x, y);
				pixel->r = 255;
				pixel->g = 0;
				pixel->b = 0;
			}
		}
	}
	vector<vector<bool>> visited(base_copy.height(), vector<bool>(base_copy.width(), false));
	Queue <pair<int, int>> q;
	visited[start.second][start.first] = true;
	SetGrey(base_copy, start);
	q.Enqueue(start);
	while(!q.IsEmpty()) {
		pair<int, int> current = q.Dequeue();
		vector<pair<int, int>> neighbors = Neighbours(current);
		for(pair<int, int> neighbor : neighbors) {
			if(Good(visited, current, neighbor)) {
				visited[neighbor.second][neighbor.first] = true;
					SetGrey(base_copy, neighbor);
				q.Enqueue(neighbor);
			}
		}
	}
	return base_copy;
}

bool TreasureMap::Good(vector<vector<bool>>& v, pair<int, int> curr, pair<int, int> next) {
	// within the image
	if (next.first < 0 || next.first >= maze.width()) return false;
	if (next.second < 0 || next.second >= maze.height()) return false;

	// unvisited
	if(v[next.second][next.first]) return false;
	
	// same colour as curr in the maze image
	if(maze.getPixel(next.first, next.second) != maze.getPixel(curr.first, curr.second)) return false;

	return true;
}

vector<pair<int, int>> TreasureMap::Neighbours(pair<int, int> curr) {
	vector<pair<int, int>> v;
	v.push_back(make_pair(curr.first-1, curr.second));
	v.push_back(make_pair(curr.first, curr.second+1));
	v.push_back(make_pair(curr.first+1, curr.second));
	v.push_back(make_pair(curr.first, curr.second-1));
	return v;
}

/***********************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE       *
* FUNCTIONS IN treasuremap-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW                  *
***********************************************/

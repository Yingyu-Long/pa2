/**
 * @file decoder.cpp
 * @description Implementations for PA2, Decoder class
 * @author (your CWLs)
**/

#include "decoder.h"
#include "queue.h"
#include "stack.h"
#include <algorithm>
using namespace std;

static void setRed(PNG& im, pair<int, int> loc) {
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
    pixel-> r = 255;
    pixel-> g = 0;
    pixel-> b = 0;
}

Decoder::Decoder(const PNG & tm, pair<int, int> s) : start(s), mapImg(tm) {
    vector<vector<bool>> visited(mapImg.height(), vector<bool>(mapImg.width(), false));
    vector<vector<int>> distance(mapImg.height(), vector<int>(mapImg.width(), 0));
    vector<vector<pair<int, int>>> discover_from(mapImg.height(), vector<pair<int, int>>(mapImg.width(), make_pair(-1, -1)));
    Queue <pair<int, int>> q;

    visited[start.second][start.first] = true;
    distance[start.second][start.first] = 0;
    q.Enqueue(start);

    // Find the treasure and build the discover_from table
    pair<int, int> furthest = start;
    int max_dist = 0;
    while(!q.IsEmpty()){
        pair<int, int> current = q.Dequeue();
        vector<pair<int, int>> neighbors = Neighbours(current);
        for(pair<int, int> neighbor : neighbors) {
            if(Good(visited, distance, current, neighbor)) {
                visited[neighbor.second][neighbor.first] = true;
                int new_dist = distance[current.second][current.first] + 1;
                distance[neighbor.second][neighbor.first] = new_dist;
                discover_from[neighbor.second][neighbor.first] = current;

                if (new_dist > max_dist) {
                    max_dist = new_dist;
                    furthest = neighbor;
                }

                q.Enqueue(neighbor);
            }
        }
    }

    // Backtrack from the treasure to the start using the discover_from table to build the pathPts vector
    pair<int, int> back_track = furthest;
    while(back_track != start) {
        pathPts.push_back(back_track);
        back_track = discover_from[back_track.second][back_track.first];
    }

    // Reverse the pathPts vector so that it goes from start to treasure
    pathPts.push_back(start);
    std::reverse(pathPts.begin(), pathPts.end());
}

PNG Decoder::RenderSolution(){
    PNG copyImg = mapImg;
    for(pair<int, int> loc : pathPts) {
        setRed(copyImg, loc);
    }
    return copyImg;
}

PNG Decoder::RenderMaze(){
    PNG copyImg = mapImg;
    Queue<pair<int, int>> q;
    vector<vector<bool>> visited(mapImg.height(), vector<bool>(mapImg.width(), false));
    vector<vector<int>> distance(mapImg.height(), vector<int>(mapImg.width(), 0));
    SetGrey(copyImg, start);
    q.Enqueue(start);
    visited[start.second][start.first] = true;
    distance[start.second][start.first] = 0;
    while (!q.IsEmpty()){
        pair<int, int> curr = q.Dequeue();
        vector<pair<int,int>> Neighbour = Neighbours(curr);
        for(pair<int, int> neighbor : Neighbour) {
            if(Good(visited, distance, curr, neighbor)) {
                visited[neighbor.second][neighbor.first] = true;
                distance[neighbor.second][neighbor.first] = distance[curr.second][curr.first] + 1;
                SetGrey(copyImg, neighbor);
                q.Enqueue(neighbor);
            }
        }  
    }

    for(int dx = -3; dx <= 3; dx++){
        for(int dy = -3; dy <= 3; dy++){
            int x = start.first + dx;
            int y = start.second + dy;
            if (x >= 0 && x < mapImg.width() && y >= 0 && y < mapImg.height()) {
                setRed(copyImg, make_pair(x, y));
            }
        }
    }

    return copyImg;
}

void Decoder::SetGrey(PNG& im, pair<int, int> loc){
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	pixel-> r = 2*(pixel->r/4);
	pixel-> g = 2*(pixel->g/4);
	pixel-> b = 2*(pixel->b/4);
}

pair<int, int> Decoder::FindSpot(){
    pair<int, int> spot;
    spot = pathPts[pathPts.size() - 1]; // the last point in the pathPts vector is the treasure
    return spot;
}

int Decoder::PathLength(){
    return pathPts.size() - 1;
}

bool Decoder::Good(vector<vector<bool>>& v, vector<vector<int>>& d, pair<int, int> curr, pair<int, int> next){
    // within the image
    if(next.first < 0 || next.first >= mapImg.width()) return false;
    if(next.second < 0 || next.second >= mapImg.height()) return false;

    // unvisited
    if(v[next.second][next.first]) return false;

    // same colour as curr in the maze image
    int curr_distance = d[curr.second][curr.first];
    RGBAPixel next_pixel = *(mapImg.getPixel(next.first, next.second));
    return Compare(next_pixel, curr_distance);
}

vector<pair<int, int>> Decoder::Neighbours(pair<int, int> curr) {
    /* REPLACE THE LINES BELOW WITH YOUR CODE */
    vector<pair<int, int>> v;
    pair<int, int> left = make_pair(curr.first - 1, curr.second);
    pair<int, int> below = make_pair(curr.first, curr.second + 1);
    pair<int, int> right = make_pair(curr.first + 1, curr.second);
    pair<int, int> above = make_pair(curr.first, curr.second - 1);
    v = {left, below, right, above};
    return v;
}

bool Decoder::Compare(RGBAPixel p, int d){
    unsigned char r_mod = p.r & 0b11;
    unsigned char g_mod = p.g & 0b11;
    unsigned char b_mod = p.b & 0b11;
    int d_mod = (r_mod << 4) | (g_mod << 2) | b_mod;
    return d_mod == ((d + 1) % 64); // because d is the curr distance, and the next pixel should be d + 1
}

/*******************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE   *
* FUNCTIONS IN decoder-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW              *
*******************************************/


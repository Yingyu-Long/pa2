/**
 * @file decoder.cpp
 * @description Implementations for PA2, Decoder class
 * @author (your CWLs)
**/

#include "decoder.h"
#include "queue.h"
#include "stack.h"
using namespace std;

Decoder::Decoder(const PNG & tm, pair<int, int> s) : start(s), mapImg(tm) {
    /* YOUR CODE HERE */
}

PNG Decoder::RenderSolution(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return PNG();
}

PNG Decoder::RenderMaze(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return PNG();
}

void Decoder::SetGrey(PNG& im, pair<int, int> loc){
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
	pixel-> r = 2*(pixel->r/4);
	pixel-> g = 2*(pixel->g/4);
	pixel-> b = 2*(pixel->b/4);
}

pair<int, int> Decoder::FindSpot(){
    /* REPLACE THE LINES BELOW WITH YOUR CODE */
    pair<int, int> spot;
    return spot;
}

int Decoder::PathLength(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return -1;
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


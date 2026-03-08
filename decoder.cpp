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
    /* YOUR CODE HERE */
    
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
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return false;
}

vector<pair<int, int>> Decoder::Neighbours(pair<int, int> curr) {
    /* REPLACE THE LINES BELOW WITH YOUR CODE */
    vector<pair<int, int>> v;
    return v;
}

bool Decoder::Compare(RGBAPixel p, int d){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return false;
}

/*******************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE   *
* FUNCTIONS IN decoder-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW              *
*******************************************/


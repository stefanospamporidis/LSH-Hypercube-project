//
//  Clustering.hpp
//  Project-Cluster
//
//  Created by <author> on 19/11/2019.
//
//

#ifndef Clustering_hpp
#define Clustering_hpp

#include <stdio.h>
#include <map>
#include <utility>
#include <random>
#include <set>
#include <algorithm>

#include "Database.hpp"
#include "Item.hpp"
#include "Curve.hpp"
#include "Vector.hpp"
#include "Hashtable.h"

#define private public

#define MAX_ITERATIONS 5
#define MAX_MEAN_ITER 5

using namespace std ;


class Clustering {
private:
    void random_init(); // Random selection of K items

    double D(Item *t); //vriskei tin minimum apostasi enos Item apo ta centroids
    int find_new_centroid(set<int> &used);
    int Binary_search(vector< std::pair<int,double> > &partial_sum_array,double x,int l,int r);
    void kmeans_init(); // K-means++ selectionof first K items

    void lloyd_assign(); // Lloyd assignment
    void range_search_assign(); // Assignment by Range search

    Curve * init_dba(std::vector<Curve *> &);
    // implementation of the dba algorithm for computing
    // a mean curve of a set of curves
    Curve * dba(std::vector<Curve *> );
    Point * meanPoint(std::vector<Point *> );
    Vector * meanVector(std::vector<Vector *>);
    void pam_update(); // Update using PAM (lloyds)
    void mean_update(); // Update using mean vectors / curve

    void init() ; // Does the initialization of the k centers
    void assign(); // Does the assignment of the n vectors to their clusters
    void update(); // Does the update of the k centers
    Database *db ; // Database with points

    int nearest_cluster(int cluster);//epistrefei to kontinotero cluster apo ena simeio
    double Silhouette_point(int cluster,int point,int nearest_cluster); //ektelei to s(i) = b(i) - a(i) / max{a(i),b(i)}

    Hash *ht ;
    int k ; // The number of clusters k

    bool isCurve ; // True if our objects are curves

    int flags[3] ; // Flags used to determine which algorithms are used
    // for init , assign and update given by user
    std::map<pair<int,int> , double> dist; // Map with distances of each pair
    // of items
    std::map<int, Item *> representative; // Map that matches each cluster to each
    // representative center
    std::map<int,int> medoid_repr ; // Used when medoid representation
    std::map<int, std::vector<int>> assigned; // Map that matches each cluster to its assigned points

    std::default_random_engine generator;

public:
    Clustering(Database *,bool ,int ,int ,int ,int ); // Database with data points
    // Followed by k and sequence of [0,1,0] etc that selects the init , assign and update
    // algorithms respectively
    double Silhouette();//Silhouette evaluation
    void runClustering(); // Function called by main
    void printRepresentatives(void) ;
    ~Clustering();
protected:

};


#endif /* Clustering_hpp */

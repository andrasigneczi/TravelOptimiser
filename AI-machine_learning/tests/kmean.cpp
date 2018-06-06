#include <armadillo>
#include "kmean.h"
#include <kmean.h>
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

namespace KMean_ns {
    
void test1();

void runTests() {
    test1();
}

arma::mat findClosestCentroids(arma::mat X, arma::mat centroids) {
    // FINDCLOSESTCENTROIDS computes the centroid memberships for every example
    //    idx = FINDCLOSESTCENTROIDS (X, centroids) returns the closest centroids
    //    in idx for a dataset X where each row is a single example. idx = m x 1 
    //    vector of centroid assignments (i.e. each entry in range [1..K])
    // 
    
    // Set K
    int K = (int)centroids.n_rows;
    
    // You need to return the following variables correctly.
    arma::mat idx = arma::zeros(X.n_rows, 1);
    
    // ====================== YOUR CODE HERE ======================
    // Instructions: Go over every example, find its closest centroid, and store
    //               the index inside idx at the appropriate location.
    //               Concretely, idx(i) should contain the index of the centroid
    //               closest to example i. Hence, it should be a value in the 
    //               range 1..K
    //
    // Note: You can use a for-loop over the examples to compute this.
    //
    
    for(size_t i=0; i < X.n_rows; ++i ) {
      double q = 2e+200;
      int kind=-1;
      for(int k=0; k < K; ++k ) {
          double d=arma::sum(pow(X.row(i)-centroids.row(k),2));
          if (q > d){
            q = d;
            kind=k;
          }
      }
      idx(i,0) = kind;
    }
    return idx;
}

arma::mat computeCentroids(arma::mat X, arma::mat idx, int K) {
    // COMPUTECENTROIDS returns the new centroids by computing the means of the 
    // data points assigned to each centroid.
    //    centroids = COMPUTECENTROIDS(X, idx, K) returns the new centroids by 
    //    computing the means of the data points assigned to each centroid. It is
    //    given a dataset X where each row is a single data point, a vector
    //    idx of centroid assignments (i.e. each entry in range [1..K]) for each
    //    example, and K, the number of centroids. You should return a matrix
    //    centroids, where each row of centroids is the mean of the data points
    //    assigned to it.
    // 
    
    // Useful variables
    size_t m = X.n_rows;
    size_t n = X.n_cols;
    
    // You need to return the following variables correctly.
    arma::mat centroids = arma::zeros(K, n);
    
    
    // ====================== YOUR CODE HERE ======================
    // Instructions: Go over every centroid and compute mean of all points that
    //               belong to it. Concretely, the row vector centroids(i, :)
    //               should contain the mean of the data points assigned to
    //               centroid i.
    //
    // Note: You can use a for-loop over the centroids to compute this.
    //
    
    arma::mat c_count = arma::zeros(K,1);
    for( size_t i = 0; i < m; ++i ) {
      centroids.row(idx(i)) += X.row(i);
      c_count(idx(i),0) += 1; 
    }
    
    for(int i = 0; i < K; ++i ) {
      centroids.row(i) = centroids.row(i)/c_count(i,0);
    }
    return centroids;
}

void runkMeans(arma::mat X, arma::mat initial_centroids, int max_iters, arma::mat& centroids, arma::mat& idx) {
    // RUNKMEANS runs the K-Means algorithm on data matrix X, where each row of X
    // is a single example
    //    [centroids, idx] = RUNKMEANS(X, initial_centroids, max_iters, ...
    //    plot_progress) runs the K-Means algorithm on data matrix X, where each 
    //    row of X is a single example. It uses initial_centroids used as the
    //    initial centroids. max_iters specifies the total number of interactions 
    //    of K-Means to execute. plot_progress is a true/false flag that 
    //    indicates if the function should also plot its progress as the 
    //    learning happens. This is set to false by default. runkMeans returns 
    //    centroids, a Kxn matrix of the computed centroids and idx, a m x 1 
    //    vector of centroid assignments (i.e. each entry in range [1..K])
    // 
    
    // Initialize values
    size_t m = X.n_rows;
    // size_t n = X.n_cols;
    size_t K = initial_centroids.n_rows;
    
    centroids = initial_centroids;
    arma::mat previous_centroids = centroids;
    idx = arma::zeros(m, 1);
    
    // Run K-Means
    for( int i=0; i < max_iters; ++i ) {
        
        // Output progress
        printf("K-Means iteration %d/%d...\n", i, max_iters);

        // For each example in X, assign it to the closest centroid
        idx = findClosestCentroids(X, centroids);
        

        // Given the memberships, compute new centroids
        centroids = computeCentroids(X, idx, K);
    }
}

arma::mat kMeansInitCentroids(arma::mat X, int K) {
    // KMEANSINITCENTROIDS This function initializes K centroids that are to be 
    // used in K-Means on the dataset X
    //    centroids = KMEANSINITCENTROIDS(X, K) returns K initial centroids to be
    //    used with the K-Means on the dataset X
    // 
    
    // You should return this values correctly
    arma::mat centroids = arma::zeros(K, X.n_cols);
    
    // ====================== YOUR CODE HERE ======================
    // Instructions: You should set centroids to randomly chosen examples from
    //               the dataset X
    //
    
    // Initialize the centroids to be random examples
    // Randomly reorder the indices of examples
    //randidx = randperm(X.n_rows);
    arma::mat randidx(1, X.n_rows);
    for( size_t i = 0; i < X.n_rows; ++i ) randidx(0,i) = (double)i;
    arma::shuffle(randidx);
    
    // Take the first K examples as centroids
    for( int i = 0; i < K; ++i )
        centroids.row(i) = X.row(randidx(i));
    return centroids;
}

void test1() {
    printf("Finding closest centroids.\n\n");
    
    // Load an example dataset that we will be using
    arma::mat X;
    X.load("ex7data2.txt");
    
    // Select an initial set of centroids
    int K = 3; // 3 Centroids
    arma::mat initial_centroids;
    initial_centroids << 3. << 3. << arma::endr << 6. << 2. << arma::endr << 8. << 5.;
    
    // Find the closest centroids for the examples using the
    // initial_centroids
    arma::mat idx = findClosestCentroids(X, initial_centroids);
    
    printf("Closest centroids for the first 3 examples: \n");
    std::cout << idx.rows(0,2);
    printf("\n(the closest centroids should be 0, 2, 1 respectively)\n");
    
    printf("Program paused. Press enter to continue.\n");
    std::cin.get();
    
    
    printf("\nComputing centroids means.\n\n");
    
    //  Compute means based on the closest centroids found in the previous part.
    arma::mat centroids = computeCentroids(X, idx, K);
    
    printf("Centroids computed after initial finding of closest centroids: \n");
    std::cout << centroids;
    printf("\n(the centroids should be\n");
    printf("   [ 2.428301 3.157924 ]\n");
    printf("   [ 5.813503 2.633656 ]\n");
    printf("   [ 7.119387 3.616684 ]\n\n");
    
    printf("Program paused. Press enter to continue.\n");
    std::cin.get();
    
    
    printf("\nRunning K-Means clustering on example dataset.\n\n");
    
    // Load an example dataset
    X.load("ex7data2.txt");
    
    // Settings for running K-Means
    K = 3;
    int max_iters = 10;
    
    // For consistency, here we set centroids to specific values
    // but in practice you want to generate them automatically, such as by
    // settings them to be random examples (as can be seen in
    // kMeansInitCentroids).
    //initial_centroids = [3 3; 6 2; 8 5];
    
    // Run K-Means algorithm. The 'true' at the end tells our function to plot
    // the progress of K-Means
    runkMeans(X, initial_centroids, max_iters,centroids, idx);
    printf("\nK-Means Done.\n\n");
    
    printf("Program paused. Press enter to continue.\n");
    std::cin.get();

    printf("\nRunning K-Means clustering on pixels from an image.\n\n");
    
    //  Load an image of a bird
    arma::mat A;
    //A.load("bird_small.png",arma::pgm_binary);
    
    // If imread does not work for you, you can try instead
    A.load("bird_small.txt");
    
    A = A / 255.; // Divide by 255 so that all values are in the range 0 - 1
    

    // Reshape the image into an Nx3 matrix where N = number of pixels.
    // Each row will contain the Red, Green and Blue pixel values
    // This gives us our dataset matrix X that we will use K-Means on.
    X = reshape(A, A.n_rows * A.n_cols, 3);
    
    // Run your K-Means algorithm on this data
    // You should try different values of K and max_iters here
    K = 16; 
    max_iters = 10;
    
    // When using K-Means, it is important the initialize the centroids
    // randomly. 
    // You should complete the code in kMeansInitCentroids.m before proceeding
    initial_centroids = kMeansInitCentroids(X, K);
    
    // Run K-Means
    runkMeans(X, initial_centroids, max_iters,centroids, idx);
    
    printf("Program paused. Press enter to continue.\n");
    std::cin.get();


    printf("\nApplying K-Means to compress an image.\n\n");
    
    // Find closest cluster members
    idx = findClosestCentroids(X, centroids);

    // Essentially, now we have represented the image X as in terms of the
    // indices in idx. 
    
    // We can now recover the image from the indices (idx) by mapping each pixel
    // (specified by its index in idx) to the centroid value
    //X_recovered = centroids(idx,:);
    arma::mat X_recovered(idx.n_rows,centroids.n_cols);
    for(size_t i = 0; i < idx.n_rows; ++i)  X_recovered.row(i) = centroids.row(idx(i));

    // Reshape the recovered image into proper dimensions
    X_recovered = reshape(X_recovered, A.n_rows, A.n_cols);

    // Display the original image 
    //subplot(1, 2, 1);
    //imagesc(A); 
    //title("Original");
    
    // Display compressed image side by side
    //subplot(1, 2, 2);
    //imagesc(X_recovered)
    //title(sprintf("Compressed, with %d colors.", K));
    printf("Compressed, with %d colors.\n", K);
    //X_recovered.save("bird_small_converted.ppm",arma::ppm_binary);
    
    
    printf("Program paused. Press enter to continue.\n");
    std::cin.get();

    
}

} // KMean_ns

#include <boost/lambda/lambda.hpp>
#include <gtsam/base/Vector.h>
#include <gtsam/linear/NoiseModel.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/geometry/Pose2.h>
#include <gtsam/nonlinear/PriorFactor.h>
#include <gtsam/slam/BetweenFactor.h>

int main()
{ 
    // Create an empty nonlinear factor graph
    gtsam::NonlinearFactorGraph graph;

    // Add a Gaussian prior on pose x_1
    gtsam::Pose2 priorMean{0.0, 0.0, 0.0};
    gtsam::noiseModel::Diagonal::shared_ptr priorNoise = 
        gtsam::noiseModel::Diagonal::Sigmas(gtsam::Vector3(0.3, 0.3, 0.1));
    graph.add(gtsam::PriorFactor<gtsam::Pose2>{1, priorMean, priorNoise});

    // Add two odometry factors
    gtsam::Pose2 odometry{2.0, 0.0, 0.0};
    gtsam::noiseModel::Diagonal::shared_ptr odometryNoise = 
        gtsam::noiseModel::Diagonal::Sigmas(gtsam::Vector3{0.2, 0.2, 0.1});
    graph.add(gtsam::BetweenFactor<gtsam::Pose2>{1, 2, odometry, odometryNoise});
    graph.add(gtsam::BetweenFactor<gtsam::Pose2>{2, 3, odometry, odometryNoise});

    graph.print();
    
    return 0;
}

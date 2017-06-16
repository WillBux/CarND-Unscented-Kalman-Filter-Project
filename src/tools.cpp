#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    //Calculate the error using the Root-Mean-Squared Error
    VectorXd rmse(4);
    rmse << 0,0,0,0;
    //making sure that the RMSE calculations do not break
    if(estimations.size() == 0){
        cout << "estimations.size() == 0" << endl;
        return rmse;
    }
    if(estimations.size() != ground_truth.size()){
        cout << "estimations.size() != ground_truth.size()" << endl;
        return rmse;
    }
    // Get the squared residuals
    for(unsigned int i=0; i < estimations.size(); ++i){
        VectorXd residual = estimations[i] - ground_truth[i];
        residual = residual.array()*residual.array();
        rmse += residual;
    }

    //Get the mean
    rmse = rmse / estimations.size();
    rmse = rmse.array().sqrt();
    return rmse;

}
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error = i_error + cte;


}

double PID::TotalError() {
  double tol = 0.2;
  double p[3] = {Kp, Kd, Ki};
  double dp[3] = {1, 1, 1};
  double best_error = 9999;
  double error;

  while ((dp[0]+dp[1]+dp[2]) > tol){
    error = PID::p_error;
    for (int i = 0; i < 3; ++i){
      p[i] = p[i] + dp[i];
      if (error < best_error){
        best_error = error;
        dp[i] = dp[i] * 1.1;
      } else {
        p[i] = p[i] -(2 * dp[i]);
        error = PID::p_error;
        if (error <  best_error){
          best_error = error;
          dp[i] = dp[i] * 1.1;
        } else {
          p[i] = p[i] + dp[i];
          dp[i] = dp[i] * 0.9;
        }

      }
      Kp = p[0];
      Kd = p[1];
      Ki = p[2];


    }

  }
  return best_error;

}


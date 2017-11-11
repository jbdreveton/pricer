// Example program
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
#include <random>
#include <algorithm>
#include <cmath>

float rand_normal(float mean, float stddev)
{//Box muller method
    static float n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        float x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            float d = sqrt(-2.0*log(r)/r);
            float n1 = x*d;
            n2 = y*d;
            float result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}

/*
std::vector<float> test(int n){
    std::vector<float> vec;
    for(int i=0; i<n;i++){
        float d = rand_normal(0,1);
        vec.push_back(sqrt(n) +d);
    }
    return vec;
}
*/

std::vector<float> simulation(int nb_discret, float S0, float K, float r, float T, float sigma){
    std::vector<float> pay_off;
    pay_off.push_back(S0);
    for(int i=1;i<nb_discret;i++){
        float epsilon = rand_normal(0,1);
        pay_off.push_back(pay_off[i-1]*exp((r-sigma*sigma/2)*(T/nb_discret)-sigma*epsilon*sqrt(T/nb_discret)));
    }
    return pay_off;
}

float pay_off_european(std::vector<float> pay_off, float K){
    float gain=0;
    if (pay_off[364]>K){
        gain=pay_off[364]-K;
    }
    std::cout << "gain european : " << gain << std::endl;
    return gain;
}

float pay_off_lookback(std::vector<float> pay_off, float K){
    float gain=0;
    double max = *std::max_element(pay_off.begin(), pay_off.end());
    if(max > K){
        gain=max-K;
    }
    std::cout << "gain_lookback : " << gain << std::endl;
    return gain;
}

float gain_monte_carlo(int nb_simulation){
    int gain_moyen_european=0;
    for(int l=0;l<nb_simulation;l++){
        gain_moyen_european+=pay_off_european(simulation(365,100,100,0.05,1,0.3),100);
    }
    return gain_moyen_european/nb_simulation;
}

float gain_lookback_mc(int nb_simulation){
    int gain_moyen_lookback=0;
    for(int l=0;l<nb_simulation;l++){
        gain_moyen_lookback+=pay_off_lookback(simulation(365,100,100,0.05,1,0.3),100);
    }
    return gain_moyen_lookback/nb_simulation;
}

int main()
{
  /*std::vector<float> t = test(10);
  std::cout << t[1] << std::endl;*/
  std::vector<float> sim = simulation(365,100,100,0.05,1,0.3);
  std::cout << sim[365] << std::endl;
  std::cout << "gain pay_off_european : " << pay_off_european(sim,100) << std::endl;
  std::cout << "gain pay_off_lookback : " << pay_off_lookback(sim,100) << std::endl;
  std::cout << "gain moyen european : " << gain_monte_carlo(100) << std::endl;
  std::cout << "gain moyen lookback : " << gain_lookback_mc(100) << std::endl;
}

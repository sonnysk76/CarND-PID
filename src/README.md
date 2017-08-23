[//]: # (Image References)
[imagen1]: ./images/turn1.png "Turn"
[imagen2]: ./imagenes/turn2.png "Turn"

### Describe the effect each of the P, I, D components had in your implementation.

# P: 
Proportional, corrects in a proportional of the deviation reported, if the number is to high it will start moving side to side.
# D: 
Differential, corrects the steering value in relation of the change of the Cross Track Error increments, decrements. In this implementation the constand Kd is set to around 20 times the Proportional Kp constant.
# I:
Integral, Correct the error of drift, since is not observable the effect of drift in the track, this constant Ki is almost 0.

Chosing the Parameters.
An implementation of Twiddle was used, the Total Error to optimize was not the correct parameter to optimize, it keeps increesing the Kp constant and the other two remain in 0.


Than manual tunning was tried, observing how each parameter affected, seting a value of 1 for the chosed parameter and the other two.
Then testing and modified to double, or half, and repeting the tunnign.
The speed was increased to 0.5 in order to get a better parameters optimization, and returned to 0.3 and test.
The final values where
Kp = 0.17
Kd = 3.7
Ki = 0.00001

The evaluation of the laps with care of not go off the track drivable area, specially in tight turns.
![imagen1]
![imagen2]


with this values the goal of complete a lap in the circuit was met.

Starting from a boolean function, the algorithms takes in input the values of X1, X2, X3, ...XN that leed to a 1 in the truth table.
(e.g. for a simple X1 & X2 boolean function, the value input in the vector would be just 11, for X1 or X2, they would be 01, 10, 11).
The algorithm then generates a Binary tree that represent graphically the function. This is done by placing in the roots the strings "X1", "X2" ..."XN".
The two subtrees of each root will then signify that the root value is 0 or 1 respectively for the left and righy subtree.
In the leaves it will be placed either a 0 or a 1, respectively if the path to that leaf leads to a 0 or a 1 of the function.
So for X1 & X2:


                                          X1
                               X2                   X2
                       0            0          0          1
                      
                  
And for X1 or X2:


                                          X1
                               X2                   X2
                       0            1          1          1
                      

                       

                             

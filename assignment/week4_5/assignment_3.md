**Assignment 3**

# **Name**: Longqing Chen **SID**: 22010057

## Part 1. Description

For this assignment, I implemented 3 different programs. 

The first one(vec_dot_product.cpp) is a calculator that computes the two vectors that the user inputs. It is very straightforwardly formatted for the user and uses dynamic memory. It prevents user from input mistakes such as vector entry mismatch and inputting letters or any other none float types by outputting an error warning and exit the program. 

The second one(vec_dot_product_time.cpp) is the initial code(brute force) I have for Task 2, calculating the dot product of 200M-element vectors. It uses dynamic memory and time measurement to calculate the time needed for the dot product calculation, which is approximately 523ms, the output of which is a float type, suffering from precision issues.

The third one is the improved version of Task 2 for Task 3, by improving the efficiency of the code for Task 2 using compile specification multi-threading calculation with the loop, the code now only takes 84ms to execute the calculation.

The third one also is a test for OpenBLAS, Task 4, the calculation takes about 90ms. 

 All of the codes can be found in my GitHub repo.

#### The first program: 

1. Calculation

   > `Please input the first vector (e.g. 2.3 4.5 6.7): 2.3 1.6 2.9`
   >
   > `Please input the second vector: 1.2 2.9 3.4`
   >
   > `The dot product is: 17.26`

2. Input type wrong

   > `Please input the first vector (e.g. 2.3 4.5 6.7): 1 2 3`
   >
   > `Please input the second vector: 2 a 3`
   >
   > `Error: input type wrong`

   

   > `Please input the first vector (e.g. 2.3 4.5 6.7): 1 4 a`
   >
   > `Error: input type wrong`

3. Vector entry mismatch

   > `Please input the first vector (e.g. 2.3 4.5 6.7): 1 2 3.2 4`
   >
   > `Please input the second vector: 1 2 3`
   >
   > `Error: vector size mismatch`

#### The second program: brute force 200M calculation

> `The dot product is: 1. 07374e+09`
>
> `Calculation took: 551ms.`

#### The third program(part I)

By optimizing multi-thread parameter, having the program "multitask" the loops instead of doing one loop at one time, the calculation rate increases significantly.

 I find that the calculation would be the fastest if there are 7 threads: 

1 thread avg: 523 ms

2 threads avg: 489 ms

3 threads avg: 421 ms

4 threads avg: 380 ms

5 threads avg: 313 ms

6 threads avg: 293 ms

7 threads avg: 270 ms

8 threads avg: 289 ms

Also, I stumbled upon several blogs online about compiler specification, here's one https://stackoverflow.com/questions/14492436/g-optimization-beyond-o3-ofastBy . 

This technique speeds up the calculation quite a bit.

> `g++ vec_dot_product_time_2.cpp -Ofast -march=native -funroll-loops`

#### The third program(part II): OpenBLAS

Here's the compile specification and the one of the OpenBLAS calculation time:

> `PS C:\cpp\assignment\week4_5> g++ vec_dot_product_time_2.cpp -I C:/OpenBlas/OpenBLAS-0.3.10/Temp/include/ -L C:/OpenBlas/OpenBLAS-0.3.10/Temp/lib -lopenblas -lpthread -lgfortran`
>
> `PS C:\cpp\assignment\week4_5> ./a`



> `The dot product is: 6.67534e+09`
>
> `The dot product is: 4.29497e+09`
>
> `Calculation took: 146ms.`

## Part 3. Difficulties and Solutions

1. Float type would cause significant bias after large additions, while double type would be less affected by such process. solution: changing float type in Task 2 to double type in Task 3.

2. Configuring OpenBLAS. I had a lot of technical difficulties configuring OpenBLAS. For example, the environment setups, the PATHs, the lib file location, the header file location, etc. Here are some links that saved my life:

   https://blog.csdn.net/yangyangyang20092010/article/details/46350519

   https://blog.csdn.net/yangyangyang20092010/article/details/45156881

   https://blog.csdn.net/weixin_44636558/article/details/105850553


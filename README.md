# k-nearest-neighbors (KNN) with server and clients

## Introduction
When the client connects to the server, the server sends him a menu of options. The client prints this menu to the console.

In the client, a new vector is given, which does not appear in the tagged vectors database, type distance, and k. The client will send these to the server. The algorithm on the server will check which of the tagged vectors in the database are closest to the new vector.
Then, it takes the K-Kathers ("similar") as input, checks what their labeling is, and classifies the new vector according to the most common labeling. The server will send the classification to the client. The client will print it to the terminal.

## Table of contents
* [General Information](#general-information)
* [Installation](#installation)
* [Project status](#project-status)
* [Contact](#Contact)


## General Information

option 1: upload files - in this option, the user enters a path of csv file that exists in his computer. The client sends the data of this file to the server. The server sends back to the client that the upload complete. This process will be twice - once of the train file and second one for the test file.

Option 2: algorithm settings - The server will send the current classifier parameter values which is the K parameter value and the current distance meter. 
If the user presses enter, the parameters must be left unchanged. Otherwise, the user can enter new values separated by a space when K can have a range
values of whole numbers and the distance matrix can have the following values: euclidean distance- AUC, taxicab geometry- MAN, Chebyshev distance- CHB, Canberra distance- CAN, or Minkowski distance- MIN.
If everything is fine - return to the main menu. If the user entered an invalid value - the error message will be returned:

Option 3: calssify data - 

option 4: - display results - 

Option 5: download results - 

The server will receive as arguments, a file name (of the tagged vectors) and a port (the server will listen on this port number). If the server receives an invalid filename (such as a file that does not exist) or an invalid port (such as a port not between 1024 and 65535), the server will print "Invalid Arguments" to the terminal and close the server.
The client will receive as arguments, an IP (of the server) and a port (the same port that the server listens to). The server and client need to be listening on the same port to connect to each other. If the client receives an invalid ip, the client will be closed. If the port is invalid (such as a port not between 1024 and 65535), the client will print "Invalid Arguments" to the terminal and close the client.

The client gets one vector, distance type and k from the user. If the user enters invalid vector (such as empty data, only spaces, data that includes characters that aren't numbers, etc), invalid distance type (such as not AUC, MAN, CAN, MIN, or CHB), or invalid k (such as not positive integer number), the client will print "invalid input" to the console and gets the next data. 
If the user enters valid vector, such as a vector that includes only numbers (integer, double or negative numbers), valid distance and valid k, the data will be sent to the server.
If the client gets -1 from the user, the connection with the server will be closed and the client will be closed. The server will continue to the next connection with another client.

The server gets the data from the client. If the data is invalid vector (such as empty data, only spaces, data that includes characters that aren't numbers, not only numeric or double values, not equal to the size of the vector that entered by the user, etc), invalid distance type (such as not AUC, MAN, CAN, MIN, or CHB), or invalid k (such as not positive integer number), the server will send "invalid input" to the client.
If the data is valid, the algorithm in the server will check which of the tagged vectors in the database are the K vectors closest to the new vector (this k we get from the client). The distance between the new vector and each of the vectors from the database is calculated using one of five algorithms (euclidean distance- AUC, taxicab geometry- MAN, Chebyshev distance- CHB, Canberra distance- CAN, or Minkowski distance- MIN), depending on the algorithm that the server gets from the client.
Then, the algorithm takes the K closest ("similar") vectors to the input and checks what their labeling is. The classification of the new vector is based on the most common labeling among the k vectors. In the end, the server will send this classification to the client.

The client gets the classification (or the error message) from the server and prints it to the console.
The connection between the server and this client will continue until the client requests to close the connection.

## Installation
Before installing this project, you need to install on your computer:
* IDE that supports c++ (like Visual Studio Code or CLion).
* Git

After it, run the following commands in the terminal:

```
git clone https://github.com/adi-ben-yehuda/advanced_ex_3.git
make
./server.out file port
```
For example:
```
./server.out iris_classified.csv 12345
```
Open a new terminal and run the following commands in this terminal:

```
./client.out ip port
```
For example: 
```
./client.out 127.0.0.1 12345
```

## Project status 
The project is in the beginning stages and will develop over time.

## Contact
Created by @adi-ben-yehuda and @ShaharMosh - feel free to contact us!

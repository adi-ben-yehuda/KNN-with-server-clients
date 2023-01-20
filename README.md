# k-nearest-neighbors (KNN) with server and clients using threads

## Introduction
After connecting the client and server, the server sends a menu to the client.
The options in the menu are:
1. Upload files - upload classified and unclassified files.
2. Algorithm settings - set k and metric distance.
3. Calssify data - classify each vector in the unclassified file according to the classified file.
4. Display results - display the classifications in the console.
5. Download results - write the classifications into a file.
8. Exit - close the connection between the client and server.
According to the choice of the client, the correct function executes.

## Table of contents
* [General Information](#general-information)
* [Installation](#installation)
* [Project status](#project-status)
* [Contact](#Contact)

## General Information
The server will receive as argument a port (the server will listen on this port number). If the server receives an invalid port (such as a port not between 1024 and 65535), the server will print "Invalid Arguments" to the terminal and close the server.
The client will receive as arguments, an IP (of the server) and a port (the same port that the server listens to). The server and client need to be listening on the same port to connect to each other. If the client receives an invalid IP, the client will be closed. If the port is invalid (such as a port not between 1024 and 65535), the client will print "Invalid Arguments" to the terminal and close the client.

The server sends a menu to the client. The client prints it to the console. 
The options in the menu are:
#### Option 1 - upload files:
The user will be given the option to type a path to a local csv file on his computer, and after pressing enter the client will send the contents of the file to the server. At the end of sending, the server will send back to the client a message "upload complete." If the path is invalid, "input invalid" will be printed.
This process will be repeated twice, when the first time you receive a file for training the classifier and the second time a file for his exam. 

#### Option 2 - algorithm settings:
The server will send the current classifier parameter values which is the K parameter value and the current distance meter. 
If the user presses enter, the parameters must be left unchanged. That is, the default values are: k=5 and metric=AUC. Otherwise, the user can enter new values separated by a space when K can have a range
values of whole numbers and the distance matrix can have the following values: euclidean distance- AUC, taxicab geometry- MAN, Chebyshev distance- CHB, Canberra distance- CAN, or Minkowski distance- MIN.
If the user entered an invalid value - the error message will be returned: "invalid value for metric" or "invalid value for K" or both.

#### Option 3 - calssify data:
The server will run the algorithm on the CSV files uploaded earlier. For each uncalssified vector, the algorithm will check which of the tagged vectors in the classified file are the K vectors closest to the new vector. The distance between the new vector and each of the vectors from the classified file is calculated using the metric that the user chose in option 2. Then, the algorithm takes the K closest ("similar") vectors to the input and checks what their labeling is. The classification of the new vector is based on the most common labeling among the k vectors. 
At the end of the run, the server will send "complete data classifying" to the client. The client will print it to the console.
If no files have been uploaded yet, will be printed "please upload data".

#### Option 4 - display results:
The server will send the list of classifications to the client. For each classification, the printout will be: the number of the line in the test file and the classification. Finally, ".Done" will be printed.
If no files have been uploaded yet, print "please upload data".
If the files to be printed have not yet been classified, print "please classify the data".

#### Option 5 - download results:
The behavior will be similar to that of option 4, except that instead of printing the results, the user will enter a path to create the file locally and there the client will save the results, in exactly the same format (without Done). 

#### Option 8 - Exit:
The connection with the server will be closed and the client will be closed.

After each option (except 8), the menu will be sent by the server to the client. The client will print it to the console.
The connection between the server and this client will continue until the client requests to close the connection.

In the server, all communication between the server and the client will take place using the TCP protocol. A new thread is created for each client; thus, several clients are treated simultaneously.
In the client, in option 5, writing to the file exists in a separate thread. Thus, the connection between the server and the client continues to operate simultaneously with writing to the file.

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

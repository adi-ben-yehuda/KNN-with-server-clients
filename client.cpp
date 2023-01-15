#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "File.h"

using namespace std;

/* Function that get the port as an argument.
 * Check if it is number and if it is in the valid range.*/
int getPort(char **argv) {
    int port = 0;
    /* Check if the arg is number*/
    if (isNumeric(argv[2])) {
        port = atoi(argv[2]);
        if (port < 1024 || port > 65535 ) { // Check if the port is in the valid range.
            port = 0;
        }
    }
    return port;
}




void option1(int sock) {
    string pathTrain = "", pathTest = "";
    char buffer[4096] = " ";
    int expected_data_len = sizeof(buffer);

    // Receive messageTrain from the server.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }

    // Get the path of train file from the user.
    cin >> pathTrain;
    // If the pathTrain is empty or invalid path.
    if (pathTrain == "" || !isFileExist(pathTrain)) {
        cout << "invalid input" << endl;
        return;
    }
    sendDataFile(sock, pathTrain);

    memset(buffer, ' ', 4096);
    // Get "upload complete" from server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer << endl;
    }

    memset(buffer, ' ', 4096);
    // Receive messageTrain from the server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer << endl;
    }

    // Get the path of test file from the user.
    getline(cin, pathTest);
    // If the pathTest is empty or invalid path.
    if (pathTest == "" || !isFileExist(pathTest)) {
        cout << "invalid input" << endl;
        return;
    }
    sendDataFile(sock, pathTest);

    memset(buffer, ' ', 4096);
    // Get "upload complete" from server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer << endl;
    }
}

int main(int argc, char **argv) {
    // If the arguments are empty. or the port is invalid.
    if (argc != 3 || getPort(argv) == 0) {
        cout << "invalid arguments" << endl;
        return false;
    }

    const char *ip_address = argv[1];
    const int port = getPort(argv);

    vector<double> p, q;
    bool isValid = true, isK = false, isDistance = false, isVector = false;
    string input = "", arg = "", data = "", option = "";
    double numCheck = 0.0, validDistance = 0.0;
    int countErrors = 0;



    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Check if the creation of the socket succeeded.
    if (sock < 0) {
        perror("error creating socket");
    }

    // Initialize the data for the connection to the server.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);

    // Check if the connection succeeded.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return false;
    }

    /* Get numbers from the user and saves them in vectors. */
    while (true) {

        // Menu
        char buffer[4096] = " ";
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            //  connection is closed
            close(sock);
        } else if (read_bytes < 0) {
            cout << "Acceptance failed" << endl;
        } else {
            cout << buffer;
        }


        cin >> option;
        // Send the data that get from the console, to the server.
        int sent_bytes = send(sock, option.c_str(), option.length(), 0);
        if (sent_bytes < 0) {
            cout << "Sending failed" << endl;
        }
        if (option == "1"){
            option1(sock);


        }

//        p.clear();
//        /* Get input from the user as a string that is separated by spaces. */
//        getline(cin, input);
//        /* If the input is entered .*/
//        if (input == "") {
//            cout << "invalid input" << endl;
//            continue;
//        }
//
//        // If the input is -1, close the client.
//        if (input == "-1") {
//            // Send the data that get from the console, to the server.
//            int sent_bytes = send(sock, "0", 1, 0);
//            if (sent_bytes < 0) {
//                cout << "Sending failed" << endl;
//            }
//            close(sock);
//            return 0;
//        }
//
//        countErrors = 0;
//        stringstream ss(input);
//
//        /* Split the input by spaces and save it in arg. */
//        while (ss >> arg) {
//            stringstream ss2(arg);
//
//            // Check if the input is numeric.
//            if (isNumeric(arg)) {
//                // After the distance comes the k.
//                if (countErrors == 1) {
//                    // Because the k is numeric, save it.
//                    data += arg; // = k
//                    isK = true;
//                    /* The k should be in the end of the line.
//                     * Check if there is another text after the k and print an error if yes. */
//                    if (ss >> arg) {
//                        cout << "invalid input" << endl;
//                        isValid = false;
//                        break;
//                    }
//                } else {
//                    data += arg + " "; // = vector
//                    isVector = true;
//                }
//            } else if (ss2 >> numCheck && ss2.eof()) { // The input is double or negative.
//                // After the distance comes the k, and it can't be a double or negative.
//                if (countErrors == 1) {
//                    isValid = false;
//                    break;
//                } else {
//                    data += arg + " "; // = vector
//                    isVector = true;
//                }
//            } else { // The data is string.
//                countErrors++;
//                if (countErrors == 1) {
//                    // If the vector is empty, print error.
//                    if (data == "") {
//                        isValid = false;
//                        break;
//                    } else {
//                        validDistance = getDistance(p, q, arg);
//                        // Check if the distance is valid algorithm.
//                        if (validDistance != -1) {
//                            data += arg + " "; // = distance
//                            isDistance = true;
//                        } else {
//                            isValid = false;
//                            break;
//                        }
//                    }
//                } else { // There are more than one time that we get a string.
//                    isValid = false;
//                    break;
//                }
//            }
//        }
//
//        // Check if the user does not enter a vector, distance or k.
//        if (!(isK && isDistance && isVector)) {
//            cout << "invalid input" << endl;
//        } else if (isValid) {
//            data += " ";
//            // Send the data that get from the console, to the server.
//            int sent_bytes = send(sock, data.c_str(), data.length(), 0);
//            if (sent_bytes < 0) {
//                cout << "Sending failed" << endl;
//                continue;
//            }


        }

        data = "";
        countErrors = 0;
        isValid = true;
        isK = false;
        isDistance = false;
        isVector = false;
//    }
}

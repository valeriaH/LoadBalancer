#include<iostream>
#include <string>

#include "server.h"
#include "request_queue.h"
#include "request.h"
#include "load_balancer.h"

using namespace std;


int main() 
{
    string user_input;
    int num_servers;
    int runtime;

    cout << "Please enter the number of servers: ";
    getline(cin, user_input);
    num_servers = stoi(user_input);

    cout << "Please enter the amount of time you would like to run the load balancer: ";
    getline(cin, user_input);
    runtime = stoi(user_input);

    //start the load balancer
    cout << "Starting load balancer..." << endl;
    load_balancer loadbalancer(runtime, num_servers);

    

    return 0;
}

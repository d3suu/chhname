#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

int main(){
	if(getuid()!=0){
		std::cout << "Welp, seems like you are not root." << std::endl; // You can't be root if your user id (getuid()) isnt 0
		return 1; // Return 1 becouse its error
	} else {
		std::cout << "Okay, you are root.\n";
	}
	std::ofstream hostname_file; // Make a ofstream object named "hostname_file" 
	hostname_file.open("/etc/hostname"); // Load /etc/hostname to "hostname_file" object
	if(hostname_file.is_open()!=true){ // Check if file loaded properly (actually check if root is able to load /etc/hostname)
		std::cout << "[ERROR] Cant open hostname file!" << std::endl; // Lol, nope
		return 1; // Return 1 becouse its error
	}
	std::cout << "Hostname file load complete.\n";
	hostname_file.close(); // Close the file becouse chhname will not remove the content of file
	std::cout << "Enter new hostname: ";
	std::string hostname_name; // Make "hostname_name" string which contains new hostname
	std::cin >> hostname_name;
	std::cout << "Are you sure about that? (y,n) ";
	std::string sure; // Make "sure" string which contains if user is sure to change the hostname
	std::cin >> sure;
	if(sure!="y"){ // If user is not sure (or actually wrote anything else than "y" to "sure" string) chhname stops
		std::cout << "Ok, stopping" << std::endl;
		return 0; // And that's not error actually
	}
	std::remove("/home/d3s/test.txt"); // chhname removes the file becouse its easier than to clear file and then write to it
	hostname_file.open("/etc/hostname"); // Load (actually create new) /etc/hostname file to "hostname_file"
	hostname_file << hostname_name; // Write "hostname_name" string to "hostname_file" object
	hostname_file.close(); // Close /etc/hostname file
	std::cout << "Finished, you can reboot securely now." << std::endl;
	return 0;
}
